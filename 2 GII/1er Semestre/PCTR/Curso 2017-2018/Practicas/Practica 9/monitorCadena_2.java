
/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
public class monitorCadena_2 {

    int readers = 0;
    boolean writing = false;
    int max_elem = 50;
    int n_elem = 0;

    synchronized void StartRead() {
        while (writing || n_elem == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        readers = readers + 1;
        n_elem--;
        notifyAll();
    }

    synchronized void EndRead() {
        readers = readers - 1;
        if (readers == 0) {
            notifyAll();
        }
    }

    synchronized void StartWrite() {
        while ((writing || (readers != 0)) || n_elem == max_elem) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        n_elem++;
        writing = true;
    }

    synchronized void EndWrite() {
        writing = false;
        notifyAll();
    }
}
