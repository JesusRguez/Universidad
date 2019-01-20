package juego;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iJuego extends Remote{
    public String reset() throws RemoteException;
    public boolean hacerIntento(int numero) throws RemoteException;
}
