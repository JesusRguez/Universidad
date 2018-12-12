/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorcadena;

import java.util.Random;
import java.util.Vector;

public class UsamonitorCadena implements Runnable {

    public static final monitorCadena_1 monitorBuffer1 = new monitorCadena_1();
    public static final monitorCadena_2 monitorBuffer2 = new monitorCadena_2();

    public int tipoHilo;

    public UsamonitorCadena(int tipoHilo){
        this.tipoHilo = tipoHilo;
    }

    Vector<int[][]> buffer1 = new Vector<>(100);
    Vector<int[][]> buffer2 = new Vector<>(50);

    Random r = new Random();

    public void run(){
        switch (tipoHilo) {
            case 1:
                while(true){
                    monitorBuffer1.inicioEscritura();
                    int[][] m = new int[10][10];
                    for (int i=0; i<10; ++i) {
                        for (int j=0; j<10; ++j) {
                            m[i][j] = r.nextInt();
                        }
                    }
                    buffer1.add(m);
                    monitorBuffer1.finEscritura();
                }
            case 2:
                while(true){
                    monitorBuffer1.inicioLectura();
                    monitorBuffer1.finLectura();
                    monitorBuffer2.inicioLectura();
                    int[][] aux = buffer1.elementAt(0);
                    buffer1.remove(0);
                    int[][] aux2 = new int[10][10];
                    for (int i=0; i<aux.length; ++i) {
                        for (int j=0; j<aux[0].length; ++j) {
                            aux2[j][i] = aux[i][j];
                        }
                    }
                    buffer2.add(aux2);
                    monitorBuffer2.finEscritura();
                }
            case 3:
            while(true){
                monitorBuffer2.inicioLectura();
                monitorBuffer2.finLectura();
                int[][] aux = buffer2.elementAt(0);
                buffer2.remove(0);
                int res = 1;
                for (int i=0; i<aux.length; ++i) {
                    res = res * aux[i][i];
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[3];
        for (int i=0; i<3; ++i) {
            hilos[i] = new Thread(new UsamonitorCadena((i&3)+1));
            hilos[i].start();
        }
        for (int i=0; i<3; ++i) {
            hilos[i].join();
        }
    }
}
