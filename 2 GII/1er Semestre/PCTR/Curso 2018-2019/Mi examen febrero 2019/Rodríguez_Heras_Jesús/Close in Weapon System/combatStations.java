/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.concurrent.*;

public class combatStations implements Runnable{

    public CIWS monitor;
    public int estacion;

    /**
     * Constructor de combatStations
     */
    public combatStations(){
        monitor = new CIWS();
    }

    public void run(){
        while(true){
            estacion = monitor.ocupada();
            System.out.println("Estacion disparando");
            monitor.liberada(estacion);
        }
    }
}
