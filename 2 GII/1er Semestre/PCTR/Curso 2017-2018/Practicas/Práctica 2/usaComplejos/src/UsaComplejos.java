
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class UsaComplejos {

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        double real, imaginario;

        int opcion;
        do {
            System.out.println("CALCULADORA DE COMPLEJOS:"); //Menú para el usuario
            System.out.println("Elige una operación:\n1.) Suma\n2.) Resta\n3.) Modulo (solo un complejo)\n4.) Producto\n5.) Cociente\n6.) ¿Es nulo? (solo un complejo)\n7.) ¿A qué cuadrante pertenece? (solo un complejo)\n8.) Conjugado (solo un complejo)");
            opcion = teclado.nextInt();
        } while (1 < opcion && opcion > 8);

        System.out.println("Introduce el primer número complejo: Parte real ENTER, parte imaginaria ENTER:");
        real = teclado.nextDouble();
        imaginario = teclado.nextDouble();
        Complejos a = new Complejos(real, imaginario);

        System.out.println("Introduce el segundo número complejo: Parte real ENTER, parte imaginaria ENTER:");
        real = teclado.nextDouble();
        imaginario = teclado.nextDouble();
        Complejos b = new Complejos(real, imaginario);

        switch (opcion) {
            case 1:
                System.out.println("La suma es " + Complejos.sumaComplejos(a, b));
                break;
            case 2:
                System.out.println("La resta es " + Complejos.restaComplejos(a, b));
                break;
            case 3:
                System.out.println("El módulo es " + Complejos.moduloComplejos(a));
                break;
            case 4:
                System.out.println("El producto es " + Complejos.productoComplejos(a, b));
                break;
            case 5:
                System.out.println("El cociente es " + Complejos.cocienteComplejos(a, b));
                break;
            case 6:
                if (Complejos.nulo(a) == true) {
                    System.out.println("Es nulo.");
                } else {
                    System.out.println("No es nulo.");
                }
                break;
            case 7:
                System.out.println("Pertenece al " + Complejos.cuadrante(a) + " cuadrante.");
                break;
            case 8:
                System.out.println("El conjugado es " + Complejos.conjugado(a));
                break;
        }
    }
}
