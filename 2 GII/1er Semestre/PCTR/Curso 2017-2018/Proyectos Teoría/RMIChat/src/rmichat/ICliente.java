package rmichat;

/**
 * @author Jesus
 */
import java.rmi.Remote;
import java.rmi.RemoteException;

interface ICliente extends Remote {

    public void recibirMensaje(String texto) throws RemoteException;
}
