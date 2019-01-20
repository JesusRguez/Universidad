package juego;

import java.rmi.server.UnicastRemoteObject;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.Naming;
import java.util.*;

public class sJuego extends UnicastRemoteObject implements iJuego{

    public static int n;

    public sJuego() throws RemoteException{
        this.n = (int)(Math.random()*99+1);
        System.out.println(n);
    }

    Scanner teclado = new Scanner(System.in);

    public String reset() throws RemoteException{
        n = (int)(Math.random()*99+1);
        System.out.println(n);
        return "El servidor ha sido reseteado";
    }

    public boolean hacerIntento(int numero) throws RemoteException{
        return n == numero;
    }

    public static void main(String[] args) throws Exception {
        iJuego OServidor = new sJuego();
        Naming.rebind("juego", OServidor);
        System.out.println("Servidor preparado...");
    }
}
