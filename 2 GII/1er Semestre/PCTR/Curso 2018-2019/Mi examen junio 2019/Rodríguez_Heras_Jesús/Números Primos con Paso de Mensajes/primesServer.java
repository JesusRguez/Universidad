import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;
import java.util.*;

public class primesServer extends UnicastRemoteObject implements primesInterface{

    /**
     * Contructor predeterminado de primesServer
     */
    public primesServer() throws RemoteException{}

    /**
     * Método primesInRange
     * @param  beginRange      Inicio del rango
     * @param  endRange        Fin del rango
     * @return                 Devuelve el número de primos en el rango recibido
     */
    public int primesInRange(int beginRange, int endRange) throws RemoteException{
        boolean esPrimo;
        int primos = 0;
        for(int i = beginRange; i <= endRange; ++i){
            esPrimo=true;
            for(int j = 2; j < i; ++j){
                if(i % j == 0){
                    esPrimo = false;
                }
            }
            if(esPrimo){
                primos++;
            }
        }
        return primos;
    }

    public static void main(String[] args) throws Exception {
        primesInterface OServidor = new primesServer();
        Naming.rebind("primes", OServidor);
        System.out.println("Servidor preparado");
    }
}
