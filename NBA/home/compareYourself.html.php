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
  <form action = "compareCreateInfo.php" method ="request">

       <div><label for ="userInput">Enter Created Players Name(full):
      <input type="text" name ="userInput" id="userInput"></label>
    </div>
	<div><label for ="userInput2">Enter NBA Player Name(full):
      <input type="text" name ="userInput2" id="userInput2"></label>
    </div>
	
  <div class = "centerit_yourself">
  <div class="styled-select_yourself">
    <select id="select" name="select">
	<div>who whas averaging more: (select and option) </div>
	<div>
	<option value="PPG">Points</option>
    <option value="AST">Assist</option>
    <option value="BLK">Blocks</option>
    <option value="ORB">Offensive Rebounds</option>
    <option value="DRB">Defensive Rebounds</option>
    </select>
	</div>
	</div>
	</div>

    <div><input type = "submit" class="button_yourself" value ="GO">
    </div>
  </form>
  </p>
  <div class = "yourself_output">
  <?php
  if(!empty($output))
  {
  echo htmlspecialchars($output, ENT_QUOTES, 'UTF-8'); }?>
  
  </div>
  
  </div>
  </body>
</html> 