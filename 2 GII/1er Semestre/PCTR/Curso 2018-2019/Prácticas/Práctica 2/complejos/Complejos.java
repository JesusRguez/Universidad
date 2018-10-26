/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package complejos;

public class Complejos{

    double real, imaginario;

    public Complejos(){}

    public Complejos(double r, double i){
        this.real = r;
        this.imaginario = i;
    }

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

    /**
     * Método para saber si un complejo es nulo
     * @return Devuelve true si el complejo es nulo y false en caso contrario
     */
    public boolean esComplejoNulo(){
        if (this.real == 0 && this.imaginario == 0) {
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
        if (this.real > 0 && this.imaginario > 0) {
            return 1;
        }else{
            if(this.real < 0 && this.imaginario > 0){
                return 2;
            }else{
                if(this.real < 0 && this.imaginario < 0){
                    return 3;
                }else{
                    if(this.real > 0 && this.imaginario < 0){
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
        Complejos c = new Complejos(this.real, (-1)*this.imaginario);
        return c;
    }
}
