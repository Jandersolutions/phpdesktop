Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/PhpFrameworksSupport


---


# PHP frameworks support #

This page discusses the most popular PHP frameworks and how to configure them for use with PHP Desktop. Most of the instructions provided here deal with configuring routing (pretty urls) and sqlite database. For administration of sqlite database you can use a tool like [phpLiteAdmin](https://code.google.com/p/phpliteadmin/) or [SQLite Browser](https://github.com/sqlitebrowser/sqlitebrowser).

Table of contents:



---

## CakePHP ##

PHPDesktop was tested and works fine with CakePHP 2.5.6.

**To get started and configure routing do the following:**
  1. Put CakePHP files to "phpdesktop-chrome/www/" directory, so that the structure is following:
    * www/app/
    * www/app/webroot/
    * www/lib/
    * www/plugins/
    * www/vendors/
  1. Edit "www/app/Config/core.php" and uncomment this line:
```
Configure::write('App.baseUrl', env('SCRIPT_NAME'));
```
  1. Edit "phpdesktop-chrome/settings.json" and set web server "www\_directory" and "404\_handler" options:
```
"web_server": {
    ...
    "www_directory": "www/app/webroot",
    ...
    "404_handler": "/index.php"
```

**To configure sqlite do the following:**
  1. Create "www/sqlite/" directory. The path to sqlite database file will be "www/sqlite/mydatabase.sqlite".
  1. Edit "www/app/Config/database.php" and set:
```
class DATABASE_CONFIG { 
    public $default = array(
            'datasource' => 'Database/Sqlite',
            'persistent' => false,
            'database' => '../../sqlite/mydatabase.sqlite',
            'prefix' => '',
            'encoding' => 'utf8',
    );
}
```


---

## CodeIgniter ##

PHPDesktop was tested and works fine with CodeIgniter 2.1.4. The latest stable version as of writing is 2.2.0, but PDO database driver is [broken in that release](https://github.com/bcit-ci/CodeIgniter/issues/3095) (SELECT queries always return 0 rows). You can download CodeIgniter 2.1.4 from [here](https://ellislab.com/codeigniter/user-guide/installation/downloads.html). You may alternatively use CodeIgniter 3.0-dev (3.0 is not yet stable as of this writing) which has a native "sqlite3" driver that you may use instead of PDO.

**To enable pretty urls do the following:**
  1. Edit "application/config/config.php" and set:
```
$config['index_page'] = '';
```
  1. Edit "phpdesktop-chrome/settings.json" and set
```
"web_server": {
    ...
    "404_handler": "/index.php"
```

**To use sqlite do the following:**
  1. Create "application/sqlite/" directory. The path to sqlite database file will be "application/sqlite/mydatabase.sqlite".
  1. Edit "application/config/database.php and set:
```
$db['default']['hostname'] = 'sqlite:'.APPPATH.'sqlite/mydatabase.sqlite';
$db['default']['dbdriver'] = 'pdo';
```


---

## Laravel ##

PHPDesktop was tested and works fine with Laravel 4.2.11.

**To get started and configure routing do the following:**
  1. Copy Laravel files to "phpdesktop-chrome/www/" directory, so that the structure is following:
    * www/app/
    * www/bootstrap/
    * www/public/
    * www/vendor/
  1. Edit "phpdesktop-chrome/settings.json" and set web server "www\_directory" and "404\_handler" options:
```
"web_server": {
    ...
    "www_directory": "www/public",
    ...
    "404_handler": "/index.php"
```

**To configure sqlite do the following**:
  1. The path to sqlite database file is "www/app/database/production.sqlite"
  1. Edit file "www/app/config/database.php" and set:
```
array(
    ...
    'default' => 'sqlite',
    ...
```


---

## Symfony ##

PHPDesktop was tested and works fine with Symfony 2.6.0.

**To get started and configure routing do the following:**
  1. Download "symfony.phar" using command:
```
php.exe -r "readfile('http://symfony.com/installer');" > symfony.phar
```
  1. Generate "myproject/" directory using command:
```
php.exe symfony.phar new myproject
```
  1. Copy "myproject/" directory to "phpdesktop-chrome/www/" directory (so that there is "phpdesktop-chrome/www/myproject/")
  1. Note that using "myproject/web/app.php" was causing issues during testing ("Oops! An Error Occurred The server returned a “404 Not Found”). Using "myproject/web/app\_dev.php" on the other hand works just fine. If you can find the cause of this, please let us know on the [Forum](http://groups.google.com/group/phpdesktop).
  1. Create "phpdesktop-chrome/www/index.php" file with the following contents:
```
<?php
include "myproject/web/app_dev.php";
?>
```
  1. Edit "phpdesktop-chrome/settings.json" and set:
```
"web_server": {
    ...
    "404_handler": "/myproject/web/app_dev.php"
```
  1. It's ready. Now launch "phpdesktop-chrome.exe"

**To use sqlite do the following:**
  1. Create directory "myproject/app/sqlite/". The path to sqlite database file will be "myproject/app/sqlite/mydatabase.sqlite".
  1. Edit "myproject/app/config.yml" and in "doctrine > dbal" section add this line:
```
path: "%database_path%"
```
  1. Edit "myproject/app/config/parameters.yml" and add this line inside "parameters" section:
```
database_path: "%kernel.root_dir%/sqlite/mydatabase.sqlite"
```


---

## Yii ##

PHPDesktop was tested and works fine with Yii 1.1.15.

**To configure routing with pretty urls do the following**:
  1. We are using the "blog" demo application that is provided with Yii 1.1.
  1. Put Yii files to "phpdesktop-chrome/www/" directory, so that the structure is following:
    * www/demos/
    * www/demos/blog/
    * www/framework/
    * www/requirements/
  1. Edit file "www/demos/blog/protected/config/main.php" and set "components > urlManager > showScriptName" to false to remove "index.php" string from urls:
```
...
'urlManager'=>array(
    'urlFormat'=>'path',
    'showScriptName'=>false,
    ...
```
  1. Edit "phpdesktop-chrome/settings.json" file and set web server "www\_directory" and "404\_handler" options:
```
"web_server": {
    "www_directory": "www/demos/blog",
    ...
    "404_handler": "/index.php"
```

**Configuring sqlite**
  * The "blog" demo application is already using sqlite by default, so there is nothing to configure. The path to sqlite database file is "www/demos/blog/protected/data/blog.db".


---

## Zend Framework ##

PHPDesktop was tested and works fine with Zend Framework 2.3.3.

**Get get started and configure routing do the following**:
  1. We will start with the [ZendSkeletonApplication](https://github.com/zendframework/ZendSkeletonApplication) and use [composer.phar](http://getcomposer.org/) to set it up (based on [Zend Quick Start](http://framework.zend.com/manual/2.3/en/modules/zend.mvc.quick-start.html)):
```
cd phpdesktop-chrome/www/
php.exe composer.phar create-project --repository-url="http://packages.zendframework.com" zendframework/skeleton-application ./
```
  1. After creating new project with comsposer, the structure in "phpdesktop-chrome/www/" directory is following:
    * www/config/
    * www/data/
    * www/module/
    * www/public/
    * www/vendor/
  1. Edit file "phpdesktop-chrome/settings.json" and set web server "www\_directory" and "404\_handler" options:
```
"web_server": {
    ...
    "www_directory": "www/public",
    ...
    "404_handler": "/index.php"
```

**To configure sqlite do the following:**
  1. Assuming that path to sqlite database file is "www/data/mydatabase.sqlite"
  1. Use this code to create sqlite adapter:
```
<?php
$adapter = new \Zend\Db\Adapter\Adapter(array(
    'driver' => 'Pdo_Sqlite',
    'database' => $_SERVER['DOCUMENT_ROOT'].'/../data/mydatabase.sqlite'
));
```