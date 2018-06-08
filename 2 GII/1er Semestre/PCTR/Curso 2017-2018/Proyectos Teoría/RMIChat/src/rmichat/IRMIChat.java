package rmichat;

/**
 * @author Jesus
 */
import java.rmi.Remote;
import java.rmi.RemoteException;

interface IRMIChat extends Remote {

    public void enviarMensaje(String mensaje) throws RemoteException;

    public void registrar(ICliente cliente) throws RemoteException;
}
