/**
 * @author Jesús Rodríguez Heas
 * @version 1.00
 */

package bonoloto;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iBonoLoto extends Remote{

    /**
     * Método para resetear el servidor
     * @return Devuelve un mensaje para saber que se ha reseteado el servidor
     * @throws RemoteException Lanza una excepción si falla
     */
    public String resetServidor() throws RemoteException;

    /**
     * Método para comparar si la apuesta es válida
     * @param  apuesta         Apuesta recibida
     * @return                 Devuelve true si coincide y false en caso contrario
     * @throws RemoteException Lanza una excepción si falla
     */
    public boolean compApuesta(int apuesta)  throws RemoteException;
}
