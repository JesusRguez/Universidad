
import java.util.Random;

public class MonteCarloParalelo implements Runnable {

    int puntos, dentro = 0;

    public MonteCarloParalelo(int puntos) {
        this.puntos = puntos;
    }

    public void run() {
        Random r = new Random();
        for (int i = 0; i < puntos; i++) {
            double x = r.nextDouble(), y = r.nextDouble();
            if (Math.sin(x) >= y) {
                dentro++;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int totalPuntos = Integer.parseInt(args[0]);
        Thread[] hilos = new Thread[Integer.parseInt(args[1])];
        MonteCarloParalelo[] tareas = new MonteCarloParalelo[hilos.length];
        for (int i = 0; i < hilos.length; ++i) {
            tareas[i] = new MonteCarloParalelo(totalPuntos / hilos.length);
            hilos[i] = new Thread(tareas[i]);
            hilos[i].start();
        }
        int totalDentro = 0;
        for (int i = 0; i < hilos.length; i++) {
            hilos[i].join();
            totalDentro += tareas[i].dentro;
        }
        System.out.println("Área: " + totalDentro / (float) totalPuntos);
    }
}
