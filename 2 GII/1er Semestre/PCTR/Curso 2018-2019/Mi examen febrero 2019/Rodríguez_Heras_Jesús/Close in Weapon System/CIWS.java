/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

public class CIWS{

    private ReentrantLock l = new ReentrantLock();
    private Condition disparo;
    private boolean[] libre;
    private int estaciones, n;

    /**
     * Constructor de CIWS
     */
    public CIWS(){
        this.estaciones = 16;
        disparo = l.newCondition();
        libre = new boolean[16];
        for (int i=0; i<16; ++i) {
            libre[i] = true;
        }
    }

    /**
     * Método ocupada
     * @return Retorna la estacion que está ocupada
     */
    public int ocupada(){
        l.lock();
        while(estaciones == 0){
            try {
                disparo.await();
            } catch(Exception e) {
                System.out.println("Error en take_print...");
            }
        }
        n = 1;
        while (!libre[n]) {
            n++;
        }
        libre[n] = false;
        estaciones--;
        l.unlock();
        return n;
    }

    /**
     * Método liberada
     * @param n Libera la estacion indicada
     */
    public void liberada(int n){
        l.lock();
        libre[n] = true;
        estaciones++;
        disparo.signal();
        l.unlock();
    }
}
