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
            Scanner teclado = new Scanner(System.in);
            String respuesta, mensaje;
            boolean fin = false;
            // hace una conexion con el socket del emisor 
            miSocket.connect(maquinaEmisora, puertoEmisor);

            do {
                mensaje = miSocket.recibeMensaje();
                //System.out.println("RECIBIDO (" + mensaje + ")");
                if (mensaje.contains("*")) {
                    System.out.println("El emisor cierra la conexion");
                    //Le envía el asterisco para cerrar la conexion
                    fin = true;
                } else {
                    //Recibe el mensaje
                    System.out.println(mensaje);

                    respuesta = teclado.nextLine();

                    if (respuesta.contains("*")) {
                        System.out.println("Tu cierras la conexion");
                        miSocket.enviaMensaje(maquinaEmisora, puertoEmisor, respuesta);
                        fin = true;
                    } else {
                        miSocket.enviaMensaje(maquinaEmisora, puertoEmisor, respuesta);
                    }

                }
            } while (fin == false);

            miSocket.disconnect();
            miSocket.close();
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        }// fin de catch
    } // fin de main
} // fin de class

