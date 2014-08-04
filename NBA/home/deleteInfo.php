 <?php
include 'DBconnect.php';
 
 $name = (isset($_REQUEST['name']) ? $_REQUEST['name'] : null);

 

if(!empty($_REQUEST))
{
$sql = "DELETE FROM createPlayer
       where name='$name'";

$result = $pdo->query($sql);

if($result)
{
  $output = "Player successfully deleted!";
}

}
 else
 {
   $output = 'Enter information';
 }
 
 
 
 
 
include 'deletePlayer.html.php';
 ?>