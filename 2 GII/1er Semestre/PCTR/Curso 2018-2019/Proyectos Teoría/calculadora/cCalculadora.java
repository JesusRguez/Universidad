package calculadora;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.Naming;
import java.util.*;

public class cCalculadora{
    public static void main(String[] args) throws Exception {
        iCalculadora ORemoto = (iCalculadora)Naming.lookup("calculadora");
        Scanner teclado = new Scanner(System.in);
        int opcion;
        String repetir;
        double a, b, r;
        do {
            System.out.println("Introduzca la opción que desea:\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. Salir");
            opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    System.out.print("Introduzca el primer número: ");
                    a = teclado.nextDouble();
                    System.out.print("Introduzca el segundo número: ");
                    b = teclado.nextDouble();
                    r = ORemoto.suma(a, b);
                    System.out.println("El resultado es: "+r);
                    System.out.print("¿Desea realizar otra operación? (S/N)");
                    teclado.nextLine();
                    repetir = teclado.nextLine();
                    if (repetir.toLowerCase().equals("n")) {
                        System.exit(0);
                    }
                break;
                case 2:
                    System.out.print("Introduzca el primer número: ");
                    a = teclado.nextDouble();
                    System.out.print("Introduzca el segundo número: ");
                    b = teclado.nextDouble();
                    r = ORemoto.resta(a, b);
                    System.out.println("El resultado es: "+r);
                    System.out.print("¿Desea realizar otra operación? (S/N)");
                    teclado.nextLine();
                    repetir = teclado.nextLine();
                    if (repetir.toLowerCase().equals("n")) {
                        System.exit(0);
                    }
                break;
                case 3:
                    System.out.print("Introduzca el primer número: ");
                    a = teclado.nextDouble();
                    System.out.print("Introduzca el segundo número: ");
                    b = teclado.nextDouble();
                    r = ORemoto.multiplicacion(a, b);
                    System.out.println("El resultado es: "+r);
                    System.out.print("¿Desea realizar otra operación? (S/N)");
                    teclado.nextLine();
                    repetir = teclado.nextLine();
                    if (repetir.toLowerCase().equals("n")) {
                        System.exit(0);
                    }
                break;
                case 4:
                    System.out.print("Introduzca el primer número: ");
                    a = teclado.nextDouble();
                    System.out.print("Introduzca el segundo número: ");
                    b = teclado.nextDouble();
                    if (b == 0) {
                        System.out.println("No se puede dividir por 0");
                        System.out.print("¿Desea realizar otra operación? (S/N)");
                        teclado.nextLine();
                        repetir = teclado.nextLine();
                        if (repetir.toLowerCase().equals("n")) {
                            System.exit(0);
                        }
                    }else{
                        r = ORemoto.division(a, b);
                        System.out.println("El resultado es: "+r);
                        System.out.print("¿Desea realizar otra operación? (S/N)");
                        teclado.nextLine();
                        repetir = teclado.nextLine();
                        if (repetir.toLowerCase().equals("n")) {
                            System.exit(0);
                        }
                    }
                break;
                case 5:
                    System.exit(0);
                break;
                default:
                    System.out.println("Introduzca una opción válida");
            }
        } while (opcion != 5);
    }
}
