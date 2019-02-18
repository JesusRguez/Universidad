<!DOCTYPE HTML>
<html>
<body>

<form action="menuSupervisar.php" method="post">
ID prueba: <input type="number" name="id"><br>
Correcto    <input type="radio" name="CorrectRadio" value = "Correcto" checked><br>
No Correcto <input type="radio" name="CorrectRadio" value = "Incorrecto" checked><br>
<textarea
  ID="text"
  cols="40"
  rows="4"
  name="motivo"
  placeholder="Motivos...">
</textarea>
<input type="submit" value = "Valorar">
</form>
</body>
</html>

<?php
if(!isset($_SESSION)){session_start();}
$db = mysqli_connect("localhost", "root", "", "Stimey");
if(isset($POST["CorrectRadio"]) && $id == mysqli_query($db, "SELECT id FROM pruebas WHERE supervisor = $_SESSION['id']");){
  $sql = "";
  if($POST["CorrectRadio"] == "Correcto"){
      $sql = "UPDATE pruebas SET status = 4";
      mysqli_query($db, $sql);
    }else{
      $sql = "UPDATE pruebas SET status = 3";
      mysqli_query($db, $sql);
      $fecha = date('Y-m-d H:i:s');
      $motivo = $POST["motivo"];
      $sql = "INSERT INTO incidencias (test,fecha,descripcion) VALUES ('".$id."', '".$fecha."','".$motivo."')";
      mysqli_query($db, $sql);
      header("Location: http://localhost/Supervisar.php");
    }
    //ID incidencia test, fecha, descripcion
}



?>
