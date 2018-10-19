/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package complejos;

import java.util.*;

class usaComplejos{

    public static Scanner teclado = new Scanner(System.in);

    public static void main(String[] args) {
        int opcion;
        Complejos a = new Complejos();
        Complejos b = new Complejos();
        Complejos c = new Complejos();
        do {
            do {
                System.out.println("Introduzca la opción que desea:\n1. Sumar dos complejos\n2. Restar dos complejos\n3. Módulo de un complejo\n4. Producto de dos complejos\n5. Cociente de dos complejos\n6. Salir.");
                opcion=teclado.nextInt();
                switch(opcion){
                    case 1:
                        System.out.print("Introduzca la parte real del primer complejo: ");
                        a.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del primer complejo: ");
                        a.imaginario = teclado.nextDouble();
                        System.out.print("\nIntroduzca la parte real del segundo complejo: ");
                        b.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del segundo complejo: ");
                        b.imaginario = teclado.nextDouble();
                        c = Complejos.suma(a, b);
                        System.out.println("El resultado es el complejo: ("+c.real+", "+c.imaginario+")");
                        break;
                    case 2:
                        System.out.print("Introduzca la parte real del primer complejo: ");
                        a.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del primer complejo: ");
                        a.imaginario = teclado.nextDouble();
                        System.out.print("\nIntroduzca la parte real del segundo complejo: ");
                        b.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del segundo complejo: ");
                        b.imaginario = teclado.nextDouble();
                        c = Complejos.resta(a, b);
                        System.out.println("El resultado es el complejo: ("+c.real+", "+c.imaginario+")");
                        break;
                    case 3:
                        System.out.print("Introduzca la parte real del primer complejo: ");
                        a.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del primer complejo: ");
                        a.imaginario = teclado.nextDouble();
                        double res = Complejos.modulo(a);
                        System.out.println("El módulo del complejo es: "+res);
                        break;
                    case 4:
                        System.out.print("Introduzca la parte real del primer complejo: ");
                        a.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del primer complejo: ");
                        a.imaginario = teclado.nextDouble();
                        System.out.print("\nIntroduzca la parte real del segundo complejo: ");
                        b.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del segundo complejo: ");
                        b.imaginario = teclado.nextDouble();
                        c = Complejos.producto(a, b);
                        System.out.println("El resultado es el complejo: ("+c.real+", "+c.imaginario+")");
                        break;
                    case 5:
                        System.out.print("Introduzca la parte real del primer complejo: ");
                        a.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del primer complejo: ");
                        a.imaginario = teclado.nextDouble();
                        System.out.print("\nIntroduzca la parte real del segundo complejo: ");
                        b.real = teclado.nextDouble();
                        System.out.print("Introduzca la parte imaginaria del segundo complejo: ");
                        b.imaginario = teclado.nextDouble();
                        c = Complejos.cociente(a, b);
                        System.out.println("El resultado es el complejo: ("+c.real+", "+c.imaginario+")");
                        break;
                    case 6:
                        break;
                }
                if (opcion < 1 || opcion > 6) {
                    System.out.println("Solo hay cuatro opciones, por favor, seleccione 1, 2, 3, 4, 5 ó 6.");
                }
            } while (opcion < 1 && opcion > 6);
        } while (opcion != 6);

    }
}
