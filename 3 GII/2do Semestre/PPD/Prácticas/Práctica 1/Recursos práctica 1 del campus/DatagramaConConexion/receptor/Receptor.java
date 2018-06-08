package receptor;

import java.net.*;
 public class Receptor {

    public static void main(String[ ] args) {
        try {
          InetAddress maquinaEmisora = InetAddress.getByName("localhost");
          int puertoEmisor = 5000;
          int miPuerto = 6000;
          String mensaje = "Soy el receptor";
          // instancia un socket datagrama para recibir los datos
          MiSocketDatagrama miSocket = new MiSocketDatagrama(miPuerto);
          // hace una conexion con el socket del emisor 
          miSocket.connect(maquinaEmisora, puertoEmisor);
          for (int i=0; i<10; i++)
            System.out.println(miSocket.recibeMensaje( ));
          // ahora manda un mensaje al otro extremo
          miSocket.enviaMensaje( maquinaEmisora, puertoEmisor, mensaje);
          miSocket.close( );
        } // fin de try
        catch (Exception ex) {ex.printStackTrace( );}// fin de catch
    } // fin de main
  } // fin de class

