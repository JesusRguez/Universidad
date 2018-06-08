
/**
 * @author Jesus Rodríguez Heras
 * @ver 1.0
 */
public class monitorImpresion {

    private int impresoras;
    //libre de 0 a 2
    private boolean libre[] = new boolean[3];

    public synchronized int take_print() {
        int n;
        while (impresoras == 0) {
            try {
                wait();
            } catch (InterruptedException ex) {
            }
        }
        n = 0;
        while (!libre[n]) {
            n++;
        }
        libre[n] = false;
        impresoras--;
        return n;
    }

    /**
     * @param n
     */
    public synchronized void release_print(int n) {
        libre[n] = true;
        impresoras++;
        notifyAll();
    }

    public monitorImpresion(int n) {
        for (int i = 0; i < n; i++) {
            libre[i] = true;
        }
        this.impresoras = n;
    }

}
