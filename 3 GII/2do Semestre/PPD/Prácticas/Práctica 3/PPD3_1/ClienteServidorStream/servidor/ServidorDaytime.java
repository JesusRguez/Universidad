package servidor;

 import java.io.*;
 import java.net.*;
 import java.util.Date; // para obtener una marca de tiempo
  public class ServidorDaytime {
    public static void main(String[] args) {
      int puertoServidor = 13; // puerto por defecto
      try {
        // instancia un socket stream para aceptar las conexiones
        ServerSocket miSocketConexion =  new ServerSocket(puertoServidor);
        System.out.println("El servidor Daytime está listo.");
        while (true) { // bucle infinito // espera para aceptar una conexión 
          System.out.println("Espera una conexión.");
          MiSocketStream miSocketDatos = new MiSocketStream   (miSocketConexion.accept( ));
          // Nota: no hay necesidad de leer una petición - la petición es implícita.
          System.out.println("Un cliente ha hecho una conexión.");
          Date marcaTiempo = new Date ( );
          System.out.println("marca de tiempo enviada: "+  marcaTiempo.toString());
          // ahora manda la respuesta al solicitante.
          miSocketDatos.enviaMensaje(marcaTiempo.toString( ));
          miSocketDatos.close( );
        } // fin de while
      } // fin de try
      catch (Exception ex) {
        ex.printStackTrace( );
      }
    } // fin de main
  } // fin de class

