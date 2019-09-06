import java.rmi.Naming;
import java.util.*;

public class primesClient{
    public static void main(String[] args) throws Exception {
        primesInterface ORemoto = (primesInterface)Naming.lookup("primes");
        Scanner teclado = new Scanner(System.in);
        int opcion;
        System.out.println("Aplicación para buscar primos en un rango");
        int r, m;
        do {
            System.out.print("Introduzca el rango de búsqueda: ");
            r = teclado.nextInt();
            System.out.print("Indique cuantos subrangos desea: ");
            m = teclado.nextInt();

            if (r < 0) {
                System.out.println("El rango debe ser mayor a 0");
            }
            if (r < m) {
                System.out.println("El número de subrangos debe ser menor que el rango total");
            }
        } while (r<m || r<0);

        int beginRange = 1;
        int endRange = r/m;
        int primos = 0;
        for (int i=0; i<m; ++i) {
            primos += ORemoto.primesInRange(beginRange, endRange);
            beginRange += (r/m);
            endRange += (r/m);
        }
        System.out.println("El número de primos en el rango dado es "+(primos-1)); //Le restamos 1 porque "El 1 no cuenta como primo" - Dicho por Antonio Tomeu en el transcurso del examen
    }
}
