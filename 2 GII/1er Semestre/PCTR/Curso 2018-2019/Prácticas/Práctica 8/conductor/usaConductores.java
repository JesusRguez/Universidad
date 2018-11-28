/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package conductor;

public class usaConductores implements Runnable{

    private static Conductores conductores;
    private int suma_puntos, resta_puntos;

    public usaConductores(int hilo, int suma_puntos, int resta_puntos){
        this.suma_puntos = suma_puntos;
        this.resta_puntos = resta_puntos;
    }

    public void run(){
        for (int i = 0; i < suma_puntos; i++) {
                    conductores.sumarPuntosConductor(conductores.mostrarConductor(conductores.get(0)), suma_puntos);
                    conductores.sumarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), suma_puntos);
                    conductores.sumarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), suma_puntos);
                    conductores.sumarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), suma_puntos);
                }
                conductores.restarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), quita_puntos);
                conductores.restarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), quita_puntos);
                conductores.restarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), quita_puntos);
                conductores.restarPuntosConductor(conductores.mostrarConductor(conductores.get(1)), quita_puntos);
    }

    public static void main(String[] args) throws InterruptedException {
        condcutores = new Conductores();

        Conductor pedro = new Conductor("Pedro", "García", "Pérez", "30269815F", 15);
        Conductor alejandro = new Conductor("Alejandro", "López", "Guerrero", "36512348L", 10);
        Conductor pablo = new Conductor("Pablo", "Vázquez", "Sánchez", "39154684G", 8);
        Conductor juan = new Conductor("Juan", "Martínez", "Díaz", "32088516C", 12);

        conductores.agregarConductor(pedro);
        conductores.agregarConductor(alejandro);
        conductores.agregarConductor(pablo);
        conductores.agregarConductor(juan);

        int total_suma_puntos = 0, total_quita_puntos = 0, nHilos = 1000000, add_puntos, rem_puntos;

        usaConductores[] hilos = new usaConductores[nHilos];
        for (int i=0; i<nHilos; ++i) {
            add_puntos = (int) (Math.random()*5);
            rem_puntos = (int) (Math.random()*5);
            hilos[i] = new usaConductores(i, add_puntos, rem_puntos);
            hilos[i].start();
            total_suma_puntos += add_puntos;
            total_quita_puntos += rem_puntos;
        }
        for (int i=0; i<nHilos; ++i) {
            hilos[i].join();
        }

        for (int i=0; i<4; ++i) {
            System.out.println(conductores.mostrarConductor(i));
        }

    }
}
