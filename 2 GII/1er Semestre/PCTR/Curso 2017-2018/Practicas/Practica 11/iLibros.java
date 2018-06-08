
import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public interface iLibros extends Remote {

    public void introducirLibro(Libro l) throws RemoteException;

    public boolean sacarLibro(String titulo) throws RemoteException;

    public Libro consultarLibro(String titulo) throws RemoteException;
}
