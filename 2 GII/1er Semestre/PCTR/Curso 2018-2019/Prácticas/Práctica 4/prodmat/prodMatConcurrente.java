/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package prodmat;

public class prodMatConcurrente extends Thread{

    static double[][] m1, m2, res;
    static int filas1, columnas1, filas2, columnas2;

    public prodMatConcurrente(double[][] m1, double[][] m2, int filas1, int filas2, int columnas1, int columnas2){
        this.m1 = m1;
        this.m2 = m2;
        this.filas1 = filas1;
        this.columnas1 = columnas1;
        this.filas2 = filas2;
        this.columnas2 = columnas2;
        res = new double[filas1][columnas2];
    }
}
