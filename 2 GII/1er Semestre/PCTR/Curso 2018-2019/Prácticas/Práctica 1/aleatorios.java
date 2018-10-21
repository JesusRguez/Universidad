/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class aleatorios{
    public static void main(String[] args) {
        System.out.println("Introduzca la longitudo de la secuencia de números aleatorios:");
        Scanner teclado = new Scanner(System.in);
        int longitud=teclado.nextInt();
        for (int i=0; i<longitud; ++i) {
            System.out.println(Math.random());
        }
    }
}
