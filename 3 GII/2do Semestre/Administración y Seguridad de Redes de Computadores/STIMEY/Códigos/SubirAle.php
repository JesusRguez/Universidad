<?php
$db = mysqli_connect("localhost", "root", "", "Stimey");


if(!isset($_SESSION)){session_start();}
  if(mysqli_query($db, "SELECT user where id = $relatedFile_text") == $_SESSION['username']){
  // If upload button is clicked ...
  if (isset($_POST['upload'])) {
  	// Get relatedFile name

  	$relatedFile = $_FILES['relatedFile']['name'];
  	// Get text
  	$relatedFile_text = mysqli_real_escape_string($db, $_POST['relatedFile_text']);

  	// relatedFile file directory
  	$target = "pruebas/".basename($relatedFile);

    $sql = "UPDATE pruebas SET relatedFile = '".$relatedFile."' WHERE id = '".$relatedFile_text."'";
    #$_SESSION['username'] = mysqli_query($db, "SELECT user where id = $relatedFile_text");

  	#$sql = "INSERT INTO pruebas (relatedFile, relatedFile_text) VALUES ('$relatedFile', '$relatedFile_text')";
  	// execute query
  	mysqli_query($db, $sql);

  	if (move_uploaded_file($_FILES['relatedFile']['tmp_name'], $target)) {
  		$msg = "relatedFile uploaded successfully";
  	}else{
  		$msg = "Failed to upload relatedFile";
  	}
  }
  $result = mysqli_query($db, "SELECT * FROM pruebas");
}
?>
<!DOCTYPE html>
<html>
<head>
<title>relatedFile Upload</title>
<style type="text/css">
   #content{
   	wIDth: 50%;
   	margin: 20px auto;
   	border: 1px solID #cbcbcb;
   }
   form{
   	wIDth: 50%;
   	margin: 20px auto;
   }
   form div{
   	margin-top: 5px;
   }
   #img_div{
   	wIDth: 80%;
   	padding: 5px;
   	margin: 15px auto;
   	border: 1px solID #cbcbcb;
   }
   #img_div:after{
   	content: "";
   	display: block;
   	clear: both;
   }
   img{
   	float: left;
   	margin: 5px;
   	wIDth: 300px;
   	height: 140px;
   }
</style>
</head>
<body>
<div ID="content">
  <?php
    while ($row = mysqli_fetch_array($result)) {
      echo "<div ID='img_div'>";
      	echo "<img src='pruebas/".$row['relatedFile']."' >";
      	echo "<p>".$row['id']."</p>";
      echo "</div>";
    }
  ?>
  <form method="POST" action="Subir.php" enctype="multipart/form-data">
  	<input type="hIDden" name="size" value="1000000">
  	<div>
  	  <input type="file" name="relatedFile">
  	</div>
  	<div>
      <textarea
      	ID="text"
      	cols="40"
      	rows="4"
      	name="relatedFile_text"
      	placeholder="Say something about this relatedFile..."></textarea>
  	</div>
  	<div>
  		<button type="submit" name="upload">POST</button>
  	</div>
  </form>
</div>
</body>
</html>
