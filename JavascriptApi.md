Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/JavascriptApi


---


# Javascript API #

PHP Desktop Chrome exposes its API through the javascript "phpdesktop"
object that is binded to the "window" object. Below are the methods of this object:

phpdesktop.**GetVersion()**

> Get the PHP Desktop version. This value is taken from the version info embedded in the phpdesktop executable.

phpdesktop.**ToggleFullscreen()**

> To go into fullscreen mode or exit fullscreen mode.

phpdesktop.**IsFullscreen()**

> Whether in fullscreen mode.


---

## Other functions ##

window.**close()**

> Close application window. See also [Issue 95](https://code.google.com/p/phpdesktop/issues/detail?id=95).