
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class intDefinidaMonteCarlo {

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param puntos = Número de puntos totales
     */
    public static void funcion1(int puntos) {
        double puntosdentro = 0;
        double x, y, buscado;

        for (int i = 0; i < puntos; i++) {
            x = Math.random();
            y = Math.random();
            if (Math.sin(x) >= y) {
                puntosdentro++;
            }
        }
        buscado = puntosdentro / puntos;
        System.out.println("La integral definida en [0, 1] es: " + buscado);
    }

    /**
     * @param puntos = Número de puntos totales
     */
    public static void funcion2(int puntos) {
        double puntosdentro = 0;
        double x, y, buscado;

        for (int i = 0; i < puntos; i++) {
            x = Math.random();
            y = Math.random();
            if (x >= y) {
                puntosdentro++;
            }
        }
        buscado = puntosdentro / puntos;
        System.out.println("La integral definida en [0, 1] es: " + buscado);
    }

    public static void main(String[] args) {
        int funcion;

        do {
            System.out.print("Seleccione la función a la que le desea");
            System.out.println(" calcular la integral en el intervalo [0, 1]");
            System.out.println("1.) f(x)=sin(x)");
            System.out.println("2.) f(x)=x");
            funcion = teclado.nextInt();
        } while (funcion != 1 && funcion != 2);

        System.out.println("Introduce el número de puntos:");
        int puntos = teclado.nextInt();

        switch (funcion) {
            case 1:
                funcion1(puntos);
                break;
            case 2:
                funcion2(puntos);
                break;
        }
    }
}
