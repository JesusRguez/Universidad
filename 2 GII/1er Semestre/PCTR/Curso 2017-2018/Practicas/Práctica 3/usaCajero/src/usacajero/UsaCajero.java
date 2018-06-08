package usacajero;

import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class UsaCajero extends Cajero implements Runnable {

    public int tipoOperacion, id;
    public double cantidad;

    /**
     * @param tipoOperacion
     * @param id
     * @param cantidad
     */
    UsaCajero(int tipoOperacion, int id, double cantidad) {
        super();
        this.tipoOperacion = tipoOperacion;
        this.id = id;
        this.cantidad = cantidad;
    }

    public static Scanner teclado = new Scanner(System.in);

    public void run() {//int id, int tipoOperacion, double cantidad

        switch (tipoOperacion) {
            case 0:
                deposito(id, cantidad);
                break;
            case 1:
                reintegro(id, cantidad);
                break;
            default:
                System.out.println("Introduce un tipo de operación válido.");
                break;
        }
    }

    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
        Thread hilo1 = new Thread(new UsaCajero(0, 1, 100));
        Thread hilo2 = new Thread(new UsaCajero(1, 2, 100));
        Thread hilo3 = new Thread(new UsaCajero(1, 1, 1200));
        Thread hilo4 = new Thread(new UsaCajero(0, 2, 500));

        hilo1.start();
        hilo2.start();
        hilo3.start();
        hilo4.start();

        hilo1.join();
        hilo2.join();
        hilo3.join();
        hilo4.join();
    }
}
