
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class escalaVector { //Multiplicar todos los elementos de un vector (1000 elementos) por el mismo número

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param vector
     * @param factor
     * @return
     */
    public static int[] escala(int[] vector, int factor) {
        int[] resultado = new int[vector.length];

        for (int i = 0; i < (i + 1) % vector.length; i++) {
            resultado[i] = factor * vector[i];
        }

        return resultado;
    }

    public static void main(String args[]) {
        //int[][] vector = new int[][];
        System.out.println("Introduce el número de elementos:");
        int numeros = teclado.nextInt();

        System.out.println("Introduce el factor escalar:");
        int factor = teclado.nextInt();

        int[] vector = new int[numeros];
        int[] resultado = new int[numeros];
        for (int i = 0; i < numeros; i++) {
            vector[i] = (int) (Math.random() * 10);
        }

        resultado = escala(vector, factor);
    }
}
