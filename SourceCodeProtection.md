Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/SourceCodeProtection


---


# Source code protection #

Table of contents:


## Introduction ##

This wiki page discusses open source solutions for php source code protection.

Commercial solutions for code protection are presented on the knowledge base wiki page, see the question: [How do I protect PHP sources in "www" directory?](https://code.google.com/p/phpdesktop/wiki/KnowledgeBase#How_do_I_protect_PHP_sources_in_"www"_directory?)

## bcompiler ##

bcompiler is a PECL extension and can compile php scripts to opcode/bytecode. Unfortunately it does not seem to be developed anymore. The last PHP version officially supported seems to be PHP 5.3. Building bcompiler extension fails on PHP 5.4, see [PHP bug #60618](https://bugs.php.net/bug.php?id=60618).

Compiling php script to bytecode can be done using this code:
```
<?php
$fh = fopen("example.phb", "w");
bcompiler_write_header($fh);
bcompiler_write_file($fh, "example.php");
bcompiler_write_footer($fh);
fclose($fh);
/* the following should be equivalent:
include "example.php";
   and
include "example.phb";
*/
?>
```

Links:
  * http://pecl.php.net/package/bcompiler
  * http://php.net/manual/en/book.bcompiler.php

## BLENC encoder ##

From PHP documentation:
<blockquote>
BLENC is a PECL extension that permits to protect PHP source scripts with Blowfish Encryption. BLENC hooks into the Zend Engine, allowing for transparent execution of PHP scripts previously encoded with BLENC. It is not designed for complete security (it is still possible to disassemble the script into opcode/bytecode using a package such as XDebug), however it does keep people out of your code and make reverse engineering difficult.<br>
</blockquote>

To increase security it is recommended to compile BLENC extension from sources with your unique encryption key embedded in a DLL. Your source code will be more difficult to decrypt.

Documentation does not state clearly whether BLENC also does compile code to opcode/bytecode before encrypting it. Probably not. See the bcompiler extension that is also presented on this wiki page that does that.

Links:
  * http://php.net/manual/en/book.blenc.php
  * http://pecl.php.net/package/BLENC
  * http://windows.php.net/downloads/pecl/releases/blenc/

### Limitations ###

As of testing BLENC 1.1.4b the following restrictions were noticed:
  * pecl.php.net page states that this extension is in BETA stage. PHP documentation states that this extension is experimental. The behaviour of this extension including the names of its functions and any other documentation surrounding this extension may change without notice in a future release of PHP. This extension should be used at your own risk.
  * Script to be encoded can only contain PHP code. Only a single php opening tag at the beginning of file and a single php closing tag at the end of file are allowed when using "blenc\_encode.php" script. See comments in that script for more details. Reported [PHP bug #68487](https://bugs.php.net/bug.php?id=68487) in regards to confusing example on blenc\_encrypt() manual page.
  * When you set php.ini "blenc.key\_file" to ".blenc\_keys" and run "blenc\_myscript\_encoded.php" then the following error will occur: "Fatal error: blenc\_compile: Validation of script ./blenc\_myscript\_encoded.php failed". It seems that when you run the encoded script directly then BLENC looks for the key in phpdesktop executable directory. Setting path to "./../www/.blenc\_keys", as found in this tutorial, was done only for simplicity of the examples, it will work only when all scripts reside in the root directory. Reported as [PHP bug #68488](https://bugs.php.net/bug.php?id=68488).
    * One solution is to put blenc keys file in "phpdesktop/.blenc\_keys" after the process of encryption have been completed and app is ready to be distributed.
    * Another solution is to use an absolute path, which can be set by application installer.
  * BLENC has issues when multiple redistributable keys are put to ".blenc\_keys" file. The solution is to use a fixed encryption key, and that will generate a single unique redistributable key for all encrypted php scripts. See BLENC\_ENCRYPTION\_KEY in the example down the page. Reported as [PHP bug #68490](https://bugs.php.net/bug.php?id=68490).

### Step by step tutorial ###

Download BLENC dll extension using the windows.php.net link up on the page. For example for PHP 5.4 download "php\_blenc-1.1.4b-5.4-nts-vc9-x86.zip". For PHP 5.6 it would be "-5.6-nts-vc11-x86.zip". There must be "nts" (assuming you're using non-thread-safe version of php) and "x86" (32bit) strings.

Extract zip file. Copy "php\_blenc.dll" to phpdesktop/php/ directory (or php/ext/ directory). Edit php.ini and add this line:

```
extension=php_blenc.dll
blenc.key_file="./../www/.blenc_keys"
```

See the "Limitations" section up the page on why the strange path for "blenc.key\_file". You can also set the "blenc.key\_file" value in a php script using `ini_set()`.

Create "blenc\_encode.php" script with contents below. Change BLENC\_ENCRYPTION\_KEY to some unique hard to guess string and keep it secret.
```
<?php
define("BLENC_ENCRYPTION_KEY", "ChangeThisToSomethingElse");
error_reporting(-1);
$source_code = file_get_contents("blenc_myscript.php");
// The encoded source passed to blenc_encrypt() cannot contain
// any php tags. We are removing php tags at the beginning and
// end of file. Also checking that there are no other php tag
// openings/closings.
$source_code = preg_replace('#^<'.'\?php\s+#', '', $source_code);
$source_code = preg_replace('#\s+\?'.'>\s*$#', '', $source_code);
if (preg_match('#<'.'\?#', $source_code) 
        || preg_match('#\?'.'>#', $source_code)) {
    print("Script to be encoded can only contain PHP code.");
    print(" Only a single php opening tag at the beginning of file");
    print(" and a single php closing tag at the end of file are allowed.");
    print(" This is a limitation as of BENC encoder 1.1.4b.");
    exit();
}
$redist_key = blenc_encrypt($source_code, "blenc_myscript_encoded.php",
                            BLENC_ENCRYPTION_KEY);
$key_file = ini_get('blenc.key_file');
file_put_contents($key_file, $redist_key);
print("DONE. See");
print(" <a href='blenc_myscript_encoded.php'>blenc_myscript_encoded.php</a>");
?>
```

Create "blenc\_myscript.php" script:
```
<?php
print("Printing a secret string: XuXuXaaa");
?>
```

Run "blenc\_encode.php" script.

Run "blenc\_myscript\_encoded.php" script.

The encoded file's source will look like:
```
BLENC   1.1.4b          c269d23aa66d05474d7b408484c74c1d
                Ô)÷M¤ÙÃAÓ‚`°¯ aq`ÊÅÞc|RÇ–;ù‚×‹+ÆZe‚¢yv6B.hí
```


## Other links ##

  * [embeder](http://wildphp.free.fr/wiki/doku.php?id=win32std:embeder)
  * [phc-win](http://wiki.swiftlytilting.com/Phc-win)
  * PECL extensions binaries can be downloaded from here. For PHP 5.4 download file ending with "-5.4-nts-vc9-x86.zip": http://windows.php.net/downloads/pecl/releases/
  * [opcache](http://php.net/manual/en/book.opcache.php) - there is `opcache_compile_file()`, but no way to retrieve bytecode contents of a script
  * [WinCache](http://php.net/manual/en/book.wincache.php) - also no API to retrieve bytecode contents
  * [ZendOpcache](http://pecl.php.net/package/ZendOpcache)
  * [APC cache](http://php.net/apc) - loading extension results in error when using PHP CGI interface
