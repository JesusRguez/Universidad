import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class monitorSem{
    private int s;
    private ReentrantLock L;
    private Condition operando;

    public monitorSem(int sem){
        L = new ReentrantLock();
        operando = L.newCondition();
        s = sem;
    }

    public synchronized void waitSem(){
        L.lock();
        while (s > 0) {
            try {
                operando.await();
            } catch(Exception e) {
                System.out.println("Error en waitSem...");
            }
            s--;
        }
        L.unlock();
    }

    public synchronized void signalSem(){
        L.lock();
        operando.signalAll();
        s++;
        L.unlock();
    }
}
