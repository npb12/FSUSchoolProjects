<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
		<link href="style.css" rel="stylesheet" type="css/text">
    <title>NBA</title>
  </head>
  <body>
      <div id="header">TEAM RAMROD</div>
	<div id="body">
  <p>
  <a href="home.html.php"> Home</a>
  </p>
  <div>
    <form action = "upanddowninfo.php" method ="request">
    <div><label for ="userInput">Enter your player to be analyzed:
      <input type="text" name ="userInput" id="userInput"></label>
    </div>
    <div><input type = "submit" class="button_updown" value ="GO">
    </div>
  </form>
  </div>
  	<div class = "player_updown">
	         <?php if(!empty($output))
			 {
		       echo $output;
             }
		 ?>
	</div>
	<div class="updown_name">

	    <?php
		if(!empty($players1))
	{
	foreach($players1 as $player1): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($player1, ENT_QUOTES, 'UTF-8');

         ?>
      </p>
    </blockquote>
    <?php endforeach; } ?>
  </div>
  <div class="updown_PER">
  <?php
    
	foreach ($players as $player): ?>
    <blockquote>
      <p><?php echo htmlspecialchars($player, ENT_QUOTES, 'UTF-8');
         ?>
      </p>
    </blockquote>
    <?php endforeach; ?>
	</div>	
	</div>

		</div>
  </body>
</html> 