
/**
 * @author Jes�s Rodr�guez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class NewtonRaphson {

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param iteraciones N�mero de repeticiones
     */
    public static void funcion1(int iteraciones) {
        double aproximacion, fn, fn_p;
        int i = 1;

        System.out.println("Introduce una aproximaci�n para la funci�n:");
        aproximacion = teclado.nextDouble();

        while (i <= iteraciones) {
            fn = Math.cos(aproximacion) - (Math.pow(aproximacion, 3));
            fn_p = -Math.sin(aproximacion) - (3 * Math.pow(aproximacion, 2));
            aproximacion = aproximacion - (fn / fn_p);

            System.out.println("Iteraci�n " + i + ": " + aproximacion + ".");
            i++;
        }
    }

    /**
     * @param iteraciones N�mero de repeticiones
     */
    public static void funcion2(int iteraciones) {
        double aproximacion, fn, fn_p;
        int i = 1;

        System.out.println("Introduce una aproximaci�n para la funci�n:");
        aproximacion = teclado.nextDouble();

        while (i <= iteraciones) {
            fn = Math.pow(aproximacion, 2) - 5;
            fn_p = 2 * aproximacion;
            aproximacion = aproximacion - (fn / fn_p);

            System.out.println("Iteraci�n " + i + ": " + aproximacion + ".");
            i++;
        }
    }

    public static void main(String[] args) {
        int funcion, iteraciones;

        do {
            System.out.println("Elige una funci�n:");
            System.out.println("1.) f(x) = cos(x) - x^3 en [0, 1]");
            System.out.println("2.) f(x) = x^2 - 5 en el [2, 3]");
            funcion = teclado.nextInt();
        } while (funcion != 1 && funcion != 2);

        System.out.println("Introduce el n�mero de iteraciones:");
        iteraciones = teclado.nextInt();

        switch (funcion) {
            case 1:
                funcion1(iteraciones);
                break;
            case 2:
                funcion2(iteraciones);
                break;
        }
    }
}
