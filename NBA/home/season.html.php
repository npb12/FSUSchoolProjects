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
  <form action = "seasonInfo.php" method ="request">
    <div class = "select_season">
  <div class="styled-select">
    <select id="select" name="select">
	<option value="name">Name</option>
	<option value="team">Team</option>
    <option value="AST">Assist</option>
    <option value="STL">Steals</option>
    <option value="BLK">Blocks</option>
    <option value="TOs">Turnovers</option>
    <option value="PPG">Points</option>
    <option value="FGP">Field Goal Percentage</option>
    <option value="3PP">3 Point Percentage</option>
    <option value="Games">Games</option>
    <option value="minPlayed">Minutes Played</option>
    <option value="FG">Field Goals</option>
    <option value="FGA">Field Goals Attempted</option>
    <option value="3p">3 pointers</option>
    <option value="3PA">3 Pointers Attempted</option>
    <option value="FT">Free Throws</option>
    <option value="FTA">Free Throws Attempted</option>
	<option value="FTP">Free Throw Percentage</option>
    <option value="ORB">Offensive Rebounds</option>
    <option value="DRB">Defensive Rebounds</option>
    </select>
	</div>
	</div>
    <div class="input_season"><label for ="userInput">
      <input type="text" name ="userInput" id="userInput"></label>
    </div>
    <div class="button_season"><input type = "submit" class="button" value ="GO">
    </div>
  </form>
  </p>

  </div>
  	</div>
    <div class = "output_two">
    <?php
		if(!empty($all))
	{
	foreach ($all as $alls): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($alls, ENT_QUOTES, 'UTF-8');
         ?>
      </p>
    </blockquote>
	
    <?php endforeach; }?>
				<?php
		if(!empty($name))
	{
	foreach ($name as $names): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($names, ENT_QUOTES, 'UTF-8');
         ?>
      </p>
    </blockquote>
	
    <?php endforeach; }?>
					<?php
		if(!empty($else))
	{
	foreach ($else as $elses): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($elses, ENT_QUOTES, 'UTF-8');
         ?>
      </p>
    </blockquote>
	
    <?php endforeach; }?>

  </div>
  </body>
</html> 