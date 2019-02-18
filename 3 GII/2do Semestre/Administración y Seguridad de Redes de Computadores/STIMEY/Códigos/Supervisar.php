<?php
  if(!isset($_SESSION)){session_start();}
  $tabla = "pruebas";
  $page_name = $tabla."_view";
  $page_ext = ".php";
  $file_name = $page_name.$page_ext;
  $id = $_SESSION['username'];
  $header = "<!DOCTYPE html>
  <html lang=\"es\">
  <head>
  <meta charset=\"utf-8\">
  <title>'".$page_name."'</title></head>
  <body>
  <div>
  <center>
     <img src=\".\LogoStimey.jpg\" alt=\"Logo Stimey\"/>
     <br> Mostrando tabla $tabla <br>
  <table border = 1><br>";
  // CONTENT
  $conexion = mysqli_connect ("localhost", "root", "", "Stimey")
  			or die("Error al conectar a la base de datos");
        //1 sin hacer // 2 en proceso // 3 no superada // 4 correcto
  $texto_consulta_filas = "SELECT count(*) from $tabla where supervisor = $id and (status == 2) order by id asc";
  $consulta_filas = mysqli_real_escape_string($conexion, $texto_consulta_filas);
  $result_filas = mysqli_query($conexion, $consulta_filas);
  $row = mysqli_fetch_array($result_filas);
  $filas = $row[0];
  $consulta_columnas = "SELECT Table_Name, count(*) as num from Information_Schema.Columns
  where Table_Name = '".$tabla."' group by Table_Name";
  $result_columnas = mysqli_query($conexion, $consulta_columnas);
  $row = mysqli_fetch_array($result_columnas, MYSQLI_NUM);
  $columnas = 7;
  $consulta_schema = "SELECT column_name from Information_Schema.Columns where table_name = '".$tabla."'";
  $result_schema = mysqli_query($conexion, $consulta_schema);
  $schema_text = "<tr><br>
  ";
  for($index = 0; $index < $columnas; ++$index)
  {
    $schema_row = mysqli_fetch_row($result_schema);
    $column_name = $schema_row[0];
    $schema_text = $schema_text."<td>'" . $column_name . "'</td>
    ";
  }
  $schema_text = $schema_text."</tr><br>
  ";
  $final_header = $header.$schema_text;
  $consulta = "SELECT * from " . $tabla;
  $result_data = mysqli_query($conexion, $consulta);
  $data = "";
  for($index = 0; $index < $filas; ++$index)
  {
    $row = mysqli_fetch_row($result_data);
    $data = $data."<tr><br>
    ";
    for($i = 0; $i < $columnas; ++$i)
    {
      $row_data = $row[$i];
      $data = $data."<td>'" . $row_data . "' </td>
      ";
    }
    $data = $data."</tr>
    ";
  }
//  while()
  {
  $content = $data;
  $footer = "</table>
  </center>
  </div>
  <?php
  header(\"Location: http://localhost/menuSupervisar.php\");
  ?>
  </body>
  </html>";
  $htmlpage = $final_header.$content.$footer;
  if(file_exists($file_name))
    $mensaje = "El fichero $file_name ha sido modificado\n";
  else
    $mensaje = "Se ha generado el fichero $file_name \n";
  if($file = fopen($file_name, "w+"))
  {
      if(fwrite($file, $htmlpage))
      {
        echo "Se ha ejecutado correctamente\n";
        header("Location: $file_name");
    		exit();
      }
      else
        echo "Ha habido un problema al crear el fichero\n";
  }
}
?>
