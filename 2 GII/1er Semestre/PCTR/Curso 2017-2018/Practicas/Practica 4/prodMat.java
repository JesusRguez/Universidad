
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 */
public class prodMat {

    double[][] matriz;
    int filas, columnas;

    /**
     * @param filas
     * @param columnas
     */
    public prodMat(int filas, int columnas) {
        this.filas = filas;
        this.columnas = columnas;
        matriz = new double[filas][columnas];
    }

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param matriz1
     * @param matriz2
     * @return
     */
    public static double[][] multiplicar(double[][] matriz1, double[][] matriz2) {
        double[][] resultado = new double[matriz2.length][matriz1.length];

        for (int i = 0; i < matriz2.length; i++) {
            for (int j = 0; j < matriz1.length; j++) {
                resultado[i][j] = 0;
                for (int k = 0; k < matriz2.length; k++) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
        return resultado;
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
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Introduzca el número de filas de la primera matriz:");
        int filas1 = teclado.nextInt();
        System.out.println("Introduzca el número de columnas de la primera matriz:");
        int columnas1 = teclado.nextInt();

        prodMat matriz1 = new prodMat(filas1, columnas1);

        System.out.println("Introduzca el número de filas de la segunda matriz:");
        int filas2 = teclado.nextInt();
        System.out.println("Introduzca el número de columnas de la segunda matriz:");
        int columnas2 = teclado.nextInt();

        prodMat matriz2 = new prodMat(filas2, columnas2);

        if (filas1 != columnas2) {
            System.out.println("No se puede realizar la multiplicación debido a que el número de filas de la primera matriz no coincide con el número de columnas de la segunda matriz.");
        } else {

            System.out.println("¿Cómo de sea rellenar las matrices?\n1.)Automático\n2.)Manual");
            int opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    rellenaMatriz(matriz1.matriz);
                    rellenaMatriz(matriz2.matriz);
                    break;
                case 2:
                    rellenaMatrizManual(matriz1.matriz);
                    rellenaMatrizManual(matriz2.matriz);
                    break;
                default:
                    System.out.println("Introduzca una opción correcta.");
                    break;
            }
            long time_start, time_end;
            time_start = System.currentTimeMillis();
            double[][] resultado = multiplicar(matriz1.matriz, matriz2.matriz);
            time_end = System.currentTimeMillis();
            /*for (int i = 0; i < resultado.length; i++) {
                for (int j = 0; j < resultado[i].length; j++) {
                    System.out.print(resultado[i][j] + "  ");
                }
                System.out.print("\n");
            }*/
            System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");

        }
    }
}
