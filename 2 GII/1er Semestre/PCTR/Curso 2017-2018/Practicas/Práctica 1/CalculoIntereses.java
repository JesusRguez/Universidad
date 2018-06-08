
/**
 * Programa en Java que escribe el calculo de intereses en la pantalla.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.*;

public class CalculoIntereses {

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Cálculo de intereses.");
        System.out.println("Dinero ingresado:");
        //Hay que separar los decimales con coma (,)
        float dinero = teclado.nextFloat();
        System.out.println("Interes anual (%): ");
        float interes = teclado.nextFloat();
        float ganancia = dinero * interes / 100 / 2;
        float gananciaanual = dinero * interes / 100;
        System.out.println("Intereses a los seis meses: " + ganancia);
        System.out.println("Dinero disponible en total a los seis meses: " + (dinero + ganancia));
        System.out.println("Dinero disponible en total al año: " + (dinero + gananciaanual));
    }
}
