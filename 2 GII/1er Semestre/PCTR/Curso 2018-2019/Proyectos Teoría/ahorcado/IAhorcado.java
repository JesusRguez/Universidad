import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IAhorcado extends Remote {
    /**
     * Método para enviar una letra
     * @param  letra Letra a comprobar
     * @return       Devuelve la posición de la primera aparición de la letra. Si se devuelve un valor negativo, es que no existe la letra en la palabra
     */
    public int enviarLetra(char letra) throws RemoteException;

    /**
     * Método para enviar una palabra
     * @param  palabra Palabra a comprobar
     * @return         Retorna true si hemos acertado y false en caso contrario
     */
    public boolean enviarPalabra(String palabra) throws RemoteException;
}
