
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Estadistica {

    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param numeros
     */
    public static double media(int[] numeros) { //Calculo de la media
        double suma = 0;
        for (int i = 0; i < numeros.length; i++) {
            suma = suma + numeros[i];
        }
        return suma / (double) numeros.length;
    }

    /**
     * @param numeros
     */
    public static int moda(int[] numeros) { //Calculo de la moda

        int[] aux = new int[numeros.length];
        int moda = 0;
        for (int i = 0; i < numeros.length; i++) {
            for (int j = i; j < numeros.length; j++) {
                if (numeros[i] == numeros[j]) {
                    aux[i]++;
                }
            }
        }

        for (int k = 0; k < numeros.length; k++) {
            if (aux[k] > aux[moda]) {
                moda = k;
            }
        }

        return numeros[moda];
    }

    /**
     * @param numeros
     */
    public static double varianza(int[] numeros) { //Calculo de la varianza
        double suma = 0;
        for (int i = 0; i < numeros.length; i++) {
            suma = suma + numeros[i];
        }
        double media = suma / (double) numeros.length;

        double sumatorio = 0;
        for (int i = 0; i < numeros.length; i++) {
            sumatorio = sumatorio + Math.pow((numeros[i] - media), 2);
        }
        double varianza = (1 / (double) numeros.length) * sumatorio;

        return varianza;
    }

    /**
     * @param numeros
     */
    public static double desviacionTipica(int[] numeros) { //Calculo de la desviación típica
        double suma = 0;
        for (int i = 0; i < numeros.length; i++) {
            suma = suma + numeros[i];
        }
        double media = suma / (double) numeros.length;

        double sumatorio = 0;
        for (int i = 0; i < numeros.length; i++) {
            sumatorio = sumatorio + Math.pow((numeros[i] - media), 2);
        }
        double varianza = (1 / (double) numeros.length) * sumatorio;

        double desviacionTipica = Math.sqrt(varianza);

        return desviacionTipica;
    }

    public static void main(String[] args) {
        if (args.length == 0 && args.length != 1) {
            System.out.println("Introduzca un parámetro entero en la línea de comandos.");
        } else {

            int numerosTotales = Integer.parseInt(args[0]); //transformación en enteros de los argumentos leídos en pantalla al inicio del
            int numeros[] = new int[numerosTotales];

            for (int i = 0; i < numerosTotales; i++) {
                numeros[i] = teclado.nextInt();
            }

            int opcion;
            do {
                System.out.println("Elige el estadístico que desea calcular:\n1.) Media\n2.) Moda\n3.) Varianza\n4.) Desviación típica");
                opcion = teclado.nextInt();
            } while (1 < opcion && opcion > 4);

            switch (opcion) {
                case 1:
                    System.out.println("La media es " + media(numeros));
                    break;
                case 2:
                    System.out.println("La moda es " + moda(numeros));
                    break;
                case 3:
                    System.out.println("La varianza es " + varianza(numeros));
                    break;
                case 4:
                    System.out.println("la desviación típica es " + desviacionTipica(numeros));
                    break;
            }
        }
    }
}
