Project will move to github: https://github.com/cztomczak/phpdesktop


---


<table cellpadding='0' cellspacing='0' align='left' border='0' width='100%'><tr>
<td width='190'>
<h1>PHP Desktop</h1>
</td>
<td valign='top'>
<br>
<a href='https://twitter.com/intent/tweet?text=PHP+desktop+GUI+framework+with+HTML5+Chrome/IE+engine&url=https://code.google.com/p/phpdesktop/' title='Tweet'><img src='https://phpdesktop.googlecode.com/git/var/share-buttons/tweet.jpg' width='71' height='24' /></a>
<a href='https://delicious.com/save?v=5&provider=phpdesktop&noui&jump=close&url=https://code.google.com/p/phpdesktop/&title=PHP+desktop+GUI+framework+with+HTML5+Chrome/IE+engine' title='Delicious'><img src='https://phpdesktop.googlecode.com/git/var/share-buttons/delicious.png' width='102' height='24' /></a>
<a href='http://www.reddit.com/submit?url=https://code.google.com/p/phpdesktop/' title='Reddit this!'><img src='https://phpdesktop.googlecode.com/git/var/share-buttons/reddit.gif?x=1' width='94' height='24' /></a>
</td>
</tr></table>

## Introduction ##

PHP Desktop is an open source project founded by Czarek Tomczak in 2012 to provide a way for developing native desktop GUI applications using web technologies such as PHP, HTML5, JavaScript and SQLite. The development workflow you are used to while creating web applications remains the same. There is no new API/framework to learn. The process of turning an existing website into a desktop application is basically a matter of copying it to the "phpdesktop/www/" directory.

In a certain sense phpdesktop acts as a PHP to EXE compiler. It embeds a web browser, a multithreaded web server and a PHP interpreter. All embedded into a single application. The web server embedded is [Mongoose](https://en.wikipedia.org/wiki/Mongoose_(web_server)) (the MIT-licensed version). Supported browsers are Internet Explorer and Google Chrome. The package with Chrome embedded has no external dependencies, everything is included in the phpdesktop binaries and works out of the box on a user's computer.

All popular PHP frameworks are supported, see the [PHP frameworks support](PhpFrameworksSupport.md) wiki page for example configurations for CakePHP, CodeIgniter, Laravel, Symfony, Yii and Zend Framework.  You can create a standalone executable for distribution with the help of the [Inno Setup installer](https://code.google.com/p/phpdesktop/wiki/KnowledgeBase#Application_installer). PHP sources can be protected with the many of the available [PHP encoders](https://code.google.com/p/phpdesktop/wiki/KnowledgeBase#How_do_I_protect_PHP_sources_in_"www"_directory?). PHP Desktop is released under non-restrictive license, thus it is [free for commercial use](https://code.google.com/p/phpdesktop/wiki/KnowledgeBase#Can_I_use_PHP_Desktop_in_a_commercial_closed_sourced_project?).

It is one of the top goals for PHP Desktop to be stable, to work reliably. PHP Desktop does not suffer from memory leaks. PHP by design was never intended for running long hours/days, as desktop applications usually do. This is not a concern when using PHP Desktop, as it is running an internal web server and serving pages through CGI. So when PHP script ends execution PHP-CGI process is killed and all memory is always freed.

Lots of other useful information can be found on the KnowledgeBase wiki page and on the [Forum](http://groups.google.com/group/phpdesktop).

## Downloads ##

  * PHP Desktop Chrome - go to the [DownloadChrome](DownloadChrome.md) wiki page.
  * PHP Desktop MSIE (Internet Explorer) - go to the [DownloadMSIE](DownloadMSIE.md) wiki page.

PHP Desktop is not strongly tied to PHP, it can also act as a packager for any other scripting languages like Perl, Ruby, Python, that provide a CGI interface for script execution. See the EmbeddingOtherScriptingLanguages wiki page to download examples for other languages.

## Help ##

  * See the [Hello World!](https://code.google.com/p/phpdesktop/wiki/KnowledgeBase#Hello_World!) example
  * Documentation is on the [wiki pages](http://code.google.com/p/phpdesktop/w/list). Start with the [KnowledgeBase](KnowledgeBase.md), [Settings](Settings.md) and [ChromeSettings](ChromeSettings.md) wiki pages.
  * Having problems or questions? Go to the [PHP Desktop Forum](https://groups.google.com/group/phpdesktop).
  * Please do not submit new issues in the tracker ("Issues" tab in the top menu), use Forum instead. By starring issue you let us know of important issues and provide email notifications for yourself when issue gets updated.

## Tutorials ##

  * [Create your first Desktop Application with PHP and PHP Desktop](http://phpocean.com/tutorials/design-and-illustration/create-your-first-desktop-application-with-php-and-php-desktop/4) (phpocean.com)
## Donations ##

To support the project please click the Paypal Donate button:

<a href='https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JQSTPDRRM8AQ8'><img src='https://phpdesktop.googlecode.com/git/var/donate.gif' /></a>

Please note that at this time PHP Desktop is unable to accept donations that sponsor the development of specific features. However you can make a donation with a comment that you would like to see some feature implemented and this will give it a higher priority, but apart from that there are no other guarantees.

## Built a cool app? ##

Built a cool app using PHP Desktop and would like to like to share info with the community? Talk about it on the [PHP Desktop Forum](https://groups.google.com/group/phpdesktop?hl=en).