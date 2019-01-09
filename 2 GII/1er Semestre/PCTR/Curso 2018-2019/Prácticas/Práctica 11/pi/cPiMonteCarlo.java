/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package pi;

import java.rmi.Naming;
import java.util.*;

public class cPiMonteCarlo{
    public static void main(String[] args) throws Exception{
        iPiMonteCarlo ORemoto = (iPiMonteCarlo)Naming.lookup("pi");
        Scanner teclado = new Scanner(System.in);
        String p = "N";
        int o = 0;
        do {
            System.out.println("¿Qué desea hacer?\n1. Enviar más puntos\n2. Resetear el servidor\n3. Salir");
            o = teclado.nextInt();
            switch (o) {
                case 1:
                    System.out.println("Introduzca el número de puntos que desea enviar");
                    int n = teclado.nextInt();
                    String respuesta = ORemoto.masPuntos(n);
                    System.out.println(respuesta);
                break;
                case 2:
                    ORemoto.reset();
                break;
                case 3:
                    System.exit(0);
                break;
            }
        } while (!p.toLowerCase().equals("s"));

    }
}
