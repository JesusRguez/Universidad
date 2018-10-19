/**
 * @author Jesús Rodríguez Heras
 */

package elipse;

class Elipse{
    double a, b, o1, o2;

    /**
     * Constructor de Elipse
     * @param radioMenor Radio menor de la elipse
     * @param radioMayor Radio mauor de la elipse
     * @param centroX    Coordenada X del centro de la elipse
     * @param centroY    Coordenada Y del centro de la elipse
     */
    public Elipse(double radioMenor, double radioMayor, double centroX, double centroY) { //Constructuor de la clase Elipse
        a = radioMayor;
        b = radioMenor;
        o1 = centroX;
        o2 = centroY;
    }

    /**
     * Método para obtener el radio mayor de la elipse
     * @return Retorna el radio mayor de la elipse
     */
    public double radioMayor(){
        return a;
    }

    /**
     * Método para obtener el radio menor de la elipse
     * @return Retorna el radio menor de la elipse
     */
    public double radioMenor(){
        return b;
    }

    /**
     * Método para calcular el área de la elipse
     * @return Retorna el área de la elipse
     */
    public double area(){
        return Math.PI * a * b;
    }

    /**
     * Método para calcular el perímetro de la elipse
     * @return Retorna el perímetro de la elipse
     */
    public double perimetro(){
        return Math.PI + (3 * (a + b) - Math.sqrt((3 * a + b) * (a + 3 * b)));
    }

    /**
     * Método para saber si un punto pertenece o no a la elipse
     * @param  x Coordenada X del punto a comprobar
     * @param  y Coordenada Y el punto a comprobar
     * @return   Devuelve true si el punto pertenece a la elipse y false en caso contrario
     */
    public boolean puntoPertenece(double x, double y) {
        boolean dentro = false;
        if (((x - Math.pow(o1, 2)) / Math.pow(a, 2)) + ((y - Math.pow(o2, 2)) / Math.pow(b, 2)) == 1) {
            dentro = true;
        }
        return dentro;
    }
}
