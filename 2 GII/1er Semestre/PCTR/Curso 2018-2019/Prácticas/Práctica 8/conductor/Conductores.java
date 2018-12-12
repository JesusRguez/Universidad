/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package conductor;

import java.util.ArrayList;

public class Conductores{

    ArrayList<Conductor> conductores;

    /**
     * Constructor de la clase Conductores
     */
    public Conductores(){
        conductores = new ArrayList<Conductor>();
    }

    /**
     * Método para mostrar un conductor
     * @param  i Índice del conductor en la lista de conductores
     * @return   Retorna el conductor
     */
    public synchronized Conductor mostrarConductor(int i){
        return conductores.get(i);
    }

    /**
     * Método apra agregar un condcutor a la lista
     * @param c Conductor a agregar
     */
    public synchronized void agregarConductor(Conductor c){
        conductores.add(c);
    }

    /**
     * Método para eliminar un conductor de la lista
     * @param c Conductor a eliminar
     */
    public synchronized void eliminarConductor(Conductor c){
        conductores.remove(c);
    }

    /**
     * Método para sumar puntos a un conductor
     * @param c      Conductor al que se le desean sumar los puntos
     * @param puntos Puntos a sumar
     */
    public synchronized void sumarPuntosConductor(Conductor c, int puntos){
        conductores.get(conductores.indexOf(c)).sumarPuntos(puntos);
    }

    /**
     * Método para restar puntos a un conductor
     * @param c      Conductor al que sele desean restar puntos
     * @param puntos Puntos a restar
     */
    public synchronized void restarPuntosConductor(Conductor c, int puntos){
        conductores.get(conductores.indexOf(c)).restarPuntos(puntos);
    }
}
