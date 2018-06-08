package emisor;

import java.util.Scanner;
import java.net.*;

public class Emisor {

    public static void main(String[] args) {
        try {
            InetAddress maquinaReceptora = InetAddress.getByName("localhost");
            int puertoReceptor = 6000;
            int miPuerto = 5000;
            //String mensaje = "Soy el emisor";
            // instancia una socket datagrama para la conexion
            MiSocketDatagrama miSocket = new MiSocketDatagrama(miPuerto);
            // hace la conexion
            String respuesta, mensaje;
            Scanner teclado = new Scanner(System.in);
            miSocket.connect(maquinaReceptora, puertoReceptor);
            boolean fin = false;

            mensaje = teclado.nextLine();
            do {
                if (mensaje.contains("*")) {
                    miSocket.enviaMensaje(maquinaReceptora, puertoReceptor, mensaje);
                    System.out.println("Tu cierras la conexion");
                    //Le envía el asterisco para cerrar la conexion
                    fin = true;
                } else {
                    //Envía el mensaje
                    miSocket.enviaMensaje(maquinaReceptora, puertoReceptor, mensaje);

                    //Recibe el mensaje
                    respuesta = miSocket.recibeMensaje();
                    if (respuesta.contains("*")) {
                        System.out.println("El receptor ha cerrado la conexion");
                        fin = true;
                    } else {
                        System.out.println(respuesta);
                        mensaje = teclado.nextLine();
                    }
                }

            } while (fin == false);

            // termina la conexion, despues cierra el socket
            miSocket.disconnect();
            miSocket.close();
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        } // fin de catch
    } // fin de main
} // fin de class

