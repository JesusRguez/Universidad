
import java.rmi.Naming;
import java.util.Scanner;

/**
 * @author Jes�s Rod�guez Heras
 * @version 1.0
 */
public class cPiMonteCarlo {

    public static void main(String[] args) throws Exception {
        Scanner teclado = new Scanner(System.in);
        iPiMonteCarlo RefObRemoto = (iPiMonteCarlo) Naming.lookup("//localhost/Servidor");
        RefObRemoto.reset();

        System.out.println("Introduzca el n�mero total de puntos que desea:");
        int nPuntos = teclado.nextInt();
        RefObRemoto.masPuntos(nPuntos);
    }

}
