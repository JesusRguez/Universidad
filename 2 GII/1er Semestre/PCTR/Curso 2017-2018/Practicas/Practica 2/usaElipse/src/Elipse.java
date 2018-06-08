
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Elipse {

    double a, b, o1, o2;

    /**
     * @param radioMenor
     * @param radioMayor
     * @param centroX
     * @param centroY
     */
    public Elipse(double radioMenor, double radioMayor, double centroX, double centroY) { //Constructuor de la clase Elipse
        a = radioMenor;
        b = radioMayor;
        o1 = centroX;
        o2 = centroY;
    }

    /**
     * @param x
     * @param y
     * @return
     */
    public boolean esUnPunto(double x, double y) {
        boolean dentro = false;
        if (((x - Math.pow(o1, 2)) / Math.pow(a, 2)) + ((y - Math.pow(y, o2) / Math.pow(b, 2))) == 1) {
            dentro = true;
        }
        return dentro;
    }

    public double superficie() {
        return Math.PI * a * b;
    }

    public double perimetro() {
        return (Math.PI * (a - b) - Math.sqrt((3 * a + b) * (a + 3 * b)));
    }

    public double radioA() {
        return a;
    }

    public double radioB() {
        return b;
    }
}
