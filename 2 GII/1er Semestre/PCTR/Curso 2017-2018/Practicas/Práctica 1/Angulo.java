
/**
 * Ejercicio 22
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.lang.Math;
import java.util.Scanner;

public class Angulo {

    //static double PI = 3.1415;
    public static void funciones(double a) {
        double ang = Math.toDegrees(a);
        System.out.println("En ángulos sexagesimales son: " + ang);
        System.out.println("El seno de " + a + " es: " + Math.sin(a));
        System.out.println("El coseno de " + " es: " + Math.cos(a));
        System.out.println("La tangente de " + " es: " + Math.tan(a));
    }

    public static void main(String[] args) {
        System.out.println("Introduzca un angulo en radianes: ");
        Scanner teclado = new Scanner(System.in);
        double a = teclado.nextDouble();

        funciones(a);
        funciones(0);
        funciones(Math.PI / 4);
        funciones(Math.PI / 2);
        funciones(Math.PI);
    }
}
