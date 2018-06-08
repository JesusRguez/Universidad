
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.io.RandomAccessFile;

/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
class RWMonitorAN {

    private int readers = 0;
    private boolean writing = false;
    private RandomAccessFile fichero;

    ReentrantLock L;

    Condition lector = L.newCondition(), escritor = L.newCondition();

    public RWMonitorAN() {
        try {
            fichero = new RandomAccessFile("data.dat", "rw");
        } catch (Exception e) {
        }
    }

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
        notifyAll();
        try {
            fichero.seek(fichero.length());
            value = fichero.readInt();
        } catch (Exception e) {
        }
        System.out.println("El lector " + hilo + " ha leido: " + value + "...");
        L.unlock();
    }

    synchronized void EndRead(int hilo) {
        L.lock();
        readers = readers - 1;
        if (readers == 0) {
            escritor.signalAll();
        }
        System.out.println("Lector finaliza lectura...");
        L.unlock();
    }

    synchronized void StartWrite(int hilo, int value) {
        L.lock();
        while (!(writing || (readers != 0))) {
            try {
                lector.await();
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

    synchronized void EndWrite(int hilo) {
        L.lock();
        writing = false;
        lector.signalAll();
        System.out.println("Escritor finaliza escritura...");
        L.unlock();
    }
}
