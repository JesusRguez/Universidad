/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorcadena;

public class monitorCadena_1 {

    private int numSlots = 0;
    //private int[][] matriz = null;
    private int[][][] buffer = null;
    private int putIn = 0, takeOut = 0;
    private int cont = 0;
    private int fila = 0, col = 0;

    /**
     * Constructor de monitorCadena_1
     */
    public monitorCadena_1(int numSlots){
        this.numSlots = numSlots;
        buffer = new int[numSlots][10][10];
    }

    /**
     * Método para insertar valores en la matriz del monitor
     * @param valor Valor a introducir en la matriz
     */
    public synchronized void insertar (int[][] m){
        while(cont == numSlots){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en insertar...");
            }
        }
        buffer[putIn] = m;
        putIn = (putIn+1)%numSlots;
        cont++;
        notifyAll();
    }

    /**
     * Método para extraer un número de la matriz del monitor
     * @return Retorna el número extraido de dicha matriz
     */
    public synchronized int[][] extraer(){
        int[][] m = new int[10][10];
        while(cont == 0){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en extraer...");
            }
        }
        for (int i=0; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                m[i][j] = buffer[takeOut][i][j];
            }
        }
        takeOut = (takeOut+1)%numSlots;
        cont--;
        notifyAll();
        return m;
    }
}
