<?php
include 'DBconnect.php';

if(isset($_POST['HomeSelect'])) 
{
  $varSelection = $_POST['HomeSelect'];
  $errorMessage = "";
  if(empty($varSelection)) 
  {
    $errorMessage = "<li>You forgot to select a choice!</li>";
  }
   
  if($errorMessage != "") 
  {
    echo("<p>There was an error with your form:</p>\n");
    echo("<ul>" . $errorMessage . "</ul>\n");
  } 
  else
  {
    $redir = "players.html.php";
    switch($varSelection)
    {
      case "Player": $redir = "players.html.php"; break;
      case "Season": $redir = "season.html.php"; break;
      case "Career": $redir = "career.html.php"; break;
      case "Teams": $redir = "teams.html.php"; break;
	  case "ComparePlayers": $redir = "ComparePlayers.html.php"; break;
	  case "upanddown": $redir = "upanddown.html.php"; break;
	  case "createPlayer": $redir = "createPlayer.html.php"; break;
	  case "compareCreated": $redir = "compareYourself.html.php"; break;
      default: echo("Error!"); exit(); break;
    }
    echo " redirecting to: $redir ";
     
    header("Location: $redir");

 
    exit();
  }
}


include 'home.html.php';


?>