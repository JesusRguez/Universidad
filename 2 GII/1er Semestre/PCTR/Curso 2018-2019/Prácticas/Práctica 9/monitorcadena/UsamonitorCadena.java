/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorcadena;

import java.util.Random;
import java.util.Vector;

public class UsamonitorCadena implements Runnable {

    public static final monitorCadena_1 monitorBuffer1 = new monitorCadena_1(100);
    public static final monitorCadena_1 monitorBuffer2 = new monitorCadena_1(50);

    public int tipoHilo;

    public UsamonitorCadena(int tipoHilo){
        this.tipoHilo = tipoHilo;
    }

    Random r = new Random();

    public void run(){
        switch (tipoHilo) {
            case 1:
                while(true){
                    int[][] m = new int[10][10];
                    for (int i=0; i<10; ++i) {
                        for (int j=0; j<10; ++j) {
                            m[i][j] = r.nextInt();
                        }
                    }
                    monitorBuffer1.insertar(m);
                }
            case 2:
                while(true){
                    int[][] aux = new int[10][10];
                    aux = monitorBuffer1.extraer();

                    int[][] aux2 = new int[10][10];
                    for (int i=0; i<aux.length; ++i){
                        for (int j=0; j<aux[0].length; ++j) {
                            aux2[j][i] = aux[i][j];
                        }
                    }
                    monitorBuffer2.insertar(aux2);
                }
            case 3:
            while(true){
                int[][] aux = new int[10][10];
                aux = monitorBuffer2.extraer();
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
