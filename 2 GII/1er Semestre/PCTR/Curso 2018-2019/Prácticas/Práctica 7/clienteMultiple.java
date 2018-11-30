/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.net.*;
import java.io.*;
import java.util.concurrent.*;

public class clienteMultiple implements Runnable{

    public void run(){
        int i = (int)(Math.random()*10);
        int puerto = 2001;
        try{
            System.out.println("Realizando conexion...");
            Socket cable = new Socket("localhost", 2001);
            System.out.println("Realizada conexion a "+cable);
            PrintWriter salida= new PrintWriter(
                                    new BufferedWriter(
                                        new OutputStreamWriter(
            cable.getOutputStream())));
            salida.println(i);
            salida.flush();
            System.out.println("Cerrando conexion...");
            cable.close();

        }catch (Exception e){
            System.out.println("Error en sockets...");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int h = Runtime.getRuntime().availableProcessors();
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        long time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            ejecutor.execute(new clienteMultiple());
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
