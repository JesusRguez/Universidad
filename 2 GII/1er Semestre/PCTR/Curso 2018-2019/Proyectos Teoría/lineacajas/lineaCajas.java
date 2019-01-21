package lineacajas;

import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

public class lineaCajas{
    private int c, clientes;
    private ReentrantLock l = new ReentrantLock();
    private boolean[] libre= new boolean[20];
    private Condition cajas;

    public lineaCajas(){
        cajas = l.newCondition();
        for (int i=0; i<20; ++i) {
            libre[i] = true;
        }
        clientes = 10;
    }

    public int take_client(){
        l.lock();
        while(clientes==0){
            try {
                cajas.await();
            } catch(Exception e) {
                System.out.println("Error en take_client...");
            }
        }
        c = 1;
        while (!libre[c]) {
            c++;
        }
        libre[c] = false;
        clientes--;
        l.unlock();
        return c;
    }

    public void drop_client(int c){
        l.lock();
        libre[c] = true;
        clientes++;
        cajas.signal();
        l.unlock();
    }
}
