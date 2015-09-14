Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/EnvironmentVariables


---


# Environment variables #

This page discusses environment variables exposed to PHP scripts.

## PHPDESKTOP`_` env variables ##

These environment variables are exposed to PHP scripts and accessible using `$_ENV`/`$_SERVER` global variables.

  * PHPDESKTOP\_VERSION - example value "31.3". This value is taken from the version info embedded in the phpdesktop executable.
  * PHPDESKTOP\_DIRECTORY - not yet available. See [Issue 125](https://code.google.com/p/phpdesktop/issues/detail?id=125).

## Mongoose web server env variables ##

These are Mongoose related env variables:

```html

[SERVER_SOFTWARE] => Mongoose/3.9c
[SERVER_PORT] => 56920```

## Example dump of `$_ENV` ##

List of env variables generated using PHPDesktop Chrome 31.8:

```html

[SERVER_NAME] => 127.0.0.1
[SERVER_ROOT] => C:\phpdesktop\phpdesktop-chrome\www
[DOCUMENT_ROOT] => C:\phpdesktop\phpdesktop-chrome\www
[SERVER_SOFTWARE] => Mongoose/3.9c
[GATEWAY_INTERFACE] => CGI/1.1
[SERVER_PROTOCOL] => HTTP/1.1
[REDIRECT_STATUS] => 200
[SERVER_PORT] => 56918
[REQUEST_METHOD] => GET
[REMOTE_ADDR] => 127.0.0.1
[REMOTE_PORT] => 56920
[REQUEST_URI] => /env-variables.php
[SCRIPT_NAME] => /env-variables.php
[SCRIPT_FILENAME] => C:\phpdesktop\phpdesktop-chrome\www\env-variables.php
[PATH_TRANSLATED] => C:\phpdesktop\phpdesktop-chrome\www\env-variables.php
[HTTPS] => off
[PATH] => C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;c:\Program Files (x86)\Java\jre7\bin\;c:\bin\;c:\Program Files (x86)\Git\bin\;c:\Python27\;;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\TortoiseGit\bin;C:\Go\bin;C:\MinGW\bin;
[APPDATA] => C:\Users\ctomczak\AppData\Roaming
[LOCALAPPDATA] => C:\Users\ctomczak\AppData\Local
[ComSpec] => C:\Windows\system32\cmd.exe
[COMSPEC] => C:\Windows\system32\cmd.exe
[OS] => Windows_NT
[ProgramFiles] => C:\Program Files (x86)
[PROGRAMFILES] => C:\Program Files (x86)
[ProgramFiles(x86)] => C:\Program Files (x86)
[ProgramW6432] => C:\Program Files
[CommonProgramFiles] => C:\Program Files (x86)\Common Files
[CommonProgramFiles(x86)] => C:\Program Files (x86)\Common Files
[CommonProgramW6432] => C:\Program Files\Common Files
[SystemDrive] => C:
[SYSTEMDRIVE] => C:
[SystemRoot] => C:\Windows
[SYSTEMROOT] => C:\Windows
[windir] => C:\Windows
[WINDIR] => C:\Windows
[ALLUSERSPROFILE] => C:\ProgramData
[ProgramData] => C:\ProgramData
[PROGRAMDATA] => C:\ProgramData f
[PUBLIC] => C:\Users\Public
[USERDOMAIN] => ctomczak-PC
[USERPROFILE] => C:\Users\ctomczak
[HOMEPATH] => \Users\ctomczak
[HOMEDRIVE] => C:
[COMPUTERNAME] => CTOMCZAK-PC
[LOGONSERVER] => \\CTOMCZAK-PC
[PATHEXT] => .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC
[PSModulePath] => C:\Windows\system32\WindowsPowerShell\v1.0\Modules\
[USERNAME] => ctomczak
[HTTP_HOST] => 127.0.0.1:56918
[HTTP_CONNECTION] => keep-alive
[HTTP_ACCEPT] => text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
[HTTP_USER_AGENT] => Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.57 Safari/537.36
[HTTP_REFERER] => http://127.0.0.1:56918/
[HTTP_ACCEPT_ENCODING] => gzip,deflate
[HTTP_ACCEPT_LANGUAGE] => en-us,en;q=0.8
[TMP] => C:\Users\ctomczak\AppData\Local\Temp\
[TEMP] => C:\Users\ctomczak\AppData\Local\Temp\
[TMPDIR] => C:\Users\ctomczak\AppData\Local\Temp\
[PHPDESKTOP_VERSION] => 31.8```