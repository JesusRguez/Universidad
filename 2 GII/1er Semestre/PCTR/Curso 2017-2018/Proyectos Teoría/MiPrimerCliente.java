
import java.rmi.Naming;

public class MiPrimerCliente {

    public static void main(String[] args) throws Exception {
        String url = args[0];
        //ISuma servidor = (ISuma) Naming.lookup("//localhost/Sumador");
        ISuma servidor = (ISuma) Naming.lookup(url);
        float resultado = servidor.suma(1, 2);
        System.out.println(resultado);
    }
}
