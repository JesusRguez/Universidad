package usalectorescritor;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class lectorEscritor {

    private int n;
    private boolean escribiendo;

    public lectorEscritor() {
        n = 0;
        escribiendo = false;
    }

    /**
     * @param i Identificador del hilo
     */
    public synchronized void inicia_lectura() {
        while (escribiendo) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        n++;
        notifyAll();
    }

    /**
     * @param i Identificador del hilo
     */
    public synchronized void fin_lectura() {
        n--;
        notifyAll();
    }

    /**
     * @param i Identificador del hilo
     */
    public synchronized void inicia_escritura() {
        while (n > 0 || escribiendo) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
            notifyAll();
        }
        escribiendo = true;
    }

    /**
     * @param i Identificador del hilo
     */
    public synchronized void fin_escritura() {
        escribiendo = false;
        notifyAll();
    }
}
