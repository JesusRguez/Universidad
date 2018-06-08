
public class Punto {

    double x, y; // Variables de instancia

    public Punto(double x, double y) { // El constructor
        this.x = x;
        this.y = y;
    }

    public void moverEn(double dx, double dy) { // Un método
        this.x += dx;
        this.y += dy;
    }

    public String toString() { // Otro método
        return "(" + this.x + "," + this.y + ")";
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public double distanciaOrigen() {
        return Math.sqrt((Math.pow(this.x, 2)) + (Math.pow(this.y, 2)));
    }

    public double distancia(Punto P) {
        return Math.sqrt((Math.pow(this.x - P.x, 2)) - (Math.pow(this.y - P.y, 2)));
    }
}
