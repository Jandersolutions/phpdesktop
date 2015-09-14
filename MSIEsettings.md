Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/MSIEsettings


---


# MSIE settings #

This are the settings for the "msie" section found in "settings.json"
file (see [Settings](Settings.md) wiki page).

## msie ##

These options are available only in MSIE engine.

**error\_page** = "error\_page.html"

> When navigation error happens (404, 500 or other) browser will
> display contents of this static file, it must be an HTML file,
> PHP file is not allowed. In that html file you can use two
> template variables: `{{status_code}}` and `{{navigate_url}}`.

> Possible status codes can be viewed here:
> http://msdn.microsoft.com/en-us/library/aa768365(v=vs.85).aspx

> If the status code was not provided by a web-server (could not
> connect for example), then an HRESULT error code with negative
> value will be provideed, see `INET_E_*` constants at the link above.

> If an empty string is set, a default Internet Explorer error
> message will be displayed.

**smooth\_scroll** = false

> Whether smooth scrolling should be enabled.

**enable\_f5\_refresh** = false

> Enable F5 key to refresh the page.

**show\_context\_menu** = false

> Whether to show mouse context menu.

**disable\_script\_debugger** = false

> When this is false and
> there is a javascript error on a webpage, a dialog box appears
> asking whether to to launch a script debugger.

**hide\_dialog\_boxes** = false

> Whether to hide dialog boxes and messages. Critical errors and security
> alerts are not suppressed.

**silent\_operations** = false

> The browsing component will behave silently, no user interface
> or user notification will occur.

