package poligono;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.ArrayList;

public class Pentagono extends Poligono {

    /**
     * @param entrada
     */
    public Pentagono(ArrayList<Punto> entrada) {
        super(entrada);
    }

    /**
     * @return
     */
    public double perimetroPentagono() {
        double l1, l2, l3, l4, l5, resultado;
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);
        Punto e = figura.get(4);

        l1 = distancia(a, b);
        l2 = distancia(b, c);
        l3 = distancia(c, d);
        l4 = distancia(d, e);
        l5 = distancia(e, a);

        resultado = l1 + l2 + l3 + l4 + l5;

        return resultado;
    }

    /**
     * @return
     */
    public double areaPentagono() {

        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);
        Punto e = figura.get(4);

        //Usamos la fórmula del área de Gauss
        double suma1 = a.x * b.y + b.x * c.y + c.x * d.y + d.x * e.y + e.x * a.y;
        double suma2 = b.x * a.y + c.x * b.y + d.x * c.y + e.x * d.y + a.x * e.y;

        return Math.abs((suma1 - suma2) / 2);
    }

}
