package servidor;

import java.io.*;
import java.net.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Servidor implements Runnable {

    MiSocketStream socketFlujo;
    static AtomicInteger clientes = new AtomicInteger(0);

    public Servidor(MiSocketStream miSocketDatos) {
        this.socketFlujo = miSocketDatos;
    }

    public void run() {
        clientes.incrementAndGet();
        String nClientes = clientes.toString();
        String bienvenida = "Bienvenido. Eres el cliente número " + clientes;
        try {
            socketFlujo.enviaMensaje(bienvenida);
        } catch (Exception e) {
            System.out.println("No he podido enviar la bienvenida.");
        }

        int a = 0, b = 0;
        String dato1 = "", dato2 = "";
        try {
            dato1 = socketFlujo.recibeMensaje();
            dato2 = socketFlujo.recibeMensaje();
        } catch (Exception e) {
            System.out.println("No he recibido nada por el socket.");
        }
        try {
            a = Integer.parseInt(dato1);
            b = Integer.parseInt(dato2);
        } catch (Exception e) {
            System.out.println("No he recibido enteros.");
        }

        Integer suma = a + b;
        String solucion = suma.toString();
        try {
            socketFlujo.enviaMensaje(solucion);
        } catch (Exception e) {
            System.out.println("No he podido enviar la solucion");
        }
        clientes.decrementAndGet();
    }

    public static void main(String[] args) {
        int puertoServidor = 13; // puerto por defecto
        try {
            // instancia un socket stream para aceptar las conexiones
            ServerSocket miSocketConexion = new ServerSocket(puertoServidor);
            System.out.println("El servidor de la suma esta listo.");
            while (true) { // bucle infinito // espera para aceptar una conexion 
                System.out.println("Espera una conexion.");
                MiSocketStream miSocketDatos = new MiSocketStream(miSocketConexion.accept());

                // Nota: no hay necesidad de leer una peticion - la peticion es implicita.
                System.out.println("Un cliente ha hecho una conexion.");

                ExecutorService executor = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

                executor.execute(new Servidor(miSocketDatos));

                executor.shutdown();

                // ahora manda la respuesta al solicitante
                miSocketDatos.close();
            } // fin de while
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        }
    } // fin de main
} // fin de class

