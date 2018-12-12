/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package lectorescritor;

public class lectorEscritor{

    private int n;
    private boolean escribiendo;

    /**
     * Constructor del monitor lectorEscritor
     */
    public lectorEscritor(){
        n = 0;
        escribiendo = false;
    }

    /**
     * Método para iniciar la lectura
     */
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

    /**
     * Método para finalizar la lectura
     */
    public synchronized void fin_lectura(){
        --n;
        while(n == 0){
            notifyAll();
        }
    }

    /**
     * Método para inciar la escritura
     */
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

    /**
     * Método para finalizar la escritura
     */
    public synchronized void fin_escritura(){
        escribiendo = false;
        notifyAll();
    }
}
