
import java.rmi.Naming;
import java.util.Scanner;

public class cBonoLoto {

    public static void main(String[] args) throws Exception {
        Scanner teclado = new Scanner(System.in);
        iBonoLoto RefObRemoto = (iBonoLoto) Naming.lookup("//localhost/Servidor");
        RefObRemoto.resetServidor();
        int[] apuesta = new int[6];
        System.out.println("Introduzca sus seis números:");
        for (int i = 0; i < 6; i++) {
            apuesta[i] = teclado.nextInt();
        }
        boolean ganador = RefObRemoto.compApuesta(apuesta);

        if (ganador) {
            System.out.println("Ha ganado");
        } else {
            System.out.println("Ha perdido");

        }
    }

}
