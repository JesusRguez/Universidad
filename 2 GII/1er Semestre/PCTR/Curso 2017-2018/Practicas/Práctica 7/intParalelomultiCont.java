
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Random;
import java.util.Scanner;

public class intParalelomultiCont implements Runnable {

    double puntosdentro;
    int puntos;

    /**
     * @param puntos
     */
    public intParalelomultiCont(int puntos) {
        this.puntos = puntos;
        this.puntosdentro = 0;
    }

    public void run() {

        double x, y;
        Random r = new Random();
        for (int i = 0; i < puntos; i++) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (Math.sin(x) >= y) {

                puntosdentro++;

            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int hilo = 4;
        double totales = 0;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce el número de puntos:");
        int puntos = teclado.nextInt();

        long time_start, time_end;
        Thread hilos[] = new Thread[4];
        intParalelomultiCont[] v = new intParalelomultiCont[hilo];
        for (int i = 0; i < hilo; i++) {
            v[i] = new intParalelomultiCont(puntos / hilo);
        }

        time_start = System.currentTimeMillis();

        for (int i = 0; i < hilo; i++) {
            hilos[i] = new Thread(v[i]);
            hilos[i].start();
        }

        for (int i = 0; i < hilo; i++) {
            hilos[i].join();
            totales = totales + v[i].puntosdentro;
        }

        time_end = System.currentTimeMillis();

        System.out.println("La solucion es: " + totales / puntos);
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
