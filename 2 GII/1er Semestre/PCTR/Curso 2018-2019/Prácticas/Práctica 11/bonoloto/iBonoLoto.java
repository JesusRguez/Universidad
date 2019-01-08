/**
 * @author Jesús Rodríguez Heas
 * @version 1.00
 */

package bonoloto;

import java.rmi.*;
public interface iBonoLoto extends Remote{

    public void resetServidor() throws RemoteException{

    }

    public boolean compApuesta(int[] apuesta)  throws RemoteException{

    }
}
