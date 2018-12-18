import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;

public class ServidorAhorcado extends UnicastRemoteObject implements IAhorcado{

    String solucion = "universidad";

    /**
     * Constructor de ServidorAhorcado
     * @throws RemoteException Excepción aprovechada para asegurarnos de que la solución esté dada en minuscula
     */
    public ServidorAhorcado() throws RemoteException {
        solucion = solucion.toLowerCase();
    }

    /**
     * Método para enviar una letra
     * @param  letra Letra a comprobar
     * @return       Devuelve la posición de la primera aparición de la letra. Si se devuelve un valor negativo, es que no existe la letra en la palabra
     */
    public int enviarLetra(char letra) throws RemoteException{
        System.out.println("Comprobando letra: "+letra);
        return solucion.indexOf(new Character(letra).toString().toLowerCase());
    }

    /**
     * Método para enviar una palabra
     * @param  palabra Palabra a comprobar
     * @return         Retorna true si hemos acertado y false en caso contrario
     */
    public boolean enviarPalabra(String palabra) throws RemoteException{
        System.out.println("Comprobando palabra: "+palabra);
        return palabra.toLowerCase().equals(solucion);
    }

    public static void main(String[] args) throws Exception {
        IAhorcado OServidor = new ServidorAhorcado();
        Naming.rebind("Ahorcado", OServidor);
        System.out.println("Servidor preparado");
    }
}
