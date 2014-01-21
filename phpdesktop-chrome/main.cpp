// Copyright (c) 2012-2014 PHP Desktop Authors. All rights reserved.
// License: New BSD License.
// Website: http://code.google.com/p/phpdesktop/

#include "defines.h"

#pragma comment(linker, "/manifestdependency:\"type='win32' "\
    "name='Microsoft.Windows.Common-Controls' version='6.0.0.0' "\
    "processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' "\
    "language='*'\"")

#include <crtdbg.h> // _ASSERT() macro
#include "resource.h"
#include <iostream>
#include <cmath>
#include <io.h>
#include <Fcntl.h>

#include "executable.h"
#include "fatal_error.h"
#include "file_utils.h"
#include "log.h"
#include "cef/browser_window.h"
#include "settings.h"
#include "single_instance_application.h"
#include "string_utils.h"
#include "web_server.h"
//#include "php_server.h"
#include "window_utils.h"
#include "cef/app.h"

SingleInstanceApplication g_singleInstanceApplication;
wchar_t* g_singleInstanceApplicationGuid = 0;
wchar_t g_windowClassName[256] = L"";
int g_windowCount = 0;
HINSTANCE g_hInstance = 0;
HANDLE g_logFileHandle = NULL;
extern std::string g_webServerUrl;

HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow, std::string title);
void InitLogging(bool show_console, std::string log_level,
                 std::string log_file);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
    BrowserWindow* browser = 0;
    BOOL b = 0;
    WORD childEvent = 0;
    HWND childHandle = 0;
    HWND shellBrowserHandle = 0;

    switch (uMsg) {
        case WM_SIZE:
            browser = GetBrowserWindow(hwnd);
            if (browser) {
                browser->OnSize();
            } else {
                LOG_WARNING << "WindowProc(): event WM_SIZE: "
                               "could not fetch BrowserWindow";
            }
            break;
        case WM_CREATE:
            g_windowCount++;
            if (GetWindow(hwnd, GW_OWNER)) {
                browser = new BrowserWindow(hwnd, true);
            } else {
                browser = new BrowserWindow(hwnd, false);
            }
            StoreBrowserWindow(hwnd, browser);
            return 0;
        case WM_DESTROY:
            g_windowCount--;
            LOG_DEBUG << "WM_DESTROY";
            RemoveBrowserWindow(hwnd);
            if (g_windowCount <= 0) {
                //LOG_DEBUG << "DISABLED: StopWebServer()";
                StopWebServer();
#ifdef DEBUG
                // Debugging mongoose, see InitLogging().
                printf("----------------------------------------");
                printf("----------------------------------------\n");
#endif
                PostQuitMessage(0);
            }
            break;
        case WM_GETMINMAXINFO:
            browser = GetBrowserWindow(hwnd);
            if (browser) {
                browser->OnGetMinMaxInfo(uMsg, wParam, lParam);
                return 0;
            } else {
                // GetMinMaxInfo may fail during window creation, so
                // log severity is only DEBUG.
                LOG_DEBUG << "WindowProc(): event WM_GETMINMAXINFO: "
                             "could not fetch BrowserWindow";
            }
            break;
        case WM_SETFOCUS:
            browser = GetBrowserWindow(hwnd);
            if (browser) {
                browser->SetFocus();
                return 0;
            } else {
                LOG_DEBUG << "WindowProc(): event WM_SETFOCUS: "
                             "could not fetch BrowserWindow";
            }
            break;
        case WM_ERASEBKGND:
            browser = GetBrowserWindow(hwnd);
            if (browser && browser->GetCefBrowser().get()) {
                CefWindowHandle hwnd = \
                        browser->GetCefBrowser()->GetHost()->GetWindowHandle();
                if (hwnd) {
                    // Dont erase the background if the browser window has been loaded
                    // (this avoids flashing)
                    return 1;
                }
            }
            break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
bool ProcessKeyboardMessage(MSG* msg) {
    /*
    if (msg->message == WM_KEYDOWN
            || msg->message == WM_KEYUP
            || msg->message == WM_SYSKEYDOWN
            || msg->message == WM_SYSKEYUP) {
        HWND root = GetAncestor(msg->hwnd, GA_ROOT);
        BrowserWindow* browser = GetBrowserWindow(root);
        if (browser) {
            if (browser->TranslateAccelerator(msg))
                return true;
        } else {
            LOG_DEBUG << "ProcessKeyboardMessage(): could not fetch BrowserWindow";
        }
    }
    */
    return false;
}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPTSTR lpstrCmdLine, int nCmdShow) {
    g_hInstance = hInstance;
    json_value* appSettings = GetApplicationSettings();
    
    // Debugging options.
    bool show_console = (*appSettings)["debugging"]["show_console"];
    bool subprocess_show_console = (*appSettings)["debugging"]["subprocess_show_console"];
    std::string log_level = (*appSettings)["debugging"]["log_level"];
    std::string log_file = (*appSettings)["debugging"]["log_file"];
    if (log_file.length() && log_file.find(":") == std::string::npos) {
        log_file = GetExecutableDirectory() + "\\" + log_file;
        log_file = GetRealPath(log_file);
    }
    
    // Initialize logging.
    if (std::wstring(lpstrCmdLine).find(L"--type=") != std::string::npos) {
        // This is a subprocess.
        InitLogging(subprocess_show_console, log_level, log_file);
    } else {
        // Main browser process.
        InitLogging(show_console, log_level, log_file);
    }
    
    // CEF subprocesses.
    CefMainArgs main_args(hInstance);
    CefRefPtr<App> app(new App);    
    int exit_code = CefExecuteProcess(main_args, app.get());
    if (exit_code >= 0) {
        // See InitLogging().
        if (g_logFileHandle) {
            CloseHandle(g_logFileHandle);
        }
        return exit_code;
    }

    LOG_INFO << "--------------------------------------------------------";
    LOG_INFO << "Started application";

    if (log_file.length())
        LOG_INFO << "Logging to: " << log_file;
    else
        LOG_INFO << "No logging file set";
    LOG_INFO << "Log level = "
             << FILELog::ToString(FILELog::ReportingLevel());

    // Main window title option.
    std::string main_window_title = (*appSettings)["main_window"]["title"];
    if (main_window_title.empty())
        main_window_title = GetExecutableName();

    // Single instance guid option.
    const char* single_instance_guid =
            (*appSettings)["application"]["single_instance_guid"];
    if (single_instance_guid && single_instance_guid[0] != 0) {
        int guidSize = strlen(single_instance_guid) + 1;
        g_singleInstanceApplicationGuid = new wchar_t[guidSize];
        Utf8ToWide(single_instance_guid, g_singleInstanceApplicationGuid,
                   guidSize);
    }
    if (g_singleInstanceApplicationGuid
            && g_singleInstanceApplicationGuid[0] != 0) {
        g_singleInstanceApplication.Initialize(
                g_singleInstanceApplicationGuid);
	    if (g_singleInstanceApplication.IsRunning()) {
            HWND hwnd = FindWindow(g_singleInstanceApplicationGuid, NULL);
            if (hwnd) {
                if (IsIconic(hwnd))
                    ShowWindow(hwnd, SW_RESTORE);
                SetForegroundWindow(hwnd);
                return 0;
            }
        }
    }

    // Window class name.
    if (g_singleInstanceApplicationGuid) {
        swprintf_s(g_windowClassName, _countof(g_windowClassName), L"%s",
                   g_singleInstanceApplicationGuid);
    } else {
        swprintf_s(g_windowClassName, _countof(g_windowClassName), L"%s",
                   Utf8ToWide(GetExecutableName()).c_str());
    }

    // LOG_DEBUG << "DISABLED: StartWebServer()";
    // g_webServerUrl = "http://127.0.0.1:54007/";
    if (!StartWebServer()) {
        FatalError(NULL, "Could not start internal web server.\n"
                   "Exiting application.");
    }

    CefSettings cef_settings;

    // log_file
    std::string chrome_log_file = (*appSettings)["chrome"]["log_file"];
    if (chrome_log_file.length() && chrome_log_file.find(":") == std::string::npos) {
        chrome_log_file = GetExecutableDirectory() + "\\" + chrome_log_file;
        chrome_log_file = GetRealPath(chrome_log_file);
    }
    CefString(&cef_settings.log_file) = chrome_log_file;
    
    // log_severity
    std::string chrome_log_severity = (*appSettings)["chrome"]["log_severity"];
    cef_log_severity_t log_severity = LOGSEVERITY_DEFAULT;
    if (chrome_log_severity == "verbose") {
        log_severity = LOGSEVERITY_VERBOSE;
    } else if (chrome_log_severity == "info") {
        log_severity = LOGSEVERITY_INFO;
    } else if (chrome_log_severity == "warning") {
        log_severity = LOGSEVERITY_WARNING;
    } else if (chrome_log_severity == "error") {
        log_severity = LOGSEVERITY_ERROR;
    } else if (chrome_log_severity == "error-report") {
        log_severity = LOGSEVERITY_ERROR_REPORT;
    } else if (chrome_log_severity == "disable") {
        log_severity = LOGSEVERITY_DISABLE;
    }
    cef_settings.log_severity = log_severity;
    
    // cache_path
    std::string cache_path = (*appSettings)["chrome"]["cache_path"];
    if (cache_path.length() && cache_path.find(":") == std::string::npos) {
        cache_path = GetExecutableDirectory() + "\\" + cache_path;
        cache_path = GetRealPath(cache_path);
    }
    CefString(&cef_settings.cache_path) = cache_path;

    CefInitialize(main_args, cef_settings, app.get());
    CreateMainWindow(hInstance, nCmdShow, main_window_title);
    CefRunMessageLoop();
    CefShutdown();
    
    // See InitLogging().
    if (g_logFileHandle) {
        CloseHandle(g_logFileHandle);
    }

    LOG_INFO << "Ended application";
    LOG_INFO << "--------------------------------------------------------";

    return 0;
}
HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow, std::string title) {
    json_value* appSettings = GetApplicationSettings();
    long default_width = (*appSettings)["main_window"]["default_size"][0];
    long default_height = (*appSettings)["main_window"]["default_size"][1];
    bool disable_maximize_button =
            (*appSettings)["main_window"]["disable_maximize_button"];
    bool center_on_screen = (*appSettings)["main_window"]["center_on_screen"];
    bool dpi_aware = (*appSettings)["application"]["dpi_aware"];

    if (default_width && default_height) {
        // Win7 DPI:
        // text size Larger 150% => ppix/ppiy 144
        // text size Medium 125% => ppix/ppiy 120
        // text size Smaller 100% => ppix/ppiy 96
        HDC hdc = GetDC(HWND_DESKTOP);
        int ppix = GetDeviceCaps(hdc, LOGPIXELSX);
        int ppiy = GetDeviceCaps(hdc, LOGPIXELSY);
        ReleaseDC(HWND_DESKTOP, hdc);
        double newZoomLevel = 0.0;
        if (ppix > 96) {
            newZoomLevel = (ppix - 96) / 24;
        }
        if (dpi_aware && newZoomLevel > 0.0) {
            default_width = default_width + (int)ceil(newZoomLevel * 0.25 * default_width);
            default_height = default_height + (int)ceil(newZoomLevel * 0.25 * default_height);
            LOG_DEBUG << "DPI, main window width/height = " << default_width
                      << "/" << default_height << ", enlarged by "
                      << ceil(newZoomLevel * 0.25 * 100) << "%";
        }
        int max_width = GetSystemMetrics(SM_CXMAXIMIZED) - 96;
        int max_height = GetSystemMetrics(SM_CYMAXIMIZED) - 64;
        LOG_DEBUG << "Window max width/height = " << max_width << "/" << max_height;
        bool max_size_exceeded = (default_width > max_width \
                || default_height > max_height);
        if (default_width > max_width) {
            default_width = max_width;
        }
        if (default_height > max_height) {
            default_height = max_height;
        }
        if (max_size_exceeded) {
            LOG_DEBUG << "Main window max size exceeded, new width/height = "
                      << default_width << "/" << default_height;
        }
    } else {
        default_width = CW_USEDEFAULT;
        default_height = CW_USEDEFAULT;
    }

    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(wc);
    wc.hbrBackground = (HBRUSH)GetSysColorBrush(COLOR_WINDOW);
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDR_MAINWINDOW));
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = g_windowClassName;

    ATOM atom = RegisterClassEx(&wc);
    _ASSERT(atom);

    HWND hwnd = CreateWindowEx(0, g_windowClassName,
            Utf8ToWide(title).c_str(), WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, default_width, default_height,
            HWND_DESKTOP, 0, hInstance, 0);
    _ASSERT(hwnd);
    if (disable_maximize_button) {
        int style = GetWindowLong(hwnd, GWL_STYLE);
        _ASSERT(style);
        int ret = SetWindowLong(hwnd, GWL_STYLE, style &~WS_MAXIMIZEBOX);
        _ASSERT(ret);
    }
    if (center_on_screen)
        CenterWindow(hwnd);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    return hwnd;
}
void InitLogging(bool show_console, std::string log_level,
                 std::string log_file) {
    if (show_console) {
        AllocConsole();
        FILE* freopen_file;
        freopen_s(&freopen_file, "CONIN$", "rb", stdin);
        freopen_s(&freopen_file, "CONOUT$", "wb", stdout);
        freopen_s(&freopen_file, "CONOUT$", "wb", stderr);
    }

#ifdef DEBUG
    // Debugging mongoose web server.
    FILE* mongoose_file;
    freopen_s(&mongoose_file,
            GetExecutableDirectory().append("\\debug-mongoose.log").c_str(),
            "ab", stdout);
#endif

    if (log_level.length())
        FILELog::ReportingLevel() = FILELog::FromString(log_level);
    else
        FILELog::ReportingLevel() = logINFO;

    if (log_file.length()) {
        // The log file needs to be opened in shared mode so that
        // CEF subprocesses can also append to this file.
        // Converting HANDLE to FILE*:
        // http://stackoverflow.com/a/7369662/623622
        g_logFileHandle = CreateFile(
                    Utf8ToWide(log_file).c_str(),
                    GENERIC_WRITE,
                    FILE_SHARE_WRITE,
                    NULL,
                    OPEN_ALWAYS,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);
        // Calling CloseHandle after CefShutdown.
        if (g_logFileHandle == INVALID_HANDLE_VALUE) {
            g_logFileHandle = NULL;
            LOG_ERROR << "Opening log file for appending failed";
            return;
        }
        int fd = _open_osfhandle((intptr_t)g_logFileHandle, _O_APPEND | _O_RDONLY);
        if (fd == -1) {
            LOG_ERROR << "Opening log file for appending failed, "
                      << "_open_osfhandle() failed";
            return;
        }
        FILE* pFile = _fdopen(fd, "a+");
        if (pFile == 0) {
            _close(fd);
            LOG_ERROR << "Opening log file for appending failed, "
                      << "_fdopen() failed";
            return;
        }
        // TODO: should we call fclose(pFile) later?
        Output2FILE::Stream() = pFile;
        /*
        OLD WAY:
        if (0 == _wfopen_s(&pFile, Utf8ToWide(log_file).c_str(), L"a"))
            Output2FILE::Stream() = pFile;
        else
            LOG_ERROR << "Opening log file for appending failed";
        */
    }
}