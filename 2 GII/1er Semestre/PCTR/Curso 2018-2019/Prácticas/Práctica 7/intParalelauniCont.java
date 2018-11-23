/**
 * @author Jesús Rodíguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;
import java.lang.Math;

public class intParalelauniCont implements Runnable{

    public int puntos;
    public static Integer contDentro = 0;

    public intParalelauniCont(int p){
        this.puntos = p;
    }

    public void run(){
        double x, y;
        Random r = new Random();
        for (int i=0; i<puntos; ++i) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (y<=Math.sin(x)) {
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
        int h = Runtime.getRuntime().availableProcessors();//Usando la ecuación de subramanian el coeficiente de bloque es 0 para este problema debido a que es de tipología numérica.
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        long time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            ejecutor.execute(new intParalelauniCont(p/h));
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();
        System.out.println("El resultado es: "+(double)contDentro/p);
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos.");
    }
}
