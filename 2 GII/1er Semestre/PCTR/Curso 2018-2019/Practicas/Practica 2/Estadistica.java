/**
 * @author Jesús Rodríguez Heras
 */

import java.lang.*;
import java.util.*;

class Estadistica{
    public static double media(double []v){
        double s=0;
        for (int i=0; i<v.length; ++i) {
            s+=v[i];
        }
        return s/v.length;
    }

    public static void moda(double []v){
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
        System.out.println("La moda es: "+moda);
    }

    public static void varianza(double []v){
        double sumatorio = 0;
        double m = media(v);
        for (int i=0; i<v.length; ++i) {
            sumatorio+=Math.pow(v[i]-m, 2);
        }
        System.out.println("La varianza es "+sumatorio/(v.length-1));
    }

    public static void desviacion(double []v){

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
            System.out.println("Seleccione la acción que desea:\n1. Media\n2. Moda\n3. Varianza\n4. Desviación típica");
            opcion=teclado.nextInt();
            switch(opcion){
                case 1:
                    double m = media(v);
                    System.out.println("La media es "+m);
                    break;
                case 2: moda(v);
                    break;
                case 3: varianza(v);
                    break;
                case 4: desviacion(v);
                    break;
                case 5: break;
            }
            if (opcion > 5) {
                System.out.println("Solo hay cuatro opciones, por favor, selecciones 1, 2, 3, 4 ó 5.");
            }
        } while (opcion < 1 && opcion > 5);
    }
}
