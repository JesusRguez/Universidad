
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Arrays;
import java.util.Random;

public class sBonoLoto extends UnicastRemoteObject implements iBonoLoto {

    public sBonoLoto() throws Exception {
    }

    int[] resultado = new int[6];

    public void resetServidor() throws RemoteException {
        Random r = new Random();
        System.out.println("Reseteando...");
        for (int i = 0; i < 6; i++) {
            resultado[i] = r.nextInt(50);
            System.out.println(resultado[i]);
        }
    }

    public boolean compApuesta(int[] apuesta) throws RemoteException {
        return Arrays.equals(apuesta, resultado);
    }

    public static void main(String[] args) throws Exception {
        iBonoLoto ObjRemoto = new sBonoLoto();
        Naming.bind("Servidor", ObjRemoto);
        System.out.println("Servidor remoto preparado...");
    }
}
