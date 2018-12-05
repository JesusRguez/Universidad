/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package lectorescritor;

public class lectorEscritor{

    private int n;
    private boolean escribiendo;

    public lectorEscritor(){
        n = 0;
        escribiendo = false;
    }

    public synchronized void inicia_lectura(){
        while(escribiendo){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Fallo en inicia_lectura...");
            }
        }
        ++n;
        notifyAll();
    }

    public synchronized void fin_lectura(){
        --n;
        while(n == 0){
            notifyAll();
        }
    }

    public synchronized void inicia_escritura(){
        while(n!=0 || escribiendo == true){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Fallo en inicia_escritura...");
            }
        }
        escribiendo = true;
    }

    public synchronized void fin_escritura(){
        escribiendo = false;
        notifyAll();
    }
}
