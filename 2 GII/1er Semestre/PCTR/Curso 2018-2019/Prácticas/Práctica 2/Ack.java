/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

class Ack{

    /**
     * Método para calcular la función de Ackerman
     * @param  n Valor del término n
     * @param  m Valor del término m
     * @return   Devuelve el resultado de aplicar la función de Ackerman a los términos n y m
     */
    public static int Ackerman(int m, int n){
        if (m == 0) {
            return n + 1;
        } else {
            if (m > 0 && n == 0) {
                return Ackerman(m - 1, 1);
            } else {
                if (m > 0 && n > 0) {
                    return Ackerman(m - 1, Ackerman(m, n - 1));
                }
            }
        }
        return n;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el término n:");
        int n = teclado.nextInt();
        System.out.println("Introduzca el término m:");
        int m = teclado.nextInt();
        System.out.println("La solución de la función de Ackerman es: "+Ackerman(m, n));
    }
}
