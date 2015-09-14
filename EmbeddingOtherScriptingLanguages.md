Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/EmbeddingOtherScriptingLanguages


---


# Embedding other scripting languages #

It is possible to embed other scripting languages like [Perl](http://www.perl.org/), [Python](http://www.python.org/) or [Ruby](http://www.ruby-lang.org/en/) (any [CGI](http://en.wikipedia.org/wiki/Common_Gateway_Interface) capable) using PHP Desktop infrastructure. You can develop native desktop applications in these languages the same way you do it with PHP.

These examples do not necessarily come with the latest version of PHP Desktop. But you can upgrade it to the latest version by downloading the latest PHP Desktop binaries and by overwriting the executable file. For example rename "phpdesktop-chrome.exe" to "ruby-desktop-chrome.exe" and overwrite the old one. You also need to overwrite all the other binary files (`*.dll` `*.pak` and possibly others).

Binaries for Perl, Python & Ruby are minimal, so that the example zip file is small. If you would like to run complex scripts with various module
dependencies, then you should update the "perl/" directory (or "python/", or "ruby/") with the full binaries.

## Perl Desktop ##

With Internet Explorer engine: [perl-desktop-msie-1.12.zip](https://docs.google.com/uc?id=0B1di2XiBBfacT215dmhiUlZxMFE&export=download) (1.2 MB).<br>
With Chrome embedded: <a href='https://docs.google.com/uc?id=0B1di2XiBBfaceUNOU2p2Ty1mNnM&export=download'>perl-desktop-chrome-31.4.zip</a> (27 MB)<br>

<h2>Python Desktop</h2>

With Internet Explorer engine: <a href='https://docs.google.com/uc?id=0B1di2XiBBfacNUswdmhFQzdIelU&export=download'>python-desktop-msie-1.12.zip</a> (1.3 MB)<br>
With Chrome embedded: <a href='https://docs.google.com/uc?id=0B1di2XiBBfacU29xOTZ2UGx5MWM&export=download'>python-desktop-chrome-31.4.zip</a> (27 MB)<br>

<h2>Ruby Desktop</h2>

With Internet Explorer engine: <a href='https://docs.google.com/uc?id=0B1di2XiBBfacM2NXZ3ZHdVlueFE&export=download'>ruby-desktop-msie-1.12.zip</a> (5.2 MB)<br>
With Chrome embedded: <a href='https://docs.google.com/uc?id=0B1di2XiBBfacb3EyZ0lyRTNsUDA&export=download'>ruby-desktop-chrome-31.4.zip</a> (31 MB)<br>


<h2>Alternative download site</h2>

<a href='https://www.dropbox.com/sh/3ihzy40v62em613/AABntIwi4d2E636MGRtBlO18a?dl=0'>https://www.dropbox.com/sh/3ihzy40v62em613/AABntIwi4d2E636MGRtBlO18a?dl=0</a>