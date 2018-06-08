
import java.util.concurrent.locks.*;
import java.util.ArrayList;

/**
 * @author Jesus Rodriguez Heras
 * @version 1.0
 */
public class pcMonitor {

    private final ReentrantLock cerrojo = new ReentrantLock();
    private final Condition not_empty = cerrojo.newCondition();
    private final Condition not_full = cerrojo.newCondition();
    private ArrayList<Integer> buffer;
    private int capacidad;

    /**
     * @param capacidad Capacidad del buffer
     */
    public pcMonitor(int capacidad) {
        buffer = new ArrayList<Integer>();
        this.capacidad = capacidad;
    }

    /**
     * @param id Identificador del hilo
     * @param valor Valor a insertar
     */
    public void insertar(int id, int valor) throws Exception {
        cerrojo.lock();
        try {
            while (buffer.size() == capacidad) {
                not_full.await();
            }
            buffer.add(valor);
            not_empty.signal();
        } finally {
            cerrojo.unlock();
        }
    }

    /**
     * @param id Identificador del hilo
     * @return Valor extraido
     */
    public int extraer(int id) throws Exception {
        int valor = 0;
        cerrojo.lock();
        try {
            while (buffer.size() == 0) {
                not_empty.await();
            }
            valor = buffer.get(0);
            buffer.remove(0);
            not_full.signal();
            return valor;
        } finally {
            cerrojo.unlock();
        }
    }
}
