Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/ChangelogMSIE


---


# Changelog - MSIE #

This is a changelog of PHP Desktop with Internet Explorer (MSIE)
engine embedded.

Version 1.14 released on November 21, 2014.
  * Added support for pretty urls with basic url rewriting for 404 errors ([Issue 81](https://code.google.com/p/phpdesktop/issues/detail?id=81)). See the ["web\_server"]["404\_handler"] option on the [Settings](Settings.md) wiki page.
  * Fixed Mongoose environment variables: REQUEST\_URI, PHP\_SELF, SCRIPT\_NAME, SCRIPT\_FILENAME, PATH\_TRANSLATED ([Issue 137](https://code.google.com/p/phpdesktop/issues/detail?id=137))
  * Fixed -400 loading error when navigating Back and Forward in history after a POST request was made ([Issue 138](https://code.google.com/p/phpdesktop/issues/detail?id=138))
  * Fixed problems when OS environment variables exceed 4KB in size ([Issue 128](https://code.google.com/p/phpdesktop/issues/detail?id=128))
  * Added missing CGI environment variables: `%windir%` and many others. See [Issue 136](https://code.google.com/p/phpdesktop/issues/detail?id=136).


Version 1.13 released on February 1, 2014.
  * Fixed problems when the temp directory returned by OS contained unicode characters. In such case phpdesktop will try other fallbacks like "C:\Windows\Temp" among others ([Issue 71](https://code.google.com/p/phpdesktop/issues/detail?id=71)).

Version 1.12 released on January 25, 2014.
  * Fixed issues with web server port conflicts. When web server listening port is set to 0 in settings.json, OS will assign a random free port. Multiple instances of phpdesktop applications may now be running simultenously without problems ([Issue 9](https://code.google.com/p/phpdesktop/issues/detail?id=9)).
  * Fixed long path causing error when spawning CGI process ([Issue 63](https://code.google.com/p/phpdesktop/issues/detail?id=63))
  * Fixed mongoose webserver issues when unicode characters are in path
  * Added the --cgi-environment argument that can be passed to the phpdesktop executable to pass arbitrary environment variables to PHP scripts. See the [CommandLineArguments](CommandLineArguments.md) wiki page. See [Issue 43](https://code.google.com/p/phpdesktop/issues/detail?id=43).
  * Added the "start\_maximized" option to settings.json ([Issue 24](https://code.google.com/p/phpdesktop/issues/detail?id=24)).
  * Added the PHPDESKTOP\_VERSION environment variable. You can access it through `$_ENV` global variable.
  * Added the temp-dir.php example
  * Added the "cgi\_temp\_dir" option to settings.json ([Issue 70](https://code.google.com/p/phpdesktop/issues/detail?id=70)).

Version 1.11 released on January 22, 2014.
  * Fixed errors when application path contained spaces ([Issue 40](https://code.google.com/p/phpdesktop/issues/detail?id=40)).
  * Fixed mongoose webserver hanging when closing application on Win7 ([Issue 61](https://code.google.com/p/phpdesktop/issues/detail?id=61)).
  * Fixed temp directory problems, including upload and session problems (see [Issue 39](https://code.google.com/p/phpdesktop/issues/detail?id=39), [Issue 23](https://code.google.com/p/phpdesktop/issues/detail?id=23)).
  * Fixed issues with clipboard Copy/Cut commands ([Issue 30](https://code.google.com/p/phpdesktop/issues/detail?id=30)).
  * Fixed problems with links like "javascript:void(0)". These are not allowed anymore, as they cause to open Internet Explorer 9 download dialog on Win7. Replaced such links with hash "#".
  * Added the upload and session examples ([Issue 41](https://code.google.com/p/phpdesktop/issues/detail?id=41)).
  * Added the sqlite example ([Issue 32](https://code.google.com/p/phpdesktop/issues/detail?id=32)).
  * Added the cookies example
  * Added the no-cache example
  * Minor fixes to other examples, seems like IE9 requires strict html structure, if `<html>` or `<body>` are missing or placed incorrectly it may cause some strange random behavior.

Version v10 released on 2013-02-13.
  * Added "silent\_operations" option to [MSIEsettings](MSIEsettings.md)
  * Updated Mongoose web server to version 3.7
  * Popup windows can be closed by calling `window.external.CloseWindow()`, see an example in "www/test\_window.php"

Version v9 released on 2013-02-04.
  * Implemented popup windows ([Issue 13](https://code.google.com/p/phpdesktop/issues/detail?id=13))
  * Added php script example for opening popup windows and handling javascript errors
  * New options in settings.json file for the popup windows and MSIE browser (see [MSIEsettings](MSIEsettings.md))
  * Fixes to MSIE control
  * Fixed web-server listening on custom port defined in settings file, it worked only when port was a string
  * Windows have now keyboard & mouse focus by default

Version v8 released on 2013-01-19.
  * Invalid option "cgi\_executable" in settings.json file, it should be named "cgi\_interpreter"
  * Added logging of error messages in Mongoose web-server

Version v7 released on 2013-01-19.
  * Embedded [Mongoose](http://code.google.com/p/mongoose/) web-server, PHP built-in web-server couldn't handle multiple requests at the same time and wasn't reliable ([Issue 14](https://code.google.com/p/phpdesktop/issues/detail?id=14))
  * Added `index_files`, `cgi_interpreter` & `cgi_extensions` options to [Settings](Settings.md), `php_executable` option was removed

Version v6 released on 2013-01-18.
  * Added application settings file, see [Settings](Settings.md) wiki page ([Issue 4](https://code.google.com/p/phpdesktop/issues/detail?id=4))

Version v5 released on 2013-01-14.
  * PHP interpreter was missing Visual C runtime DLLs

Version v4 released on 2013-01-14.
  * External links open in system's default browser ([Issue 7](https://code.google.com/p/phpdesktop/issues/detail?id=7)).
  * Fixed keyboard handling for Input & Textarea controls ([Issue 11](https://code.google.com/p/phpdesktop/issues/detail?id=11)).

Version v3 released on 2013-01-13.
  * Fixed hardcoded title for the window which was "ASD"
  * Updated php scripts in the "www/" directory, index.php lists all php scripts in that directory

Version v2 released on 2013-01-13.
  * Added loading of extensions to "php/php.ini" file
  * Added pdo\_mysql extension
  * Unpacked dlls packed with upx
  * Added libeay32.dll & ssleay32.dll as php\_curl.dll depends on these
  * Added libpq.dll as pgsql extensions depend on it

Version v1 released on 2013-01-12.
  * Initial release of PHP Desktop with Internet Explorer engine embedded