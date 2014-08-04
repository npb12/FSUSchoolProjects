<?php
include 'DBconnect.php';



if(isset($_REQUEST['select'])) 
{
  $selection = $_REQUEST['select'];
  
}


if(isset($_REQUEST['select2'])) 
{
  $selection2 = $_REQUEST['select2'];
}

$userInput = (isset($_REQUEST['userInput']) ? $_REQUEST['userInput'] : null);

$userInput2 = (isset($_REQUEST['userInput2']) ? $_REQUEST['userInput2'] : null);

if(!empty($_REQUEST))
{
$sql = "select $selection
        from `$selection2`
		where name = '$userInput'";

$result1 = $pdo->query($sql);

$row1 = $result1->fetch();

$p1 = $row1[0];

$sql2 = "select $selection
        from `$selection2`
		where name = '$userInput2'";

$result2 = $pdo->query($sql2);

$row2 = $result2->fetch();


$p2 = $row2[0];

if($p1 > $p2)
{
  $output = $userInput . " " . "has a better average of" . " " . $selection . " " . "in his" . " " . $selection2;
}
else if($p1 < $p2)
{
  $output = $userInput2 . " " . "has a better average of" . " " . $selection . " " . "in his" . " " . $selection2;
}  
else
{
  $output = $userInput . " and " . $userInput2 . " " . "have the same average of" . " " . $selection . " " . "in his" . " " . $selection2; 
}
}
else 
{
echo 'Enter desired info:';
}

include 'ComparePlayers.html.php';
?>