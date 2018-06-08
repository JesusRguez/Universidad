
import com.sun.prism.impl.PrismSettings;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class usaFiloApiAn implements Runnable {

    private static filoApiAN monitor = new filoApiAN();

    int tipoHilo;

    /**
     * @param tipoHilo
     */
    public usaFiloApiAn(int tipoHilo) {
        this.tipoHilo = tipoHilo;
    }

    public void run() {
        while (true) {
            monitor.takeForks(this.tipoHilo);
            System.out.println("Hilo " + Thread.currentThread() + " coge los palillos.");
            try {
                Thread.sleep(100);
            } catch (InterruptedException ex) {
                Logger.getLogger(usaFiloApiAn.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("Hilo " + Thread.currentThread() + " suelta los palillos.");
            monitor.releaseForks(this.tipoHilo);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int filosofos = 5;
        ExecutorService pool = Executors.newFixedThreadPool(filosofos);

        for (int i = 0; i < filosofos; i++) {
            pool.execute(new usaFiloApiAn(i));
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);

    }
}
