
import java.util.Random;
import java.util.Vector;

/**
 * @author Jesus Rodríguez Heras
 * @version 1.0
 */
public class usaMonitorCadena implements Runnable {

    public static final monitorCadena_1 monitorbuffer1 = new monitorCadena_1();
    public static final monitorCadena_1 monitorbuffer2 = new monitorCadena_1();

    int tipoHilo;

    public usaMonitorCadena(int tipoHilo) {
        this.tipoHilo = tipoHilo;
    }

    Vector<int[][]> buffer1 = new Vector<>(100);
    Vector<int[][]> buffer2 = new Vector<>(50);
    Random r = new Random();

    public void run() {
        switch (tipoHilo) {
            case 1:
                while (true) {
                    monitorbuffer1.StartWrite();
                    int[][] m = new int[10][10];
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 10; j++) {
                            m[i][j] = r.nextInt();
                        }
                    }
                    buffer1.add(m);
                    monitorbuffer1.EndWrite();
                }

            case 2:
                while (true) {
                    monitorbuffer1.StartRead();
                    monitorbuffer1.EndRead();
                    monitorbuffer2.StartWrite();
                    int[][] aux = buffer1.elementAt(0);
                    buffer1.remove(0);
                    int[][] aux2 = new int[10][10];

                    for (int i = 0; i < aux.length; i++) {
                        for (int j = 0; j < aux[0].length; j++) {
                            aux2[j][i] = aux[i][j];
                        }
                    }
                    buffer2.add(aux2);
                    monitorbuffer2.EndWrite();
                }

            case 3:
                while (true) {
                    monitorbuffer2.StartRead();
                    monitorbuffer2.EndRead();
                    int[][] aux = buffer2.elementAt(0);
                    buffer2.remove(0);
                    int res = 1;
                    for (int i = 0; i < aux.length; i++) {
                        res = res + aux[i][i];
                    }
                }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[3];
        for (int i = 0; i < 3; i++) {
            hilos[i] = new Thread(new usaMonitorCadena((i & 3) + 1));
        }
        for (int i = 0; i < 3; i++) {
            hilos[i].start();
        }
        for (int i = 0; i < 3; i++) {
            hilos[i].join();
        }
    }
}
