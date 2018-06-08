
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

/**
 * @author Jesús Rodíguez Heras
 * @version 1.0
 */
public class sLibros extends UnicastRemoteObject implements iLibros {

    ArrayList<Libro> BD;

    public sLibros() throws Exception {
        BD = new ArrayList<Libro>();
    }

    public void introducirLibro(Libro l) throws RemoteException {
        BD.add(l);
    }

    public boolean sacarLibro(String titulo) throws RemoteException {
        boolean conseguido = false;
        for (int i = 0; i < BD.size(); i++) {
            if (BD.get(i).titulo == titulo && BD.get(i).reservado == false) {
                BD.get(i).reservado = true;
                conseguido = true;
            }
        }
        return conseguido;
    }

    public Libro consultarLibro(String titulo) throws RemoteException {
        Libro l = null;
        for (int i = 0; i < BD.size(); i++) {
            if (BD.get(i).titulo == titulo) {
                l = BD.get(i);
            }
        }
        return l;
    }

    public static void main(String[] args) throws Exception {
        iLibros ObjRemoto = new sLibros();
        Naming.bind("Servidor", ObjRemoto);
        System.out.println("Servidor remoto preparado...");
    }
}
