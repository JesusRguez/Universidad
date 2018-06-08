
/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
public class usaMonitorImpresion implements Runnable {

    public static monitorImpresion monitor = new monitorImpresion(3);
    public int impresora;

    public usaMonitorImpresion() {
    }

    public void run() {
        impresora = monitor.take_print();
        System.out.println("Impreso.");
        monitor.release_print(impresora);
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[(int) (Runtime.getRuntime().availableProcessors() / (1 - 0.5))];
        for (int i = 0; i < hilos.length; i++) {
            hilos[i] = new Thread(new usaMonitorImpresion());
        }
        for (int i = 0; i < hilos.length; i++) {
            hilos[i].start();
        }
        for (int i = 0; i < hilos.length; i++) {
            hilos[i].join();
        }
    }
}
