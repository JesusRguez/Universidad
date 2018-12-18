import java.rmi.Naming;
import java.util.*;

public class ClienteAhorcado {

    public static void main(String[] args) throws Exception {
        //IAhorcado ORemoto = (IAhorcado)Naming.lookup("ahorcado");//Para mi ordenador
        IAhorcado ORemoto = (IAhorcado)Naming.lookup("//10.142.105.196/Ahorcado");//Para el de Salguero
        boolean fin = false;
        Scanner teclado = new Scanner(System.in);
        String entrada;
        do {
            System.out.print("Introduzca letra o palabra: ");
            entrada = teclado.nextLine();
            if(entrada.length() == 1){
                System.out.println(ORemoto.enviarLetra(entrada.charAt(0)));
            }else{
                fin = ORemoto.enviarPalabra(entrada);
                if (fin == false) {
                    System.out.println("Palabra no acertada");
                }else{
                    System.out.println("Palabra acertada.\nHAS GANADO!");
                }
            }
        } while (!fin);
    }
}
