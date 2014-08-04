 <?php
include 'DBconnect.php';
 

 $userInput = (isset($_REQUEST['userInput']) ? $_REQUEST['userInput'] : null);
 
 
 
 $view = "CREATE VIEW SPER AS
SELECT s.name as name, (s.PPG + s.DRB + s.Games + (s.ORB * 2) + (s.AST * 2) + (s.STL * 3) + (s.BLK * 2) - (s.TOs * 3))/s.minPlayed AS PER
FROM season AS s";

$getview = $pdo->query($view);


$view2 = "CREATE VIEW CPER AS
SELECT c.name as name, (c.PPG + c.DRB + c.Games + (c.ORB * 2) + (c.AST * 2) + (c.STL * 3) + (c.BLK * 2) - (c.TOs * 3))/c.minPlayed AS PER
FROM career AS c"; 
 
 $getview2 = $pdo->query($view2);
 
 
 
 $list = "CREATE VIEW updown AS
          SELECT (s.PER - c.PER) as updowns, s.name as names
          FROM SPER as s
          INNER JOIN CPER as c 
		  LIMIT 182";
 
 $res = $pdo->query($list);



 $view ="SELECT * FROM updown ORDER BY updowns DESC";

 $query = $pdo->query($view);

while($ro = $query->fetch())
{ 
  $players[] = $ro['updowns'];
  $players1[] = $ro['names'];
  
}
 //calculation of individual up or down
if(!empty($_REQUEST))
 {
 
  $sql = "SELECT s.name as sname, s.PER as sppg, c.name, c.PER as cppg
          FROM SPER as s
          INNER JOIN CPER as c
          ON c.name ='$userInput' and  s.name=c.name";

  $result = $pdo->query($sql);
  
  $row = $result->fetch();



  $season = $row[1];
  $career = $row[3];
  
  


if($season > $career)
{
  $output = $userInput . " " .  'is currently up';
}
else if($season < $career)
{
  $output =  $userInput . " " .  'is currently down';
}
else 
{
  $output = $userInput . " " .  'is currently playing his average';
}


$sq = "drop view CPER, SPER, updown";

$result = $pdo->query($sq);

 
 }

















 



 

include 'upanddown.html.php';
 ?>