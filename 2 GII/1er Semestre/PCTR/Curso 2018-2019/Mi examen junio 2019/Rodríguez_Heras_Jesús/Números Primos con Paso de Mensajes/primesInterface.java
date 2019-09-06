import java.rmi.Remote;
import java.rmi.RemoteException;

public interface primesInterface extends Remote{
    /**
     * Método primesInRange
     * @param  beginRange      Inicio del rango
     * @param  endRange        Fin del rango
     * @return                 Devuelve el número de primos en el rango recibido
     */
    public int primesInRange(int beginRange, int endRange) throws RemoteException;
}
