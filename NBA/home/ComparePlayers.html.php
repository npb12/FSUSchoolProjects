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
  <form action = "compareinfo.php" method ="request">

    <div><label for ="userInput">Enter Player 1's name(full):
      <input type="text" name ="userInput" id="userInput"></label>
    </div>
	<div><label for ="userInput2">Enter Player 2's name(full):
      <input type="text" name ="userInput2" id="userInput2"></label>
    </div>
	<div class = "centerit">
	 <div class="styled-select">
	<select id="select2" name="select2">
	<div>
    <option value="season">Season</option>
    <option value="career">Career</option>
    </select>
	</div>
	</div>
	</div>
  <div class = "centerit">
  <div class="styled-select">
    <select id="select" name="select">
	<div>who whas averaging more: (select and option) </div>
	<div>
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

    <div><input type = "submit" class="button" value ="GO">
    </div>
  </form>
  </p>
  
  
  </div>
    <div class = "yourself_output">
  <?php
  if(!empty($output))
  {
  echo htmlspecialchars($output, ENT_QUOTES, 'UTF-8'); }?>
  
  </div>
  	</div>
  </body>
</html> 