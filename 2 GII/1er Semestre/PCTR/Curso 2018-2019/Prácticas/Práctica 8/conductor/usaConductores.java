/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package conductor;

/*public class usaConductores implements Runnable{

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
}*/

public class usaConductores extends Thread {

    private static Conductores conductores;
    private int suma_puntos, quita_puntos;

    /**
     * @param hilo Identificador del hilo
     * @param suma_puntos Número de puntos que el hilo sumára a los conductores
     * @param quita_puntos Número de puntos que el hilo quitará a los
     * conductores
     */
    public usaConductores(int hilo, int suma_puntos, int quita_puntos) {

        this.suma_puntos = suma_puntos;
        this.quita_puntos = quita_puntos;
    }

    public void run() {
        for (int i = 0; i < suma_puntos; i++) {
            conductores.sumarPuntosConductor(conductores.mostrarConductor(0), 1);
            conductores.sumarPuntosConductor(conductores.mostrarConductor(1), 1);
            conductores.sumarPuntosConductor(conductores.mostrarConductor(2), 1);
        }
        conductores.restarPuntosConductor(conductores.mostrarConductor(0), quita_puntos);
        conductores.restarPuntosConductor(conductores.mostrarConductor(1), quita_puntos);
        conductores.restarPuntosConductor(conductores.mostrarConductor(2), quita_puntos);
    }

    public static void main(String[] args) throws Exception {
        conductores = new Conductores();
        Conductor fernando = new Conductor("Fernando", "García", "Marquez", "30269815F", 15);
        Conductor paula = new Conductor("Paula", "Rodríguez", "Perez", "36512348L", 12);
        Conductor juan = new Conductor("Juan", "Sanchez", "Lopez", "39154684G", 13);
        int total_suma_puntos = 0, total_quita_puntos = 0, n_hilos = 100, add_puntos, rem_puntos;
        conductores.agregarConductor(fernando);
        conductores.agregarConductor(paula);
        conductores.agregarConductor(juan);
        usaConductores[] hilos = new usaConductores[n_hilos];
        for (int i = 0; i < n_hilos; i++) {
            add_puntos = (int) (Math.random() * 5);
            rem_puntos = (int) (Math.random() * 5);
            hilos[i] = new usaConductores(i, add_puntos, rem_puntos);
            hilos[i].start();
            total_suma_puntos += add_puntos;
            total_quita_puntos += rem_puntos;
        }
        for (int i = 0; i < n_hilos; i++) {
            hilos[i].join();
        }
        System.out.println("\nConductor: " + conductores.mostrarConductor(0));
        System.out.println("Debería de tener " + (15 + total_suma_puntos - total_quita_puntos) + " puntos...\n");
        System.out.println("Conductor: " + conductores.mostrarConductor(1));
        System.out.println("Debería de tener " + (12 + total_suma_puntos - total_quita_puntos) + " puntos...\n");
        System.out.println("Conductor: " + conductores.mostrarConductor(2));
        System.out.println("Debería de tener " + (13 + total_suma_puntos - total_quita_puntos) + " puntos...\n");
    }
}
