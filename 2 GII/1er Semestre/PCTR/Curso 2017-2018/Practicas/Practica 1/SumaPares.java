
/**
 * Ejercicio 18
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class SumaPares {

    static void suma(int n) {
        int s = 0;
        for (int i = 2; i <= 2 * n; i = i + 2) {
            s = s + i;
        }
        System.out.println(s);
    }

    public static void main(String[] args) {
        int n;
        Scanner teclado = new Scanner(System.in);
        System.out.print("Introduce el número n: ");
        n = teclado.nextInt();
        suma(n);
    }
}
