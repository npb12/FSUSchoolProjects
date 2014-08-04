<?php
include 'DBconnect.php';

if(isset($_REQUEST['select'])) 
{
  $selection = $_REQUEST['select'];
}




//user input for description of selection
$userInput = (isset($_REQUEST['userInput']) ? $_REQUEST['userInput'] : null);

if(!empty($_REQUEST))
{
  if($selection == 'name')
  {
  //query for user selection and input
  $sql = "SELECT * 
        FROM career
		WHERE name = '$userInput'";
  $result = $pdo->query($sql);

  //returning query 
  //storing as $players
  while($row = $result->fetch())
  { 
    $var1[] =  $row['name']. " " .$row['Games'] . " " . $row['minPlayed'] . " " . $row['FG']
    . " " . $row['FGA'] . " " . $row['FGP'] . " " .  $row['3p'] . " " . $row['3PA']  . " " . $row['3PP'] . " " . $row['FT'] . " " . $row['FTA']
	 . " " . $row['FTP']. " " . $row['TOs'] . " " .  $row['ORB'] . " " . $row['DRB'] . " " . $row['AST'] . " " . $row['STL'] . " " . $row['BLK']
	. " " . $row['PPG'];
    echo "<br>";
  }
}
else
{
//query for user selection and input
$sql = "SELECT name, $selection 
        FROM career
		WHERE $selection >= '$userInput'";
$result = $pdo->query($sql);

//returning query 
//storing as $players
while($row = $result->fetch())
{  
  
  $output[] = $row['name'] . " " . $row[$selection];
  
  echo "<br>";
  
}
}
}
else
{
  null;
}



include 'career.html.php';


?>