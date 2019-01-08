/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filoapian;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.io.RandomAccessFile;

public class filoApiAN {
    public static int tenedores[] = new int[5];
    public static Condition ok[] = new Condition[5];

    /**
     * Constructor de filoApiAN
     */
    public filoApiAN(){
        for (int i=0; i<5; ++i) {
            tenedores[i] = 2;
        }
    }

    /**
     * Método para coger tenedores
     * @param i Identificador del tenedor
     */
    public void take_forks(int i){
        while(tenedores[i] != 2){
            try {
                ok[i].await();
            } catch(Exception e) {
                System.out.println("Error en take_forks...");
            }
        }
        tenedores[(i+1)%5]--;
        tenedores[(i-1)%5]--;
    }

    /**
     * Método para soltar tenedores
     * @param i Identificador del tenedor
     */
    public void release_forks(int i){
        tenedores[(i+1)%5]++;
        tenedores[(i-1)%5]++;
        if (tenedores[(i+1)%5] == 2) {
            ok[(i+1)%5].signalAll();
        }
        if (tenedores[(i-1)%5] == 2) {
            ok[(i-1)%5].signalAll();
        }
    }
}
