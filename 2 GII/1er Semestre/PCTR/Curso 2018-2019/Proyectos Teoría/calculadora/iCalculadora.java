package calculadora;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iCalculadora extends Remote{
    public double suma(double a, double b) throws RemoteException;
    public double resta(double a, double b) throws RemoteException;
    public double multiplicacion(double a, double b) throws RemoteException;
    public double division(double a, double b) throws RemoteException;
}
