package biblioteca;

import java.rmi.*;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class sLibro extends UnicastRemoteObject implements iLibro{

    ArrayList<Libro> biblioteca = new ArrayList<Libro>();

    public sLibro() throws RemoteException{}

    public void insertarLibro(Libro l) throws RemoteException{
        biblioteca.add(l);
    }

    public boolean extraerLibro(String titulo) throws RemoteException{
        boolean borrado = false;
        for (int i=0; i<biblioteca.size(); ++i) {
            if (biblioteca.get(i).titulo().equals(titulo)) {
                biblioteca.remove(i);
                borrado = true;
            }
        }
        return borrado;
    }

    public Libro consultarLibro(String titulo) throws RemoteException{
        for (int i=0; i<biblioteca.size(); ++i) {
            if (biblioteca.get(i).titulo().equals(titulo)) {
                return biblioteca.get(i);
            }
        }
        return null;
    }

    public static void main(String[] args) throws Exception{
        iLibro OServidor = new sLibro();
        Naming.rebind("biblioteca", OServidor);
        System.out.println("Servidor preparado...");
    }
}
