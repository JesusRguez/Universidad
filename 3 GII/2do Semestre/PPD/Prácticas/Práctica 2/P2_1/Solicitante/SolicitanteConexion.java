package Solicitante;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class SolicitanteConexion implements Runnable {

    int tipoHilo;
    static boolean fin = false;
    static MiSocketStream SocketFlujo;

    public SolicitanteConexion(int tipoHilo) {
        this.tipoHilo = tipoHilo;
    }

    Scanner teclado = new Scanner(System.in);

    public void run() {
        try {
            switch (tipoHilo) {
                case 1://El 1 es el de recibir
                    String mensaje;
                    while (fin == false) {
                        try {
                            mensaje = SocketFlujo.recibeMensaje();
                            if (mensaje.contains("*")) {
                                System.err.println("El aceptador ha cerrado la conexion");
                                fin = true;
                            } else {
                                System.out.println(mensaje);
                            }
                        } catch (SocketTimeoutException e) {
                            System.out.println("Tiempo de espera agotado");
                            SocketFlujo.enviaMensaje("*");
                            fin = true;
                        }
                    }
                    break;
                case 2://El 2 es el de enviar
                    while (fin == false) {
                        String respuesta = teclado.nextLine();
                        if (respuesta.contains("*")) {
                            System.out.println("Tu cierras la conexion");
                            SocketFlujo.enviaMensaje(respuesta);
                            fin = true;
                        } else {
                            SocketFlujo.enviaMensaje(respuesta);
                        }
                    }
                    break;
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        try {

            String maquinaAceptadora = "localhost";
            int puertoAceptador = 5000;
            // instancia un socket de datos
            MiSocketStream miSocket = new MiSocketStream(maquinaAceptadora, puertoAceptador);
            /**/ System.out.println("Solicitud de conexion concedida");

            SocketFlujo = miSocket;

            Thread hilo1 = new Thread(new SolicitanteConexion(1));
            Thread hilo2 = new Thread(new SolicitanteConexion(2));

            hilo1.start();
            hilo2.start();
            hilo1.join();
            hilo2.join();

            String mensaje = miSocket.recibeMensaje();
            /**/ System.out.println("Mensaje recibido:");
            System.out.println("\t" + mensaje);
            miSocket.close();
            /**/ System.out.println("socket de datos cerrado");
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        }
    } // fin de main
} // fin de class

