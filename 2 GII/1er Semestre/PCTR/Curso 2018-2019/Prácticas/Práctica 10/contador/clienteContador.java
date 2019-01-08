/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package contador;

import java.io.*;
import java.net.Socket;

public class clienteContador implements Runnable{

    public void run(){
        int i = (int) (Math.random() * 10);
        int puerto = 2001;
        try {
            System.out.println("Realizando conexion...");
            Socket cable = new Socket("localhost", 2001);
            System.out.println("Realizada conexion a " + cable);
            PrintWriter salida = new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    cable.getOutputStream())));
            salida.println(i);
            salida.flush();
            System.out.println("Cerrando conexion...");
            cable.close();
        }
        catch (Exception e) {
            System.out.println("Error en sockets...");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[100];
        for (int i = 0; i < 100; i++) {
            hilos[i] = new Thread(new clienteContador());
            hilos[i].start();
        }
        for (int i = 0; i < 100; i++) {
            hilos[i].join();
        }
    }
}
