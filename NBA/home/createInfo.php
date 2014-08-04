 <?php
include 'DBconnect.php';
 
 $name = (isset($_REQUEST['name']) ? $_REQUEST['name'] : null);
 $points = (isset($_REQUEST['PPG']) ? $_REQUEST['PPG'] : null);
 $Assists = (isset($_REQUEST['AST']) ? $_REQUEST['AST'] : null);
 $ORB = (isset($_REQUEST['ORB']) ? $_REQUEST['ORB'] : null);
 $DRB = (isset($_REQUEST['DRB']) ? $_REQUEST['DRB'] : null);
 $BLK = (isset($_REQUEST['BLK']) ? $_REQUEST['BLK'] : null);
 
 if(!empty($_REQUEST))
 {
$sql = "INSERT INTO createPlayer(name, PPG, AST, ORB, DRB, BLK)
VALUES ('$name', '$points', '$Assists', '$ORB', '$DRB', 'BLK')";

$result = $pdo->query($sql);

if($result)
{
  $output = "Player successfully added!";
}
 }
 else
 {
   $output = "";
 }
 
 
 
 
 
 
include 'createPlayer.html.php';
 ?>