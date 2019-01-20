package calculadora;

import java.rmi.server.UnicastRemoteObject;
import java.rmi.Naming;
import java.rmi.Remote;
import java.rmi.RemoteException;

public class sCalculadora extends UnicastRemoteObject implements iCalculadora{

    public sCalculadora()throws RemoteException{};

    public double suma(double a, double b) throws RemoteException{
        return a+b;
    }

    public double resta(double a, double b) throws RemoteException{
        return a-b;
    }

    public double multiplicacion(double a, double b) throws RemoteException{
        return a*b;
    }

    public double division(double a, double b) throws RemoteException{
        return a/b;
    }

    public static void main(String[] args) throws Exception {
        iCalculadora OServidor = new sCalculadora();
        Naming.rebind("calculadora", OServidor);
        System.out.println("Servidor preparado...");
    }
}
