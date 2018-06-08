
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;
import java.util.concurrent.*;
import java.math.*;
import java.util.Random;

public class intParalelauniCont implements Runnable {

    static double puntosdentro;
    int puntos;

    Object o;

    /**
     * @param puntos
     * @param p
     */
    public intParalelauniCont(int puntos, Object p) {
        this.puntos = puntos;
        this.puntosdentro = 0;
        o = p;
    }

    public void run() {

        double x, y;
        Random r = new Random();
        for (int i = 0; i < puntos; i++) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (Math.sin(x) >= y) {
                synchronized (o) {
                    puntosdentro++;
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int cores = 4;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce el número de puntos:");
        int puntos = teclado.nextInt();

        System.out.println("Introduzca el coeficiente de bloqueo:");
        double coeficienteBloqueo = teclado.nextDouble();

        int hilos = (int) (cores / (1 - coeficienteBloqueo));

        ExecutorService pool = Executors.newFixedThreadPool(hilos);
        Object o = new Object();
        intParalelauniCont O = new intParalelauniCont(puntos / hilos, o);
        long time_start = System.currentTimeMillis();

        for (int i = 0; i < hilos; i++) {
            pool.execute(O);
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);

        long time_end = System.currentTimeMillis();

        double solucion = O.puntosdentro / puntos;

        System.out.println("La solucion es: " + solucion);
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
