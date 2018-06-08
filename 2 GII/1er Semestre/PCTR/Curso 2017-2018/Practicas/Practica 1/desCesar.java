
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class desCesar {

    /**
     * @param cadena = Cadena a descifrar
     * @param desplazamiento = Desplazamiento seleccionado por el usuario
     */
    public static void descifrar(String cadena, int desplazamiento) {
        StringBuilder descifrado = new StringBuilder();
        int ASCII;

        for (int i = 0; i < cadena.length(); i++) {
            ASCII = (int) (cadena.charAt(i));
            ASCII = ASCII - (desplazamiento % 27);
            descifrado.append((char) (ASCII));
        }

        System.out.println("La cadena es:\n" + descifrado.toString());
    }

    public static void main(String[] args) {
        int desplazamiento;

        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca la cadena a descodificar:");
        String cadena = teclado.nextLine();

        do {
            System.out.println("Introudzca el desplazamiento (entre 0 y 27):");
            desplazamiento = teclado.nextInt();
        } while (desplazamiento < 0 && desplazamiento > 27);

        descifrar(cadena, desplazamiento);
    }
}
