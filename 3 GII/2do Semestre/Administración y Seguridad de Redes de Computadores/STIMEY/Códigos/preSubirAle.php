<?php
  if(!isset($_SESSION)){session_start();}

  // Create database connection
  $db = mysqli_connect("localhost", "root", "", "Stimey");

  // Initialize message variable
  $msg = "";
  header("Location: http://localhost/generarhtml.php");
?>
