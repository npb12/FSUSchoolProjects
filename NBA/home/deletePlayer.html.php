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
  <a href="home.html.php">Home</a>
  </p>
  <p>
  Enter the infomation to delete a created player's record 
  </p>
  <form action = "deleteInfo.php" method ="request">
    <div><label for ="name">Name:
      <input type="text" name ="name" id="name"></label>
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