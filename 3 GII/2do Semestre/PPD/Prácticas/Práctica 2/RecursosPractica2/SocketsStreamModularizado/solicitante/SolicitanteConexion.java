package solicitante;

 import java.net.*;
 import java.io.*;
 public class SolicitanteConexion {
    public static void main(String[] args) {
        try {
          String maquinaAceptadora = "localhost";
          int puertoAceptador = 5000;
          // instancia un socket de datos
          MiSocketStream miSocket =
            new MiSocketStream(maquinaAceptadora, puertoAceptador);
  /**/    System.out.println("Solicitud de conexion concedida");
          String mensaje = miSocket.recibeMensaje( );
  /**/    System.out.println("Mensaje recibido:");
          System.out.println("\t" + mensaje);
          miSocket.close( );
  /**/    System.out.println("socket de datos cerrado");
        } // fin de try
        catch (Exception ex) {
          ex.printStackTrace( );
        }
    } // fin de main
  } // fin de class

