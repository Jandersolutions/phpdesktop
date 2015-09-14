Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/Settings


---


# Settings #

This page describes settings that can be found in the "settings.json" file.

Table of contents:


## application ##

**single\_instance\_guid** = ""

> Set this to non-empty string to disallow multiple instances
> of your application. This string should be unique. It is
> recommended to use a
> [GUID generator](http://www.google.com/search?q=guid+generator)
> for that. An example GUID would be:
> "4C00DEC0-9298-4dc4-98BD-0FAE9F3BA730".

**dpi\_aware** = true

> Since PHPDesktop Chrome 39 behavior of DPI and zomming has changed. DPI awareness is always enabled in phpdesktop (DeclareDPIAware.manifest is embedded in exe). Setting this option to false will only affect window size during creation.

> Whether application should be DPI aware. If you change text size settings on Windows (in Win7 go to Control Panel -> Appearance and Personalization -> Display), then app will detect this and enlarge texts in the Chrome browser. Chrome zooming techology will be used. System's default text enlarging mechanism that would make text look fuzzy won't be used.

> When dpi aware is set to true, besides enlarging text size, the window size (specified by the "default\_size" setting under the "main\_window" section) will also be enlarged respectively. So if the Win7 text size settings are set to Large (150%) and you set the default\_size to [1024, 768], then the window will be resized to [1536, 1152].

## debugging ##

**show\_console** = false

> Whether to show command-line console with debug output. This is almost the same output that is written to the log file with the exception that messages from the subprocesses (Renderer, GPU) are not visible in the main console window.

**subprocess\_show\_console** = false

> Show more consoles for all Chrome subprocesses.

**log\_level** = "INFO"

> Application level logging (do not mistake with php logging), possible values are: ERROR, WARNING,
> INFO, DEBUG, DEBUG1, DEBUG2, DEBUG3, DEBUG4. Level of
> ERROR will only log severe errors, DEBUG4 is most verbose.

**log\_file** = ""

> Log file for application logging. Do not mistake with php logging. To set php log file set the
> "error\_log" option in php.ini: http://www.php.net/manual/en/errorfunc.configuration.php#ini.error-log

> Debug output is written to this file, set it to empty
> string to disable logging to file.

> Restriction: Only one instance of an application can log to
> that file at the same time, when second instance of an
> application is started, it won't write messages to the log file.


## main\_window ##

**title** = "PHP Desktop MSIE"

> Main window title. If set to empty executable's name will
> be used instead.

**icon** = ""

> Set icon for main window. The allowed extension for the icon is "ico".
> Only relative path is allowed.

> If you would like to change the icon that is embedded in the
> executable file then do the following steps:

  1. Download [Resource Hacker](http://www.angusj.com/resourcehacker/) and run it.
  1. From the "File" menu select open, navigate and choose "phpdesktop-msie.exe" (or "phpdesktop-chrome.exe").
  1. On the left side there should be a tree control, expand "/Icon Group/128/1033", right click on the "1033", select "Replace Resource..." and replace that resource with your icon.
  1. That's it, save it and see the changes by running the executable file.

> When you change icon embedded in the executable file you do not
> need to set it anymore in the settings file.

**default\_size** = [1024, 768]

> Default size of the window, width & height.

**minimum\_size** = [800, 600]

> Minimum size of the window, width & height. User won't be able
> to resize the window to a size smaller than this. A value of
> 0 means there is not minimum size limit when resizing.

**maximum\_size** = [0, 0]

> Maximum size of the window, width & height. User won't be able
> to resize the window to a size bigger than this. A value of 0
> means there is no maximum size limit when resizing.

**disable\_maximize\_button** = false

> Whether to disable maximize button. You can mix this option
> along with minimum\_size & maximum\_size, thus allowing you to
> define a window with a fixed size that cannot be resized in
> any way.

**center\_on\_screen** = true

> Whether to center window on screen. If you set this to false,
> OS will take care of positioning the window.

**start\_maximized** = false

> Starts the main application window maximized.

**start\_fullscreen** = false

> Starts the main application window in fullscreen mode.

**always\_on\_top** = false

> Places the window above all non-topmost windows. The window maintains its topmost position even when it is deactivated.

**save\_position** = false

> Not yet implemented. Whether to save window size & position and restore it on next
> launch of the application. See [Issue 89](https://code.google.com/p/phpdesktop/issues/detail?id=89).



## popup\_window ##

**icon** = ""

> You can set a different icon for popup windows. If set to empty,
> main window icon will be used.

**fixed\_title** = ""

> The title for the popup window is set according to meta `<title>`
> tag on a webpage, however you can set a fixed title for all
> popup windows, in this case meta title will be ignored.

**center\_relative\_to\_parent** = true

> Center popup window relative to the parent window.

**default\_size** = [1024, 768]

> The default size used when there is no size specified for the popup window (no width/height parameters passed to window.open).

## web\_server ##

**listen\_on** = ["127.0.0.1", 0]

> Ip address & port to listen on. It is recommended for the
> port to be in range 49152–65535. When set to 0, OS will assign
> a random free port. It is recommended to set it to 0 to avoid
> port conflicts.

**www\_directory** = "www"

> Document root directory for your PHP scripts.

**index\_files** = ["index.html", "index.php"]

> List of files to be treated as directory index. A maximum
> of 32 files is allowed.

**cgi\_interpreter** = "php/php-cgi.exe"

> CGI interpreter for all CGI scripts regardless script extension.

> From Mongoose documentation:
> "Mongoose decides which interpreter to use by looking at the first
> line of a CGI script" - this is probably not true after
> we've set cgi extensions.

**cgi\_extensions** = ["php"]

> Files with these extension are treated as CGI. A maximum
> of 32 extensions is allowed.

**cgi\_temp\_dir** = ""

> The temp directory for the CGI environment. This will set three env variables: TMP, TEMP, TMPDIR. It is recommended to leave this string empty, read below.

> If set to empty string PHP Desktop will set a temp directory for you automatically. If the temp directory returned by OS contains unicode characters (PHP doesn't play well with unicode), then it will choose another temp directory for you that will not cause problems with PHP.

**404\_handler** = "/pretty-urls.php"

Http 404 not found errors will call the provided php script. You can use this to enable support for pretty urls in application. This is an equivalent of using Apache's mod\_rewrite using this set of rules:

```
<IfModule mod_rewrite.c>
RewriteCond %{REQUEST_FILENAME} !-f
RewriteCond %{REQUEST_FILENAME} !-d
RewriteRule ^(.*)$ pretty-urls.php/$1 [L]
</IfModule>
```

To know what pretty url was accessed check `$_SERVER["PATH_INFO"]` or `$_SERVER["REQUEST_URI"]`. See [pretty-urls.php](https://code.google.com/p/phpdesktop/source/browse/phpdesktop-chrome/www/pretty-urls.php) script for an example.

**hide\_files** = `[]`

> Patterns for the files to hide. Files that match the pattern will not show up
> in directory listing and return `404 Not Found` if requested. Pattern must be for
> a file name only, not including directory name. Maximum number of patterns is 100.

> Special characters that can be used in patterns:

  * `*` (matches multiple characters)
  * `?` (matches one character)

> Example values: `[".*", "secret.txt"]` - hides all files starting with dot and additionally "secret.txt".

## msie ##

MSIE settings are described on a separate wiki page, see the [MSIEsettings](MSIEsettings.md) wiki page.

## chrome ##

Chrome settings are described on a separate wiki page, see the ChromeSettings wiki page.