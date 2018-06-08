package usaconductores;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class UsaConductores extends Thread {

    private static Conductores conductores;
    private int suma_puntos, quita_puntos;

    /**
     * @param hilo Identificador del hilo
     * @param suma_puntos Número de puntos que el hilo sumára a los conductores
     * @param quita_puntos Número de puntos que el hilo quitará a los
     * conductores
     */
    public UsaConductores(int hilo, int suma_puntos, int quita_puntos) {

        this.suma_puntos = suma_puntos;
        this.quita_puntos = quita_puntos;
    }

    public void run() {
        for (int i = 0; i < suma_puntos; i++) {
            conductores.sumarPuntoConductor(conductores.mostrarConductor(0));
            conductores.sumarPuntoConductor(conductores.mostrarConductor(1));
            conductores.sumarPuntoConductor(conductores.mostrarConductor(2));
        }
        conductores.eliminarPuntosConductor(conductores.mostrarConductor(0), quita_puntos);
        conductores.eliminarPuntosConductor(conductores.mostrarConductor(1), quita_puntos);
        conductores.eliminarPuntosConductor(conductores.mostrarConductor(2), quita_puntos);
    }

    public static void main(String[] args) throws Exception {
        conductores = new Conductores();
        Conductor fernando = new Conductor("30269815F", "Fernando", "García Marquez", 15);
        Conductor paula = new Conductor("36512348L", "Paula", "Rodríguez Perez", 12);
        Conductor juan = new Conductor("39154684G", "Juan", "Sanchez Lopez", 13);
        int total_suma_puntos = 0, total_quita_puntos = 0, n_hilos = 1000000, add_puntos, rem_puntos;
        conductores.agregarConductor(fernando);
        conductores.agregarConductor(paula);
        conductores.agregarConductor(juan);
        UsaConductores[] hilos = new UsaConductores[n_hilos];
        for (int i = 0; i < n_hilos; i++) {
            add_puntos = (int) (Math.random() * 5);
            rem_puntos = (int) (Math.random() * 5);
            hilos[i] = new UsaConductores(i, add_puntos, rem_puntos);
            hilos[i].start();
            total_suma_puntos += add_puntos;
            total_quita_puntos += rem_puntos;
        }
        for (int i = 0; i < n_hilos; i++) {
            hilos[i].join();
        }
        System.out.println("\nConductor: " + conductores.mostrarConductor(0));
        System.out.println("Debería de tener " + (15 + total_suma_puntos - total_quita_puntos) + "puntos...\n");
        System.out.println("Conductor: " + conductores.mostrarConductor(1));
        System.out.println("Debería de tener " + (12 + total_suma_puntos - total_quita_puntos) + "puntos...\n");
        System.out.println("Conductor: " + conductores.mostrarConductor(2));
        System.out.println("Debería de tener " + (13 + total_suma_puntos - total_quita_puntos) + "puntos...\n");
    }
}
