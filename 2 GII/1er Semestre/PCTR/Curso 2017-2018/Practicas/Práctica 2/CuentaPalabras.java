
import java.io.FileInputStream;
import java.io.IOException;

/**
 * Programa para leer de un fichero.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class CuentaPalabras {

    public static void contar(FileInputStream entrada) {
        int c, palabrastotales = 0;
        char palabra;
        try {
            while ((c = entrada.read()) >= 0) {
                palabra = (char) c;
                if (palabra == ' ') {
                    palabrastotales++;
                }
            }
            if (palabrastotales > 0) {
                palabrastotales++;
            }
            System.out.println("Hay " + palabrastotales + " palabras en el fichero.");
        } catch (Exception ex) {
            System.out.println("Esto no tira.");
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            FileInputStream entrada = new FileInputStream("Datos.txt");
            contar(entrada);
        } catch (Exception ex) {
            System.out.println("No se pudo leer el fichero.");
        }
    }
}
