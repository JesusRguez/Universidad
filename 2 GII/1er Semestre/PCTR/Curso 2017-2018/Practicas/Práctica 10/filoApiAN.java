
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.concurrent.locks.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class filoApiAN {

    private int[] fork = new int[5];
    private ReentrantLock lock;
    Condition[] OktoEat = new Condition[5];

    public filoApiAN() {
        fork = new int[5];
        lock = new ReentrantLock();

        for (int i = 0; i < fork.length; i++) {
            fork[i] = 2;
        }
        for (int i = 0; i < OktoEat.length; i++) {
            OktoEat[i] = lock.newCondition();
        }
    }

    /**
     * @param i
     */
    public void takeForks(int i) {
        lock.lock();

        while (fork[i] != 2) {
            try {
                OktoEat[i].await();
            } catch (InterruptedException ex) {
                Logger.getLogger(filoApiAN.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        fork[(i + 1) % 5]--;
        fork[(i + 5 - 1) % 5]--;
        //System.out.println(fork[0] + " - " + fork[1] + " - " + fork[2] + " - " + fork[3] + " - " + fork[4]);
        lock.unlock();
    }

    /**
     * @param i
     */
    public void releaseForks(int i) {
        lock.lock();
        fork[(i + 1) % 5]++;
        fork[(i + 5 - 1) % 5]++;
        if (fork[(i + 1) % 5] == 2) {
            OktoEat[(i + 1) % 5].signalAll();
        }
        if (fork[(i + 5 - 1) % 5] == 2) {
            OktoEat[(i + 5 - 1) % 5].signalAll();
        }
        lock.unlock();
    }
}
