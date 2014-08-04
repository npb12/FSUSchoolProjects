<?php
// trying for a connection, returning output if failed
try
{
  $pdo = new PDO('mysql:host=localhost;dbname=nba_players', 'npb12', 'tarheel5');
  $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  $pdo->exec('SET NAMES "utf8"');
  
}
catch(PDOException $e)
{
  $output = 'Unable to connect to the database server.';
  include 'output.html.php';
  exit();
}








?>