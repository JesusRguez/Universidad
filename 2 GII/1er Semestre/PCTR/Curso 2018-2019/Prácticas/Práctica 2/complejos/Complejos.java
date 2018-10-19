/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package complejos;

class Complejos{

    double real, imaginario;

    Complejos(){}

    /**
     * Método para sumar complejos
     * @param  a Primer complejo
     * @param  b Segundo complejo
     * @return   Retorna el complejo resultante
     */
    public static Complejos suma(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = a.real + b.real;
        res.imaginario = a.imaginario + b.imaginario;
        return res;
    }

    /**
     * Método para restar complejos
     * @param  a Primero complejo
     * @param  b Segundo complejo
     * @return   Retorna el complejo resultante
     */
    public static Complejos resta(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = a.real - b.real;
        res.imaginario = a.imaginario - b.imaginario;
        return res;
    }

    /**
     * Método para calcular el módulo de un complejo
     * @param  a Complejo al que calcular el módulo
     * @return   Retorna el módulo del complejo
     */
    public static double modulo(Complejos a){
        double res = Math.sqrt(Math.pow(a.real, 2)+(Math.pow(a.imaginario, 2)));
        return res;
    }

    /**
     * Método para calcular el producto de complejos
     * @param  a Primer complejo
     * @param  b Segundo complejo
     * @return   Retorna el producto de dos complejos
     */
    public static Complejos producto(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = a.real * b.imaginario;
        res.imaginario = a.imaginario * b.real;
        return res;
    }

    /**
     * Método para calcular el cociente de complejos
     * @param  a Primer complejo
     * @param  b Segundo complejo
     * @return   Retorna el cociente de dos complejos
     */
    public static Complejos cociente(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = (a.real * b.real + a.imaginario * b.imaginario) / (Math.pow(b.real, 2) + Math.pow(b.imaginario, 2));
        res.imaginario = (a.imaginario * b.real - a.real * b.imaginario) / (Math.pow(b.real, 2) + Math.pow(b.imaginario, 2));
        return res;
    }
}
