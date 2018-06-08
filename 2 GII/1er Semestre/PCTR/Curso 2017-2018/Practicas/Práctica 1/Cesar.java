
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class Cesar {

    /**
     * @param cadena = Cadena a cifrar
     * @param desplazamiento = Desplazamiento seleccionado por el usuario
     */
    public static void cifrar(String cadena, int desplazamiento) {
        StringBuilder cifrado = new StringBuilder();
        int valorASCII;

        for (int i = 0; i < cadena.length(); i++) {
            valorASCII = (int) (cadena.charAt(i));
            valorASCII = valorASCII + (desplazamiento % 27);
            cifrado.append((char) (valorASCII));
        }

        System.out.println("La cadena cifrada es:\n" + cifrado.toString());
    }

    public static void main(String[] args) {
        int desplazamiento;

        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca la cadena a codificar:");
        String cadena = teclado.nextLine();

        do {
            System.out.println("Introudzca el desplazamiento (entre 0 y 27):");
            desplazamiento = teclado.nextInt();
        } while (desplazamiento < 0 && desplazamiento > 27);

        cifrar(cadena, desplazamiento);
    }
}
