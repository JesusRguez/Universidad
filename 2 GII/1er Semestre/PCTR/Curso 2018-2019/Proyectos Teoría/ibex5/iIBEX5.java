package ibex5;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iIBEX5 extends Remote {
    public String consultarCotizaciones() throws RemoteException;
    public String consultarCotizacion(String e) throws RemoteException;
}
