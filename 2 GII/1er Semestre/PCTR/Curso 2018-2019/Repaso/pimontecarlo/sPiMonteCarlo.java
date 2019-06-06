package pimontecarlo;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;

public class sPiMonteCarlo extends UnicastRemoteObject implements iPiMonteCarlo{

    public int puntosTotales;
    public int aciertos;
    public double aprox;

    public sPiMonteCarlo() throws Exception{
        puntosTotales = 0;
        aciertos = 0;
        aprox = 0;
    }

    public String puntos(int p) throws RemoteException{
        puntosTotales += p;
        for (int i = 0; i < p; ++i) {
            double x = Math.random();
            double y = Math.random();
            if(Math.pow(x, 2) + Math.pow(y, 2) <= 1){
                aciertos++;
            }
        }
        aprox = 4.0*aciertos/puntosTotales;
        return ("La aproximación con "+puntosTotales+" es: "+aprox+". Aciertos: "+aciertos);
    }

    public void reset() throws RemoteException{
        puntosTotales = 0;
        aciertos = 0;
        aprox = 0;
    }

    public static void main(String[] args) throws Exception{
        iPiMonteCarlo OServidor = new sPiMonteCarlo();
        Naming.rebind("pi", OServidor);
        System.out.println("Servidor preparado");
    }
}
