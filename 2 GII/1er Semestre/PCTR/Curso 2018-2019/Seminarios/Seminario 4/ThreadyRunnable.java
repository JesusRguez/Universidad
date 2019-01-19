
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
public class ThreadyRunnable extends Thread { //implements Runnable{

    private int id, nveces, n = 0;

    public ThreadyRunnable(int i) {
        this.id = i;
    }

    public void run() {
        for (int i = 0; i < nveces; i++) {
            if (i % 10 == 0) {
                try {
                    Thread.currentThread().sleep(1000);
                } catch (InterruptedException ex) {
                    Logger.getLogger(ThreadyRunnable.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            n = n + 1;
        }
        System.out.println("Soy el hilo " + id);
    }

    public static void main(String[] args) {
        //ThreadyRunnable h1 = new ThreadyRunnable(1);
        //h1.start();

        Thread hilos[] = new Thread[10];
        for (int i = 0; i < 10; i++) {
            hilos[i] = new Thread(new ThreadyRunnable(i));
            hilos[i].setPriority(i + 1);
            hilos[i].start();
        }
    }
}
