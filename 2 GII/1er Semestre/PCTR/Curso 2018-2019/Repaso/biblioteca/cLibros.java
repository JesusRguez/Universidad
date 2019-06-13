package biblioteca;

import java.rmi.Naming;
import java.util.*;

public class cLibros{
    public static void main(String[] args) throws Exception {
        iLibros ORemoto = (iLibros)Naming.lookup("biblioteca");
        Scanner teclado = new Scanner(System.in);
        int opcion;
        do {
            System.out.println("Introduzca una opción:\n1. Insertar un nuevo libro\n2. Extraer un libro\n3. Consultar un libro\n4. Salir");
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
                    Libro lNuevo = new Libro(titulo, autor, editorial, isbn);
                    ORemoto.insertarLibro(lNuevo);
                    System.out.println("Libro insertado");
                break;
                case 2:
                    System.out.print("Introduzca el título del libro a extraer: ");
                    teclado.nextLine();
                    titulo = teclado.nextLine();
                    boolean encontrado = ORemoto.extraerLibro(titulo);
                    if (encontrado) {
                        System.out.println("El libro se ha extraido satisfactoriamente");
                    }else{
                        System.out.println("El libro no se ha encontrado");
                    }
                break;
                case 3:
                    System.out.print("Introduzca el título del libro que de sea consultar: ");
                    teclado.nextLine();
                    titulo = teclado.nextLine();
                    Libro l = ORemoto.consultarLibro(titulo);
                    if (l == null) {
                        System.out.println("No se ha encontrado el libro");
                    }else{
                        System.out.println(l.toString());
                    }
                break;
                case 4:

                break;
                default:
                    System.out.println("Solo hay 4 opciones, por favor, introduzca 1, 2, 3 ó 4.");
            }
        } while (opcion != 4);
    }
}
