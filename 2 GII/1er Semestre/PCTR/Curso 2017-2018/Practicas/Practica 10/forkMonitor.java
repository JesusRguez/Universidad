//POSIBLE MODELO DE MONITOR PARA EL PROBLEMA DE LOS FILOSOFOS
//API JAVA UTIIZADO: ALTO NIVEL

import java.util.concurrent.*;
import java.util.concurrent.locks.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class forkMonitor {

    private int[] fork = new int[5];
    private ReentrantLock lock;
    Condition[] OktoEat = new Condition[5];

    public forkMonitor() {
        fork = new int[5];
        lock = new ReentrantLock();

        for (int i = 0; i < fork.length; i++) {
            fork[i] = 2;
        }
        for (int i = 0; i < OktoEat.length; i++) {
            OktoEat[i] = lock.newCondition();
        }
    }

    public void takeForks(int i) {
        lock.lock();
        while (fork[i] != 2) {
            try {
                OktoEat[i].await();
            } catch (InterruptedException ex) {
                Logger.getLogger(forkMonitor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        fork[(i + 1) % 5] = fork[(i + 5 - 1) % 5]--;
        fork[(i + 1) % 5] = fork[(i + 5 - 1) % 5]--;
        lock.unlock();
    }

    public void releaseForks(int i) {
        lock.lock();
        fork[(i + 1) % 5] = fork[(i + 1) % 5]++;
        fork[(i + 1) % 5] = fork[(i + 1) % 5]++;
        if (fork[(i + 1) % 5] == 2) {
            OktoEat[(i + 1) % 5].signalAll();
        }
        if (fork[(i + 5 - 1) % 5] == 2) {
            OktoEat[(i + 5 - 1) % 5].signalAll();
        }
        lock.unlock();
    }
}
