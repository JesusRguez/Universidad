/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package prodmat;

import java.util.*;

public class UsaprodMatConcurrente extends prodMatConcurrente{

    public int filaHilo, columnaHilo;

    /**
     * Constructor de UsaprodMatConcurrente
     * @param m1          Primera matriz
     * @param m2          Segunda matriz
     * @param filas1      Filas de la primera matriz
     * @param columnas1   Columnas de la primera matriz
     * @param filas2      Filas de la segunda matriz
     * @param columnas2   Columnas de la segunda matriz
     * @param filaHilo    Fila que irá asociada al hilo
     * @param columnaHilo Columna que irá asociada al hilo
     */
    public UsaprodMatConcurrente(double[][] m1, double[][] m2, int filas1, int columnas1, int filas2, int columnas2, int filaHilo, int columnaHilo){
        super(m1, m2, filas1, columnas1, filas2, columnas2);
        this.filaHilo = filaHilo;
        this.columnaHilo = columnaHilo;
    }

    /**
     * Método para imprimir una matriz
     * @param m Matriz a imprimir
     */
    public static void imprimeMatriz(double[][] m){
        for (int i=0; i<m.length; ++i) {
            for (int j=0; j<m[i].length; ++j) {
                System.out.print(m[i][j]+"\t");
            }
            System.out.print("\n");
        }
    }

    /**
     * Método run
     */
    public void run(){
        res[filaHilo][columnaHilo] = 0;
        for (int i=0; i<m2.length; ++i) {
            res[filaHilo][columnaHilo] += m1[filaHilo][i] * m2[i][columnaHilo];
        }
    }

    public static void main(String[] args) throws InterruptedException{
        double[][] m1, m2, res;
        int filas1 = 0, columnas1 = 0, filas2 = 0, columnas2 = 0;
        long time_start, time_end;
        Scanner teclado = new Scanner(System.in);
        int opcion;
        UsaprodMatConcurrente[] hilos;

        do {
            System.out.println("Introduzca la opción que desea:\n1. Introducir datos manualmente\n2. Introducir solo las dimensiones");
            opcion = teclado.nextInt();
            switch(opcion){
                case 1:
                    do {
                        System.out.println("Introduzca las filas de la primera matriz");
                        filas1 = teclado.nextInt();
                        System.out.println("Introduzca las columnas de la primera matriz");
                        columnas1 = teclado.nextInt();
                        System.out.println("Introduzca las filas de la segunda matriz");
                        filas2 = teclado.nextInt();
                        System.out.println("Introduzca las columnas de la segunda matriz");
                        columnas2 = teclado.nextInt();
                        if(columnas1 != filas2){
                            System.out.println("El número de columnas de la primera matriz no coincide con el número de filas de la segunda matriz");
                        }
                    } while (columnas1 != filas2);

                    m1 = new double[filas1][columnas1];
                    System.out.println("Introduzca los valores de la matriz:");
                    for (int i=0; i<filas1; ++i) {
                        for (int j=0; j<columnas1; ++j) {
                            System.out.println("Introduzca el valor de la coordenada ("+i+", "+j+"):");
                            m1[i][j] = teclado.nextDouble();
                        }
                    }

                    m2 = new double[filas2][columnas2];
                    System.out.println("Introduzca los valores de la matriz:");
                    for (int i=0; i<filas2; ++i) {
                        for (int j=0; j<columnas2; ++j) {
                            System.out.println("Introduzca el valor de la coordenada ("+i+", "+j+"):");
                            m2[i][j] = teclado.nextDouble();
                        }
                    }

                    hilos = new UsaprodMatConcurrente[filas1];
                    time_start = System.currentTimeMillis();
                    for (int i=0; i<filas1; ++i) {
                        for (int j=0; j<columnas2; ++j) {
                            hilos[i] = new UsaprodMatConcurrente(m1, m2, filas1, columnas1, filas2, columnas2, i, j);
                            hilos[i].start();
                        }
                    }

                    for (int i=0; i<hilos.length; ++i) {
                        hilos[i].join();
                    }
                    time_end = System.currentTimeMillis();

                    imprimeMatriz(prodMatConcurrente.res);

                    System.out.println("\nHa tardado "+(time_end-time_start)/(double)1000+" segundos");
                    break;
                case 2:
                    do {
                        System.out.println("Introduzca las filas de la primera matriz");
                        filas1 = teclado.nextInt();
                        System.out.println("Introduzca las columnas de la primera matriz");
                        columnas1 = teclado.nextInt();
                        System.out.println("Introduzca las filas de la segunda matriz");
                        filas2 = teclado.nextInt();
                        System.out.println("Introduzca las columnas de la segunda matriz");
                        columnas2 = teclado.nextInt();
                        if(columnas1 != filas2){
                            System.out.println("El número de columnas de la primera matriz no coincide con el número de filas de la segunda matriz");
                        }
                    } while (columnas1 != filas2);

                    Random r = new Random();
                    m1 = new double[filas1][columnas1];
                    for (int i=0; i<filas1; ++i) {
                        for (int j=0; j<columnas1; ++j) {
                            m1[i][j] = r.nextDouble()*10;
                        }
                    }

                    m2 = new double[filas2][columnas2];
                    for (int i=0; i<filas2; ++i) {
                        for (int j=0; j<columnas2; ++j) {
                            m2[i][j] = r.nextDouble()*10;
                        }
                    }

                    hilos = new UsaprodMatConcurrente[filas1];
                    time_start = System.currentTimeMillis();

                    for (int i=0; i<filas1; ++i) {
                        for (int j=0; j<columnas2; ++j) {
                            hilos[i] = new UsaprodMatConcurrente(m1, m2, filas1, columnas1, filas2, columnas2, i, j);
                            hilos[i].start();
                        }
                    }

                    for (int i=0; i<hilos.length; ++i) {
                        hilos[i].join();
                    }
                    time_end = System.currentTimeMillis();

                    imprimeMatriz(prodMatConcurrente.res);

                    System.out.println("Ha tardado "+(time_end - time_start)/(double)1000+" segundos");
                    break;
                default:
                    System.out.println("Solo hay dos opciones, por favor, introduce 1 ó 2.");
            }
        } while (opcion < 1 || opcion > 2);
    }
}
