package punto;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface longInterface extends Remote{

    /**
     * Método lonSubSegmento
     * @param  n     Número de puntos
     * @param  datos Puntos transferidos
     * @return       Devuelve la longitud del subsegmento
     */
    public float lonSubSegmento(int n, punto[] datos) throws RemoteException;
}
