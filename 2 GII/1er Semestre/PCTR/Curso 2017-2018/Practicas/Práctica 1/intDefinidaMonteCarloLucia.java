
import java.util.Scanner;
import java.util.Random;

public class intDefinidaMonteCarloLucia {

    /**
     *
     * @param n
     */
    public static void calcularFuncion2(int n) {
        int x = 1;
        double valorAleatorio, sumaValoresAleatorios = 0;
        Random aleatorio = new Random();
        double f = Math.sin(x);

        for (int i = 0; i < n; i++) {
            valorAleatorio = aleatorio.nextInt(n) * 1;
            if (valorAleatorio < f) {
                sumaValoresAleatorios = sumaValoresAleatorios + valorAleatorio;
            }
        }
        double aproximacion = sumaValoresAleatorios / n;
    }

    /**
     *
     * @param n
     */
    public static void calcularFuncion1(int n) {

        int x = 1;
        Random aleatorio = new Random();
        double valorAleatorio, sumaValoresAleatorios = 0, f = x;

        for (int i = 0; i < n; i++) {
            valorAleatorio = aleatorio.nextInt(n) * 1;
            if (valorAleatorio < f) {
                sumaValoresAleatorios = sumaValoresAleatorios + valorAleatorio;
            }
        }
        double aproximacion = sumaValoresAleatorios / n;
    }

    static public void main(String[] args) {

        Scanner teclado = new Scanner(System.in);

        System.out.println("Escriba el numero de puntos que desea generar");
        int nPuntos = teclado.nextInt();

        System.out.println("Elige una funcion.");
        int f = teclado.nextInt();

        switch (f) {
            case 1:
                calcularFuncion1(nPuntos);
            case 2:
                calcularFuncion2(nPuntos);
        }
    }
}