> When you set `disable_script_debugger`, `hide_dialog_boxes`
> and `silent_operations`  to true, then you won't see any dialog
> boxes when javascript error occurs, or any other unexpected
> user interface controls or notifications. A recommended
> way for  dealing with javascript errors is to use "window.onerror"
> event, see [test\_javascript\_errors.php](https://code.google.com/p/phpdesktop/source/browse/phpdesktop-msie/www/test_javascript_errors.php) script.

**use\_themes** = true

> Specifies whether hosted browser should use themes for pages
> it displays.

**autocomplete\_forms** = false

> Whether to enable AutoComplete in forms.

**windowed\_select\_control** = true

> Internet Explorer 7 or later.

> Setting to true causes MSHTML to create standard Microsoft
> Win32 "windowed" select and drop-down controls.

> Setting to false causes MSHTML to use the Document Object Model
> (DOM) to create native "windowless" select controls that can be
> visually layered under other elements.

**disable\_scrollbars** = false

> Disable scrollbars.

**flat\_scrollbars** = false

> Use flat scrollbars.

**utf8\_url\_encoding** = true

> Whether to enable utf-8 encoding for urls.

**dpi\_aware** = false

> Internet Explorer 8 or later. When set to true, causes layout
> engine to calculate document pixels as 96 dots per inch (dpi).
> Normally, a document pixel is the same size as a screen pixel.

**registry\_settings\_path** = ""

> Not yet implemented.

> A path to registry (in HKEY\_CURRENT\_USER) where browser control
> settings are stored. An example path would be:
> "`Software\\My Application Name\\WebBrowser2 Settings`".

**registry\_settings** = {}

> Not yet implemented.

> The default settings can be found
> in "HKEY\_CURRENT\_USER\Software\Microsoft\Internet Explorer\Main",
> example keys:

> "Anchor Underline" "yes" <br>
<blockquote>"Cache_Update_Frequency" "Once_Per_Session" <br>
"CompatibilityFlags" 0 <br>
"Disable Script Debugger" "yes" <br>
"Display Inline Images" "yes" <br>
"Do404Search" 1 <br>
"Enable Browser Extensions" "yes" <br>
"FullScreen" "no" <br>
"Local Page" "C:\Windows\system32\blank.htm" <br>
"Play_Animations" "yes" <br>
"Play_Background_Sounds" "yes" <br>
"Use_DlgBox_Colors" "yes" <br>
"UseClearType" "no" <br>
"XMLHTTP" 1 <br></blockquote>

<blockquote>"Page_Transitions" <br>
"CSS_Compat" <br>
"Expand Alt Text" <br>
"Display Inline Videos" <br>
"Print_Background" <br>
"Use Stylesheets" <br>
"SmoothScroll" <br>
"Show image placeholders" <br>
"DisableScriptDebuggerIE" <br>
"Move System Caret" <br>
"Force Offscreen Composition" <br>
"Enable AutoImageResize" <br>
"UseThemes" <br>
"UseHR" <br>
"Disable_Local_Machine_Navigate" <br>
"Cleanup HTCs" <br>
"AlwaysAllowExecCommand" <br></blockquote>

<blockquote>Browser features can be also controlled through "HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main\FeatureControl",<br>
example keys:</blockquote>

<blockquote>FEATURE_RESTRICT_ABOUT_PROTOCOL_IE7 <br>
FEATURE_AJAX_CONNECTIONEVENTS <br>
FEATURE_SHOW_APP_PROTOCOL_WARN_DIALOG <br>
FEATURE_BROWSER_EMULATION <br>
FEATURE_ENABLE_CLIPCHILDREN_OPTIMIZATION <br>
FEATURE_MANAGE_SCRIPT_CIRCULAR_REFS <br>
FEATURE_ENABLE_SCRIPT_PASTE_URLACTION_IF_PROMPT <br>
FEATURE_BLOCK_SETCAPTURE_XDOMAIN <br>
FEATURE_CROSS_DOMAIN_REDIRECT_MITIGATION <br>
FEATURE_DOWNLOAD_INITIATOR_HTTP_HEADER  <br>
FEATURE_CFSTR_INETURLW_DRAGDROP_FORMAT  <br>
FEATURE_BLOCK_CROSS_PROTOCOL_FILE_NAVIGATION  <br>
FEATURE_IE6_DEFAULT_FRAME_NAVIGATION_BEHAVIOR  <br>
FEATURE_VIEWLINKEDWEBOC_IS_UNSAFE  <br>
FEATURE_GPU_RENDERING  <br>
FEATURE_MAXCONNECTIONSPER1_0SERVER  <br>
FEATURE_MAXCONNECTIONSPERSERVER  <br>
FEATURE_IFRAME_MAILTO_THRESHOLD  <br>
FEATURE_MIME_TREAT_IMAGE_AS_AUTHORITATIVE  <br>
FEATURE_SECURITYBAND  <br>
FEATURE_IVIEWOBJECTDRAW_DMLT9_WITH_GDI  <br>
FEATURE_NINPUT_LEGACYMODE  <br>
FEATURE_BLOCK_LMZ_IMG  <br>
FEATURE_BLOCK_LMZ_OBJECT <br>
FEATURE_BLOCK_LMZ_SCRIPT <br>
FEATURE_ISOLATE_NAMED_WINDOWS <br>
FEATURE_DOWNLOAD_PROMPT_META_CONTROL <br>
FEATURE_SCRIPTURL_MITIGATION <br>
FEATURE_WARN_ON_SEC_CERT_REV_FAILED <br>
FEATURE_LOAD_SHDOCLC_RESOURCES <br>
FEATURE_SPELLCHECKING <br>
FEATURE_STATUS_BAR_THROTTLING <br>
FEATURE_RESTRICT_CDL_CLSIDSNIFF <br>
FEATURE_SHIM_MSHELP_COMBINE <br>
FEATURE_WEBOC_DOCUMENT_ZOOM <br>
FEATURE_WEBOC_MOVESIZECHILD <br>
FEATURE_WEBSOCKET <br>
FEATURE_WEBSOCKET_AUTHPROMPT <br>
FEATURE_WEBSOCKET_CLOSETIMEOUT <br>
FEATURE_WEBSOCKET_MAXCONNECTIONSPERSERVER <br>
FEATURE_WEBSOCKET_FOLLOWHTTPREDIRECT <br>
FEATURE_RESTRICTED_ZONE_WHEN_FILE_NOT_FOUND <br></blockquote>

<blockquote>For a description of these features see:<br>
<a href='http://msdn.microsoft.com/en-us/library/ee330720(v=vs.85).aspx'>http://msdn.microsoft.com/en-us/library/ee330720(v=vs.85).aspx</a></blockquote>

<b>features_per_process</b>

<blockquote>Not yet implemented.</blockquote>

<blockquote>These browser control settings are set per application process.<br>
It extends "registry_settings", but does not require creating<br>
registry keys to set them. Available per process features:</blockquote>

<blockquote>FEATURE_OBJECT_CACHING <br>
FEATURE_ZONE_ELEVATION <br>
FEATURE_MIME_HANDLING <br>
FEATURE_MIME_SNIFFING <br>
FEATURE_WINDOW_RESTRICTIONS <br>
FEATURE_WEBOC_POPUPMANAGEMENT <br>
FEATURE_BEHAVIORS <br>
FEATURE_DISABLE_MK_PROTOCOL <br>
FEATURE_SECURITYBAND <br>
FEATURE_RESTRICT_ACTIVEXINSTALL <br>
FEATURE_VALIDATE_NAVIGATE_URL <br>
FEATURE_RESTRICT_FILEDOWNLOAD <br>
FEATURE_ADDON_MANAGEMENT <br>
FEATURE_HTTP_USERNAME_PASSWORD_DISABLE <br>
FEATURE_SAFE_BINDTOOBJECT <br>
FEATURE_UNC_SAVEDFILECHECK <br>
FEATURE_GET_URL_DOM_FILEPATH_UNENCODED <br>
FEATURE_TABBED_BROWSING <br>
FEATURE_SSLUX <br>
FEATURE_DISABLE_NAVIGATION_SOUNDS <br>
FEATURE_DISABLE_LEGACY_COMPRESSION <br>
FEATURE_FORCE_ADDR_AND_STATUS <br>
FEATURE_XMLHTTP <br>
FEATURE_DISABLE_TELNET_PROTOCOL <br>
FEATURE_FEEDS <br>
FEATURE_BLOCK_INPUT_PROMPTS <br></blockquote>

<blockquote>These features should not be set through "registry_settings",<br>
as they might be overwritten by per-process default values.</blockquote>

<blockquote>For a description of these features see:<br>
<a href='http://msdn.microsoft.com/en-us/library/ee330720(v=vs.85).aspx'>http://msdn.microsoft.com/en-us/library/ee330720(v=vs.85).aspx</a>