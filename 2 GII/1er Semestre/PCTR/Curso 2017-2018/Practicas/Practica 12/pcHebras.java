
import java.util.Scanner;

/**
 * @author Jesus Rodriguez Heras
 * @version 1.0
 */
public class pcHebras {

    private static pcMonitor monitor = new pcMonitor(100);
    private static int n_vueltas;

    /**
     */
    static class Productor extends Thread {

        private int id;

        /**
         * @param id Identificador del hilo
         */
        public Productor(int id) {
            this.id = id;
        }

        @Override
        public void run() {
            int valor;
            for (int i = 0; i < n_vueltas; i++) {
                try {
                    valor = (int) (Math.random() * 10);
                    monitor.insertar(id, valor);
                } catch (Exception e) {
                }
            }
        }
    }

    /**
     */
    static class Consumidor extends Thread {

        private int id;

        /**
         * @param id Identificador del hilo
         */
        public Consumidor(int id) {
            this.id = id;
        }

        @Override
        public void run() {
            int valor;
            for (int i = 0; i < n_vueltas; i++) {
                try {
                    monitor.extraer(id);
                } catch (Exception e) {
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce el numero de vueltas:");
        n_vueltas = teclado.nextInt();
        long time = System.currentTimeMillis();
        Productor[] productores = new Productor[5];
        Consumidor[] consumidores = new Consumidor[5];
        for (int i = 0; i < 5; i++) {
            productores[i] = new Productor(i);
            consumidores[i] = new Consumidor(i);
            productores[i].start();
            consumidores[i].start();
        }
        for (int i = 0; i < 5; i++) {
            productores[i].join();
            consumidores[i].join();
        }
        time = System.currentTimeMillis() - time;
        System.out.println("Ejecución finalizada en " + (double) time / 1000 + " segundos.");
    }
}
