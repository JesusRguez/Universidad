package biblioteca;

import java.rmi.Naming;
import java.util.*;

public class cLibro{
    public static void main(String[] args) throws Exception{
        iLibro ORemoto = (iLibro)Naming.lookup("biblioteca");
        Scanner teclado = new Scanner(System.in);
        int opcion;
        do {
            System.out.println("Introduzca una opción\n1. Insertar libro\n2. Borrar libro\n3. Consultar libro\n4. Salir");
            opcion = teclado.nextInt();
            String titulo = "";
            switch (opcion) {
                case 1:
                    System.out.print("Introduzca el título del libro: ");
                    teclado.nextLine();
                    titulo = teclado.nextLine();
                    System.out.print("Introduzca el autor del libro: ");
                    String autor = teclado.nextLine();
                    System.out.print("Introduzca la editorial del libro: ");
                    String editorial = teclado.nextLine();
                    System.out.print("Introduzca la ISBN del libro: ");
                    String isbn = teclado.nextLine();
                    Libro nuevo = new Libro(titulo, autor, editorial, isbn);
                    ORemoto.insertarLibro(nuevo);
                    System.out.println("Libro insertado");
                break;
                case 2:
                    System.out.print("Introduzca el título del libro que desea extraer: ");
                    teclado.nextLine();
                    titulo = teclado.nextLine();
                    if (ORemoto.extraerLibro(titulo)){
                        System.out.println("Libro extraido correctamente.");
                    }else{
                        System.out.println("El libro no se encuentra disponible.");
                    }
                break;
                case 3:
                    Libro l = new Libro();
                    System.out.print("Introduzca el título del libro que desea consultar: ");
                    teclado.nextLine();
                    titulo = teclado.nextLine();
                    l = ORemoto.consultarLibro(titulo);
                    if (l==null) {
                        System.out.println("No se encontró el libro.");
                    }else{
                        System.out.println(l.toString());
                    }
                break;
                case 4:
                    System.exit(0);
                break;
                default:
                    System.out.println("Solo hay cuatro opciones, por favor, introduzca una opción correcta.");
            }
        } while (opcion != 4);
    }
}
