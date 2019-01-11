/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package biblioteca;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iLibros extends Remote {
    /**
     * Método para insertar un libro
     * @param  l               Libro a insertar
     * @throws RemoteException Lanza una excepción si falla
     */
    public void insertarLibro(Libro l) throws RemoteException;

    /**
     * Método para extraer un libro
     * @param  titulo          Título del libro a extraer
     * @return                 Devuelve true si ha podido extraerlo y false en caso contrario o si no ha encontrado dicho libro
     * @throws RemoteException Lanza una excepción si falla
     */
    public boolean extraerLibro(String titulo) throws RemoteException;

    /**
     * Método para consultar un libro
     * @param  titulo          Título del libro a consultar
     * @return                 Devuelve toda la información del libro consultado o null si no lo encuentra
     * @throws RemoteException Lanza una excepción si falla
     */
    public Libro consultarLibro(String titulo) throws RemoteException;
}
