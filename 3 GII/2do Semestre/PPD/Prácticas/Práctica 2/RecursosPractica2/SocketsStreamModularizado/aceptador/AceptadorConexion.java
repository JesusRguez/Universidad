package aceptador;

import java.net.*;
import java.io.*;
  public class AceptadorConexion {
   public static void main(String[] args) {
       try {
          int numPuerto = 5000;
          String mensaje = "Soy el que acepta";
          // instancia un socket para aceptar la conexion
          ServerSocket socketConexion = new ServerSocket(numPuerto);
  /**/    System.out.println("preparado para aceptar una conexion");
          // espera una peticion de conexion, instante en el cual
          // se crea un socket de datos
          MiSocketStream socketDatos =
            new MiSocketStream(socketConexion.accept());
  /**/    System.out.println("conexion aceptada");
          socketDatos.enviaMensaje(mensaje);

  /**/    System.out.println("mensaje enviado");
          socketDatos.close( );
  /**/    System.out.println("socket de datos cerrado");
          socketConexion.close( );
  /**/    System.out.println("socket de conexion cerrado");
        } // fin de try
        catch (Exception ex) {
          ex.printStackTrace( );
        } // fin de catch
    } // fin de main
  } // fin de class


