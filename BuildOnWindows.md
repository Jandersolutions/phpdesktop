Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/BuildOnWindows


---


# Build instructions for Windows #

This page provides step by step instructions on how to build PHP Desktop Chrome from sources.

Table of contents:


## Preliminary notes ##

Requirements:
  * Visual Studio 2010 or Visual C++ 2010 Express Edition which is free. Download [VS2010Express1.iso](http://go.microsoft.com/?linkid=9709969). You may use newer versions up to VS2013, but .vcxproj/.sln files are available only for VS2010.

In case of any trobules see also [Issue 64](https://code.google.com/p/phpdesktop/issues/detail?id=64) which explains some of possible issues.

## Download PHP Desktop sources ##

```
git clone https://code.google.com/p/phpdesktop/
```

As of this writing PHP Desktop Chrome has two branches:
  * phpdesktop-chrome/ - this one includes Chrome 31 and is stable
  * phpdesktop-chrome-cef2171/ - this one includes Chrome 39 (CEF branch 2171) and is a Release Candidate as of writing

You can apply further instructions to any of these branches.

## Download CEF sources / prebuilt binaries ##

If you would like to use CEF prebuilt binaries then go to [www.cefbuilds.com](http://cefbuilds.com/). You have to download CEF for the same branch and revision that phpdesktop uses. See [phpdesktop-chrome/cef/README.txt](https://code.google.com/p/phpdesktop/source/browse/phpdesktop-chrome/cef/README.txt). If you're building phpdesktop with CEF branch 2171 see [phpdesktop-chrome-cef2171/cef/README.txt](https://code.google.com/p/phpdesktop/source/browse/phpdesktop-chrome-cef2171/cef/README.txt). Look for CEF version in that file. In our case for phpdesktop-chrome/ branch it is 3.1650.1562 as of writing. For cef2171 branch it is 3.2171.1902 as of writing.
  * Go to [www.cefbuilds.com](http://cefbuilds.com/)
  * Select branch 1650 > Windows 32bit > click "more revisions"
  * Now find CEF version that matches the one in README.txt. In our case it is "CEF Version: 3.1650.1562" as of writing. Click on the "2014-01-13 CEF 3.1650.1562 (39MB)" link to download and then extract it.

If you would like to build CEF from sources then see  [CEF Branches and building](https://code.google.com/p/chromiumembedded/wiki/BranchesAndBuilding) (external) wiki page. Recently Chromium has migrated from SVN to GIT and now building older branches (branch 1650 with CEF 3.1650.1562) from sources is not officially supported.

## Build cefclient and copy CEF files to phpdesktop ##

The CEF binaries downloaded from cefbuilds.com after extracting have "cef\_binary\_3.2171.1902\_windows32" directory. From now on we will refer to this directory as cef\_binary/.

Build cefclient and libcef\_dll\_wrapper projects:
  1. Go to cef\_binary/ directory
  1. Edit file cefclient/cefclient\_win.cpp and change CEF\_ENABLE\_SANDBOX macro value to 0 (building with sandbox enabled is supported only for VS2013)
  1. Open cefclient2010.sln in Visual Studio
  1. Change configuration to either Debug or Release. In this tutorial we choose Release, so all later instructions apply to this configuration. If you would like to build using Debug configuration, then just repeat the same steps but for Debug/ folder instead of Release/ folder.
  1. Build cefclient (a sample browser) and libcef\_dll\_wrapper (C++ library) projects. This will generate files in out/ directory.
  1. Go to cef\_binary/out/Release/ directory.
  1. Run cefclient.exe sample browser and see if all works fine

Copy CEF binaries and libraries to phpdesktop:
  1. Go to cef\_binary/out/Release/ directory
  1. Copy lib/libcef\_dll\_wrapper.lib file to phpdesktop-chrome/Release/ directory
  1. Copy all files from cef\_binary/out/Release/ to phpdesktop-chrome/Release/ directory
  1. You can delete these files from phpdesktop-chrome/Release/ directory:
    1. Delete obj/ directory as this is a relic after compiling
    1. Delete lib/ directory which was already copied to a proper location
    1. Delete cefclient.exe/cefclient.pdb as this is a sample browser not needed by phpdesktop
  1. Go to cef\_binary/Release/ directory and copy libcef.lib to phpdesktop-chrome/lib/Release/ directory

If you're building with version of CEF different from README.txt (eg. upgrading to a newer CEF) then also replace contents of phpdesktop-chrome/cef/include/ directory with cef\_binary/include/ directory. Also overwrite phpdesktop-chrome/cef/README.txt file with cef\_binary/README.txt.

## Download PHP binaries ##

Go to http://windows.php.net/download/ and:
  * For PHP 5.4 download "VC9 x86 Non Thread Safe" zip file
  * For PHP 5.6 download "VC11 x86 Non Thread Safe" zip file

Extract it and put binaries in phpdesktop-chrome/php/ directory.

If you want to support Windows XP download PHP 5.4 binaries and additionally move all DLL extensions from php/ext/ directory to the root php/ directory. See [Issue 34](https://code.google.com/p/phpdesktop/issues/detail?id=34) for why it needs to be done so. You will also have to create/modify php.ini and set extension\_dir option:

```
extension_dir=./
```

## Build phpdesktop-chrome project ##

  1. Go to phpdesktop-chrome/ directory
  1. Open phpdesktop-chrome.sln file in Visual Studio
  1. Change configuration to Release
  1. Build phpdesktop-chrome project. This will generate Release/phpdesktop-chrome.exe executable.
  1. Run phpdesktop-chrome.exe executable