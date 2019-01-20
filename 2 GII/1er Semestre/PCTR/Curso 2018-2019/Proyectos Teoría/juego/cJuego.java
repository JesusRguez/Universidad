package juego;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.Naming;
import java.util.*;

public class cJuego{
    public static void main(String[] args) throws Exception{
        iJuego ORemoto = (iJuego)Naming.lookup("juego");
        Scanner teclado = new Scanner(System.in);
        int opcion;
        do {
            System.out.println("Introduzca la opción que desea:\n1. Hacer intento\n2. Resetear servidor\n3. Salir");
            opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    System.out.print("Introduzca el número a comprobar: ");
                    int n = teclado.nextInt();
                    boolean acierto = ORemoto.hacerIntento(n);
                    if (acierto) {
                        System.out.println("Has acertado\n¿Quieres volver a probar? (S/N)");
                        teclado.nextLine();
                        String reset = teclado.nextLine();
                        if (reset.toLowerCase().equals("s")) {
                            String respuesta = ORemoto.reset();
                            System.out.println(respuesta);
                        }else{
                            System.exit(0);
                        }
                    }else{
                        System.out.println("No has hacertado\n¿Quieres volver a probar? (S/N)");
                        teclado.nextLine();
                        String reset = teclado.nextLine();
                        if (reset.toLowerCase().equals("n")) {
                            System.exit(0);
                        }
                    }
                break;
                case 2:
                String res = ORemoto.reset();
                System.out.println(res);
                break;
                case 3:
                    System.exit(0);
                break;
                default:
                System.out.println("Introduzca una opción válida");
            }
        } while (opcion != 3);
    }
}
