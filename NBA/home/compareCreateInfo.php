<?php
include 'DBconnect.php';





if(isset($_REQUEST['select'])) 
{
  $selection = $_REQUEST['select'];
  
}



$userInput = (isset($_REQUEST['userInput']) ? $_REQUEST['userInput'] : null);

$userInput2 = (isset($_REQUEST['userInput2']) ? $_REQUEST['userInput2'] : null);

if(!empty($_REQUEST))
{
$sql = "select $selection
        from createplayer
		where name = '$userInput'";

$result1 = $pdo->query($sql);

$row1 = $result1->fetch();

$created = $row1[0];

$sql2 = "select $selection
        from season
		where name = '$userInput2'";

$result2 = $pdo->query($sql2);

$row2 = $result2->fetch();


$player = $row2[0];

if($created > $player)
{
  $output = $userInput . " " . "has a better average of" . " " . $selection . " " . "in his season";
}
else if($created < $player)
{
  $output = $userInput2 . " " . "has a better average of" . " " . $selection . " " . "in his season";
}  
else
{
  $output = $userInput . " and " . $userInput2 . " " . "have the same average of" . " " . $selection . " " . "in their season"; 
}
}
else 
{
 $output = "";
}

include 'CompareYourself.html.php';
?>