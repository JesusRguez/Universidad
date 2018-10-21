/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

public class Punto {
    double x, y; // Variables de instancia

    /**
     * Constructor de la clase Punto
     * @param x Coordenada X del punto
     * @param y Coordenada Y del punto
     */
    public Punto(double x, double y) {
        this.x= x; this.y= y;
    }

    /**
     * Método para mover un punto
     * @param dx Incremento de la coordenada X para mover un punto en el eje de abscisas
     * @param dy Incremento de la coordenada Y para mover un punto en el eje de ordenadas
     */
    public void moverEn(double dx, double dy) {
        this.x+= dx; this.y+= dy;
    }

    /**
     * Método para calcular la distancia entre dos puntos
     * @param  a Primer punto
     * @param  b Segundo punto
     * @return   Retorna la distancia entre los puntos a y b
     */
    public static double distancia(Punto a, Punto b){
        return Math.abs(Math.sqrt(Math.pow((b.x - a.x), 2) + Math.pow((b.y - a.y), 2)));
    }

    /**
     * Método toString de la clase Punto
     * @return Retorna un punto como un String
     */
    public String toString() {
        return "("+this.x+","+this.y+")";
    }
}
