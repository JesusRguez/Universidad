
import java.util.Random;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
public class triatlonBarreras implements Runnable {

    public CyclicBarrier meta1;
    public CyclicBarrier meta2;
    public CyclicBarrier metaFinal;
    public static double[] tiempos = new double[100];
    public int indice;

    public triatlonBarreras(CyclicBarrier meta1, CyclicBarrier meta2, CyclicBarrier metaFinal, int indice) {
        this.meta1 = meta1;
        this.meta2 = meta2;
        this.metaFinal = metaFinal;
        this.indice = indice;
    }

    public void run() {
        Random r = new Random();
        //primera prueba
        long time_start, time_end;
        time_start = System.currentTimeMillis();
        try {
            Thread.sleep(Math.abs(r.nextInt(100)));
        } catch (InterruptedException ex) {
            Logger.getLogger(triatlonBarreras.class.getName()).log(Level.SEVERE, null, ex);
        }
        time_end = System.currentTimeMillis();
        double tiempo = (time_end - time_start) / (double) 1000;
        tiempos[indice] = tiempo;
        try {
            meta1.await();
        } catch (Exception ex) {
            Logger.getLogger(triatlonBarreras.class.getName()).log(Level.SEVERE, null, ex);
        }
        //segunda prueba
        long time_start1, time_end1;
        time_start1 = System.currentTimeMillis();
        try {
            Thread.sleep(Math.abs(r.nextInt(100)));
        } catch (InterruptedException ex) {
            Logger.getLogger(triatlonBarreras.class.getName()).log(Level.SEVERE, null, ex);
        }
        time_end1 = System.currentTimeMillis();
        double tiempo1 = (time_end1 - time_start1) / (double) 1000;
        tiempos[indice] = tiempo1;
        try {
            meta2.await();
        } catch (Exception ex) {
            Logger.getLogger(triatlonBarreras.class.getName()).log(Level.SEVERE, null, ex);
        }
        //tercera prueba
        long time_start2, time_end2;
        time_start2 = System.currentTimeMillis();
        try {
            Thread.sleep(Math.abs(r.nextInt(100)));
        } catch (InterruptedException ex) {
            Logger.getLogger(triatlonBarreras.class.getName()).log(Level.SEVERE, null, ex);
        }
        time_end2 = System.currentTimeMillis();
        double tiempo2 = (time_end2 - time_start2) / (double) 1000;
        tiempos[indice] = tiempo2;
        try {
            metaFinal.await();
        } catch (Exception ex) {
            Logger.getLogger(triatlonBarreras.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int hilos = 100;
        CyclicBarrier meta1 = new CyclicBarrier(hilos);
        CyclicBarrier meta2 = new CyclicBarrier(hilos);
        CyclicBarrier metaFinal = new CyclicBarrier(hilos);

        ExecutorService pool = Executors.newFixedThreadPool(100);

        for (int i = 0; i < hilos; i++) {
            pool.execute(new triatlonBarreras(meta1, meta2, metaFinal, i));
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);

        int auxMin = 0;
        for (int i = 1; i < hilos; i++) {
            if (tiempos[i] < tiempos[auxMin]) {
                auxMin = i;
            }
        }
        System.out.println("El ganador es el corredor con el dorsal " + auxMin);
    }

}
