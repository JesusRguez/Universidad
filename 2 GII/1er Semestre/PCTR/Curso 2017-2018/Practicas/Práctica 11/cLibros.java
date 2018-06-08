
import java.rmi.Naming;
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class cLibros {

    public static void main(String[] args) throws Exception {
        Scanner teclado = new Scanner(System.in);
        iLibros RefObRemoto = (iLibros) Naming.lookup("//localhost/Servidor");

        System.out.println("Introduzca la opcion que desea:\n1.) Introducir libro\n2.) Sacar libro\n3.) Consultar libro");
        int decision = teclado.nextInt();

        switch (decision) {
            case 1:
                teclado.nextLine();
                System.out.println("Introduzca la ISBN del libro:");
                String ISBN = teclado.nextLine();
                System.out.println("Introduzca el título del libro:");
                String titulo = teclado.nextLine();
                System.out.println("Introduzca el autor:");
                String autor = teclado.nextLine();
                boolean reservado = false;
                Libro l = new Libro(ISBN, titulo, autor, reservado);
                RefObRemoto.introducirLibro(l);
                break;
            case 2:
                teclado.nextLine();
                System.out.println("Introduzca el titulo:");
                titulo = teclado.nextLine();
                reservado = RefObRemoto.sacarLibro(titulo);
                if (reservado) {
                    System.out.println("El libro ha sido reservado por usted");
                } else {
                    System.out.println("El libro ya estaba reservado");
                }
                break;
            case 3:
                teclado.nextLine();
                System.out.println("Introduzca el título:");
                titulo = teclado.nextLine();
                l = RefObRemoto.consultarLibro(titulo);
                if (l == null) {
                    System.out.println("No existe el libro");
                } else {
                    System.out.println(l.ISBN + "\n" + l.titulo + "\n" + l.autor + "\n" + l.reservado);
                }

                break;

        }

    }
}
