/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.lang.Math;

class NewtonRaphson{

    /**
     * Método para la función f(x)=cos(x)-x³
     * @param aprox       Aproximación inicial de la función
     * @param iteraciones Número de iteraciones a ejecutar
     */
    public static void coseno(double aprox, int iteraciones){
        for (int i=0; i<iteraciones; ++i) {
            aprox=aprox-((Math.cos(aprox)-Math.pow(aprox,3))/(-Math.sin(aprox)-3*Math.pow(aprox,2)));
            System.out.println((i+1)+". "+aprox);
        }
    }

    /**
     * Método para la función f(x)=x²-5
     * @param aprox       Aproximación inicial de la función
     * @param iteraciones Número de iteraciones a ejecutar
     */
    public static void cuadrado(double aprox, int iteraciones){
        for (int i=0; i<iteraciones; ++i) {
            aprox=aprox-((Math.pow(aprox,2)-5)/(2*aprox));
            System.out.println((i+1)+". "+aprox);
        }
    }

    public static void main(String[] args) {
        System.out.println("Seleccione la función que desea aproximar:\n1. f(x)=cos(x)-x³ en [0, 1]\n2. f(x)=x²-5 en [2, 3]");
        Scanner teclado = new Scanner(System.in);
        int opcion = teclado.nextInt();
        System.out.println("Introduzca la aproximación inicial:");
        double aprox = teclado.nextDouble();
        System.out.println("Introduzca el número de iteraciones:");
        int iteraciones = teclado.nextInt();
        switch (opcion) {
            case 1: coseno(aprox, iteraciones); break;
            case 2: cuadrado(aprox, iteraciones); break;
        }
    }
}
