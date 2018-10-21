/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package elipse;

import java.util.*;

class usaElipse{
    public static void main(String[] args) {
        int opcion;
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el radio menor de la elipse:");
        double a = teclado.nextDouble();
        System.out.println("Introduzca el readio mayor de la elipse:");
        double b = teclado.nextDouble();
        System.out.println("Introduzca la coordenada x del centro de la elipse:");
        double o1 = teclado.nextDouble();
        System.out.println("Introduzca la cooreenada y del centro de la elipse:");
        double o2 = teclado.nextDouble();

        Elipse E = new Elipse(a, b, o1, o2);
        do {
            do {
                System.out.println("Seleccione qué desea hacer:\n1.) Saber si un punto pertenece a la elipse\n2.) Superficie de la elipse\n3.) Perímetro de la elipse\n4.) Radio menor de la elipse\n5.) Radio mayor de la elipse\n6. Salir");
                opcion = teclado.nextInt();
                switch (opcion) {
                    case 1:
                        System.out.println("Introduce la coordenada x del punto:");
                        double x = teclado.nextDouble();
                        System.out.println("Introduce la coordenada y del punto:");
                        double y = teclado.nextDouble();
                        boolean dentro = E.puntoPertenece(x, y);
                        if (dentro == true) {
                            System.out.println("El punto pertenece la elipse.");
                        } else {
                            System.out.println("El punto no pertenece a la elpise.");
                        }
                        break;
                    case 2:
                        System.out.println("El área de la elipse es " + E.area());
                        break;
                    case 3:
                        System.out.println("El perímetro de la elipse es " + E.perimetro());
                        break;
                    case 4:
                        System.out.println("El radio mayor de la elipse es " + E.radioMenor());
                        break;
                    case 5:
                        System.out.println("El radio menor de la elipse es " + E.radioMayor());
                        break;
                    case 6:
                        break;
                    default:
                        System.out.println("Solo hay seis opciones, por favor, seleccione 1, 2, 3, 4, 5 ó 6.");
                }
            } while (1 < opcion && opcion > 6);
        } while (opcion != 6);
    }
}
