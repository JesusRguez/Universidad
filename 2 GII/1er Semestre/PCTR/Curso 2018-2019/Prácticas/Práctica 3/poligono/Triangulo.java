/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

import java.util.*;

class Triangulo extends Poligono{

    /**
     * Constructor de la clase Triángulo
     * @param puntos Puntos que forman el triángulo
     */
    public Triangulo(ArrayList<Punto> puntos){
        super(puntos);
    }

    /**
     * Método para calcular el perímetro de un triángulo
     * @return Retorna el perímetro del triángulo
     */
    public double perimetroTriangulo(){
        double l1, l2, l3;

        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);

        l1 = Punto.distancia(a, b);
        l2 = Punto.distancia(b, c);
        l3 = Punto.distancia(c, a);

        return l1 + l2 + l3;
    }

    public double areaTriangulo(){
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);

        //Usamos la fórmula del área de Gauss
        return ((a.x * b.y + b.x * c.y + a.y * c.x) - (c.x * b.y + b.x * a.y + c.y * a.x)) / 2;
    }
}
