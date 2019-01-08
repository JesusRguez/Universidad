/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package contador;

import java.net.*;
import java.io.*;
import static java.lang.Thread.sleep;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicLong;

public class atomicServer implements Runnable{

    Socket enchufe;
    static AtomicLong contador = new AtomicLong(0);

    /**
     * Constructor de atomicServer
     * @param s Socket
     */
    public atomicServer(Socket s){
        enchufe = s;
    }

    public void run(){
        try{
            BufferedReader entrada = new BufferedReader(
                                        new InputStreamReader(
                                            enchufe.getInputStream()));
            String datos = entrada.readLine();
            int j;
            int i = Integer.valueOf(datos).intValue();
            for(j=1; j<=20; j++){
                System.out.println("El hilo "+Thread.currentThread().getName()+" escribiendo el dato "+i);
                Thread.sleep(1000);
            }
            enchufe.close();
            System.out.println("El hilo "+Thread.currentThread().getName()+" cierra su conexion");
            contador.incrementAndGet();
        } catch(Exception e) {
            System.out.println("Error...");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int puerto = 2001;
        ExecutorService ejecutor = Executors.newCachedThreadPool();

        try{
            ServerSocket chuff = new ServerSocket (puerto, 3000);
            while (contador.get() < (long) 20){
                System.out.println("Esperando solicitud de conexion...");
                Socket cable = chuff.accept();
                System.out.println("Recibida solicitud de conexion...");
                ejecutor.execute(new atomicServer(cable));
            }
        } catch (Exception e){
            System.out.println("Error en sockets...");
        }
    }
}
