package rmichat;

/**
 * @author Jesus
 */
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

public class Cliente extends UnicastRemoteObject implements ICliente {

    public Cliente() throws RemoteException {
    }

    public static void main(String[] args) throws Exception {
        Cliente cliente = new Cliente();
        IRMIChat servidor = (IRMIChat) Naming.lookup("//" + args[0] + "/chat");
        servidor.registrar(cliente);

        Scanner teclado = new Scanner(System.in);
        String texto = "";
        while (!texto.equals("salir")) {
            texto = teclado.nextLine();
            servidor.enviarMensaje(texto);
        }
    }

    public void recibirMensaje(String texto) throws RemoteException {
        System.out.println(texto);
    }
}
