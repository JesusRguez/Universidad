package filoapian;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class filoApiAN {
    private int tenedores[] = new int[5];
    private Condition ok[] = new Condition[5];
    private ReentrantLock L;

    public filoApiAN(){
        L = new ReentrantLock();
        for (int i=0; i<5; ++i) {
            tenedores[i] = 2;
            ok[i] = L.newCondition();
        }
    }

    public void take_forks(int i){
        L.lock();
        while (tenedores[i] != 2) {
            try {
                ok[i].await();
            } catch(Exception e) {
                System.out.println("Error en take_forks...");
            }
        }
        tenedores[(i+1)%5]--;
        tenedores[(i+5-1)%5]--;
        L.unlock();
    }

    public void release_forks(int i){
        L.lock();
        tenedores[(i+1)%5]++;
        tenedores[(i+5-1)%5]++;
        if (tenedores[(i+1)%5] == 2) {
            ok[(i+1)%5].signalAll();
        }
        if (tenedores[(i+5-1)%5] == 2) {
            ok[(i+5-1)%5].signalAll();
        }
        L.unlock();
    }
}
