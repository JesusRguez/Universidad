/**
 * @author Jesús Rodríguez Heas
 * @version 1.00
 */

package bonoloto;

import java.rmi.Naming;
import java.util.*;

public class cBonoLoto{
    public static void main(String[] args) throws Exception{
        iBonoLoto ORemoto = (iBonoLoto)Naming.lookup("bonoloto");
        boolean fin = false;
        int n;
        String p = "N";
        Scanner teclado = new Scanner(System.in);
        do {
            System.out.print("Introduzca una apuesta:");
            n = teclado.nextInt();
            fin = ORemoto.compApuesta(n);
            if (fin) {
                System.out.println("Has acertado");
                System.out.println("¿Quieres probar de nuevo? (S/N)");
                teclado.nextLine();
                p = teclado.nextLine();
                if (p.toLowerCase().equals("s")) {
                    ORemoto.resetServidor();
                    System.out.println("Has dicho de seguir");
                    fin = false;
                }
            }else{
                System.out.println("No has acertado. Prueba otra vez");
            }
        } while (!fin);
    }
}
