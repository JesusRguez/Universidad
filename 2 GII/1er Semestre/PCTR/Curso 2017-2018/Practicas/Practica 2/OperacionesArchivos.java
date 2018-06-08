
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 * Programa para hacer operaciones con ficheros.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class OperacionesArchivos {

    public static void copiarArchivo(String rutaOrigen, String rutaDestino) {
        //NO ME SALE!
        File origen = new File(rutaOrigen);
        File copia = new File(rutaDestino);
        FileInputStream entrada;
        FileOutputStream salida;

        if (copia.isDirectory()) {
            copia = new File(copia.getAbsolutePath() + "/" + origen.getName());
        }
        try {
            entrada = new FileInputStream(origen.getAbsolutePath());
            salida = new FileOutputStream(copia.getAbsolutePath());
            int leido;
            while ((leido = entrada.read()) != -1) {
                salida.write(leido);
            }
            salida.close();
            entrada.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error al copiar: no se pudo abrir algún archivo.");
        } catch (IOException e) {
            System.out.println("Error de lectura/escritura.");
        }

    }

    public static void main(String[] args) throws IOException {
        try {
            File entrada = new File("Datos.txt");
            File salida = new File("Datos2.txt");
            copiarArchivo(entrada.getPath(), salida.getPath());
        } catch (Exception ex) {
            System.out.println("No se pudo leer el fichero.");
        }
    }
}
