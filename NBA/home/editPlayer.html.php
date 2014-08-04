<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>NBA</title>
		<link href="style.css" rel="stylesheet" type="css/text">
  </head>
  <body>
      <div id="header">TEAM RAMROD</div>
	<div id="body">
  <p>
  <a href="home.html.php"> Home</a>
  </p>
  <p>
  Enter the player name and information you would like to be updated
  </p>
  <p>
  <form action = "editInfo.php" method ="request">
    <div><label for ="name">Name:
      <input type="text" name ="name" id="name"></label>
    </div>
	    <div><label for ="PPG">Points:
      <input type="text" name ="PPG" id="PPG"></label>
    </div>
	<div><label for ="AST">Assists:
      <input type="text" name ="AST" id="AST"></label>
    </div>
	<div><label for ="ORB">Offensive Rebounds:
      <input type="text" name ="ORB" id="ORB"></label>
    </div>
	<div><label for ="DRB">Defensive Rebounds:
      <input type="text" name ="DRB" id="DRB"></label>
    </div>
	<div><label for ="BLK">Blocks:
      <input type="text" name ="BLK" id="BLK"></label>
    </div>
	
    <div><input type = "submit" class="button" value ="GO">
    </div>
  </form>
  </p>
    <div class = "edit_output">
  <?php
  if(!empty($output))
  {
  echo htmlspecialchars($output, ENT_QUOTES, 'UTF-8'); }?>
  
  </div>
  
  </div>
  </body>
</html> 