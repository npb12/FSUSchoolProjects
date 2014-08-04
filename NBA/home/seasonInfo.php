<?php
include 'DBconnect.php';

if(isset($_REQUEST['select'])) 
{
  $selection = $_REQUEST['select'];
}




//user input for description of selection
$userInput = (isset($_REQUEST['userInput']) ? $_REQUEST['userInput'] : null);
//players name should bring the result of all stats
//team name
if(!empty($_REQUEST))
{

if($selection == 'name')
{
//query for user selection and input
$sql = "SELECT * 
        FROM season
		WHERE $selection = '$userInput'";
$result = $pdo->query($sql);

//returning query 
//storing as $players
while($row = $result->fetch())
{ 
  $all[] =  $row['name'] . " " . $row['team']. " " . $row['Games'] . " " . $row['minPlayed'] . " " . $row['FG']
    . " " . $row['FGA'] . " " . $row['FGP'] . " " . $row['3p'] . " " . $row['3PA'] . " " . $row['3PP'] . " " . $row['FT'] . " " . $row['FTA']
    . " " . $row['FTP']. " " . $row['TOs'] . " " . $row['ORB'] . " " . $row['DRB'] . " " . $row['AST'] . " " . $row['STL'] . " " . $row['BLK']
	. " " . $row['PPG'];
  echo "<br>";
  
}
}
else if($selection == 'Team')
{
  $sql = "SELECT name 
        FROM season
		WHERE Team = '$userInput'";
$result = $pdo->query($sql);

while($row = $result->fetch())
{ 
  $name[] = $row['name'];
  
}



}
else
{
//query for user selection and input
$sql = "SELECT name, team, $selection 
        FROM season
		WHERE $selection >= '$userInput'";
$result = $pdo->query($sql);

//returning query 
//storing as $players
while($row = $result->fetch())
{ 
  $else[] = $row['name'] . " " . $row['team']. " " . $row[$selection];
  
  echo "<br>";
  
}
}
}
else
{
  echo 'Enter desired info: ';
}



include 'season.html.php';


?>