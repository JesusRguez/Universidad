
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 */
public class algoLamport implements Runnable {

    static int[] numero;
    static boolean[] eligiendo;
    static int n;
    static int numeroscompartidos = 100;

    public algoLamport(int n) {
        numero = new int[n];
        eligiendo = new boolean[n];
        for (int i = 0; i < n; i++) {
            numero[i] = 0;
            eligiendo[i] = false;
        }
        algoLamport.n = n;
    }

    public int maximo(int[] numero) {
        int resultado = 0;
        for (int i = 0; i < algoLamport.n; i++) {
            if (numero[i] > resultado) {
                resultado = numero[i];
            }
        }
        return resultado;
    }

    public void run() {
        for (int i = 0; i < n; i++) {
            eligiendo[i] = true;
            numero[i] = maximo(numero);
            eligiendo[i] = false;
            for (int j = 0; j < n; j++) {
                while (eligiendo[j]) {
                };
                while ((numero[j] != 0) && ((numero[j] < numero[i]) || ((numero[j] == numero[i]) && (j < i)))) {
                };
            }
            //SECCIÓN CRÍTICA
            if (algoLamport.n % 2 == 0) {
                numeroscompartidos++;
            } else {
                numeroscompartidos--;
            }

            numero[i] = 0;
        }

    }

    public static void main(String[] args) throws InterruptedException {

        Scanner teclado = new Scanner(System.in);
        System.out.println("Elija el numero de hilos:");
        int n = teclado.nextInt();

        Thread[] hilos = new Thread[n];

        for (int i = 0; i < n; i++) {
            hilos[i] = new Thread(new algoLamport(i));
            hilos[i].start();
        }

        for (int i = 0; i < n; i++) {
            hilos[i].join();
        }
        System.out.println(algoLamport.numeroscompartidos);
    }
}
