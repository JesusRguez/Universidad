package poligono;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Punto {

    double x, y; // Variables de instancia

    /**
     * @param x
     * @param y
     */
    public Punto(double x, double y) { // El constructor
        this.x = x;
        this.y = y;
    }

    /**
     * @param dx
     * @param dy
     */
    public void moverEn(double dx, double dy) { // Un método
        this.x += dx;
        this.y += dy;
    }

    /**
     * @return
     */
    public String toString() { // Otro método
        return "(" + this.x + "," + this.y + ")";
    }

    /**
     * @return
     */
    public double getX() {
        return this.x;
    }

    /**
     * @return
     */
    public double getY() {
        return this.y;
    }

    /**
     * @return
     */
    public double distanciaOrigen() {
        return Math.sqrt((Math.pow(this.x, 2)) + (Math.pow(this.y, 2)));
    }

    /**
     * @param P
     * @return
     */
    public double distancia(Punto P) {
        return Math.sqrt((Math.pow(this.x - P.x, 2)) - (Math.pow(this.y - P.y, 2)));
    }
}
