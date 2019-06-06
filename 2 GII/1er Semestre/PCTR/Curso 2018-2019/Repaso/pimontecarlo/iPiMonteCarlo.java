package pimontecarlo;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iPiMonteCarlo extends Remote {
    public String puntos(int p) throws RemoteException;
    public void reset() throws RemoteException;
}
