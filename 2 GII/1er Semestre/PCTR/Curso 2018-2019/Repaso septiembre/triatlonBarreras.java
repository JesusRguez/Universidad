import java.util.concurrent.*;
import java.util.concurrent.CyclicBarrier;

public class triatlonBarreras implements Runnable{

    public static final CyclicBarrier barrera = new CyclicBarrier(100);
    public int idHilo;
    public static long tiempos[] = new long[100];

    public triatlonBarreras(int idHilo){
        this.idHilo = idHilo;
        tiempos[idHilo] = 0;
    }

    public void run(){
        double t;
        t = Math.random()*1000;
        long time_start = System.currentTimeMillis();
        try {
            Thread.sleep((int)t);
        } catch(Exception e) {
            System.out.println("Error en sleep 1...");
        }
        long time_end = System.currentTimeMillis();
        tiempos[idHilo] += time_end - time_start;
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
            System.out.println("Error en sleep 2...");
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
            System.out.println("Error en sleep 3...");
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
        double t = tiempos[0];
        int pos = 0;
        for (int i=0; i<100; ++i) {
            if (tiempos[i] < t) {
                t = tiempos[i];
                pos = i;
            }
        }
        return pos;
    }

    public static void main(String[] args) throws InterruptedException {
        ExecutorService ejecutor = Executors.newFixedThreadPool(100);
        for (int i=0; i<100; ++i) {
            ejecutor.execute(new triatlonBarreras(i));
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);

        int ganador = minimo(tiempos);

        System.out.println("La hebra ganadora ha sido la "+ganador+" y ha tardado "+tiempos[ganador]+" milisegundos");
    }
}
