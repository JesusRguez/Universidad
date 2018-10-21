/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

import java.util.*;

class Cuadrado extends Poligono{

    /**
     * Constructor de la clase Poligono
     * @param puntos Puntos que forman el cuadrado
     */
    public Cuadrado(ArrayList<Punto> puntos){
        super(puntos);
    }

    /**
     * Método para calcular el perímetro del cuadrado
     * @return Retorna el perímetro del cuadrado
     */
    public double perimetroCuadrado(){
        double l1, l2, l3, l4;

        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);

        l1 = Punto.distancia(a, b);
        l2 = Punto.distancia(b, c);
        l3 = Punto.distancia(c, d);
        l4 = Punto.distancia(d, a);

        return l1 + l2 + l3 + l4;
    }

    /**
     * Método para calcular el área del Cuadrado
     * @return Retorna el área del cuadrado
     */
    public double areaCuadrado(){
        Punto a = figura.get(0);
        Punto b = figura.get(1);
        Punto c = figura.get(2);
        Punto d = figura.get(3);

        //Usamos la fórmula de Gauss para calcular el área
        double suma1 = a.x * b.y + b.x * c.y + c.x * d.y + d.x * a.y;
        double suma2 = b.x * a.y + c.x * b.y + d.x * c.y + a.x * d.y;

        return Math.abs((suma1 - suma2) / 2);
    }
}
