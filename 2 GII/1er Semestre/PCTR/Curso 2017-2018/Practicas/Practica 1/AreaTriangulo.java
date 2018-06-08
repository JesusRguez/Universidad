
/**
 * Programa en Java que escribe el �rea de un tri�ngulo en la pantalla.
 *
 * @author Jes�s Rodr�guez Heras
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

        System.out.println("Siguiento el Sistema Internacional de medidas, todas las medidas ser�n en metros");
        BufferedReader dato = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Introduce la base del tri�ngulo");
        base = Float.parseFloat(dato.readLine());
        System.out.println("Introduce la altura del tri�ngulo");
        altura = Float.parseFloat(dato.readLine());
        area = AT.areatriangulo(base, altura);
        System.out.println("El �rea del tri�ngulo es: " + area + " metros cuadrados.");
    }
}
