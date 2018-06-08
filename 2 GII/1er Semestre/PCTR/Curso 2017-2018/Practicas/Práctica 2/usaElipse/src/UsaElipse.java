
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class UsaElipse {

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int opcion;

        System.out.println("Introduzca el radio menor de la elipse:");
        double a = teclado.nextDouble();
        System.out.println("Introduzca el readio mayor de la elipse:");
        double b = teclado.nextDouble();
        System.out.println("Introduzca la coordenada x del centro de la elipse:");
        double o1 = teclado.nextDouble();
        System.out.println("Introduzca la cooreenada y del centro de la elipse:");
        double o2 = teclado.nextDouble();

        Elipse A = new Elipse(a, b, o1, o2);
        do {
            System.out.println("Seleccione qué desea hacer:\n1.) Saber si un punto pertenece a la elipse\n2.) Superficie de la elipse\n3.) Perímetro de la elipse\n4.)Radio menor de la elipse\n5.) Radio mayor de la elipse");
            opcion = teclado.nextInt();
        } while (1 < opcion && opcion > 5);

        System.out.println("Introduce la coordenada x del punto:");
        double x = teclado.nextDouble();
        System.out.println("Introduce la coordenada y del punto:");
        double y = teclado.nextDouble();

        switch (opcion) {
            case 1:
                boolean dentro = A.esUnPunto(x, y);
                if (dentro == true) {
                    System.out.println("El punto está dentro de la elipse.");
                } else {
                    System.out.println("El punto no está dentro de la elpise.");
                }
                break;
            case 2:
                System.out.println("La superficie de la elipse es " + A.superficie());
                break;
            case 3:
                System.out.println("El perímetro de la elipse es " + A.perimetro());
                break;
            case 4:
                System.out.println("El radio mayor es " + A.radioA());
                break;
            case 5:
                System.out.println("El radio menor es " + A.radioB());
                break;
        }
    }
}
