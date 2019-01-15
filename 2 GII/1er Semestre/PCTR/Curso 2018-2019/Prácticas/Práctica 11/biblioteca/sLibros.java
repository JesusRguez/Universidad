/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package biblioteca;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;
import java.util.*;

public class sLibros extends UnicastRemoteObject implements iLibros{

    ArrayList<Libro> biblioteca = new ArrayList<Libro>();

    public sLibros() throws RemoteException{}

    /**
     * Método para insertar un libro
     * @param  l               Libro a insertar
     * @throws RemoteException Lanza una excepción si falla
     */
    public void insertarLibro(Libro l) throws RemoteException{
        biblioteca.add(l);
    }

    /**
     * Método para extraer un libro
     * @param  titulo          Título del libro a extraer
     * @return                 Devuelve true si ha podido extraerlo y false en caso contrario o si no ha encontrado dicho libro
     * @throws RemoteException Lanza una excepción si falla
     */
    public boolean extraerLibro(String titulo) throws RemoteException{
        boolean borrado = false;
        for (int i=0; i<biblioteca.size(); ++i) {
            if (biblioteca.get(i).titulo.equals(titulo)) {
                biblioteca.remove(i);
                borrado = true;
            }
        }
        return borrado;
    }

    /**
     * Método para consultar un libro
     * @param  titulo          Título del libro a consultar
     * @return                 Devuelve toda la información del libro consultado o null si no lo encuentra
     * @throws RemoteException Lanza una excepción si falla
     */
    public Libro consultarLibro(String titulo) throws RemoteException{
        for (int i=0; i<biblioteca.size(); ++i) {
            if (biblioteca.get(i).titulo.equals(titulo)) {
                return biblioteca.get(i);
            }
        }
        return null;
    }

    public static void main(String[] args) throws Exception{
        iLibros OServidor = new sLibros();
        Naming.rebind("biblioteca", OServidor);
        System.out.println("Servidor preparado");
    }
}
