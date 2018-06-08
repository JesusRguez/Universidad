
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class drakkarVikingo {

    private int marmita;

    public synchronized void comer() {
        while (marmita == 0) {
            notifyAll();
            try {
                wait();
            } catch (InterruptedException ex) {
            }
        }
        marmita--;
    }

    public synchronized void llenar_marmita() {
        while (marmita > 0) {
            try {
                wait();
            } catch (InterruptedException ex) {
            }
            marmita = 10;
            notifyAll();
        }
    }

    public drakkarVikingo(int marmita) {
        this.marmita = marmita;
    }
}
