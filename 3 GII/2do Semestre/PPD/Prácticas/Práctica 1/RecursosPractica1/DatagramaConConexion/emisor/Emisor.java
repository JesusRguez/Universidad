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
            miSocket.connect(maquinaReceptora, puertoReceptor);

            String respuesta;
            Scanner teclado = new Scanner(System.in);
            String mensaje = teclado.nextLine();
            while (!"*".equals(mensaje)) {
                miSocket.enviaMensaje(maquinaReceptora, puertoReceptor, mensaje);
                respuesta = miSocket.recibeMensaje();

                // ahora recibe un mensaje desde el otro extremo*/
                if ("*".equals(respuesta)) {
                    miSocket.disconnect();
                    miSocket.close();
                    System.out.println("Se ha cerrado la conexion.");
                } else {
                    System.out.println(respuesta);
                    mensaje = teclado.nextLine();

                }
            }
            //Si sale del bucle es porque el receptor ha cerrado la comunicación.
            if ("*".equals(mensaje)) {
                miSocket.enviaMensaje(maquinaReceptora, puertoReceptor, mensaje);

            }

            // termina la conexion, despues cierra el socket
            miSocket.disconnect();
            miSocket.close();
            System.out.println("Se ha cerrado la conexion.");
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        } // fin de catch
    } // fin de main
} // fin de class

