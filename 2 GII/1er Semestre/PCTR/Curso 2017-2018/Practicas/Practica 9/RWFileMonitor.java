
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.io.RandomAccessFile;

public class RWFileMonitor {

    private int readers = 0;
    private boolean writing = false;
    private RandomAccessFile fichero;

    public RWFileMonitor() {
        try {
            fichero = new RandomAccessFile("data.dat", "rw");
        } catch (Exception e) {
        }
    }

    /**
     * @param hilo
     */
    public synchronized void StartRead(int hilo) {
        int value = 0;
        while (writing) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        readers = readers + 1;
        System.out.println("Lector " + hilo + " inicia lectura...");
        notifyAll();
        try {
            fichero.seek(fichero.length());
            value = fichero.readInt();
        } catch (Exception e) {
        }
        System.out.println("El lector " + hilo + " ha leido: " + value + "...");
    }

    /**
     * @param hilo
     */
    public synchronized void EndRead(int hilo) {
        readers = readers - 1;
        if (readers == 0) {
            notifyAll();
        }
        System.out.println("Lector " + hilo + " finaliza lectura...");
    }

    /**
     * @param hilo
     * @param value
     */
    public synchronized void StartWrite(int hilo, int value) {
        while (writing || readers != 0) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        writing = true;
        System.out.println("Escritor " + hilo + " inicia escritura...");
        try {
            fichero.seek(fichero.length());
            fichero.writeInt(value);
        } catch (Exception e) {
        }
    }

    /**
     * @param hilo
     */
    public synchronized void EndWrite(int hilo) {
        writing = false;
        notifyAll();
        System.out.println("Escritor " + hilo + " finaliza escritura...");
    }
}
