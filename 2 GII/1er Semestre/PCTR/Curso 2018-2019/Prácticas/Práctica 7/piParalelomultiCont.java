/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;
import java.lang.Math;

public class piParalelomultiCont implements Runnable{
    public int puntos, nHilos, idHilo;
    public static Object lock;
    public static int res[];

    public piParalelomultiCont(int p, int nHilos, int idHilo){
        this.puntos = p;
        this.nHilos = nHilos;
        this.idHilo = idHilo;
        lock = new Object();
        res = new int[nHilos];
        for (int i=0; i<nHilos; ++i) {
            res[i] = 0;
        }
    }

    public void run(){
        double x, y;
        Random r = new Random();
        for (int i=0; i<puntos; ++i) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (Math.pow(x,2)+Math.pow(y,2) <= 1) {
                synchronized (lock){
                    res[idHilo]+=1;
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de puntos:");
        int p = teclado.nextInt();
        System.out.println("Introduzca el coeficiente de bloqueo:");
        double c = teclado.nextDouble();
        int cores = Runtime.getRuntime().availableProcessors();
        int h = (int)(cores/(1-c));

        int sol=0;
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        long time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            ejecutor.execute(new piParalelomultiCont(p/h, h, i));
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        for (int i=0; i<h; ++i) {
            sol+=res[i];
        }
        long time_end = System.currentTimeMillis();
        System.out.println("El resultado es: "+4*(double)sol/p);
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos.");
    }
}
