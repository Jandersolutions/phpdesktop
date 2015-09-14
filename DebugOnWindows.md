Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/DebugOnWindows


---


# How to debug PHPDesktop app on Windows #

This page provides instructions on how to debug application in case of a crash.

## Application logs ##

First and easiest thing to do is to check debug.log file which contains application logs, including CEF logs. You may change "log\_severity" option to "verbose" to have more detailed logs, see the ChromeSettings wiki page.

## Crash in PHPDesktop related code ##

If this is a crash that happens in PHPDesktop reated code then you should build app from sources using instructions provided on the BuildOnWindows wiki page. In the future we may provide Release symbols for "phpdesktop-chrome.exe" executable, so that it is not required to build it from sources to debug the stack trace.

## Crash in CEF/Chrome related code ##

If crash happens in CEF/Chrome related code then it should be reported to the [CEF Issue Tracker](https://code.google.com/p/chromiumembedded/issues/list). Here are guidelines for what the report should contain:
  * Problem must be reproducible in cefclient.exe application, which is a sample browser included with CEF binaries. The easiest way to obtain it is to download "`TestApp`" binaries from [cefbuilds.com](http://cefbuilds.com). Problem must be reproducible using the latest CEF branch or trunk.
  * Include a minimal example or step by step instructions to reproduce problem.
  * If it is not easy to reproduce problem when for example crash happens only on some computers, or when it is not possible to provide an example, because code or data are private and cannot be shared, then the alternative is to obtain CEF stack trace for the crash. See the next section "How to get CEF stack trace".

## How to get CEF stack trace ##

If crash happens in CEF/Chrome related code, for example in the renderer process, then here are the steps to debug it:
  1. Install Visual C++ 2010 Express edition (we will refer to it as Visual Studio from now on). It's free, see [link1](http://www.visualstudio.com/en-us/downloads#d-2010-express) or [link2](http://go.microsoft.com/?linkid=9709969) (iso file).
  1. Download "Release symbols" for given branch from [cefbuilds.com](http://cefbuilds.com). It must match the exact same CEF branch and CEF revision that PHPDesktop was build with. Put "libcef.dll.pdb" in app directory next to "libcef.dll".
  1. Launch application
  1. In Visual Studio attach debugger to the phpdesktop-chrome.exe running process.
    1. You need to identify which one of them is the renderer process (assuming that crash happens in the renderer process), as there may be three or more running processes with the same name "phpdesktop-chrome.exe". You can use a tool like [Process Explorer](http://technet.microsoft.com/en-us/sysinternals/bb896653.aspx) to see what command line arguments were used to launch subprocess. In Process Explorer hover over the process or click its properties, an argument like "--type=renderer" will mean this is it. For GPU process that would be "--type=gpu-process". The PID column in Process Explorer is a process identifier. You use that identifier to attach to that specific process in Visual Studio.
    1. Visual C++ 2010 Express Edition supports "Attach to process" option, but it is available only in Expert Settings. In menu check option Tools->Settings->Expert Settings.
    1. In menu select Debug -> Attach to Process
    1. Find the process using process identifier (ID column), select it and click "Attach".
  1. Debugging was started. Now wait for the process to crash and when it happens you should see stack trace in the [call stack window](http://stackoverflow.com/questions/945193/how-do-i-find-the-stack-trace-in-visual-studio).
  1. Now that we have stack trace for the crash, an issue may be submitted to the [CEF Issue Tracker](https://code.google.com/p/chromiumembedded/issues/list).