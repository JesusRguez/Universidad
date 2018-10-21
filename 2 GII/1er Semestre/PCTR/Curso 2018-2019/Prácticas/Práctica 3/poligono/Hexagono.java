/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

import java.util.*;

class Hexagono extends Poligono{

    /**
     * Constructor de Hexagono
     * @param puntos Puntos que forman el hexágono
     */
    public Hexagono(ArrayList<Punto> puntos){
        super(puntos);
    }

    /**
     * Método para calcular el perímetro de un hexágono
     * @return Retorna el perímetro del hexágono
     */
    public double perimetroHexagono(){
        double l1, l2, l3, l4, l5, l6;

        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);
        Punto e = figura.get(4);
        Punto f = figura.get(5);

        l1 = Punto.distancia(a, b);
        l2 = Punto.distancia(b, c);
        l3 = Punto.distancia(c, d);
        l4 = Punto.distancia(d, e);
        l5 = Punto.distancia(e, f);
        l6 = Punto.distancia(f, a);

        return l1 + l2 + l3 + l4 + l5 + l6;
    }

    /**
     * Método para calcular el área del hexágono
     * @return Retorna el área del hexágono
     */
    public double areaHexagono(){
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);
        Punto e = figura.get(4);
        Punto f = figura.get(5);

        //Usamos la fórmula del área de Gauss
        double suma1 = a.x * b.y + b.x * c.y + c.x * d.y + d.x * e.y + e.x * f.y + f.x * a.y;
        double suma2 = b.x * a.y + c.x * b.y + d.x * c.y + e.x * d.y + f.x * e.y + a.x * f.y;

        return Math.abs((suma1 - suma2) / 2);
    }

}
