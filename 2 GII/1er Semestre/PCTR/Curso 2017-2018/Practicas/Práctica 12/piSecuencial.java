
import java.util.Scanner;

/**
 * @author Jesus Rodriguez Heras
 * @version 1.0
 */
public class piSecuencial {

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el numero de intentos:");
        int intentos = teclado.nextInt();
        int puntos = 0;
        long time_start, time_end;
        time_start = System.currentTimeMillis();
        for (int i = 0; i < intentos; i++) {
            double cx = Math.random();
            double cy = Math.random();
            if (Math.pow(cx, 2) + Math.pow(cy, 2) <= 1) {
                puntos++;
            }
        }
        time_end = System.currentTimeMillis();
        System.out.println(4.0 * puntos / intentos + "\nEn " + (time_end - time_start) / (double) 1000 + " segundos");

    }
}
