/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;
import java.lang.Math;

public class piParalelouniCont implements Runnable{
    public int puntos;
    public static Integer contDentro = 0;

    public piParalelouniCont(int p){
        this.puntos = p;
    }

    public void run(){
        double x, y;
        Random r = new Random();
        for (int i=0; i<puntos; ++i) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (Math.pow(x,2)+Math.pow(y,2) <= 1) {
                synchronized (contDentro){
                    contDentro++;
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
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);

        long time_start = System.currentTimeMillis();

        for (int i=0; i<h; ++i) {
            ejecutor.execute(new piParalelouniCont(p/h));
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();
        System.out.println("El resultado es: "+4*(double)contDentro/p);
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos.");
    }
}
