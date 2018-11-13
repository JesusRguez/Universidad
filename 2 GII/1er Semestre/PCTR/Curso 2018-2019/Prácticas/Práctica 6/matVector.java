/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class matVector{

    /**
     * Método para multiplicar la matriz por el vector
     * @param  m Matriz a multiplicar
     * @param  v Vector a multiplicar
     * @return   Retorna un vector "res" como resultado de la multiplicación de la matriz por el vector
     */
    public static double[] producto(double[][] m, double[] v){
        double[] res = new double[v.length];
        double aux = 0;
        for (int i=0; i<m.length; ++i) {
            for (int j=0; j<m[i].length; ++j) {
                aux += m[i][j]*v[j];
            }
            res[i] = aux;
            aux = 0;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int filas = 0, columnas = 0, tvector = 0, opcion;
        double[][] m;
        double[] v;
        double[] res;
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

                    time_start = System.currentTimeMillis();
                    res = producto(m, v);
                    time_end = System.currentTimeMillis();

                    System.out.println("\nHa tardado "+(time_end-time_start)/(double)1000+" segundos");
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

                    time_start = System.currentTimeMillis();
                    res = producto(m, v);
                    time_end = System.currentTimeMillis();

                    System.out.println("Ha tardado "+(time_end - time_start)/(double)1000+" segundos");
                    break;
                default:
                    System.out.println("Solo hay dos opciones, por favor, introduce 1 ó 2.");
            }
        } while (opcion < 1 || opcion > 2);
    }
}
