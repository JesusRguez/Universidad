
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.*;

public class intParaleloFutureCont implements Callable {

    Long puntosdentro = new Long(0);
    double puntos;

    /**
     * @param puntos
     */
    public intParaleloFutureCont(double puntos) {
        this.puntos = puntos;
    }

    public Long call() {
        double x, y;
        Random r = new Random();
        for (int i = 0; i < puntos; i++) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (Math.sin(x) >= y) {

                puntosdentro++;

            }
        }
        return puntosdentro;
    }

    public static void main(String[] args) throws InterruptedException, ExecutionException {
        int nhilos = 4;
        double puntos;
        int totaldentro = 0;

        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce el número de puntos:");
        puntos = teclado.nextDouble();

        ArrayList<Future<Long>> contParciales = new ArrayList<Future<Long>>();

        long time_start, time_end;
        time_start = System.currentTimeMillis();

        ThreadPoolExecutor ept = new ThreadPoolExecutor(
                nhilos,
                nhilos,
                0L,
                TimeUnit.MILLISECONDS,
                new LinkedBlockingQueue<Runnable>());
        for (int i = 0; i < nhilos; i++) {
            contParciales.add(ept.submit(
                    new intParaleloFutureCont(puntos / nhilos)));
        }
        for (Future<Long> iterador : contParciales) {
            try {
                totaldentro += iterador.get();
            } catch (CancellationException e) {
            } catch (ExecutionException e) {
            } catch (InterruptedException e) {
            }
        }

        ept.shutdown();

        time_end = System.currentTimeMillis();

        System.out.println("La solucion es: " + (double) totaldentro / puntos);
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
