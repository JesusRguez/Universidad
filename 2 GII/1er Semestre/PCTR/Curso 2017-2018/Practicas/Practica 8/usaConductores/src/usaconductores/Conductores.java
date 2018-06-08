package usaconductores;

import java.util.ArrayList;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Conductores {

    ArrayList<Conductor> conductores;

    public Conductores() {
        conductores = new ArrayList<Conductor>();
    }

    /**
     * @param index Índice del conductor en el ArrayList
     */
    public synchronized Conductor mostrarConductor(int index) {
        return conductores.get(index);
    }

    /**
     * @param conductor Nuevo conductor a añadir
     */
    public synchronized void agregarConductor(Conductor conductor) {
        conductores.add(conductor);
    }

    /**
     * @param conductor Conductor a eliminar
     */
    public synchronized void eliminarConductor(Conductor conductor) {
        conductores.remove(conductor);
    }

    /**
     * @param conductor Conductor al que se le sumará un punto
     */
    public synchronized void sumarPuntoConductor(Conductor conductor) {
        conductores.get(conductores.indexOf(conductor)).sumarPunto();
    }

    /**
     * @param conductor Conductor al que se le quitará puntos
     * @param puntos Cantidad de puntos a quitar
     */
    public synchronized void eliminarPuntosConductor(Conductor conductor, int puntos) {
        conductores.get(conductores.indexOf(conductor)).quitarPuntos(puntos);
    }

}
