
/**
 * Programa en Java que usamos para un ejemplo de encapsulamiento en la pantalla.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.lang.Math;
import java.util.Scanner;

public class Encapsula {

    public static void main(String[] args) {
        double a, b;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce el primer número:");
        a = teclado.nextDouble();
        System.out.println("Introduce el segundo número");
        b = teclado.nextDouble();

        System.out.println("El seno de " + a + " es " + Math.sin(a));
        System.out.println("El seno de " + b + " es " + Math.sin(b));
        System.out.println("El coseno de " + a + " es " + Math.cos(a));
        System.out.println("El coseno de " + b + " es " + Math.cos(b));
        System.out.println("La tangente de " + a + " es " + Math.tan(a));
        System.out.println("La tangente de " + b + " es " + Math.tan(b));
        System.out.println("El máximo de " + a + " y " + b + " es: " + Math.max(a, b));
        System.out.println("El mínimo de " + a + " y " + b + " es: " + Math.min(a, b));
        System.out.println("El logaritmo de " + a + " es: " + Math.log(a));
        System.out.println("El logaritmo de " + b + " es: " + Math.log(b));
    }
}
