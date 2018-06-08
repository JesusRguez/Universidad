
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class MiPrimerServidor extends UnicastRemoteObject implements ISuma {

    MiPrimerServidor() throws RemoteException {
    }

    public float suma(float a, float b) throws RemoteException {
        float c = a + b;
        System.out.println(a + "+" + b + "=" + c);
        return c;
    }

    public static void main(String[] args) throws Exception {
        ISuma ORemoto = new MiPrimerServidor();
        Naming.rebind("Sumador", (MiPrimerServidor) ORemoto);
    }
}
