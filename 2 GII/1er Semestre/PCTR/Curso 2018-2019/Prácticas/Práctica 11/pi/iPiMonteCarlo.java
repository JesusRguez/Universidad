/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package pi;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iPiMonteCarlo extends Remote{

    /**
     * Método reset
     * @throws RemoteException Lanza una excepción si el reset falla
     */
    public void reset() throws RemoteException;

    /**
     * Método masPuntos
     * @param  nPuntos         Número de puntos que recibe
     * @throws RemoteException Lanza una excepción si falla
     */
    public String masPuntos(int nPuntos)  throws RemoteException;
}
