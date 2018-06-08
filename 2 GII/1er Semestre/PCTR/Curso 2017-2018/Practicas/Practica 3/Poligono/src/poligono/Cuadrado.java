package poligono;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.ArrayList;

public class Cuadrado extends Poligono {

    /**
     * @param entrada
     */
    public Cuadrado(ArrayList<Punto> entrada) {
        super(entrada);
    }

    /**
     * @return
     */
    public double perimetroCuadrado() {
        double l1, l2, l3, l4, resultado;
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);

        l1 = distancia(a, b);
        l2 = distancia(b, c);
        l3 = distancia(c, d);
        l4 = distancia(d, a);

        resultado = l1 + l2 + l3 + l4;

        return resultado;
    }

    /**
     * @return
     */
    public double areaCuadrado() {
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);

        //Usamos la fórmula del área de Gauss
        double suma1 = a.x * b.y + b.x * c.y + c.x * d.y + d.x * a.y;
        double suma2 = b.x * a.y + c.x * b.y + d.x * c.y + a.x * d.y;

        return Math.abs((suma1 - suma2) / 2);
    }
}
