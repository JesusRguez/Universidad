/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.concurrent.CyclicBarrier;

public class triatlonBarreras implements Runnable{

    public static final CyclicBarrier barrera = new CyclicBarrier(100);
    public int idHilo;
    public static long tiempos[] = new long[100];

    /**
     * Constructor de triatlonBarreras
     * @param idHilo Identificador del hilo
     */
    public triatlonBarreras(int idHilo){
        this.idHilo = idHilo;
    }

    public void run(){
        double t;
        t = Math.random()*1000;
        long time_start = System.currentTimeMillis();
        try {
            Thread.sleep((int)t);
        } catch(Exception e) {
            System.out.println("Error en el sleep 1...");
        }
        long time_end = System.currentTimeMillis();
        tiempos[idHilo] = time_end - time_start;
        try {
            barrera.await();
        } catch(Exception e) {
            System.out.println("Fallo en el await 1...");
        }

        t = Math.random()*1000;
        long time_start2 = System.currentTimeMillis();
        try {
            Thread.sleep((int)t);
        } catch(Exception e) {
            System.out.println("Error en el sleep 2...");
        }
        long time_end2 = System.currentTimeMillis();
        tiempos[idHilo] += time_end2 - time_start2;
        try {
            barrera.await();
        } catch(Exception e) {
            System.out.println("Fallo en el await 2...");
        }

        t = Math.random()*1000;
        long time_start3 = System.currentTimeMillis();
        try {
            Thread.sleep((int)t);
        } catch(Exception e) {
            System.out.println("Error en el sleep 3...");
        }
        long time_end3 = System.currentTimeMillis();
        tiempos[idHilo] += time_end3 - time_start3;
        try {
            barrera.await();
        } catch(Exception e) {
            System.out.println("Fallo en el await 3...");
        }
    }

    public static int minimo(long[] tiempos){
        int t = 0;
        for (int i=0; i<100; ++i) {
            if (tiempos[i]<tiempos[t]) {
                t = i;
            }
        }
        return t;
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[100];
        System.out.println("Comienza la carrera");
        for (int i=0; i<100; ++i) {
            hilos[i] = new Thread(new triatlonBarreras(i));
            hilos[i].start();
        }
        for (int i=0; i<100; ++i) {
            hilos[i].join();
        }
        System.out.println("Termina la carrera");
        System.out.println("Total de corredores: "+hilos.length);
        int ganador = minimo(tiempos);
        System.out.println("La hebra ganadora ha sido la "+ganador+" y ha tardado "+tiempos[ganador]/*/(double)1000*/+" milisegundos.");
    }
}
