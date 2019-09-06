package punto;

import java.rmi.*;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class longServer extends UnicastRemoteObject implements longInterface{

    /**
     * Constructor de longServer
     */
    public longServer() throws RemoteException{}

    /**
     * Método lonSubSegmento
     * @param  n     Número de puntos
     * @param  datos Puntos transferidos
     * @return       Devuelve la longitud del subsegmento
     */
    public float lonSubSegmento(int n, punto[] datos) throws RemoteException{
        float distancia = 0;
        for (int i=0; i<n; ++i) {
            distancia += Math.sqrt(Math.pow(datos[i].x,2) + Math.pow(datos[i].y,2));
        }
        return distancia;
    }

    public static void main(String[] args) throws Exception{
        longInterface OServidor = new longServer();
        Naming.rebind("punto", OServidor);
        System.out.println("Servidor preparado...");
    }
}
