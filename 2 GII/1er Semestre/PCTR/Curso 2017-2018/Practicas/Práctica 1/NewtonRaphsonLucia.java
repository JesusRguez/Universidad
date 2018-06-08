
/**
 * @author Lucía Caro Barrera
 */
import java.util.Scanner;

public class NewtonRaphsonLucia {

    static Scanner teclado = new Scanner(System.in);

    /**
     *
     * @param repeticionFuncion
     */
    public static void calcularFuncion2(int repeticionFuncion) {

        double x, fDerivada, f;
        do {
            System.out.println("Inserta un numero aproximado entre 2 y 3");
            x = teclado.nextDouble();
        } while (x < 2 || x > 3);

        //int i; Se puede declarar dentro del for
        for (int i = 0; i < repeticionFuncion; i++) {
            fDerivada = 2 * x;
            f = Math.pow(x, 2) - 5;
            x = x - (f / fDerivada);

            System.out.println("Iteración " + i + ": " + x + ".");//Para imprimir las iteraciones con sus aproximaciones
        }
    }

    /**
     *
     * @param repeticionFuncion
     */
    public static void calcularFuncion1(int repeticionFuncion) {

        double x, fDerivada, f;
        do {
            System.out.println("Inserta un numero aproximado entre 0 y 1");
            x = teclado.nextDouble();
        } while (x < 0 || x > 1);

        //int i; Se puede declarar dentro del for
        for (int i = 0; i < repeticionFuncion; i++) {
            fDerivada = -Math.sin(x) - 3 * Math.pow(x, 2);
            f = Math.cos(x) - (Math.pow(x, 3));
            x = x - (f / fDerivada);

            System.out.println("Iteración " + i + ": " + x + ".");//Para imprimir las iteraciones con sus aproximaciones
        }
    }

    static public void main(String[] args) {
        //int f;Se puede declarar abajo en el teclado.nextInt();
        //Scanner teclado = new Scanner(System.in); Esto es para leer localmente, no en el resto de funciones.

        System.out.println("¿Que funcion desea realizar?");
        System.out.println("1.) f(x) = cos(x) - x^3 en [0, 1]");
        System.out.println("2.) f(x) = x^2 - 5 en el [2, 3]");
        int f = teclado.nextInt();
        System.out.println("¿Cuantas veces deseas repetir la funcion?");
        int repeticionFuncion = teclado.nextInt();

        switch (f) {
            case 1:
                calcularFuncion1(repeticionFuncion);
                break;
            case 2:
                calcularFuncion2(repeticionFuncion);
                break;
        }
    }
}
