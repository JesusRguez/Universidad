package ibex5;

import java.rmi.*;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.Naming;
import java.util.*;

public class cIBEX5{

    public static void main(String[] args) throws Exception {
        iIBEX5 ORemoto = (iIBEX5)Naming.lookup("ibex5");
        int opcion;
        Scanner teclado = new Scanner(System.in);
        do {
            System.out.println("Introduzca la opción que desea:\n1. Consultar todas las cotizaciones\n2. Consutlar la cotización de una entidad\n3. Salir");
            opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    System.out.println(ORemoto.consultarCotizaciones());
                break;
                case 2:
                    System.out.print("Introduzca el nombre de la entidad a consultar: ");
                    teclado.nextLine();
                    String e = teclado.nextLine();
                    String entidad = ORemoto.consultarCotizacion(e);
                    if (entidad == null) {
                        System.out.println("No se ha encontrado dicha entidad");
                    }else{
                        System.out.println(entidad+"\n");
                    }
                break;
                case 3:
                    System.exit(0);
                break;
                default:
                    System.out.println("Por favor, introduzca una opción válida.");
            }
        } while (opcion !=3);
    }
}
