/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package hilo;

import java.util.*;

public class usaHilo extends Hilo{

    /**
     * Constructor de usaHilo
     * @param tipoHilo    Designa el tipo de hilo: sumador(true)/restador(false)
     * @param iteraciones Número de veces que se sumara/restará la variable n de la clase Hilo
     */
    public usaHilo(boolean tipoHilo, int iteraciones){
        super(tipoHilo, iteraciones);
    }

    public static void main(String[] args) throws InterruptedException{
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de iteraciones:");
        int iteraciones = teclado.nextInt();

        usaHilo H1 = new usaHilo(true, iteraciones);
        usaHilo H2 = new usaHilo(false, iteraciones);

        H1.start();
        H2.start();

        H1.join();
        H2.join();

        System.out.println("El valor final de n es: "+H1.n);
    }
}
