
import java.util.Scanner;

/**
 * @author Jesús
 */
public class resImagen {

    int matriz[][];
    int dimension;

    /**
     * @param dimension
     */
    public resImagen(int dimension) {
        this.dimension = dimension;
        matriz = new int[dimension][dimension];
    }

    public void rellenarImagen() {
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                matriz[i][j] = (int) (Math.random() * 20);
            }
        }
    }

    /**
     * @param imagen
     * @return
     */
    public int[][] resolucion(int[][] imagen) {
        resImagen resultado = new resImagen(dimension);
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                resultado.matriz[i][j] = (4 * imagen[i][j] - imagen[(i + 1) % dimension][j] - imagen[i][(j + 1) % dimension] - imagen[(i - 1 + dimension) % dimension][j] - imagen[i][(j - 1 + dimension) % dimension]) / 8;
            }
        }
        return resultado.matriz;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca las dimensiones de la matriz NxN:");
        int n = teclado.nextInt();

        resImagen imagen = new resImagen(n);
        imagen.rellenarImagen();
        resImagen imagen2 = new resImagen(n);

        long time_start, time_end;
        time_start = System.currentTimeMillis();

        imagen2.matriz = imagen.resolucion(imagen.matriz);

        time_end = System.currentTimeMillis();
        System.out.println("\nTarda " + (time_end - time_start) / (double) 1000 + " segundos");
    }
}
