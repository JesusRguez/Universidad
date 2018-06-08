package prodmatahiloporfila;

/**
 * @author Jesús Rodríguez Heras
 */
public class prodMatConcurrente extends Thread {

    static double[][] matriz1, matriz2;
    static int filas1, columnas1, filas2, columnas2;
    static double[][] resultado;

    /**
     * @param matriz1Aux
     * @param matriz2Aux
     * @param filas1
     * @param columnas1
     * @param filas2
     * @param columnas2
     */
    public prodMatConcurrente(double[][] matriz1Aux, double[][] matriz2Aux, int filas1, int columnas1, int filas2, int columnas2) {
        this.filas1 = filas1;
        this.columnas1 = columnas1;
        this.filas2 = filas2;
        this.columnas2 = columnas2;
        this.matriz1 = matriz1Aux;
        this.matriz2 = matriz2Aux;
        resultado = new double[filas1][columnas2];
    }

}
