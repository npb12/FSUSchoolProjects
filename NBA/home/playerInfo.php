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

  

  $sql = "SELECT * 
        FROM players
		WHERE $selection = '$userInput'";
  $result = $pdo->query($sql);
  
  

while($row = $result->fetch())
{ 
  
  $all[] =  $row['name']. " " . $row['age'] . " " . $row['position'] . " " . $row['height'] . " " . $row['college'] . " " . $row['nationality'];

  echo "<br>";
  
}
  
}
else
{
  null;
}





include 'players.html.php';



?>