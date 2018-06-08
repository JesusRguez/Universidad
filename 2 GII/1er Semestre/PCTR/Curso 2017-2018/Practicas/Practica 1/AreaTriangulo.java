
/**
 * Programa en Java que escribe el área de un triángulo en la pantalla.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.io.*;

public class AreaTriangulo {

    float areatriangulo(float base, float altura) {
        return base * altura / 2;
    }

    public static void main(String[] args) throws IOException {
        float base, altura, area;

        AreaTriangulo AT;
        AT = new AreaTriangulo();

        System.out.println("Siguiento el Sistema Internacional de medidas, todas las medidas serán en metros");
        BufferedReader dato = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Introduce la base del triángulo");
        base = Float.parseFloat(dato.readLine());
        System.out.println("Introduce la altura del triángulo");
        altura = Float.parseFloat(dato.readLine());
        area = AT.areatriangulo(base, altura);
        System.out.println("El área del triángulo es: " + area + " metros cuadrados.");
    }
}
