/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Complejos {

    static double[] complejo;

    /**
     * @param real
     * @param imaginario
     */
    public Complejos(double real, double imaginario) { //Constructor de la clase Complejos
        complejo = new double[2];
        complejo[0] = real;
        complejo[1] = imaginario;
    }

    /**
     * @param a
     * @param b
     * @return
     */
    public static Complejos sumaComplejos(Complejos a, Complejos b) {
        //complejo = new double[2];
        double real, imaginario;
        real = a.complejo[0] + b.complejo[0];
        imaginario = a.complejo[1] + b.complejo[1];
        Complejos resultado = new Complejos(real, imaginario);
        System.out.println(resultado.complejo[0] + "+" + resultado.complejo[1] + "i");
        return resultado;
    }

    /**
     * @param a
     * @param b
     * @return
     */
    public static Complejos restaComplejos(Complejos a, Complejos b) {
        //complejo = new double[2];
        double real, imaginario;
        real = a.complejo[0] - b.complejo[0];
        imaginario = a.complejo[1] - b.complejo[1];
        Complejos resultado = new Complejos(real, imaginario);

        return resultado;
    }

    /**
     * @param a
     * @return
     */
    public static double moduloComplejos(Complejos a) {
        return Math.hypot(a.complejo[0], a.complejo[1]);

    }

    /**
     * @param a
     * @param b
     * @return
     */
    public static Complejos productoComplejos(Complejos a, Complejos b) {
        //complejo = new double[2];
        double real, imaginario;
        real = a.complejo[0] * b.complejo[0] - a.complejo[1] * b.complejo[1];
        imaginario = a.complejo[0] * b.complejo[1] + a.complejo[1] * b.complejo[0];
        Complejos resultado = new Complejos(real, imaginario);

        return resultado;
    }

    /**
     * @param a
     * @param b
     * @return
     */
    public static Complejos cocienteComplejos(Complejos a, Complejos b) {
        //complejo = new double[2];
        double real, imaginario;
        real = ((a.complejo[0] * b.complejo[0]) + (a.complejo[1] * b.complejo[1])) / ((Math.pow(b.complejo[0], 2)) + (Math.pow(b.complejo[1], 2)));
        imaginario = ((a.complejo[1] * b.complejo[0]) - (a.complejo[0] * b.complejo[1])) / ((Math.pow(b.complejo[0], 2)) + (Math.pow(b.complejo[1], 2)));
        Complejos resultado = new Complejos(real, imaginario);

        return resultado;
    }

    /**
     * @param a
     * @return
     */
    static boolean nulo(Complejos a) {
        if (a.complejo[0] == 0 && a.complejo[1] == 0) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * @param a
     * @return
     */
    static int cuadrante(Complejos a) {
        if (a.complejo[0] >= 0 && a.complejo[1] >= 0) {
            return 1;
        } else if (a.complejo[0] < 0 && a.complejo[1] >= 0) {
            return 2;
        } else if (a.complejo[0] < 0 && a.complejo[1] < 0) {
            return 3;
        } else {
            return 4;
        }
    }

    /**
     * @param a
     * @return
     */
    static Complejos conjugado(Complejos a) {
        double conj = a.complejo[1] * (-1);
        Complejos resultado = new Complejos(a.complejo[0], conj);
        return resultado;
    }
}
