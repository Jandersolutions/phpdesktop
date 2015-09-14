Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/PhpDesktopPro


---


# PHP Desktop Pro #

This wiki page discusses plans for PHP Desktop Pro - a commercial version of PHP Desktop that may appear in the future.

## Preface ##

There is a demand for many new features in PHP Desktop, but up to this day it is still a single person development effort. Dedication of lots of time is required to make PHP Desktop greater than it is today. This can't be done by one person, at least not in his free time. Currently the only way to support PHP Desktop is through [donations](https://code.google.com/p/phpdesktop/wiki/Donations), but that way of supporting is definitely not working. Donations are rare and are less than 0.01% of development costs up to this day, despite a great interest manifested by tens of thousands of downloads. A commercial Pro version might get things better, hence this idea.

## Everything included in the box ##

The idea is to have a complete solution for all the most common issues when creating and deploying desktop application. So that user can do everything without leaving PHP Desktop Pro application. No need to install/know how to use third party tools, while still leaving an option to do so for more advanced users. At least a basic support should be included for things like: a) php source protection b) license key anti-piracy mechanism c) creation of app installer d) auto-updater.

## Features ##

If there is a feature that isn't listed here, but would prompt you to pay for the Pro version, please let us know on the [Forum](http://groups.google.com/group/phpdesktop).

  * A price between $100-$200 that would give a single developer perpetual and royalty-free license. Access to future releases for 1-3 years.
  * A guaranteed good quality support in the future
  * Latest version of Chromium included
  * A built-in support for application auto-updater
  * Graphical user interface for configuration of various options. Support for saving/loading project files. PHP Desktop Pro GUI would itself be written in PHP and use PHP Desktop framework, and that would guarantee better testing phase for the framework, early detection and solutions for real application's issues.
  * License key protection for application
  * A built-in php source protection solution ([bcompiler](http://us2.php.net/manual/en/book.bcompiler.php), [embeder](http://wildphp.free.fr/wiki/doku.php?id=win32std:embeder), [phc-win](http://wiki.swiftlytilting.com/Phc-win), [APC](http://us2.php.net/manual/en/book.apc.php), [WinCache](http://us2.php.net/manual/en/book.wincache.php), [BLENC](http://php.net/manual/en/book.blenc.php), see also [PECL dlls](http://windows.php.net/downloads/pecl/releases/))
  * Protection for static files (css/js/images)
  * Basic built-in support for creating application installer (embed NSIS installer internally)
  * Support for system tray icon
  * Custom window themes declared using HTML 5
  * Guaranteed compatibility with the most popular CMS/frameworks: Wordpress, Joomla, Drupal, Zend Framework, Laravel, Symfony and possibly others.
  * Linux support
  * Mac OSX support
  * Latest version of Mongoose web server commercial edition [[link](http://cesanta.com/libmongoose.shtml)]
  * Many other features found in the tracker [[link](https://code.google.com/p/phpdesktop/issues/list)]


<a href='Hidden comment: 
==When can I expect a PHP Desktop Pro release?==

A Pro edition will appear when there is sufficient interest in a paid version from  the community, that would make such a project profitable.
'></a>


## For discussion ##

  * Should Internet Explorer version be abandonded in favor of better support for Chrome version? A poll should include question on what version of PHP Desktop user is currently using (Chrome or MSIE). If ratio is something like 90% to 10% then we probably shouldn't invest much time into further development of IE version.
  * What would be the best way to set priority for features to be implemented first? Initially creating a poll for all PHP Desktop users might be a good idea. Later on we could enable a special voting for users who bought Pro version.
  * Some kind of marketplace for applications? Or at least an option to host application installer on phpdesktop website. That way you don't need to keep your own web hosting for distribution of application updates. Having an easy way for auto updates to work out of the box would be nice to have.
  * License key protection for application can be implemented in a few ways:
    * A set of license keys generated in advance and embedded directly in application, a fastest and easiest way to implement licenses, but the least secure
    * A more secure way that uses license keys that are binded to unique computer identifier and require internet connection to a license verification server. That serve may be hosted by developer on his own server, or an out of the box solution provided by phpdesktop website. This option provides instant access to license key for user, it is validated on the web server side. This can be configured for one license key to be allowed to be used for example on 1-5 computers.
    * User before obtaining license key must send a unique computer identifier generated by application, and using that unique id a license key is generated that is later sent to user. Internet connection is not required for app to work.