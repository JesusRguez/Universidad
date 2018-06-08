package Aceptador;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class AceptadorConexion implements Runnable {

    int tipoHilo;
    static boolean fin = false;
    static MiSocketStream SocketFlujo;

    public AceptadorConexion(int tipoHilo) {
        this.tipoHilo = tipoHilo;
    }

    Scanner teclado = new Scanner(System.in);

    public void run() {
        try {
            switch (tipoHilo) {
                case 1://el 1 es de enviar
                    while (fin == false) {
                        String mensaje = teclado.nextLine();
                        if (mensaje.contains("*")) {
                            System.out.println("Tu cierras la conexion");
                            SocketFlujo.enviaMensaje(mensaje);
                            fin = true;
                        } else {
                            SocketFlujo.enviaMensaje(mensaje);
                        }
                    }
                    break;
                case 2://el 2 es de recibir
                    String respuesta;
                    while (fin == false) {
                        try {
                            respuesta = SocketFlujo.recibeMensaje();

                            if (respuesta.contains("*")) {
                                System.out.println("El solicitante ha cerrado la conexion");
                                fin = true;
                            } else {
                                System.out.println(respuesta);
                            }
                        } catch (SocketTimeoutException e) {
                            System.err.println("Tiempo de espera agotado");
                            SocketFlujo.enviaMensaje("*");
                            fin = true;
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

            int numPuerto = 5000;
            String mensaje = "Soy el que acepta";
            // instancia un socket para aceptar la conexion
            ServerSocket socketConexion = new ServerSocket(numPuerto);
            /**/ System.out.println("preparado para aceptar una conexion");
            // espera una peticion de conexion, instante en el cual
            // se crea un socket de datos
            SocketFlujo = new MiSocketStream(socketConexion.accept());
            /**/ System.out.println("conexion aceptada");

            Thread hilo1 = new Thread(new AceptadorConexion(1));
            Thread hilo2 = new Thread(new AceptadorConexion(2));

            hilo1.start();
            hilo2.start();
            hilo1.join();
            hilo2.join();

            SocketFlujo.close();
            /**/ System.out.println("socket de datos cerrado");
            socketConexion.close();
            /**/ System.out.println("socket de conexion cerrado");
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        } // fin de 

    }
} // fin de main
// fin de class

