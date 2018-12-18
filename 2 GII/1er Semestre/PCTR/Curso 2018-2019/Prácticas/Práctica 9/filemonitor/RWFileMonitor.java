/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filemonitor;

import java.io.RandomAccessFile;

public class RWFileMonitor{

    private int lectores = 0;
    private boolean escribiendo = false;
    private RandomAccessFile fichero;

    /**
     * Constructor de RWFileMonitor
     */
    public RWFileMonitor(){
        try {
            fichero = new RandomAccessFile("data.dat", "rw");
        } catch(Exception e) {
            System.out.println("Error al abrir el fichero...");
        }
    }

    /**
     * Método para inciar la lectura
     * @param hilo Identificador del hilo que inicia la lectura
     */
    public synchronized void inicioLectura(int hilo){
        int valor = 0;
        while(escribiendo == true){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Fallo en inicioLectura...");
            }
        }
        ++lectores;
        System.out.println("Lector "+hilo+" ha leido "+valor);
    }

    /**
     * Método para finalizar la lectura
     * @param hilo Identificador del hilo que finaliza la lectura
     */
    public synchronized void finLectura(int hilo){
        --lectores;
        while(lectores == 0){
            notifyAll();
        }
        System.out.println("Lector "+hilo+" finaliza su lectura");
    }

    /**
     * Método para inciar la escritua
     * @param hilo  Identificador del hilo que inicia la escritura
     * @param valor Valor que escribirá el hilo
     */
    public synchronized void inicioEscritura(int hilo, int valor){
        while(escribiendo == true || lectores != 0){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en inicioEscritura...");
            }
        }
        escribiendo = true;
        System.out.println("Escritor "+hilo+" inicia su escritura");
        try {
            fichero.seek(fichero.length());
            fichero.writeInt(valor);
        } catch(Exception e) {
            System.out.println("Error al escribir en el fichero...");
        }
    }

    /**
     * Método para finalizar la escritura
     * @param hilo Identificador del hilo que finaliza la escritura
     */
    public synchronized void finEscritura(int hilo){
        escribiendo = false;
        notifyAll();
        System.out.println("Escritor "+hilo+" finaliza su escritura");
    }
}
