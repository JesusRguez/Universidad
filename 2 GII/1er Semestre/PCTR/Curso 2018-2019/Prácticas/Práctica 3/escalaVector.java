/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class escalaVector{
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce el número de elementos:");
        int n = teclado.nextInt();
        System.out.println("Introduzca el factor escalar:");
        int f = teclado.nextInt();

        int[] v = new int[n];
        int[] r = new int[n];

        for (int i=0; i<n; ++i) {
            v[i] = (int)(Math.random()*10);
        }

        for (int i=0; i<n; ++i) {
            r[i] = f*v[i];
        }
    }
}
