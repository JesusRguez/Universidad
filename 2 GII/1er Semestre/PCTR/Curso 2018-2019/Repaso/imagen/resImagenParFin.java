import java.util.concurrent.*;
import java.util.*;

public class resImagenParFin implements Runnable{
    public static int matriz[][], res[][];
    public int fila, columna;

    public resImagenParFin(int fila, int columna){
        this.fila = fila;
        this.columna = columna;
    }

    public void run(){
        res[fila][columna] = (4*matriz[fila][columna] - matriz[(fila+1)%matriz.length][columna] - matriz[fila][(columna+1)%matriz.length] - matriz[(fila-1+matriz.length)%matriz.length][columna] - matriz[fila][(columna-1+matriz.length)%matriz.length])/8;
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
            }
        }
        ExecutorService pool = Executors.newFixedThreadPool(n*n);
        long time_start = System.currentTimeMillis();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                pool.execute(new resImagenParFin(i, j));
            }
        }
        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
