package poligono;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Poligono {

    public static ArrayList<Punto> figura;
    public static Scanner teclado = new Scanner(System.in);

    /**
     * @param entrada
     */
    public Poligono(ArrayList<Punto> entrada) {
        figura = new ArrayList();

        figura = entrada;
    }

    /**
     * @param a
     * @param b
     * @return
     */
    public static double distancia(Punto a, Punto b) {
        return Math.abs(Math.sqrt(Math.pow((b.x - a.x), 2) + Math.pow((b.y - a.y), 2)));
    }

    /**
     * @return
     */
    public int nLados() {
        return figura.size();
    }

    /**
     * @return
     */
    public double escalado() {
        return 0;
    }

    /**
     * @return
     */
    public double despX() {
        System.out.println("Seleccione la cantidad a desplazar en el eje X:");
        double desplazamiento = teclado.nextDouble();
        for (int i = 0; i < figura.size(); i++) {
            figura.get(i).x = figura.get(i).x * desplazamiento;
        }
        return 0;
    }

    /**
     * @return
     */
    public double despY() {
        System.out.println("Seleccione la cantidad a desplazar en el eje Y:");
        double desplazamiento = teclado.nextDouble();
        for (int i = 0; i < figura.size(); i++) {
            figura.get(i).y = figura.get(i).y * desplazamiento;
        }
        return 0;
    }

    /**
     * @param escala
     */
    public void zoom(double escala) {
        for (int i = 0; i < figura.size(); i++) {
            figura.get(i).x = figura.get(i).x * escala;
            figura.get(i).y = figura.get(i).y * escala;
        }
    }

    /**
     * @return
     */
    public String toString() {
        return "(" + this.figura + ")";
    }
}
