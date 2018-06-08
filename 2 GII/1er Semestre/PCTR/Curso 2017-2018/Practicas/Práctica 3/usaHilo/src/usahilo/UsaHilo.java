package usahilo;

import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class UsaHilo extends Hilo {

    /**
     * @param tipoHilo
     * @param iteraciones
     */
    public UsaHilo(boolean tipoHilo, int iteraciones) {
        super(tipoHilo, iteraciones);
    }

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Introduce el número de iteraciones:");
        int iteraciones = teclado.nextInt();

        UsaHilo H1 = new UsaHilo(true, iteraciones);
        UsaHilo H2 = new UsaHilo(false, iteraciones);

        H1.start();
        H2.start();

        H1.join();
        H2.join();
        System.out.println(H1.n);
    }

}
