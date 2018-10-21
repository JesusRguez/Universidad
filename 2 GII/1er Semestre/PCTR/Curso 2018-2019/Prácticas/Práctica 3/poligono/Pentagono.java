/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

import java.util.*;

public class Pentagono extends Poligono{

    /**
     * Constructor de la clase Pentagono
     * @param puntos Puntos que forman el pentágono
     */
    public Pentagono(ArrayList<Punto> puntos){
        super(puntos);
    }

    /**
     * Método para calcular el perímetro del pentágono
     * @return Retorna el perímetro del pentágono
     */
    public double perimetroPentagono(){
        double l1, l2, l3, l4, l5;

        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);
        Punto e = figura.get(4);

        l1 = Punto.distancia(a, b);
        l2 = Punto.distancia(b, c);
        l3 = Punto.distancia(c, d);
        l4 = Punto.distancia(d, e);
        l5 = Punto.distancia(e, a);

        return l1 + l2 + l3 + l4 + l5;
    }

    /**
     * Método para calcular el área del pentágono
     * @return Retorna el área del pentágono
     */
    public double areaPentagono(){
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);
        Punto e = figura.get(4);

        //Usamos la fórmula el área de Gauss
        double suma1 = a.x * b.y + b.x * c.y + c.x * d.y + d.x * e.y + e.x * a.y;
        double suma2 = b.x * a.y + c.x * b.y + d.x * c.y + e.x * d.y + a.x * e.y;

        return Math.abs((suma1 - suma2) / 2);
    }

}
