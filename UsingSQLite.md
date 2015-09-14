Project will move to github. Find this wiki page at the new address: https://github.com/cztomczak/phpdesktop/wiki/UsingSQLite


---


# Using SQLite #

## Introduction ##

To administrate sqlite database use a tool like [phpLiteAdmin](https://code.google.com/p/phpliteadmin/) or [SQLite Browser](https://github.com/sqlitebrowser/sqlitebrowser).

Examples on this page use a set of helper functions for interacting with the PDO interface. Go download [pdo.php](https://code.google.com/p/phpdesktop/source/browse/var/pdo.php) and then include it:

```

include "./pdo.php"; ```

`pdo_sqlite` extension needs to be enabled (it is by default).

## Connecting to a database file ##

```php

$db_file = "./my_database.sqlite3";
PDO_Connect("sqlite:$db_file");```

## Fetching data ##

All functions accept an optional parameters array as a second argument to a function. Use it to bind data to queries.

```php

$fruits = PDO_FetchAll("SELECT * FROM fruits WHERE calories < :calories", array("calories"=>500));
// $fruits = array(array("name"=>"apple", "calories"=>150), array("name"=>"banana", "calories"=>400)); ```

```php

$calories = PDO_FetchOne("SELECT calories FROM fruits WHERE name = :name", array("name"=>"apple"));
// $calories = 150; ```

```php

$apple = PDO_FetchRow("SELECT * FROM fruits WHERE name = :name", array("name"=>"apple"));
// $apple = array("name"=>"apple", "calories"=>150); ```

```php

$fruits = PDO_FetchAssoc("SELECT name, calories FROM fruits");
// $fruits = array("apple"=>150, "banana"=>"400"); ```

## Executing INSERT or UPDATE queries ##

```php

PDO_Execute("INSERT INTO fruits (name, calories) VALUES (:name, :calories)", array("name"=>"apple", "calories"=>150)); ```

```php

PDO_Execute("UPDATE fruits SET calories = 150 WHERE name = 'apple'");  ```

## Last INSERT id ##

```php

$id = PDO_LastInsertId();```

## PDO is more than just SQLite ##

PDO interface can be used with various database engines, for example to connect to MySQL database do so:

```php

PDO_Connect('mysql:host=localhost;dbname=testdb;charset=UTF-8', 'username','password');```