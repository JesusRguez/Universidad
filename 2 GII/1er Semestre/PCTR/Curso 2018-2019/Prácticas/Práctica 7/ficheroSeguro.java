/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.io.*;
import java.util.*;

public class ficheroSeguro implements Runnable{
    public static int n;
    public Object lock;
    public int desplazamiento;
    public String cadena;

    public ficheroSeguro(int n, Object l, String cadena, int desplazamiento){
        this.n = n;
        this.lock = l;
        this.desplazamiento = desplazamiento;
        this.cadena = cadena;
    }

    public synchronized void run(){
        //synchronized(lock){
            try{
                RandomAccessFile fichero = new RandomAccessFile("fichero.txt", "rw");
                try {
                    fichero.seek(desplazamiento);
                    fichero.writeUTF(cadena);
                    fichero.close();
                }catch(IOException ex){
                    System.out.println("Fallo al escribir en el fichero.");
                }
            }catch (FileNotFoundException e) {
                System.out.println("Fallo al abrir el fichero.");
            }
        //}
    }

    public static void main(String[] args) throws InterruptedException {
        int n = 4;
        int desplazamiento = 0;
        Scanner teclado = new Scanner(System.in);

        System.out.println("A continuación va a escribir 4 cadenas en un fichero de forma paralela por exlusión mutua:");
        System.out.println("Introduce la cadena 1:");
        String cadena1 = teclado.nextLine();
        System.out.println("Introduce la cadena 2:");
        String cadena2 = teclado.nextLine();
        System.out.println("Introduce la cadena 3:");
        String cadena3 = teclado.nextLine();
        System.out.println("Introduce la cadena 4:");
        String cadena4 = teclado.nextLine();

        Object lock = new Object();

        Thread a = new Thread(new ficheroSeguro(n, lock, cadena1, desplazamiento));
        desplazamiento += 2*cadena1.length();
        Thread b = new Thread(new ficheroSeguro(n, lock, cadena2, desplazamiento));
        desplazamiento += 2*cadena2.length();
        Thread c = new Thread(new ficheroSeguro(n, lock, cadena3, desplazamiento));
        desplazamiento += 2*cadena3.length();
        Thread d = new Thread(new ficheroSeguro(n, lock, cadena4, desplazamiento));

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
