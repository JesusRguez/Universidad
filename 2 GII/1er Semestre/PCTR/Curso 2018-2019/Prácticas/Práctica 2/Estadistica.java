/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.lang.*;
import java.util.*;

class Estadistica{

    /**
     * Método para calcular al media aritmética
     * @param  []v Array de valores de entrada
     * @return     Retorna la media aritmética
     */
    public static double media(double []v){
        double s=0;
        for (int i=0; i<v.length; ++i) {
            s+=v[i];
        }
        return s/v.length;
    }

    /**
     * Método para calcular la moda
     * @param  []v Array de valores de entrada
     * @return     Retorna la moda
     */
    public static double moda(double []v){
        int repeticiones;
        int maxrepeticiones = 0;
        double moda = 0;
        for (int i=0; i<v.length; ++i) {
            repeticiones = 0;
            for (int j=0; j<v.length; ++j) {
                if (v[i] == v[j]) {
                    repeticiones++;
                }
                if (repeticiones > maxrepeticiones) {
                    moda = v[i];
                    maxrepeticiones = repeticiones;
                }
            }
        }
        return moda;
    }

    /**
     * Método para calcular la varianza
     * @param  []v Array de valores de entrada
     * @return     Retorna la varianza
     */
    public static double varianza(double []v){
        double sumatorio = 0;
        double m = media(v);
        for (int i=0; i<v.length; ++i) {
            sumatorio+=Math.pow(v[i]-m, 2);
        }
        return sumatorio/(v.length-1);
    }

    /**
     * Método para calcular la desviación típica
     * @param  []v Array de valores de entrada
     * @return     Retorna la desviación típica
     */
    public static double desviacion(double []v){
        return Math.sqrt(varianza(v));
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de elementos:");
        int n = teclado.nextInt();
        double []v = new double[n];
        for (int i=0; i<n; ++i) {
            System.out.print("Introduzca el elemento "+(i+1)+": ");
            v[i] = teclado.nextDouble();
        }
        int opcion;
        do {
            do {
                System.out.println("Seleccione la acción que desea:\n1. Media\n2. Moda\n3. Varianza\n4. Desviación típica\n5. Salir");
                opcion=teclado.nextInt();
                switch(opcion){
                    case 1:
                        double me = media(v);
                        System.out.println("La media es "+me);
                        break;
                    case 2:
                        double mo = moda(v);
                        System.out.println("La moda es "+mo);
                        break;
                    case 3:
                        double va = varianza(v);
                        System.out.println("La varianza es "+va);
                        break;
                    case 4:
                        double d = desviacion(v);
                        System.out.println("La desviación es "+d);
                        break;
                    case 5: break;
                }
                if (opcion < 1 || opcion > 5) {
                    System.out.println("Solo hay cuatro opciones, por favor, seleccione 1, 2, 3, 4 ó 5.");
                }
            } while (opcion < 1 && opcion > 5);
        } while (opcion != 5);
    }
}
