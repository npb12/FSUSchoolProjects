<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>NBA</title>
  </head>
  <body>
      <div id="header">TEAM RAMROD</div>
	<div id="body">
  <p>
  <a href="home.html.php"> Home</a>
  	<link href="style.css" rel="stylesheet" type="css/text">
  </p>
  <p>
  <form action = "teamInfo.php" method ="request">
      <div class = "select_season">
  <div class="styled-select">
    <select id="select" name="select">
      <option value="teamname">Team Name</option>
      <option value="coach">Coach</option>
      <option value="year">Year</option>
    </select>
	</div>
	</div>
    <div class ="input_season"><label for ="userInput">
      <input type="text" name ="userInput" id="userInput"></label>
    </div>
    <div class="button_season"><input type = "submit" class="button" value ="GO">
    </div>
  </form>
  </p>
	</div>
	    <div class="design_team">
    <?php
	if(!empty($players))
	{
	foreach ($players as $player): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($player, ENT_QUOTES, 'UTF-8');
         ?>
      </p>
    </blockquote>
    <?php endforeach; } ?>
	    <div class="design_left_team">
		<?php
		if(!empty($players1))
	{
	foreach ($players1 as $player1): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($player1, ENT_QUOTES, 'UTF-8');
         ?>
      </p>
    </blockquote>
	
    <?php endforeach; }?>

	</div>
	</div>


  </body>
</html> 