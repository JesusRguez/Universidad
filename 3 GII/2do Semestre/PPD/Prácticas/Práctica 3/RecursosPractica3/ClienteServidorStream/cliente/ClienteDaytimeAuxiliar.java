package cliente;

import java.net.*;

public class ClienteDaytimeAuxiliar {

    public static String obtenerMarcaTiempo(String nombreMaquina, String numPuerto) throws Exception {

        String marcaTiempo = "";
        int puertoServidor = Integer.parseInt(numPuerto);
        // instancia un socket en modo stream y espera a que se haga 
        // una conexion al puerto servidor
        System.out.println("Peticion de conexion realizada");
        MiSocketStream miSocket = new MiSocketStream(nombreMaquina, puertoServidor);
        // ahora espera hasta recibir la marca de tiempo
        marcaTiempo = miSocket.recibeMensaje();
        miSocket.close(); // implica la desconexion
        return marcaTiempo;
    } // fin
} // fin de class
