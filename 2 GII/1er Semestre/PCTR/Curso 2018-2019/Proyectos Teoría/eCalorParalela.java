// -100 - 100
// 1000*1000
// centro = 20*20 estará a 50grados
// bordes a 10050grados y el resto a 00grados
//

import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.ReentrantLock;

public class eCalorParalela implements Runnable{

    public static double cuerpo[][] = new double[1000][1000];
    public static Scanner teclado = new Scanner(System.in);
    public static ReentrantLock l = new ReentrantLock();
    public int id;
    public int opcion;
    public int h;
    public static int a;
    public static int b;
    public static double borde;
    public static double centro;
    public static double resto;

    public eCalorParalela(int id, int opcion, int h){
        this.id = id;
        this.opcion = opcion;
        this.h = h;
    }

    public void run(){
        int rango, inicio, fin;
        switch (opcion) {
            case 1:
                rango = 1000/h;
                inicio = id*rango;
                fin = inicio+rango-1;
                l.lock();
                procesarCuerpo(inicio, fin);
                l.unlock();
            break;
            case 2:
                rango = a/h;
                inicio = id*rango;
                fin = inicio+rango-1;
                l.lock();
                determinarDimension(inicio, fin);
                l.unlock();
            break;
        }
    }

    public static void procesarCuerpo(int inicio, int fin){
        for (int i=inicio; i<fin; ++i) {
            for (int j=0; j<1000; ++j) {
                cuerpo[i][j] = 0;
                if (i==0 || i == 999) {
                    cuerpo[i][j] = 100;
                }
                if (j==0 || j==999) {
                    cuerpo[i][j] = 100;
                }
            }
        }
        for (int i=490; i<510; ++i) {
            for (int j=490; j<510; ++j) {
                cuerpo[i][j] = 50;
            }
        }
    }

    public static void determinarDimension(int inicio, int fin){
        int centro1 = a/2;
        int centro1l = centro1 - 10;
        int centro1r = centro1 + 10;
        int centro2 = b/2;

        for (int i=0; i<a; ++i) {
            for (int j=0; j<b; ++j) {
                cuerpo[i][j] = resto;
                if (i==0 || i == a-1) {
                    cuerpo[i][j] = borde;
                }
                if (j==0 || j==b-1) {
                    cuerpo[i][j] = borde;
                }
            }
        }
        for (int i=centro1l; i<centro1r; ++i) {
            if (centro1l >= inicio && centro1r <fin) {
                for (int j=centro2 - 10; j<centro2 + 10; ++j) {
                    cuerpo[i][j] = centro;
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int opcion;
        do {
            System.out.println("Introduzca la opción que desea:\n1. Procesar cuerpo de 1000x1000\n2. Determinar dimensión");
            opcion = teclado.nextInt();
            if (opcion < 1 || opcion > 2) {
                System.out.println("Introduzca una opción válida");
            }
        } while (opcion < 1 || opcion > 2);

        if (opcion == 2) {
            System.out.print("Introduzca las dimensiones de la matriz:\nLado 1: ");
            int a = teclado.nextInt();
            System.out.print("Lado 2: ");
            int b = teclado.nextInt();
            System.out.print("Introduzca la temperatura el borde: ");
            double borde = teclado.nextDouble();
            System.out.print("Introduzca la temperatura del centro: ");
            double centro = teclado.nextDouble();
            System.out.print("Introduzca la temperatura del resto del cuerpo: ");
            double resto = teclado.nextDouble();
        }

        int h = Runtime.getRuntime().availableProcessors();
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        for (int i=0; i<h; ++i) {
            ejecutor.execute(new eCalorParalela(i, opcion, h));
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
    }
}
