
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class matVector {

    public static Scanner teclado = new Scanner(System.in);

    static double[][] matriz;
    static double[] vector;
    int filas, columnas;

    /**
     * @param filas
     * @param columnas
     */
    public matVector(int filas, int columnas) {
        this.filas = filas;
        this.columnas = columnas;
        matriz = new double[filas][columnas];
        vector = new double[filas];
    }

    /**
     * @param matriz
     */
    public static void rellenaMatriz(matVector matriz) {
        for (int i = 0; i < matriz.filas; i++) {
            for (int j = 0; j < matriz.columnas; j++) {
                matriz.matriz[i][j] = Math.random() * 10;
            }
        }
    }

    /**
     * @param matriz
     */
    public static void rellenaVector(matVector matriz) {
        for (int i = 0; i < matriz.columnas; i++) {
            matriz.vector[i] = Math.random() * 10;
        }
    }

    /**
     * @param matriz
     */
    public static void rellenaMatrizManual(matVector matriz) {
        for (int i = 0; i < matriz.filas; i++) {
            for (int j = 0; j < matriz.columnas; j++) {
                System.out.println("Introduzca el elemento " + i + 1 + ", " + j + 1 + ":");
                matriz.matriz[i][j] = teclado.nextDouble();
            }
        }
    }

    /**
     * @param matriz
     */
    public static void rellenaVectorManual(matVector matriz) {
        for (int i = 0; i < matriz.columnas; i++) {
            System.out.println("Introduzca el elemento " + i + 1 + ":");
            matriz.vector[i] = teclado.nextDouble();
        }
    }

    /**
     * @return
     */
    public double[] multiplica() {
        double[] resultado = new double[columnas];

        for (int i = 0; i < filas; i++) {
            resultado[i] = 0;
            for (int j = 0; j < columnas; j++) {
                resultado[i] = resultado[i] + matriz[i][j] * vector[j];
            }
        }

        return resultado;
    }

    public static void main(String[] args) {
        long time_start, time_end;

        System.out.println("Introuce el número de filas:");
        int filas = teclado.nextInt();
        System.out.println("Introduce el número de columnas:");
        int columnas = teclado.nextInt();

        matVector matriz = new matVector(filas, columnas);

        System.out.println("Seleccione como desea rellenar la matriz y el vector:\n1.) Automático\n2.) Manual");
        int opcion = teclado.nextInt();

        switch (opcion) {
            case 1:
                rellenaMatriz(matriz);
                rellenaVector(matriz);
                break;
            case 2:
                rellenaMatrizManual(matriz);
                rellenaVectorManual(matriz);
                break;
            default:
                System.out.println("Seleccione una opción correcta.");
                break;
        }
        time_start = System.currentTimeMillis();
        double[] resultado = matriz.multiplica();
        time_end = System.currentTimeMillis();

        /*for (int i = 0; i < resultado.length; i++) {
            System.out.println(resultado[i]);
        }*/
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
