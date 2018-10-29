/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package complejos;

public class Complejos{

    double[] c = new double[2];

    public Complejos(){}

    /**
     * Constructor de Complejos
     * @param r Parte real del complejo
     * @param i Parte imaginaria del complejo
     */
    public Complejos(double r, double i){
        this.c[0] = r;
        this.c[1] = i;
    }

    /**
     * Método para sumar complejos
     * @param  a Primer complejo
     * @param  b Segundo complejo
     * @return   Retorna el complejo resultante
     */
    public static Complejos suma(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.c[0] = a.c[0] + b.c[0];
        res.c[1] = a.c[1] + b.c[1];
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
        res.c[0] = a.c[0] - b.c[0];
        res.c[1] = a.c[1] - b.c[1];
        return res;
    }

    /**
     * Método para calcular el módulo de un complejo
     * @param  a Complejo al que calcular el módulo
     * @return   Retorna el módulo del complejo
     */
    public static double modulo(Complejos a){
        double res = Math.sqrt(Math.pow(a.c[0], 2)+(Math.pow(a.c[1], 2)));
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
        res.c[0] = a.c[0] * b.c[1];
        res.c[1] = a.c[1] * b.c[0];
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
        res.c[0] = (a.c[0] * b.c[0] + a.c[1] * b.c[1]) / (Math.pow(b.c[0], 2) + Math.pow(b.c[1], 2));
        res.c[1] = (a.c[1] * b.c[0] - a.c[0] * b.c[1]) / (Math.pow(b.c[0], 2) + Math.pow(b.c[1], 2));
        return res;
    }

    /**
     * Método para saber si un complejo es nulo
     * @return Devuelve true si el complejo es nulo y false en caso contrario
     */
    public boolean esComplejoNulo(){
        if (this.c[0] == 0 && this.c[1] == 0) {
            return true;
        }else{
            return false;
        }
    }

    /**
     * Método para obtener el cuadrante de un complejo
     * @return Retorna el cuadrante del complejo
     */
    public int cuadranteComplejo(){
        if (this.c[0] > 0 && this.c[1] > 0) {
            return 1;
        }else{
            if(this.c[0] < 0 && this.c[1] > 0){
                return 2;
            }else{
                if(this.c[0] < 0 && this.c[1] < 0){
                    return 3;
                }else{
                    if(this.c[0] > 0 && this.c[1] < 0){
                        return 4;
                    }
                }
            }
        }

        return 0;
    }

    /**
     * Método para calcular el conjugado de un complejo
     * @return Retorna el conjugado de un complejo
     */
    public Complejos conjugadoComplejos(){
        Complejos c = new Complejos(this.c[0], (-1)*this.c[1]);
        return c;
    }

    /**
     * Método para obtener la parte real de un complejo
     * @return Retorna la parte real del complejo
     */
    public double getReal(){
        return this.c[0];
    }

    /**
     * Método para establecer la parte real de un complejo
     * @param r Parte real del complejo
     */
    public void setReal(double r){
        this.c[0] = r;
    }

    /**
     * Método para obtener la parte imaginaria de un cumplejo
     * @return Retorna la parte imaginaria del complejo
     */
    public double getImaginario(){
        return this.c[1];
    }

    /**
     * Método para establecer la parte imaginaria de un complejo
     * @param i Parte imaginaria del complejo
     */
    public void setImaginario(double i){
        this.c[1] = i;
    }
}
