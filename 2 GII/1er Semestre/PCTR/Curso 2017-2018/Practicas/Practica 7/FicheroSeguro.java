
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class FicheroSeguro implements Runnable {

    static int n;
    int offset;
    String cadena;
    Object o;

    /**
     * @param n
     * @param cadena
     * @param p
     * @param offset
     */
    public FicheroSeguro(int n, String cadena, Object p, int offset) {
        this.n = n;
        this.cadena = cadena;
        this.offset = offset;
        o = p;
    }

    public void run() {
        synchronized (o) {
            try {
                RandomAccessFile fichero = new RandomAccessFile("fichero.txt", "rw");

                try {
                    fichero.seek(offset);
                    fichero.writeChars(cadena);
                } catch (IOException ex) {
                }

            } catch (FileNotFoundException ex) {
            }
        }

    }

    public static void main(String[] args) throws InterruptedException {
        int n = 4;
        int desplazamiento = 0;
        Scanner teclado = new Scanner(System.in);

        System.out.println("Introduce la cadena 1:");
        String cadena1 = teclado.nextLine();
        System.out.println("Introduce la cadena 2:");
        String cadena2 = teclado.nextLine();
        System.out.println("Introduce la cadena 3:");
        String cadena3 = teclado.nextLine();
        System.out.println("Introduce la cadena 4:");
        String cadena4 = teclado.nextLine();

        Object o = new Object();

        Thread a = new Thread(new FicheroSeguro(n, cadena1, o, 0));
        desplazamiento = desplazamiento + 2 * cadena1.length();
        System.out.println(desplazamiento);
        Thread b = new Thread(new FicheroSeguro(n, cadena2, o, desplazamiento));
        desplazamiento = desplazamiento + 2 * cadena2.length();
        System.out.println(desplazamiento);
        Thread c = new Thread(new FicheroSeguro(n, cadena3, o, desplazamiento));
        desplazamiento = desplazamiento + 2 * cadena3.length();
        System.out.println(desplazamiento);
        Thread d = new Thread(new FicheroSeguro(n, cadena4, o, desplazamiento));

        a.start();
        b.start();
        c.start();
        d.start();

        a.join();
        b.join();
        c.join();
        d.join();

    }
}
