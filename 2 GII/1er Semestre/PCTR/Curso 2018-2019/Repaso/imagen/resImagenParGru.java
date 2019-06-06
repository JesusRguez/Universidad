import java.util.concurrent.*;
import java.util.*;

public class resImagenParGru implements Runnable{
    public static int tam, hilos, matriz[][], res[][];
    public int idHilo;

    public resImagenParGru(int idHilo, int hilos, int tam){
        this.idHilo = idHilo;
        this.hilos = hilos;
        this.tam = tam;
    }

    public void run() {
        for (int i=0; i<tam; ++i) {
            for (int j=idHilo*tam/hilos; j<(idHilo+1)*tam/hilos; ++j) {
                res[i][j] = (4*matriz[i][j] - matriz[(i+1)%matriz.length][j] - matriz[i][(j+1)%matriz.length] - matriz[(i+matriz.length-1)%matriz.length][j] - matriz[i][(j+matriz.length-1)%matriz.length])/8;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el tamaño de la matriz NxN:");
        int n = teclado.nextInt();
        matriz = new int[n][n];
        res = new int[n][n];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                matriz[i][j] = (int) Math.random()*20;
                res[i][j] = 0;
            }
        }
        int hilos = Runtime.getRuntime().availableProcessors();
        ExecutorService pool = Executors.newFixedThreadPool(hilos);
        long time_start = System.currentTimeMillis();
        for (int i=0; i<hilos; ++i) {
            pool.execute(new resImagenParGru(i, hilos, n));    
        }
        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
