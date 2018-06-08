
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class escalaVectorParalelo extends Thread {

    public static Scanner teclado = new Scanner(System.in);

    public static int tamaño;

    static int[] vector;

    static int[] resultado;

    private int eleccion, factor;

    /**
     * @param numeros
     * @param eleccion
     * @param factor
     */
    public escalaVectorParalelo(int numeros, int eleccion, int factor) {
        vector = new int[numeros];

        this.eleccion = eleccion;
        this.factor = factor;

        tamaño = numeros;
    }

    public void run() {
        resultado = new int[tamaño];

        switch (eleccion) {
            case 1:
                for (int i = 0; i < tamaño / 4; i++) {
                    resultado[i] = factor * vector[i];
                }
                break;
            case 2:
                for (int i = tamaño / 4; i < tamaño / 2; i++) {
                    resultado[i] = factor * vector[i];
                }
                break;
            case 3:
                for (int i = tamaño / 2; i < (3 / 4 * tamaño); i++) {
                    resultado[i] = factor * vector[i];
                }
                break;
            case 4:
                for (int i = (3 / 4 * tamaño); i < tamaño; i++) {
                    resultado[i] = factor * vector[i];
                }
                break;
        }

    }

    public static void main(String args[]) throws InterruptedException {
        System.out.println("Introduce el número de elementos:");
        int numeros = teclado.nextInt();
        System.out.println("Introduce el factor:");
        int factor = teclado.nextInt();

        escalaVectorParalelo hilo1 = new escalaVectorParalelo(numeros, 1, factor);
        escalaVectorParalelo hilo2 = new escalaVectorParalelo(numeros, 2, factor);
        escalaVectorParalelo hilo3 = new escalaVectorParalelo(numeros, 3, factor);
        escalaVectorParalelo hilo4 = new escalaVectorParalelo(numeros, 4, factor);

        for (int i = 0; i < numeros; i++) {
            vector[i] = (int) (Math.random() * 10);
        }

        hilo1.start();
        hilo2.start();
        hilo3.start();
        hilo4.start();

        hilo1.join();
        hilo2.join();
        hilo3.join();
        hilo4.join();
    }
}
