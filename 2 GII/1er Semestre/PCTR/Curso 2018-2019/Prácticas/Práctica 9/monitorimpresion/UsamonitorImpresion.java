/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorimpresion;

public class UsamonitorImpresion implements Runnable {

    public static monitorImpresion monitor = monitorImpresion(3);
    public int impresora;

    /**
     * Constructor vacío de UsamonitorImpresion
     */
    public UsamonitorImpresion(){}

    public void run(){
        impresora = monitor.take_print();
        System.out.println("Impreso");
        monitor.drop_print(impresora);
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[(int) (Runtime.getRuntime().availableProcessors() / (1-0.5))];
        for (int i=0; i<hilos.length; ++i) {
            hilos[i] = new Thread(new UsamonitorImpresion());
            hilos[i].start();
        }
        for (int i=0; i<hilos.length; ++i) {
            hilos[i].join();
        }
    }
}
