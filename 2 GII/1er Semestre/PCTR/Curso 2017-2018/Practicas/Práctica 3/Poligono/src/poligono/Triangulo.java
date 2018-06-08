package poligono;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.ArrayList;

public class Triangulo extends Poligono {

    /**
     * @param entrada
     */
    public Triangulo(ArrayList<Punto> entrada) {
        super(entrada);
    }

    /**
     * @return
     */
    public double perimetroTriangulo() {
        double l1, l2, l3, resultado;

        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);

        l1 = distancia(a, b);
        l2 = distancia(b, c);
        l3 = distancia(c, a);

        resultado = l1 + l2 + l3;

        return resultado;
    }

    /**
     * @return
     */
    public double areaTriangulo() {
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);

        //Usamos la fórmula del área de Gauss
        return ((a.x * b.y + b.x * c.y + a.y * c.x) - (c.x * b.y + b.x * a.y + c.y * a.x)) / 2;
    }
}
