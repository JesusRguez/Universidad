
/**
 * @author Jesús Rodíguesz Heras
 * @version 1.0
 */
import java.net.*;
import java.io.*;
import static java.lang.Thread.sleep;
import java.util.concurrent.*;

public class ServidorHiloconPool implements Runnable {

    Socket enchufe;
    static Integer contador = 0;

    /**
     * @param s
     */
    public ServidorHiloconPool(Socket s) {
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
            synchronized (contador) {
                contador++;
            }
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

            while (contador < 20) {
                System.out.println("Esperando solicitud de conexion...");
                Socket cable = chuff.accept();
                System.out.println("Recibida solicitud de conexion...");
                pool.execute(new ServidorHiloconPool(cable));
            }
        } catch (Exception e) {
            System.out.println("Error en sockets...");
        }
    }
}

//Solución en tiempo:
//El número de peticiones que tira el cliente (100 en este caso) entre los 4 hilos que se crean en el servidor Y todo ello multiplicado
//por los 20 segundos que tarda por repetición debido al sleep de 1000 ms (1s).
//Por lo tanto, para el caso de las 100 peticiones: 100/4*20=500 segundos.
//Como fórmula general para este programa tenemos: númerodepeticiones/tamañodelpool*20segundosporiteracion
