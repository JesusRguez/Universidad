/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class prodMat{

    /**
     * Método para multipilicar dos matrices
     * @param  m1 Primera matriz
     * @param  m2 Segunda matriz
     * @return    Retorna una matriz "res" como resultado de la multipilcación de las matrices anteriores
     */
    public static double[][] producto(double[][] m1, double[][] m2){
        double[][] res = new double[m1.length][m2.length];
        for (int i=0; i<res.length; ++i) {
            for (int j=0; j<res[i].length; ++j) {
                res[i][j] = 0;
                for (int k=0; k<res.length; ++k) {
                    res[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return res;
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

    public static void main(String[] args) {
        double[][] m1, m2, res;
        int filas1 = 0, columnas1 = 0, filas2 = 0, columnas2 = 0;
        long time_start, time_end;
        Scanner teclado = new Scanner(System.in);
        int opcion;

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

                    res = new double[filas1][columnas2];

                    time_start = System.currentTimeMillis();
                    res = producto(m1, m2);
                    time_end = System.currentTimeMillis();

                    imprimeMatriz(res);

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

                    res = new double[filas1][columnas2];

                    time_start = System.currentTimeMillis();
                    res = producto(m1, m2);
                    time_end = System.currentTimeMillis();

                    imprimeMatriz(res);

                    System.out.println("Ha tardado "+(time_end - time_start)/(double)1000+" segundos");
                    break;
                default:
                    System.out.println("Solo hay dos opciones, por favor, introduce 1 ó 2.");
            }
        } while (opcion < 1 || opcion > 2);
    }
}
