/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package lectorescritor;

import java.io.*;

public class usalectorEscritor implements Runnable{

    private static final lectorEscritor monitor = new lectorEscritor();
    public static RandomAccessFile fichero;
    public int tipoHilo;

    /**
     * Constructor de la clase usalectorEscritor
     * @param tipoHilo Tipo de hilo: 1=lector; 2=escritor
     */
    public usalectorEscritor(int tipoHilo){
        this.tipoHilo = tipoHilo;
    }

    public void run(){
        if (tipoHilo == 1) {
            while(true){
                try {
                    monitor.inicia_lectura();
                    Thread.sleep(1000);
                    try {
                        fichero.seek(0);
                        System.out.println(fichero.readLine());
                    } catch(IOException e) {
                        System.out.println("Error en fichero...");
                    }
                    monitor.fin_lectura();
                    Thread.sleep(500);
                } catch(InterruptedException e) {
                    System.out.println("Error en lectores...");
                }
            }
        }else{
            while(true){
                try {
                    monitor.inicia_escritura();
                    Thread.sleep(1000);
                    try {
                        fichero.getFilePointer();
                        fichero.writeChars("Escribiendo en fichero\n");
                    } catch(IOException e) {
                        System.out.println("Fallo en fichero...");
                    }
                    monitor.fin_escritura();
                    Thread.sleep(500);
                } catch(Exception e) {
                    System.out.println("Error en escritores...");
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        try {
            fichero = new RandomAccessFile("datos.txt", "rw");
        } catch(Exception e) {
            System.out.println("No se ha podido abrir el fichero");
        }
        Thread hilos[] = new Thread[10];
        for (int i=0; i<5; ++i) {
            hilos[i] = new Thread(new usalectorEscritor(1)); // lectores=1
            hilos[i].start();
        }
        for (int i=5; i<10; ++i) {
            hilos[i] = new Thread(new usalectorEscritor(2)); // escritores=2
            hilos[i].start();
        }
        for (int i=0; i<10; ++i) {
            hilos[i].join();
        }
        fichero.close();
    }
}
