package usaprodmatconcurrente;

import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 */
public class UsaprodMatConcurrente extends prodMatConcurrente {

    public static Scanner teclado = new Scanner(System.in);

    int filaHilo, columnaHilo;

    /**
     * @param matriz1Aux
     * @param matriz2Aux
     * @param filas1
     * @param columnas1
     * @param filas2
     * @param columnas2
     * @param filaHilo
     * @param columnaHilo
     */
    public UsaprodMatConcurrente(double[][] matriz1Aux, double[][] matriz2Aux, int filas1, int columnas1, int filas2, int columnas2, int filaHilo, int columnaHilo) {
        super(matriz1Aux, matriz2Aux, filas1, columnas1, filas2, columnas2);
        this.filaHilo = filaHilo;
        this.columnaHilo = columnaHilo;
    }

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
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.println("Introduzca el elemento " + i + 1 + ", " + j + 1 + ":");
                matriz[i][j] = teclado.nextDouble();
            }
        }
    }

    public void run() {
        resultado[filaHilo][columnaHilo] = 0;

        for (int j = 0; j < resultado.length; j++) {
            resultado[filaHilo][columnaHilo] += matriz1[filaHilo][j] * matriz2[j][columnaHilo];
        }

        //System.out.println(resultado[filaHilo][columnaHilo]);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Introduzca el número de filas de la primera matriz:");
        int filas1 = teclado.nextInt();
        System.out.println("Introduzca el número de columnas de la primera matriz:");
        int columnas1 = teclado.nextInt();

        double[][] matriz1Aux = new double[filas1][columnas1];
        for (int i = 0; i < filas1; i++) {
            for (int j = 0; j < columnas1; j++) {
                matriz1Aux[i][j] = 0;
            }
        }

        System.out.println("Introduzca el número de filas de la segunda matriz:");
        int filas2 = teclado.nextInt();
        System.out.println("Introduzca el número de columnas de la segunda matriz:");
        int columnas2 = teclado.nextInt();

        double[][] matriz2Aux = new double[filas2][columnas2];
        for (int i = 0; i < filas2; i++) {
            for (int j = 0; j < columnas2; j++) {
                matriz2Aux[i][j] = 0;
            }
        }

        if (filas1 != columnas2) {
            System.out.println("No se puede realizar la multiplicación debido a que el número de filas de la primera matriz no coincide con el número de columnas de la segunda matriz.");
        } else {

            System.out.println("¿Cómo de sea rellenar las matrices?\n1.)Automático\n2.)Manual");
            int opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    rellenaMatriz(matriz1Aux);
                    rellenaMatriz(matriz2Aux);
                    break;
                case 2:
                    rellenaMatrizManual(matriz1Aux);
                    rellenaMatrizManual(matriz2Aux);
                    break;
                default:
                    System.out.println("Introduzca una opción correcta.");
                    break;
            }
            long time_start, time_end;
            UsaprodMatConcurrente[] hilos = new UsaprodMatConcurrente[filas1 * columnas2];
            time_start = System.currentTimeMillis();
            int k = 0;
            for (int i = 0; i < filas1; i++) {
                for (int j = 0; j < columnas2; j++) {
                    hilos[k] = new UsaprodMatConcurrente(matriz1Aux, matriz2Aux, filas1, columnas1, filas2, columnas2, i, j);
                    hilos[k].start();
                    k++;
                }
            }

            for (int i = 0; i < hilos.length; i++) {
                hilos[i].join();
            }
            time_end = System.currentTimeMillis();
            System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
        }
    }
}
