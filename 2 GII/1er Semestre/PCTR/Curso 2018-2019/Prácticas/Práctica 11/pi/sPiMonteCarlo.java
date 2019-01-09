/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package pi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;

public class sPiMonteCarlo extends UnicastRemoteObject implements iPiMonteCarlo{

    public int puntosTotales;
    public int aciertos;
    public double aprox;

    /**
     * Constructor de sPiMonteCarlo
     */
    public sPiMonteCarlo() throws Exception{
        puntosTotales = 0;
        aciertos = 0;
        aprox = 0;
    }

    /**
     * Método reset
     * @throws RemoteException Lanza una excepción si el reset falla
     */
    public void reset() throws RemoteException{
        puntosTotales = 0;
        aciertos = 0;
        aprox = 0;
    }

    /**
     * Método masPuntos
     * @param  nPuntos         Número de puntos que recibe
     * @throws RemoteException Lanza una excepción si falla
     */
    public String masPuntos(int nPuntos)  throws RemoteException{
        puntosTotales += nPuntos;
        for (int i = 0; i < nPuntos; ++i) {
            double x = Math.random();
            double y = Math.random();
            if(Math.pow(x, 2) + Math.pow(y, 2) <= 1){
                aciertos++;
            }
        }
        aprox = 4.0*aciertos/puntosTotales;
        return ("Aproximacion actual: "+aprox+" con "+puntosTotales+" puntos y "+aciertos+" aciertos");
    }

    public static void main(String[] args) throws Exception{
        iPiMonteCarlo OServidor = new sPiMonteCarlo();
        Naming.rebind("pi", OServidor);
        System.out.println("Servidor preparado");
    }
}
