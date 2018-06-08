package receptor;

import java.util.Scanner;
import java.net.*;

public class Receptor {

    public static void main(String[] args) {
        try {
            InetAddress maquinaEmisora = InetAddress.getByName("localhost");
            int puertoEmisor = 5000;
            int miPuerto = 6000;
            // instancia un socket datagrama para recibir los datos
            MiSocketDatagrama miSocket = new MiSocketDatagrama(miPuerto);
            // hace una conexion con el socket del emisor 
            miSocket.connect(maquinaEmisora, puertoEmisor);

            String respuesta = miSocket.recibeMensaje();
            System.out.println(respuesta);
            Scanner teclado = new Scanner(System.in);
            String mensaje = teclado.nextLine();
            while (!"*".equals(mensaje)) {
                //System.out.println(miSocket.recibeMensaje());
                // ahora manda un mensaje al otro extremo
                miSocket.enviaMensaje(maquinaEmisora, puertoEmisor, mensaje);
                respuesta = miSocket.recibeMensaje();

                if ("*".equals(respuesta)) {
                    miSocket.disconnect();
                    miSocket.close();
                    System.out.println("Se ha cerrado la conexion.");
                } else {
                    System.out.println(respuesta);
                    mensaje = teclado.nextLine();
                    miSocket.enviaMensaje(maquinaEmisora, puertoEmisor, mensaje);
                }

            }
            //Si sale del bucle es porque el emisor ha cerrado la comunicación.
            if ("*".equals(mensaje)) {
                miSocket.enviaMensaje(maquinaEmisora, puertoEmisor, mensaje);
                System.out.println("Se ha cerrado la conexion.");
            }
            miSocket.disconnect();
            miSocket.close();
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        }// fin de catch
    } // fin de main
} // fin de class

