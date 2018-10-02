import java.util.*;
import java.lang.Math;

class intDefinidaMonteCarlo{

    public static void seno(int puntos){
        double aciertos=0;
        double x, y;
        for (int i=0; i<puntos; ++i) {
            x = Math.random();
            y = Math.random();
            if (y<=Math.sin(x)) {
                aciertos++;
            }
        }
        System.out.println("El resultado es: "+aciertos/puntos);
    }

    public static void lineal(int puntos){
        double aciertos=0;
        double x, y;
        for (int i=0; i<puntos; ++i) {
            x = Math.random();
            y = Math.random();
            if (y<=Math.sin(x)) {
                aciertos++;
            }
        }
        System.out.println("El resultado es: "+aciertos/puntos);
    }

    public static void main(String[] args) {
        System.out.println("Seleccione la función a la que le calculará la integral definida por el método de MonteCarlo:\n1. f(x)=sin(x)\n2. f(x)=x");
        Scanner teclado = new Scanner(System.in);
        int opcion = teclado.nextInt();
        System.out.println("Introduzca el número de puntos:");
        int puntos = teclado.nextInt();
        switch (opcion) {
            case 1: seno(puntos); break;
            case 2: lineal(puntos); break;
        }
    }
}
