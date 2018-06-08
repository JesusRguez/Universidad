package usahilo;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Hilo extends Thread {

    public static int n = 0, nVueltas;
    public boolean tipoHilo;

    /**
     * @param tipoHilo
     * @param nVueltas
     */
    Hilo(boolean tipoHilo, int nVueltas) {
        this.tipoHilo = tipoHilo;
        this.nVueltas = nVueltas;
    }

    public void run() {

        if (tipoHilo == true) {
            for (int i = 0; i < nVueltas; i++) {
                n++;
            }
        } else {
            for (int i = 0; i < nVueltas; i++) {
                n--;
            }
        }
    }
}
