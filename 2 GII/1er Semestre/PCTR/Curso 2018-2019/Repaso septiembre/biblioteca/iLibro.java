package biblioteca;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iLibro extends Remote{
    public void insertarLibro(Libro l) throws RemoteException;
    public boolean extraerLibro(String titulo) throws RemoteException;
    public Libro consultarLibro(String titulo) throws RemoteException;
}
