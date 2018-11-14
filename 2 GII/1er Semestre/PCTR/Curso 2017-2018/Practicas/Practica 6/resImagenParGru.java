
import java.util.Scanner;
import java.util.concurrent.*;

/**
 * @author Jess Rodrguez Heras
 */
public class resImagenParGru implements Runnable {

    static int matriz[][];
    int id;
    static int tam, hilos;
    static int matriz2[][];

    /**
     * @param id
     * @param hilos
     * @param tam
     */
    public resImagenParGru(int id, int hilos, int tam) {
        this.id = id;
        resImagenParGru.hilos = hilos;
        resImagenParGru.tam = tam;
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
        for (int i = 0; i < tam; i++) {
            for (int j = id * tam / hilos; j < (id + 1) * tam / hilos; j++) {
                matriz2[i][j] = (4 * matriz[i][j] - matriz[(i + 1) % matriz.length][j] - matriz[i][(j + 1) % matriz.length] - matriz[(i + matriz.length - 1) % matriz.length][j] - matriz[i][(j + matriz.length - 1) % matriz.length]) / 8;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca las dimensiones de la matriz NxN:");
        int n = teclado.nextInt();
        System.out.println("Introduzca el numero de hilos:");
        int hilos = teclado.nextInt();

        matriz = new int[n][n];
        matriz2 = new int[n][n];

        resImagenParGru imagen = new resImagenParGru(n, hilos, n);
        imagen.rellenarImagen();

        long time_start, time_end;
        time_start = System.currentTimeMillis();

        ExecutorService pool = Executors.newFixedThreadPool(hilos);
        for (int i = 0; i < hilos; i++) {
            resImagenParGru A = new resImagenParGru(i, hilos, n);
            pool.execute(A);

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
