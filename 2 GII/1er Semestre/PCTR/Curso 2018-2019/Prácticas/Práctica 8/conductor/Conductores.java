/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package conductor;

import java.util.ArrayList;

public class Conductores{

    ArrayList<Conductor> conductores;

    public Conductores(){
        conductores = new ArrayList<Conductor>();
    }

    public synchronized String mostrarConductor(int i){
        return conductores.get(i).toString();
    }

    public synchronized void agregarConductor(Conductor c){
        conductores.add(c);
    }

    public synchronized void eliminarConductor(Conductor c){
        conductores.remove(c);
    }

    public synchronized void sumarPuntosConductor(Conductor c, int puntos){
        conductores.get(conductores.indexOf(c)).sumarPuntos(puntos);
    }

    public synchronized void restarPuntosConductor(Conductor c, int puntos){
        conductores.get(conductores.indexOf(c)).restarPuntos(puntos);
    }
}
