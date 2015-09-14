Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/ChromeSettings


---


# Chrome settings #

This are the settings that can be found in the "chrome" section in the "settings.json" file (see also the [Settings](Settings.md) wiki page).

**cache\_path** = "webcache"

The directory where cache data will be stored on disk. If set to empty string, an in-memory cache will be used and your cookies and other data (like HTML5 databases) will not persist across app launch sessions. Chrome flushes cache data to disk every 30 seconds or so.

**command\_line\_switches** = {}

There are many settings that can be customized through Chrome command line switches. These switches can only be set programmatically in the settings.json file, by passing a dictionary of switches, with switch name as a key. The switch name should not contain the "-" or "--" prefix, otherwise it will be ignored. Switch value may be an empty string, if the switch doesn't require a value. These switches are set only for the main browser process.

See the peter.sh website for an assembled list of all Chrome switches:<br>
<a href='http://peter.sh/experiments/chromium-command-line-switches/'>http://peter.sh/experiments/chromium-command-line-switches/</a>

See also CEF switches in the <a href='https://code.google.com/p/chromiumembedded/source/browse/trunk/cef3/libcef/common/cef_switches.cc'>cef_switches.cc</a> file.<br>
<br>
Example code in settings.json:<br>
<br>
<pre><code>command_line_switches: {<br>
    "lang": "fr",<br>
    "enable-media-stream: ""<br>
},<br>
</code></pre>

Example switches:<br>
<br>
<ul><li>{"lang": "fr"} - The language file that we want to try to open. Of the form language[-country] where language is the 2 letter code from ISO-639. See locales/ directory for a full list of supported languages.<br>
</li><li>{"enable-media-stream": ""} - Enables media streaming (WebRTC audio/video).<br>
</li><li>{"enable-speech-input": ""} - Enable speech input (x-webkit-speech).<br>
</li><li>{"disable-web-security": ""} - Don't enforce the <a href='http://en.wikipedia.org/wiki/Same-origin_policy'>same-origin policy</a>.<br>
</li><li>{"proxy-server": "socks5://127.0.0.1:8888"} - To set custom proxy. See also <a href='https://code.google.com/p/chromiumembedded/wiki/GeneralUsage#Proxy_Resolution'>Proxy Resolution</a> page.<br>
</li><li>{"no-proxy-server": ""} - By default Chromium uses the IE proxy settings (set in Internet Explorer options). To disable use of that proxy set the "no-proxy-server" Chromium switch. See also <a href='https://code.google.com/p/chromiumembedded/wiki/GeneralUsage#Proxy_Resolution'>Proxy Resolution</a> page.</li></ul>

These switches can also be set from command line when launching the phpdesktop executable, for example "phpdesktop-chrome.exe --enable-media-stream". This can be useful to quickly test some of the switches without being forced to edit the settings.json file. Also when combined with the ability to <a href='CommandLineArguments.md'>pass CGI environment variables as command line arguments</a> you are capable of creating multiple phpdesktop browser windows with a mix of different settings to fulfill your application specific needs.<br>
<br>
<b>context_menu</b> = {}<br>
<br>
The mouse context menu is configurable using the following options:<br>
<br>
<ul><li>enable_menu - whether to enable context menu.<br>
</li><li>navigation - whether to show the "Back", "Forward" and "Reload" options.<br>
</li><li>print - whether to show the "Print..." option.<br>
</li><li>view_source - whether to show the "View source" option.<br>
</li><li>open_in_external_browser - whether to show the "Open page in external browser" and "Open frame in external browser" options.<br>
</li><li>devtools - whether to show the "Show Developer Tools" option. See also the "devtools_F12" option. You have to set the "remote_debugging_port" option for the developer tools to be available.</li></ul>

<b>devtools_F12</b> = true<br>
<br>
Developer tools will open when pressing the F12 key. See also the ["context_menu"]["devtools"] option. You have to set the "remote_debugging_port" option for the developer tools to be available.<br>
<br>
<b>external_drag</b> = true<br>
<br>
BUG NOTICE: This also controls internal drag and drop events on websites, see <a href='https://code.google.com/p/phpdesktop/issues/detail?id=97'>Issue 97</a>.<br>
<br>
Whether to allow external drag events to enter the browser window. For example an url is dragged and navigation occurs, or a file is dragged and its contents are displayed.<br>
<br>
There are methods for detecting what type of element is dragged into the window, in future we might allow filtering and allowing some type of the drag events, see <a href='https://code.google.com/p/phpdesktop/issues/detail?id=91'>Issue 91</a>.<br>
<br>
<b>external_navigation</b> = true<br>
<br>
Whether to allow navigation to exernal websites inside PHP Desktop browser. When set to false external links will be opened in OS default browser. This behavior applies in general to external navigation, so this gets fired not only when clicking a link, but also when doing a redirect (whether it is initiated from php or from javascript using the window.location object).<br>
<br>
<b>log_file</b> = "debug.log"<br>
<br>
The directory and file name to use for the debug log. If empty, the default name of "debug.log" will be used and the file will be written to the application directory.<br>
<br>
<b>log_severity</b> = "default"<br>
<br>
The log severity. Only messages of this severity level or higher will be<br>
logged. Also configurable using the "log-severity" command-line switch with<br>
a value of "verbose", "info", "warning", "error", "error-report" or<br>
"disable". The default is "info".<br>
<br>
<b>reload_page_F5</b> = true<br>
<br>
Reloading page with cache ignored will be available under the F5 key. See also the ["context_menu"]["reload_page"] option.<br>
<br>
<b>remote_debugging_port</b> = 0<br>
<br>
Port for remote debugging. A value between 1024 and 65535 is accepted. A value of 0 will generate a random port. A value of -1 will disable remote debugging.