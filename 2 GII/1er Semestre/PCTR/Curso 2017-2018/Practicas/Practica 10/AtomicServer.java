
import java.io.BufferedReader;
import java.io.InputStreamReader;
import static java.lang.Thread.sleep;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicLong;

/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
public class AtomicServer implements Runnable {

    Socket enchufe;
    static AtomicLong contador = new AtomicLong(0);

    /**
     * @param s
     */
    public AtomicServer(Socket s) {
        enchufe = s;
    }

    public void run() {
        try {
            BufferedReader entrada = new BufferedReader(
                    new InputStreamReader(
                            enchufe.getInputStream()));
            String datos = entrada.readLine();
            int j;
            int i = Integer.valueOf(datos).intValue();
            for (j = 1; j <= 20; j++) {
                System.out.println("El hilo " + Thread.currentThread().getName() + " escribiendo el dato " + i);
                sleep(1000);
            }
            enchufe.close();
            System.out.println("El hilo " + Thread.currentThread().getName() + "cierra su conexion...");

            contador.incrementAndGet();

        } catch (Exception e) {
            System.out.println("Error...");
        }
    }

    public static void main(String[] args) {

        int puerto = 2001;
        int hilos = 20;

        ExecutorService pool = Executors.newFixedThreadPool(hilos);

        try {
            ServerSocket chuff = new ServerSocket(puerto, 3000);

            while (contador.get() < (long) 20) {
                System.out.println("Esperando solicitud de conexion...");
                Socket cable = chuff.accept();
                System.out.println("Recibida solicitud de conexion...");
                pool.execute(new AtomicServer(cable));
            }
        } catch (Exception e) {
            System.out.println("Error en sockets...");
        }
    }
}
