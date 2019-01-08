/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filemonitor;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.io.RandomAccessFile;

public class RWMonitorAN {

    private int readers = 0;
    private boolean writing = false;
    private RandomAccessFile fichero;

    ReentrantLock L = new ReentrantLock();

    Condition lector = L.newCondition();
    Condition escritor = L.newCondition();

    /**
     * Constructor de RWMonitorAN
     */
    public RWMonitorAN() {
        try {
            fichero = new RandomAccessFile("data.dat", "rw");
        } catch (Exception e) {
        }
    }

    /**
     * Método StartRead
     * @param hilo Identificador del hilo que empieza a leer
     */
    synchronized void StartRead(int hilo) {
        L.lock();
        int value = 0;
        while (!writing) {
            try {
                lector.await();
            } catch (InterruptedException e) {
            }
        }
        readers = readers + 1;
        System.out.println("Lector inicia lectura...");
        try {
            fichero.seek(fichero.length());
            value = fichero.readInt();
        } catch (Exception e) {
        }
        System.out.println("El lector " + hilo + " ha leido: " + value + "...");
        L.unlock();
    }

    /**
     * Método EndRead
     * @param hilo Identificador del hilo que termina de leer
     */
    synchronized void EndRead(int hilo) {
        L.lock();
        readers = readers - 1;
        if (readers == 0) {
            escritor.signalAll();
        }
        System.out.println("Lector finaliza lectura...");
        L.unlock();
    }

    /**
     * Método StartWrite
     * @param hilo  Identificador del hilo que empieza a escribir
     * @param value Valor que escribde dicho hilo
     */
    synchronized void StartWrite(int hilo, int value) {
        L.lock();
        while (!(writing || (readers != 0))) {
            try {
                escritor.await();
            } catch (InterruptedException e) {
            }
        }
        writing = true;
        System.out.println("Escritor inicia escritura...");
        try {
            fichero.seek(fichero.length());
            fichero.writeInt(value);
        } catch (Exception e) {
        }
        L.unlock();
    }

    /**
     * Método EndWrite
     * @param hilo Identificador del hilo que termina de escribir
     */
    synchronized void EndWrite(int hilo) {
        L.lock();
        writing = false;
        lector.signalAll();
        System.out.println("Escritor finaliza escritura...");
        L.unlock();
    }
}
