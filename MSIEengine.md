Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/MSIEengine


---


# MSIE engine #

Information on the Internet Explorer (MSIE) engine embedded in
PHP Desktop.

## Version ##

The minimum version of Internet Explorer installed on end-user's
machine must be at least 6.0 SP2 (released on August 25, 2004).
It might work with older versions, but it was not tested.

## Context menu ##

Internet Explorer context menu has been disabled, but you are
still able to Copy and Paste by using keyboard shortcuts
(ctrl+c, ctrl+v). You can add a context menu with Copy/Paste/Cut
operations by adding javascript code, take a look at example
code here: http://stackoverflow.com/a/200194/623622

## Restrictions on running scripts ##

There are no restrictions when running scripts (javascript,
wscript, vbscript, java, activex) inside your application's
window. Scripts have full access to system resources, so be
carefully not to run some third party website in an iframe,
as it might put a dangerous activex control that will
have access to read/write any files on user's computer.
This had to be done this way, so that you have a reliable control
in your application, no matter what type of
restrictions have been put on Local Intranet or other
security zones in Internet Explorer settings. Your application
scripts will always work. This approach might be revised if
there is a demand to control these settings.

## Keyboard shortcuts ##

Many of Internet Explorer keyboard shortcuts have been
disabled: F5 (refresh), Backspace (back in history) and
others (ctrl+p, ctrl+n, etc), so that it feels like
native application and not a browser. Only one shortcut
is remaining: Ctrl+F (find on a page), as it might be
useful.

## Window size & position ##

If you need to manipulate window's positon or size you
have two functions available: window.resizeTo and
window.moveTo. Other methods like window.resizeBy and
window.moveBy have not yet been implemented.

## How to use a newer version of IE engine ##

The default version of IE engine embedded is IE 7.0. Even if you have IE 11 installed on Windows 7, then still the embedded version will be IE 7. To force it to be IE 10 for example you have to add the registry keys below. These registry keys could be added by your application's installer.

```
32 bits: [(HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE)\Software\Microsoft\Internet Explorer\Main\FeatureControl\FEATURE_BROWSER_EMULATION]
64 bits: [(HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE)\Software\wow6432node\Microsoft\Internet Explorer\Main\FeatureControl\FEATURE_BROWSER_EMULATION]
 "phpdesktop-msie.exe" = dword 10000 (Hex: 0x2710)
```

See these articles for reference:
  * https://msdn.microsoft.com/en-us/library/ee330730(v=vs.85).aspx#browser_emulation
  * https://support.askia.com/hc/en-us/articles/200011472-Change-the-version-of-Internet-Explorer-in-askiadesign-s-web-test-mode
  * http://blogs.msdn.com/b/ie/archive/2009/03/10/more-ie8-extensibility-improvements.aspx

When [Issue 150](https://code.google.com/p/phpdesktop/issues/detail?id=150) gets fixed there will be an option in settings.json to set IE version more easily.

<br><br><br><br><br>
<br><br><br><br><br>
<br><br><br><br><br>
<br><br><br><br><br>
<br><br><br><br><br>
<br><br><br><br><br>