
import java.util.Scanner;
import java.util.concurrent.*;

/**
 * @author Jesús Rodríguez Heras
 */
public class resImagenParFin implements Runnable {

    static int matriz[][];
    int fila, columna;
    static int matriz2[][];

    /**
     * @param filas
     * @param columnas
     */
    public resImagenParFin(int filas, int columnas) {
        this.fila = filas;
        this.columna = columnas;

    }

    public void rellenarImagen() {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                matriz[i][j] = (int) (Math.random() * 20);
                matriz2[i][j] = 0;
            }
        }
    }

    public void run() {
        matriz2[fila][columna] = (4 * matriz[fila][columna] - matriz[(fila + 1) % matriz.length][columna] - matriz[fila][(columna + 1) % matriz.length] - matriz[(fila + matriz.length - 1) % matriz.length][columna] - matriz[fila][(columna + matriz.length - 1) % matriz.length]) / 8;
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca las dimensiones de la matriz NxN:");
        int n = teclado.nextInt();

        matriz = new int[n][n];
        matriz2 = new int[n][n];

        resImagenParFin imagen = new resImagenParFin(n, n);
        imagen.rellenarImagen();

        long time_start, time_end;
        time_start = System.currentTimeMillis();

        ExecutorService pool = Executors.newFixedThreadPool(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resImagenParFin A = new resImagenParFin(i, j);
                pool.execute(A);
            }
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);

        time_end = System.currentTimeMillis();
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.println(matriz2[i][j]);
            }
        }*/
    }
}
