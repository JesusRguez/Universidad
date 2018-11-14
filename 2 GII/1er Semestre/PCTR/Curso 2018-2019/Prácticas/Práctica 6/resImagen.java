/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class resImagen{

    /**
     * Método para realizar el resaltado de una matriz
     * @param  matriz Matriz a resaltar
     * @return        Devuelve la matriz resaltada
     */
    public static int[][] resaltado(int[][] matriz){
        for (int i=0; i<matriz.length; ++i) {
            for (int j=0; j<matriz[i].length; ++j) {
                matriz[i][j] = (4*matriz[i][j] - matriz[(i+1)%matriz.length][j] - matriz[i][(j+1)%matriz.length] - matriz[(i-1+matriz.length)%matriz.length][j] - matriz[i][(j-1+matriz.length)%matriz.length])/8;
            }
        }
        return matriz;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int matriz[][];
        System.out.println("Introduzca el tamaño de la matriz NxN:");
        int n = teclado.nextInt();
        matriz = new int[n][n];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                matriz[i][j] = (int) Math.random()*20;
            }
        }
        long time_start = System.currentTimeMillis();
        matriz = resaltado(matriz);
        long time_end = System.currentTimeMillis();
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
