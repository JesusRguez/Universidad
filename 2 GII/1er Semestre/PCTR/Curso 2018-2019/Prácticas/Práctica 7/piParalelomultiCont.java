/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;
import java.lang.Math;

public class piParalelomultiCont implements Runnable{
    public int puntos, nHilos, idHilo;
    public static int res[];

    public piParalelomultiCont(int p, int nHilos, int idHilo){
        this.puntos = p;
        this.nHilos = nHilos;
        this.idHilo = idHilo;
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
                res[idHilo]+=1;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de puntos:");
        int p = teclado.nextInt();
        int h = Runtime.getRuntime().availableProcessors();//Usando la ecuación de subramanian el coeficiente de bloque es 0 para este problema debido a que es de tipología numérica.
        int sol = 0;
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
