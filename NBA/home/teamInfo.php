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
  if($selection == 'teamname')
  {//query for user selection and input
    $sql = "SELECT Coach, Year 
            FROM teams
		    WHERE Team = '$userInput'";
    $result = $pdo->query($sql);
	$var1 = 'Coach';
	$var2 = 'Year';
  }
  else if($selection == 'coach')
  {
      $sql = "SELECT Team, Year 
            FROM teams
		    WHERE Coach = '$userInput'";
    $result = $pdo->query($sql);
	$var1 = 'Team';
	$var2 = 'Year';
  }
  else if($selection == 'year')
  {
        $sql = "SELECT Team, Coach
            FROM teams
		    WHERE year = '$userInput'";
    $result = $pdo->query($sql);
	$var1 = 'Team';
	$var2 = 'Coach';
  }
/*get to return more than just team  name in returning $players
and also do if statement for returning certain values depending
on the selection of the select drop down*/
while($row = $result->fetch())
{ 
  $players[] = $row[$var1];
  $players1[] = $row[$var2];
  
}
}
else
{
  null;
}



include 'teams.html.php';


?>