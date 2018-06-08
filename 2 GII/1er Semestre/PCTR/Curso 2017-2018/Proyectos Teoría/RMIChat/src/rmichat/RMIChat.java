package rmichat;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;

/**
 * @author Jesus
 */
public class RMIChat extends UnicastRemoteObject implements IRMIChat {

    Vector<ICliente> clientes = new Vector<ICliente>();

    public RMIChat() throws RemoteException {
    }

    public static void main(String[] args) throws Exception {
        RMIChat chat = new RMIChat();
        Naming.rebind("//localhost/chat", chat);
        System.out.println("Servidor preparado");
    }

    @Override
    public void enviarMensaje(String mensaje) throws RemoteException {
        for (int i = 0; i < clientes.size(); i++) {
            clientes.get(i).recibirMensaje(mensaje);
        }
    }

    @Override
    public void registrar(ICliente cliente) {
        clientes.add(cliente);
    }

}
