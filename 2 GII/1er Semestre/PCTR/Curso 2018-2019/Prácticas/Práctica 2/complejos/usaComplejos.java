/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package complejos;

import java.util.*;

public class usaComplejos{

    public static Scanner teclado = new Scanner(System.in);

    public static void main(String[] args) {
        int opcion;
        Complejos a = new Complejos();
        Complejos b = new Complejos();
        Complejos c = new Complejos();

        System.out.print("Introduzca la parte real del primer complejo: ");
        a.setReal(teclado.nextDouble());
        System.out.print("Introduzca la parte imaginaria del primer complejo: ");
        a.setImaginario(teclado.nextDouble());
        System.out.print("\nIntroduzca la parte real del segundo complejo: ");
        b.setReal(teclado.nextDouble());
        System.out.print("Introduzca la parte imaginaria del segundo complejo: ");
        b.setImaginario(teclado.nextDouble());

        do {
            System.out.println("Introduzca la opción que desea:\n1. Sumar dos complejos\n2. Restar dos complejos\n3. Módulo de un complejo\n4. Producto de dos complejos\n5. Cociente de dos complejos\n6. ¿Es nulo?\n7. Cuadrante\n8. Conjugado\n9. Salir.");
            opcion=teclado.nextInt();
            switch(opcion){
                case 1:
                    c = Complejos.suma(a, b);
                    System.out.println("El resultado es el complejo: ("+c.getReal()+", "+c.getImaginario()+")");
                    break;
                case 2:
                    c = Complejos.resta(a, b);
                    System.out.println("El resultado es el complejo: ("+c.getReal()+", "+c.getImaginario()+")");
                    break;
                case 3:
                    System.out.println("Seleccione el complejo al que quiere calcular el módulo:\n1. ("+a.getReal()+", "+a.getImaginario()+")\n2. ("+b.getReal()+", "+b.getImaginario()+")");
                    opcion = teclado.nextInt();
                    double res;
                    switch(opcion){
                        case 1:
                            res = Complejos.modulo(a);
                            System.out.println("El módulo del complejo es: "+res);
                            break;
                        case 2:
                            res = Complejos.modulo(b);
                            System.out.println("El módulo del complejo es: "+res);
                            break;
                        default:
                            System.out.println("Solo hay dos opciones, por favor, introduzca 1 ó 2.");
                    }
                    break;
                case 4:
                    c = Complejos.producto(a, b);
                    System.out.println("El resultado es el complejo: ("+c.getReal()+", "+c.getImaginario()+")");
                    break;
                case 5:
                    c = Complejos.cociente(a, b);
                    System.out.println("El resultado es el complejo: ("+c.getReal()+", "+c.getImaginario()+")");
                    break;
                case 6:
                    System.out.println("Seleccione el complejo que quiere comprobar si es nulo:\n1. ("+a.getReal()+", "+a.getImaginario()+")\n2. ("+b.getReal()+", "+b.getImaginario()+")");
                    opcion = teclado.nextInt();
                    switch(opcion){
                        case 1:
                            if(a.esComplejoNulo()){
                                System.out.println("El complejo introducido es nulo");
                            }else{
                                System.out.println("El complejo introducido no es nulo");
                            }
                            break;
                        case 2:
                            if(b.esComplejoNulo()){
                                System.out.println("El complejo introducido es nulo");
                            }else{
                                System.out.println("El complejo introducido no es nulo");
                            }
                            break;
                        default:
                            System.out.println("Solo hay dos opciones, por favor, introduzca 1 ó 2.");
                    }
                    break;
                case 7:
                    System.out.println("Seleccione el complejo al que le quiere comprobar el cuadrante:\n1. ("+a.getReal()+", "+a.getImaginario()+")\n2. ("+b.getReal()+", "+b.getImaginario()+")");
                    opcion = teclado.nextInt();
                    switch(opcion){
                        case 1:
                            System.out.println("El complejo introducido está en el cuadrante "+a.cuadranteComplejo());
                            break;
                        case 2:
                            System.out.println("El complejo introducido está en el cuadrante "+b.cuadranteComplejo());
                            break;
                        default:
                            System.out.println("Solo hay dos opciones, por favor, introduzca 1 ó 2.");
                    }
                    break;
                case 8:
                    System.out.println("Seleccione el complejo al que le quiere calcular el conjugado:\n1. ("+a.getReal()+", "+a.getImaginario()+")\n2. ("+b.getReal()+", "+b.getImaginario()+")");
                    opcion = teclado.nextInt();
                    switch(opcion){
                        case 1:
                            c = a.conjugadoComplejos();
                            System.out.println("El conjugado del complejo introducido es ("+c.getReal()+", "+c.getImaginario()+")");
                            break;
                        case 2:
                            c = b.conjugadoComplejos();
                            System.out.println("El conjugado del complejo introducido es ("+c.getReal()+", "+c.getImaginario()+")");
                            break;
                        default:
                            System.out.println("Solo hay dos opciones, por favor, introduzca 1 ó 2.");
                    }
                    break;
                case 9:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay seis opciones, por favor, seleccione 1, 2, 3, 4, 5 ó 6.");
            }
        } while (opcion != 9);

    }
}
