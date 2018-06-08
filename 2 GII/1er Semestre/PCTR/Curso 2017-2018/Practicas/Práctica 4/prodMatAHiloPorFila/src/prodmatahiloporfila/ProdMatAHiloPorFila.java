package prodmatahiloporfila;

import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 */
public class ProdMatAHiloPorFila extends prodMatConcurrente {

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
     */
    public ProdMatAHiloPorFila(double[][] matriz1Aux, double[][] matriz2Aux, int filas1, int columnas1, int filas2, int columnas2, int filaHilo) {
        super(matriz1Aux, matriz2Aux, filas1, columnas1, filas2, columnas2);
        this.filaHilo = filaHilo;
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
        for (int i = 0; i < columnas2; i++) {
            resultado[filaHilo][i] = 0;
            for (int j = 0; j < filas2; j++) {
                resultado[filaHilo][i] = resultado[filaHilo][i] + (matriz1[filaHilo][j] * matriz2[i][j]);
            }
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

        //prodMatConcurrente matriz1 = new prodMatConcurrente(filas1, columnas1);
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
            ProdMatAHiloPorFila[] hilos = new ProdMatAHiloPorFila[filas1 * columnas2];
            time_start = System.currentTimeMillis();

            for (int i = 0; i < columnas2; i++) {
                hilos[i] = new ProdMatAHiloPorFila(matriz1Aux, matriz2Aux, filas1, columnas1, filas2, columnas2, i);
                hilos[i].start();
            }

            for (int i = 0; i < columnas2; i++) {
                hilos[i].join();
            }
            time_end = System.currentTimeMillis();
            System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
        }
    }
}
