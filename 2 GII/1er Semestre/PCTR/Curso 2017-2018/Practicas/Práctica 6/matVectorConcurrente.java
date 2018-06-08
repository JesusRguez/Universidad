
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class matVectorConcurrente implements Runnable {

    public static Scanner teclado = new Scanner(System.in);

    static double[][] matriz;
    static double[] vector;
    static int filas, columnas;
    static double[] resultado;
    int filaquecontrolaelhilo;

    /**
     * @param filas
     * @param columnas
     * @param matriz
     * @param vector
     * @param filaquecontrolaelhilo
     */
    public matVectorConcurrente(int filas, int columnas, double[][] matriz, double[] vector, int filaquecontrolaelhilo) {
        matVectorConcurrente.vector = vector;
        matVectorConcurrente.matriz = matriz;
        matVectorConcurrente.filas = filas;
        matVectorConcurrente.columnas = columnas;
        this.filaquecontrolaelhilo = filaquecontrolaelhilo;
        matVectorConcurrente.resultado = new double[filas];
        for (int i = 0; i < filas; i++) {
            resultado[i] = 0;
        }
    }

    /**
     * @param matriz
     */
    public static void rellenaMatriz(double[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                matriz[i][j] = Math.random() * 10;
            }
        }
    }

    /**
     * @param vector
     */
    public static void rellenaVector(double[] vector) {
        for (int i = 0; i < vector.length; i++) {
            vector[i] = Math.random() * 10;
        }
    }

    /**
     * @param matriz
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
     * @param vector
     */
    public static void rellenaVectorManual(double[] vector) {
        for (int i = 0; i < vector.length; i++) {
            System.out.println("Introduzca el elemento " + i + 1 + ":");
            vector[i] = teclado.nextDouble();
        }
    }

    public void run() {
        for (int j = 0; j < columnas; j++) {
            resultado[filaquecontrolaelhilo] = resultado[filaquecontrolaelhilo] + matriz[filaquecontrolaelhilo][j] * vector[j];
        }
    }

    public static void main(String[] args) throws InterruptedException {

        System.out.println("Introduce el número de filas:");
        int arg_filas = teclado.nextInt();

        System.out.println("Introduce el número de columnas:");
        int arg_columnas = teclado.nextInt();

        double[][] matrizAux = new double[arg_filas][arg_columnas];
        double[] vectorAux = new double[arg_columnas];

        System.out.println("Seleccione como desea rellenar la matriz y el vector:\n1.) Automático\n2.) Manual");
        int opcion = teclado.nextInt();

        switch (opcion) {
            case 1:
                rellenaMatriz(matrizAux);
                rellenaVector(vectorAux);
                break;
            case 2:
                rellenaMatrizManual(matrizAux);
                rellenaVectorManual(vectorAux);
                break;
            default:
                System.out.println("Seleccione una opción correcta.");
                break;
        }

        long time_start, time_end;
        Thread[] hilos = new Thread[arg_filas];
        time_start = System.currentTimeMillis();

        for (int i = 0; i < arg_filas; i++) {
            hilos[i] = new Thread(new matVectorConcurrente(arg_filas, arg_columnas, matrizAux, vectorAux, i));
            hilos[i].start();
        }

        for (int i = 0; i < hilos.length; i++) {
            hilos[i].join();
        }

        time_end = System.currentTimeMillis();
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
