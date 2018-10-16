/**
 * @author Jesús Rodríguez Heras
 */

package complejos;

class Complejos{

    double real, imaginario;

    Complejos(){}

    public static Complejos suma(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = a.real + b.real;
        res.imaginario = a.imaginario + b.imaginario;
        return res;
    }

    public static Complejos resta(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = a.real - b.real;
        res.imaginario = a.imaginario - b.imaginario;
        return res;
    }

    public static double modulo(Complejos a){
        double res = Math.sqrt(Math.pow(a.real, 2)+(Math.pow(a.imaginario, 2)));
        return res;
    }

    public static Complejos producto(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = a.real * b.imaginario;
        res.imaginario = a.imaginario * b.real;
        return res;
    }

    public static Complejos cociente(Complejos a, Complejos b){
        Complejos res = new Complejos();
        res.real = (a.real * b.real + a.imaginario * b.imaginario) / (Math.pow(b.real, 2) + Math.pow(b.imaginario, 2));
        res.imaginario = (a.imaginario * b.real - a.real * b.imaginario) / (Math.pow(b.real, 2) + Math.pow(b.imaginario, 2));
        return res;
    }
}
