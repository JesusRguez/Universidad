
/**
 * Ejercicio 21
 *
 * @author Jes�s Rodr�guez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class Vocales {

    public static void contarVocales(String texto) {
        int vocalA, vocalE, vocalI, vocalO, vocalU;
        vocalA = vocalE = vocalI = vocalO = vocalU = 0;

        for (int i = 0; i < texto.length(); i++) {
            switch (Character.toUpperCase(texto.charAt(i))) {
                case 'A':
                    vocalA++;
                    break;
                case 'E':
                    vocalE++;
                    break;
                case 'I':
                    vocalI++;
                    break;
                case 'O':
                    vocalO++;
                    break;
                case 'U':
                    vocalU++;
                    break;
                default:
                    break;
            }
        }
        System.out.println("La vocal A aparece " + vocalA + " veces.");
        System.out.println("La vocal E aparece " + vocalE + " veces.");
        System.out.println("La vocal I aparece " + vocalI + " veces.");
        System.out.println("La vocal O aparece " + vocalO + " veces.");
        System.out.println("La vocal U aparece " + vocalU + " veces.");
    }

    public static void main(String[] args) {
        String texto;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca un texto. Para terminar, pulse ENTER:");
        texto = teclado.nextLine();

        contarVocales(texto);
    }
}
