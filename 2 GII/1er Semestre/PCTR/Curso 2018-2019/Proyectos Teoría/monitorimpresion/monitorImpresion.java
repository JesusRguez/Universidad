package monitorimpresion;

import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

public class monitorImpresion{
    private int n, impresoras;
    private boolean[] libre = new boolean[3];
    private ReentrantLock l = new ReentrantLock();
    private Condition imp;

    public monitorImpresion(){
        imp = l.newCondition();
        for (int i=0; i<3; ++i) {
            libre[i] = true;
        }
        impresoras = 3;
    }

    public int take_print(){
        l.lock();
        while(impresoras == 0){
            try {
                imp.await();
            } catch(Exception e) {
                System.out.println("Error en take_print...");
            }
        }
        n = 1;
        while (!libre[n]) {
            n++;
        }
        libre[n] = false;
        impresoras--;
        l.unlock();
        return n;
    }

    public void drop_print(int n){
        l.lock();
        libre[n] = true;
        impresoras++;
        imp.signal();
        l.unlock();
    }
}
