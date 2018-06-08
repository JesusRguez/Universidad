
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.net.*;
import java.io.*;
import static java.lang.Thread.sleep;
import java.util.ArrayList;

public class ServidorHilosinPool implements Runnable {

    static boolean terminado;
    Socket enchufe;
    static Integer contador = 0;

    /**
     * @param s
     */
    public ServidorHilosinPool(Socket s) {
        enchufe = s;
        terminado = false;
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
        this.terminado = true;
    }

    public static void main(String[] args) {

        int puerto = 2001;
        ArrayList<Thread> lista = new ArrayList();

        try {
            ServerSocket chuff = new ServerSocket(puerto, 3000);

            while (contador < 20) {
                System.out.println("Esperando solicitud de conexion...");
                Socket cable = chuff.accept();
                System.out.println("Recibida solicitud de conexion...");
                lista.add(new Thread(new ServidorHilosinPool(cable)));
                lista.get(0).start();
                lista.remove(0);
            }
        } catch (Exception e) {
            System.out.println("Error en sockets...");
        }
    }
}

//Solución en tiempo:
//El número de peticiones que tira el cliente (100 en este caso) y cada petición tarda 1 segundo.
//Pero al ser paralelo, hace las 100 de una vez, por lo que, como lo hace 20 veces por cada hilo, son 20 segundos.
