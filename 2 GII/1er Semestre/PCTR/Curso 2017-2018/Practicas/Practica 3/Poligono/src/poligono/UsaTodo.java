package poligono;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.ArrayList;
import java.util.Scanner;

public class UsaTodo {

    public static Scanner teclado = new Scanner(System.in);
    public static ArrayList<Punto> entrada;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int eleccionPoligono;

        do {
            System.out.println("Seleccione el polígono con el que va a trabajar:\n1.) Triángulo\n2.) Cuadrado\n3.) Pentágono\n4.) Hexágono");
            eleccionPoligono = teclado.nextInt();
        } while (1 < eleccionPoligono && eleccionPoligono > 4);

        switch (eleccionPoligono) {
            case 1:
                controlaTriangulo();
                break;
            case 2:
                controlaCuadrado();
                break;
            case 3:
                controlaPentagono();
                break;
            case 4:
                controlaHexagono();
                break;
        }
    }

    private static void controlaTriangulo() {
        int eleccionOperacion;

        System.out.println("Introduzca los puntos del triángulo:");
        double x, y;
        entrada = new ArrayList();
        for (int i = 0; i < 3; i++) {
            System.out.println("Introduzca el " + i + 1 + " punto x:");
            x = teclado.nextDouble();
            System.out.println("Introduzca el " + i + 1 + " punto y:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }
        System.out.println("La lista tiene " + entrada.size() + " elementos.");

        Triangulo T = new Triangulo(entrada);

        do {
            System.out.println("Seleccione una operacion a realizar:\n1.) Perímetro\n2.) Área");
            eleccionOperacion = teclado.nextInt();
        } while (1 < eleccionOperacion && eleccionOperacion > 2);

        switch (eleccionOperacion) {
            case 1:
                System.out.println("El perímetro del triángulo es " + Math.abs(T.perimetroTriangulo()));
                break;
            case 2:
                System.out.println("El área del triángulo es " + Math.abs(T.areaTriangulo()));
                break;
        }
    }

    private static void controlaCuadrado() {
        int eleccionOperacion;

        System.out.println("Introduzca los puntos del cuadrado:");
        double x, y;
        entrada = new ArrayList();
        for (int i = 0; i < 4; i++) {
            System.out.println("Introduzca el " + i + 1 + " punto x:");
            x = teclado.nextDouble();
            System.out.println("Introduzca el " + i + 1 + " punto y:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }
        Cuadrado C = new Cuadrado(entrada);

        do {
            System.out.println("Seleccione una operacion a realizar:\n1.) Perímetro\n2.) Área");
            eleccionOperacion = teclado.nextInt();
        } while (1 < eleccionOperacion && eleccionOperacion > 2);
        switch (eleccionOperacion) {
            case 1:
                System.out.println("El perímetro del cuadrado es " + Math.abs(C.perimetroCuadrado()));
                break;
            case 2:
                System.out.println("El área el cuadrado es " + Math.abs(C.areaCuadrado()));
                break;
        }
    }

    private static void controlaPentagono() {
        int eleccionOperacion;

        System.out.println("Introduzca los puntos del pentágono:");
        double x, y;
        entrada = new ArrayList();
        for (int i = 0; i < 5; i++) {
            System.out.println("Introduzca el " + i + " punto x:");
            x = teclado.nextDouble();
            System.out.println("Introduzca el " + i + " punto y:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }

        Pentagono P = new Pentagono(entrada);

        do {
            System.out.println("Seleccione una operacion a realizar:\n1.) Perímetro\n2.) Área");
            eleccionOperacion = teclado.nextInt();
        } while (1 < eleccionOperacion && eleccionOperacion > 2);
        switch (eleccionOperacion) {
            case 1:
                System.out.println("El perímetro del pentágono es: " + Math.abs(P.perimetroPentagono()));
                break;
            case 2:
                System.out.println("El área del pentágono es: " + Math.abs(P.areaPentagono()));
                break;
        }
    }

    private static void controlaHexagono() {
        int eleccionOperacion;

        System.out.println("Introduzca los puntos del hexágono:");
        double x, y;
        entrada = new ArrayList();
        for (int i = 0; i < 6; i++) {
            System.out.println("Introduzca el " + i + 1 + " punto x:");
            x = teclado.nextDouble();
            System.out.println("Introduzca el " + i + 1 + " punto y:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }
        Hexagono H = new Hexagono(entrada);

        do {
            System.out.println("Seleccione una operacion a realizar:\n1.) Perímetro\n2.) Área");
            eleccionOperacion = teclado.nextInt();
        } while (1 < eleccionOperacion && eleccionOperacion > 2);
        switch (eleccionOperacion) {
            case 1:
                System.out.println("El perímetro del hexágono es: " + Math.abs(H.perimetroHexagono()));
                break;
            case 2:
                System.out.println("El área del hexágono es: " + Math.abs(H.areaHexagono()));
                break;
        }
    }

}
