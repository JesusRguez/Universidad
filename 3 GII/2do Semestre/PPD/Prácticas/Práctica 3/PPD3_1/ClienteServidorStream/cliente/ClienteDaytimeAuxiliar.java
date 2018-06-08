package cliente;

 import java.net.*;
 
 public class ClienteDaytimeAuxiliar {

    public static String obtenerMarcaTiempo(String nombreMaquina, String numPuerto) throws Exception {

      String marcaTiempo = "";
      int puertoServidor = Integer.parseInt(numPuerto);
      // instancia un socket en modo stream y espera a que se haga 
      // una conexi�n al puerto servidor
     System.out.println("Petici�n de conexi�n realizada");
      MiSocketStream miSocket = new MiSocketStream(nombreMaquina, puertoServidor);
      // ahora espera hasta recibir la marca de tiempo
      marcaTiempo = miSocket.recibeMensaje();
      miSocket.close( ); // implica la desconexi�n
      return marcaTiempo;
    } // fin
  } // fin de class
