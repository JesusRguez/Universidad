
import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 * Programa para leer de un fichero.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class PasoMayusculas {

    public static void main(String[] args) throws IOException {
        RandomAccessFile entrada = null;
        RandomAccessFile salida = null;
        boolean finArchivo = false;
        char c;

        try {
            entrada = new RandomAccessFile("Datos.txt", "rw");
            salida = new RandomAccessFile("Datos2.txt", "rw");
            c = (char) entrada.readByte();
            entrada.seek(entrada.getFilePointer() - 1);
            salida.writeByte(Character.toUpperCase(c));
            do {
                try {
                    if (entrada.readByte() == ' ') {
                        c = (char) entrada.readByte();
                        entrada.seek(entrada.getFilePointer() - 1);
                        salida.writeByte(Character.toUpperCase(c));
                    } else {
                        c = (char) entrada.readByte();
                        entrada.seek(entrada.getFilePointer() - 1);
                        salida.writeByte(c);
                    }
                } catch (EOFException ex) {
                    finArchivo = true;
                    entrada.close();
                    salida.close();
                    System.out.println("Se ha realizado el cambio.");
                }
            } while (!finArchivo);
        } catch (Exception ex) {
            System.out.println("No se pudo leer el fichero.");
        }
    }
}
