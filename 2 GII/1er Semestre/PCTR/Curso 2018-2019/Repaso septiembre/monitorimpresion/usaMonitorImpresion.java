package monitorimpresion;

import java.util.*;
import java.util.concurrent.*;

public class usaMonitorImpresion implements Runnable{

    public static monitorImpresion monitor;

    public usaMonitorImpresion(){
        this.monitor = new monitorImpresion();
    }

    public void run(){
        int impresora;
        while(true){
            impresora = monitor.take_print();
            System.out.println("Imprimiendo en la impresora "+impresora+" por el hilo "+Thread.currentThread().getName());
            /*try {
                Thread.sleep(100);
            } catch(Exception e) {
                System.out.println("Error en el sleep...");
            }*/
            monitor.drop_print(impresora);
        }
    }

    public static void main(String[] args) throws InterruptedException{
        Scanner teclado = new Scanner(System.in);
        System.out.print("Introduce el número de hilos: ");
        int hilos = teclado.nextInt();
        ExecutorService ejecutor = Executors.newFixedThreadPool(hilos);
        for (int i=0; i<hilos; ++i) {
            ejecutor.execute(new usaMonitorImpresion());
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
    }
}
