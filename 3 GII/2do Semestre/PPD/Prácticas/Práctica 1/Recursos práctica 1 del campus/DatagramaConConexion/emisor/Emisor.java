package emisor;

import java.net.*;
 public class Emisor {
    public static void main(String[] args) {
        try {
          InetAddress maquinaReceptora = InetAddress.getByName("localhost");
          int puertoReceptor = 6000;
          int miPuerto = 5000;
          String mensaje = "Soy el emisor";
          // instancia una socket datagrama para la conexion
          MiSocketDatagrama miSocket = new MiSocketDatagrama(miPuerto);
          // hace la conexion
          miSocket.connect(maquinaReceptora, puertoReceptor);
          for (int i=0; i<10; i++)
            miSocket.enviaMensaje( maquinaReceptora, puertoReceptor, mensaje);
          // ahora recibe un mensaje desde el otro extremo
          System.out.println(miSocket.recibeMensaje( ));
          // termina la conexion, despues cierra el socket
          miSocket.disconnect( );
          miSocket.close( );
        } // fin de try
        catch (Exception ex) {ex.printStackTrace( );} // fin de catch
    } // fin de main
} // fin de class

