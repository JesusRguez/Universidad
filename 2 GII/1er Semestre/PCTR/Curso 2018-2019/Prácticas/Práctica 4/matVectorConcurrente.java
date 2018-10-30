/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.lang.*;

public class matVectorConcurrente implements Runnable{
    static double[][] m;
    static double[] v;
    static double[] res;
    static int filas, columnas, tvector;
    int filaControl;

    public matVectorConcurrente(int filas, int columnas, int tvector, double[][] matriz, double[] vector, int filaControl){
        matVectorConcurrente.filas = filas;
        matVectorConcurrente.columnas = columnas;
        matVectorConcurrente.tvector = tvector;
        matVectorConcurrente.m = matriz;
        matVectorConcurrente.v = vector;
        this.filaControl = filaControl;
        matVectorConcurrente.res = new double[tvector];
        for (int i=0; i<tvector; ++i) {
            res[i] = 0;
        }
    }

    public void run(){
        for (int i=0; i<columnas; ++i) {
            res[filaControl] += m[filaControl][i] * v[i];
        }
    }

    public static void imprimeVector(double[] v){
        for (int i=0; i<v.length; ++i) {
            System.out.print(v[i]+"   ");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        int opcion;
        Thread[] hilos;
        long time_start, time_end;
        do {
            System.out.println("Introduzca la opción que desea:\n1. Introducir datos manualmente\n2. Introducir solo las dimensiones");
            opcion = teclado.nextInt();
            switch(opcion){
                case 1:
                    do {
                        System.out.println("Introduzca las filas de la matriz");
                        filas = teclado.nextInt();
                        System.out.println("Introduzca las columnas de la matriz");
                        columnas = teclado.nextInt();
                        System.out.println("Introduzca el tamaño del vector");
                        tvector = teclado.nextInt();
                        if(columnas != tvector){
                            System.out.println("El número de columnas y el tamaño del vector debe coincidir.");
                        }
                    } while (columnas != tvector);

                    m = new double[filas][columnas];
                    System.out.println("Introduzca los valores de la matriz:");
                    for (int i=0; i<filas; ++i) {
                        for (int j=0; j<columnas; ++j) {
                            System.out.println("Introduzca el valor de la coordenada ("+i+", "+j+"):");
                            m[i][j] = teclado.nextDouble();
                        }
                    }

                    v = new double[tvector];
                    System.out.println("Introduzca los valores del vecotr:");
                    for (int i=0; i<tvector; ++i) {
                        System.out.println("Introduzca el valor de la coordenada "+i+":");
                        v[i] = teclado.nextDouble();
                    }

                    res = new double[tvector];

                    hilos = new Thread[filas];
                    time_start = System.currentTimeMillis();
                    for (int i=0; i<filas; ++i) {
                        hilos[i] = new Thread(new matVectorConcurrente(filas, columnas, tvector, m, v, i));
                        hilos[i].start();
                    }
                    for (int i=0; i<filas; ++i) {
                        hilos[i].join();
                    }
                    time_end = System.currentTimeMillis();
                    imprimeVector(res);
                    System.out.println("\nHa tardado "+(time_end - time_start)/(double)1000+" segundos");
                    break;
                case 2:
                    do {
                        System.out.println("Introduzca las filas de la matriz");
                        filas = teclado.nextInt();
                        System.out.println("Introduzca las columnas de la matriz");
                        columnas = teclado.nextInt();
                        System.out.println("Introduzca el tamaño del vector");
                        tvector = teclado.nextInt();
                        if(columnas != tvector){
                            System.out.println("El número de columnas y el tamaño del vector debe coincidir,");
                        }
                    } while (columnas != tvector);
                    Random r = new Random();
                    m = new double[filas][columnas];
                    for (int i=0; i<filas; ++i) {
                        for (int j=0; j<columnas; ++j) {
                            m[i][j] = r.nextDouble()*10;
                        }
                    }

                    v = new double[tvector];
                    for (int i=0; i<tvector; ++i) {
                        v[i] = r.nextDouble()*10;
                    }

                    res = new double[tvector];

                    hilos = new Thread[filas];
                    time_start = System.currentTimeMillis();
                    for (int i=0; i<filas; ++i) {
                        hilos[i] = new Thread(new matVectorConcurrente(filas, columnas, tvector, m, v, i));
                        hilos[i].start();
                    }
                    for (int i=0; i<filas; ++i) {
                        hilos[i].join();
                    }
                    time_end = System.currentTimeMillis();
                    imprimeVector(res);
                    System.out.println("\nHa tardado "+(time_end - time_start)/(double)1000+" segundos");
                    break;
                default:
                    System.out.println("Solo hay dos opciones, por favor, introduce 1 ó 2.");
            }
        } while (opcion < 1 || opcion > 2);
    }
}
