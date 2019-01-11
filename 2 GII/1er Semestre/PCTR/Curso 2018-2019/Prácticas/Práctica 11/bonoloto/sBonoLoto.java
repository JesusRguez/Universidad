/**
 * @author Jesús Rodríguez Heas
 * @version 1.00
 */

package bonoloto;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;

public class sBonoLoto extends UnicastRemoteObject implements iBonoLoto{

    public int numero;

    /**
     * Constructor de sBonoLoto
     */
    public sBonoLoto() throws Exception{
        numero = (int)(Math.random()*49 + 1);
        System.out.println(numero);
    }

    /**
     * Método para resetear el servidor
     * @return Devuelve un mensaje para saber que se ha reseteado el servidor
     * @throws RemoteException Lanza una excepción si falla
     */
    public String resetServidor() throws RemoteException{
        numero = (int)(Math.random()*49 + 1);
        System.out.println(numero);
        return "El servidor ha sido reseteado";
    }

    /**
     * Método compApuesta
     * @param  a Apuesta
     * @return   Devuelve true si la apuesta es acertada y false en caso contrario
     */
    public boolean compApuesta(int a) throws RemoteException{
        return a == numero;
    }

    public static void main(String[] args) throws Exception {
        iBonoLoto OServidor = new sBonoLoto();
        Naming.rebind("bonoloto", OServidor);
        System.out.println("Servidor preparado");
    }
}
