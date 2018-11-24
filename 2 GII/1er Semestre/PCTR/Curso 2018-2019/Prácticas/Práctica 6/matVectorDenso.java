/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.Scanner;
import java.util.concurrent.*;

public class matVectorDenso implements Runnable {

    public static Scanner teclado = new Scanner(System.in);

    public static double[][] matriz;
    public static double[] vector;
    public static int filas, columnas;
    public static double[] resultado;
    public static double coeficienteBloqueo;
    public static int cores = 4;
    public static int hilos;
    public int idHilo;

    /**
     * Constructor de matVectorDenso
     * @param filas    Filas de la matriz
     * @param columnas Columnas de la matriz
     * @param matriz   Matriz a multiplicar por el vector
     * @param vector   Vector por el que se va a multiplicar la matriz
     * @param idHilo   Identificador del thread
     */
    public matVectorDenso(int filas, int columnas, double[][] matriz, double[] vector, int idHilo) {
        matVectorDenso.vector = vector;
        matVectorDenso.matriz = matriz;
        matVectorDenso.filas = filas;
        matVectorDenso.columnas = columnas;
        this.idHilo = idHilo;
        matVectorDenso.resultado = new double[filas];
        for (int i = 0; i < filas; i++) {
            resultado[i] = 0;
        }
    }

    /**
     * @param matriz Matriz a rellenar
     */
    public static void rellenaMatriz(double[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                matriz[i][j] = Math.random() * 10;
            }
        }
    }

    /**
     * @param vector Vector a rellenar
     */
    public static void rellenaVector(double[] vector) {
        for (int i = 0; i < vector.length; i++) {
            vector[i] = Math.random() * 10;
        }
    }

    /**
     * @param matriz Matriz a rellenar
     */
    public static void rellenaMatrizManual(double[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz.length; j++) {
                System.out.println("Introduzca el elemento " + i + 1 + ", " + j + 1 + ":");
                matriz[i][j] = teclado.nextDouble();
            }
        }
    }

    /**
     * @param vector Vector a rellenar
     */
    public static void rellenaVectorManual(double[] vector) {
        for (int i = 0; i < vector.length; i++) {
            System.out.println("Introduzca el elemento " + i + 1 + ":");
            vector[i] = teclado.nextDouble();
        }
    }

    /**
     * Método run()
     */
    public void run() {
        for (int i = idHilo * filas / hilos; i < (idHilo + 1) * filas / hilos; i++) {
            resultado[i] = 0;
            for (int j = 0; j < columnas; j++) {
                resultado[idHilo] = resultado[idHilo] + matriz[idHilo][j] * vector[j];
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {

        System.out.println("Introduce el número de filas:");
        int arg_filas = teclado.nextInt();

        System.out.println("Introduce el número de columnas:");
        int arg_columnas = teclado.nextInt();

        double[][] matrizAux = new double[arg_filas][arg_columnas];
        double[] vectorAux = new double[arg_columnas];

        System.out.println("Seleccione como desea rellenar la matriz y el vector:\n1.) Manual\n2.) Automático");
        int opcion = teclado.nextInt();

        switch (opcion) {
            case 1:
                rellenaMatrizManual(matrizAux);
                rellenaVectorManual(vectorAux);
                break;
            case 2:
                rellenaMatriz(matrizAux);
                rellenaVector(vectorAux);
                break;
            default:
                System.out.println("Seleccione una opción correcta.");
                break;
        }

        //System.out.println("Introduzca el coeficiente de bloqueo:");
        coeficienteBloqueo = 0; //teclado.nextDouble(); //Coeficiente de bloqueo = 0 porque no hay interbloqueo al ser un problema de tipo numérico

        hilos = (int) (cores / (1 - coeficienteBloqueo));

        long time_start, time_end;

        ExecutorService pool = Executors.newCachedThreadPool();
        time_start = System.currentTimeMillis();
        for (int i = 0; i < hilos; i++) {
            pool.execute(new matVectorDenso(arg_filas, arg_columnas, matrizAux, vectorAux, i));
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);

        time_end = System.currentTimeMillis();
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
