
/**
 * Ejercicios 19 y 20
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class Nombre {

    public static void escribeAlReves(String nombre) { //Función del ejercicio 20
        System.out.println("Escrito al reves: ");
        for (int i = nombre.length() - 1; i >= 0; i--) {
            System.out.print(nombre.charAt(i));
        }
    }

    public static void main(String[] args) {
        String nombre, apellido1, apellido2;
        int tam;

        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduce tu nombre: ");
        nombre = teclado.nextLine();
        System.out.println("Introduce tu primer apellido: ");
        apellido1 = teclado.nextLine();
        System.out.println("Introduce tu segundo apellido: ");
        apellido2 = teclado.nextLine();

        apellido1 = apellido1.concat(apellido2);
        nombre = nombre.concat(apellido1);

        tam = nombre.length();
        System.out.println(nombre);
        System.out.println("Dicha cadena mide " + tam + " caracteres.");

        escribeAlReves(nombre);
    }
}
