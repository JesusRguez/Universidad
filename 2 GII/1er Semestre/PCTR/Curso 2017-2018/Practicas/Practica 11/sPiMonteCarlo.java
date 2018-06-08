
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Random;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class sPiMonteCarlo extends UnicastRemoteObject implements iPiMonteCarlo {

    public Integer puntosTotales = 0, puntosDentro = 0;
    Random myRandom = new Random();

    public sPiMonteCarlo() throws Exception {
    }

    public void reset() throws RemoteException {
        puntosTotales = 0;
    }

    public void masPuntos(int nPuntos) throws RemoteException {
        int newPuntosTotales = nPuntos, newPuntosDentro = 0;
        for (int i = 0; i < nPuntos; i++) {
            float cx = myRandom.nextFloat();
            float cy = myRandom.nextFloat();
            if (Math.pow(cx, 2) + Math.pow(cy, 2) <= 1) {
                newPuntosDentro++;
            }
        }
        synchronized (puntosTotales) {
            puntosTotales = puntosTotales + newPuntosTotales;
        }

        synchronized (puntosDentro) {
            puntosDentro = puntosDentro + newPuntosDentro;

        }
        System.out.println(4.0 * puntosDentro / puntosTotales);
    }

    public static void main(String[] args) throws Exception {
        iPiMonteCarlo ObjRemoto = new sPiMonteCarlo();
        Naming.bind("Servidor", ObjRemoto);
        System.out.println("Servidor remoto preparado...");
    }
}
