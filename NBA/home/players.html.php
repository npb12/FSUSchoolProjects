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
  <form action = "playerInfo.php" method ="request">

  <div class="select_season">
  <div class="styled-select">
    <select id="select" name="select">
	  <option value="name">Name</option>
      <option value="Age">Age</option>
      <option value="position">Position</option>
      <option value="height">Height</option>
      <option value="college">College</option>
	  <option value="nationality">Nationality</option>
	  
    </select>
	</div>
	</div>
    <div class = "input_season"><label for ="userInput">
      <input type="text" name ="userInput" id="userInput"></label>
    </div>
    <div class="button_season"><input type = "submit" class ="button" value ="GO">
    </div>
  </form>
  </p>
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
	</div>
  </body>
</html>  