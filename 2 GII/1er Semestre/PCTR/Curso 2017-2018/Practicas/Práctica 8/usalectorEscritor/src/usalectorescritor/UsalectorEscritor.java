package usalectorescritor;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import static java.lang.Thread.sleep;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class UsalectorEscritor extends Thread {

    private static final lectorEscritor monitor = new lectorEscritor();

    static RandomAccessFile fichero;

    private int tipoHilo;

    public UsalectorEscritor(int tipoHilo) {
        this.tipoHilo = tipoHilo;
    }

    public void run() {
        switch (tipoHilo) {
            case 1:
                while (true) {
                    try {
                        monitor.inicia_lectura();
                        sleep(1000);
                        try {
                            fichero.seek(0);
                            System.out.println(fichero.readLine());
                        } catch (IOException ex) {
                        }
                        monitor.fin_lectura();
                        sleep(500);
                    } catch (InterruptedException ex) {
                    }
                }

            case 2:
                while (true) {
                    try {
                        monitor.inicia_escritura();
                        sleep(1000);
                        try {
                            fichero.getFilePointer();
                            fichero.writeChars("Escribiendo en fichero\n");
                        } catch (IOException ex) {
                        }
                        monitor.fin_escritura();
                        sleep(500);
                    } catch (InterruptedException ex) {
                    }
                }

        }
    }

    public static void main(String[] args) throws InterruptedException, IOException {
        try {
            fichero = new RandomAccessFile("datos.txt", "rw");
        } catch (FileNotFoundException ex) {
        }

        UsalectorEscritor[] personas = new UsalectorEscritor[10];
        personas[0] = new UsalectorEscritor(1);

        for (int i = 1; i < 10; i++) {
            personas[i] = new UsalectorEscritor(2);

        }
        for (int i = 0; i < 10; i++) {
            personas[i].start();
        }

        for (int i = 0; i < 10; i++) {
            personas[i].join();
        }
        fichero.close();
    }
}
