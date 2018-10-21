/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

import java.util.*;

class Poligono{
    public static ArrayList<Punto> figura;
    public static Scanner teclado = new Scanner(System.in);

    /**
     * Constructor de la clase Poligono
     * @param nueva figura nueva que le llega como parámetro de entrada
     */
    public Poligono(ArrayList<Punto> nueva){
        figura = new ArrayList<Punto>();
        figura = nueva;
    }

    /**
     * Método para calcular el número de lados de una figura
     * @return Devuelve el número de lados que coincide con el número de puntos de la figura
     */
    public int nLados(){
        return figura.size();
    }

    /**
     * Método para desplazar una figura existente
     */
    public void desplazarFigura(){
        System.out.println("Introduzca el incremento en el eje X: ");
        double desplazamientoX = teclado.nextDouble();
        System.out.println("Introduzca el incremento en el eje Y: ");
        double desplazamientoY = teclado.nextDouble();
        for (int i=0; i<figura.size(); ++i) {
            figura.get(i).moverEn(desplazamientoX, desplazamientoY);
        }
    }

    /**
     * Método para hacer zoom a una figura existente
     */
    public void zoom(){
        System.out.println("Introduzca la escala para hacer zoom a la imagen: ");
        double escala = teclado.nextDouble();
        for (int i=0; i<figura.size(); ++i) {
            figura.get(i).x = figura.get(i).x * escala;
            figura.get(i).y = figura.get(i).y * escala;
        }
    }
}
