package ibex5;

import java.rmi.*;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.Naming;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;
import java.util.ArrayList;

public class sIBEX5 extends UnicastRemoteObject implements iIBEX5{

    public static ArrayList<ibex5> entidades = new ArrayList<ibex5>();

    public sIBEX5() throws RemoteException{}

    /*
     * Método para consultar las cotizaciones generales
     * @return Devuelve todas las cotizaciones de las empresas en ese momento
     */
    public synchronized String consultarCotizaciones() throws RemoteException{
        String res = "";
        for (int i=0; i<entidades.size(); ++i) {
            res+=entidades.get(i).toString()+"\n";
        }
        return res;
    }

    /*
     * Método para consultar las cotizaciones de una empresa
     * @param  empresa         Empresa de la cual queremos saber las cotizaciones en ese momento
     * @return                 Devuelve las cotizaciones de la empresa señalada
     */
    public synchronized  String consultarCotizacion(String empresa) throws RemoteException{
        for (int i=0; i<entidades.size(); ++i) {
            if (entidades.get(i).nombre.equals(empresa)) {
                return entidades.get(i).toString();
            }
        }
        return null;
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Introduzca los 5 valores bursátiles actuales:");
        String n, a;
        double v;
        Scanner teclado = new Scanner(System.in);
        for (int i=0; i<5; ++i) {
            System.out.print("Introduzca el nombre de la entidad: ");
            teclado.nextLine();
            n = teclado.nextLine();
            System.out.print("Introduzca el acrónimo de la entidad: ");
            a = teclado.nextLine();
            System.out.print("Introduzca el varlor de la entidad: ");
            v = teclado.nextDouble();
            ibex5 e = new ibex5(n, a, v);
            entidades.add(e);
        }

        iIBEX5 OServidor = new sIBEX5();
        Naming.rebind("ibex5", OServidor);
        System.out.println("Servidor preparado...");

        while (true) {
            Thread.sleep(100);
            for (int i=0; i<entidades.size(); ++i) {
                entidades.get(i).valor(Math.random()*-2000+1000);
            }
        }
    }
}
