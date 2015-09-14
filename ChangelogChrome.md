Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/ChangelogChrome


---


# Changelog - Chrome #

Release notes for PHP Desktop Chrome.

Version 31.9 - Release Candidate.
  * Added the main window "always\_on\_top" option, see [Issue 98](https://code.google.com/p/phpdesktop/issues/detail?id=98)
  * Added the web server "hide\_files" option, see [Issue 17](https://code.google.com/p/phpdesktop/issues/detail?id=17)

Version 39.2 - Release Candidate.
  * Updated to Chrome 39.0.2171.36 (CEF branch 2171 revision `1902`). See [Issue 146](https://code.google.com/p/phpdesktop/issues/detail?id=146).
  * Added the main window "always\_on\_top" option, see [Issue 98](https://code.google.com/p/phpdesktop/issues/detail?id=98)
  * Added the web server "hide\_files" option, see [Issue 17](https://code.google.com/p/phpdesktop/issues/detail?id=17)

Version 33.0 - Release Candidate.
  * This release is largely motivated by the donation made by TK Dewjee, so say thanks to him
  * Updated to Chrome 33.0.1750.170 (CEF branch 1750 revision `1805`). See [Issue 147](https://code.google.com/p/phpdesktop/issues/detail?id=147).
  * Updated to PHP 5.4.35

Version 31.8 released on November 21, 2014.
  * Added support for pretty urls with basic url rewriting for 404 errors ([Issue 81](https://code.google.com/p/phpdesktop/issues/detail?id=81)). See the ["web\_server"]["404\_handler"] option on the [Settings](Settings.md) wiki page.
  * Fixed Mongoose environment variables: REQUEST\_URI, PHP\_SELF, SCRIPT\_NAME, SCRIPT\_FILENAME, PATH\_TRANSLATED ([Issue 137](https://code.google.com/p/phpdesktop/issues/detail?id=137))
  * Fixed -400 loading error when navigating Back and Forward in history after a POST request was made ([Issue 138](https://code.google.com/p/phpdesktop/issues/detail?id=138))
  * Fixed problems when OS environment variables exceed 4KB in size ([Issue 128](https://code.google.com/p/phpdesktop/issues/detail?id=128))
  * Added missing CGI environment variables: `%windir%` and many others. See [Issue 136](https://code.google.com/p/phpdesktop/issues/detail?id=136).

Version 31.7 released on October 3, 2014.
  * Updated php versions in binary releases: PHP 5.6.1 and 5.4.33
  * Added more examples to the www/ directory
  * php.exe is now bundled along with php-cgi.exe ([Issue 96](https://code.google.com/p/phpdesktop/issues/detail?id=96))
  * Fixed false positive result on virustotal.com for PHP 5.5.8 release by replacing it with PHP 5.6.1 ([Issue 122](https://code.google.com/p/phpdesktop/issues/detail?id=122))

Version 31.6 released on February 1, 2014.
  * Fixed buggy drawing of the popup window on Win XP ([Issue 72](https://code.google.com/p/phpdesktop/issues/detail?id=72)).
  * When PHP fails due to unicode path issue, do not display the "No input file specified" message in browser window. Instead display a message about the unicode problem and how to solve it, then terminate application immediately ([Issue 74](https://code.google.com/p/phpdesktop/issues/detail?id=74)).
  * Fixed problems when the temp directory returned by OS contained unicode characters. In such case phpdesktop will try other fallbacks like "C:\Windows\Temp" among others ([Issue 71](https://code.google.com/p/phpdesktop/issues/detail?id=71)).

Verion 31.5 released on January 26, 2014.
  * Added the "context\_menu" option in the settings.json file. See the ChromeSettings wiki page ([Issue 67](https://code.google.com/p/phpdesktop/issues/detail?id=67)).
  * When there is an error while opening/parsing the settings.json file, application will display a message about the error and terminate immediately.
  * Fixed error handling when a firewall blocks loading of the main webpage on application startup. A message is displayed to the user to check his firewall settings.

Version 31.4 released on January 25, 2014.
  * Added ability to download files. New option "enable\_downloads" added to the settings.json file. Added the download.php example. ([Issue 65](https://code.google.com/p/phpdesktop/issues/detail?id=65))
  * Exposed PHP Desktop API to javascript, see the JavascriptApi wiki page. Added the javascript-api.php example. Exposed the ToggleFullscreen() and GetVersion() methods ([Issue 38](https://code.google.com/p/phpdesktop/issues/detail?id=38), [Issue 66](https://code.google.com/p/phpdesktop/issues/detail?id=66)).
  * Fixed issues with web server port conflicts. When web server listening port is set to 0 in settings.json, OS will assign a random free port. Multiple instances of phpdesktop applications may now be running simultenously without problems ([Issue 9](https://code.google.com/p/phpdesktop/issues/detail?id=9)).
  * Fixed long path causing error when spawning CGI process ([Issue 63](https://code.google.com/p/phpdesktop/issues/detail?id=63))
  * Fixed mongoose webserver issues when unicode characters are in path
  * Added the "remote\_debugging\_port" option to settings.json. When set to 0 it will generate a random port. Use this option now instead of the "remote-debugging-port" command line switch.
  * Added the --cgi-environment argument that can be passed to the phpdesktop executable to pass arbitrary environment variables to PHP scripts. See the [CommandLineArguments](CommandLineArguments.md) wiki page. See [Issue 43](https://code.google.com/p/phpdesktop/issues/detail?id=43).
  * Added the "start\_maximized" option to settings.json ([Issue 24](https://code.google.com/p/phpdesktop/issues/detail?id=24)).
  * Added the PHPDESKTOP\_VERSION environment variable. You can access it through `$_ENV` global variable.
  * Added the temp-dir.php example
  * Added the "cgi\_temp\_dir" option to settings.json ([Issue 70](https://code.google.com/p/phpdesktop/issues/detail?id=70)).
  * Added the "start\_fullscreen" setting

Version 31.3 released on January 22, 2014.
  * Fixed the temp directory problems, including upload and session problems (see [Issue 39](https://code.google.com/p/phpdesktop/issues/detail?id=39), [Issue 23](https://code.google.com/p/phpdesktop/issues/detail?id=23)).
  * Fixed application crash when the main window was closed before closing the popup window.
  * Fixed icons not being set for popup windows.
  * Fixed the SERVER\_NAME env variable (was "mydomain.com"), it is now set to the ip address that server listens on.
  * Added the upload and session examples ([Issue 41](https://code.google.com/p/phpdesktop/issues/detail?id=41)).
  * Added new settings "center\_relative\_to\_parent" and "default\_size" for popup windows.
  * Added the no-cache example.

Version 31.2 released on January 21, 2014.
  * Fixed the Developer Tools window not loading on Win8 ([Issue 60](https://code.google.com/p/phpdesktop/issues/detail?id=60)).

Version 31.1 released on January 21, 2014.
  * Added the "cache\_path" setting in ChromeSettings ([Issue 58](https://code.google.com/p/phpdesktop/issues/detail?id=58)).
  * Added the "external\_drag" setting in ChromeSettings.
  * Added the "external\_navigation" setting in ChromeSettings ([Issue 59](https://code.google.com/p/phpdesktop/issues/detail?id=59)).
  * Added the "command\_line\_switches" setting in ChromeSettings ([Issue 56](https://code.google.com/p/phpdesktop/issues/detail?id=56)).
  * Added the "subprocess\_show\_console" setting in [Settings](Settings.md).
  * Added the "log\_file" and "log\_severity" settings in ChromeSettings.
  * Added the "reload\_page\_F5" and "devtools\_F12" settings in ChromeSettings ([Issue 57](https://code.google.com/p/phpdesktop/issues/detail?id=57)).

Version 31.0 released on January 19, 2014.
  * Initial release (See [Issue 1](https://code.google.com/p/phpdesktop/issues/detail?id=1))
  * Includes Chrome version 31.0.1650.57
  * Application is DPI-aware, see the "dpi\_aware" setting on the [Settings](Settings.md) wiki page.