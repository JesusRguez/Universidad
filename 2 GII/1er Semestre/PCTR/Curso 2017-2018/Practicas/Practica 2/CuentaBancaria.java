
/**
 * Clase que modela una cuenta bancaria.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class CuentaBancaria {
//Atributos privados
//Titular de la cuenta

    private String titular;
//Codigo identificativo de la cuenta
    private long codigo;
//Saldo actual de la cuenta
    private double saldo;
//Constructor nulo

    public CuentaBancaria() {
    }
//Constructor

    public CuentaBancaria(String titu, long cod, double sald) {
        titular = titu;
        codigo = cod;
        saldo = sald;
    }
//Metodos observadores

    public String Titular() {
        return titular;
    }

    public long Codigo() {
        return codigo;
    }

    public double Saldo() {
        return saldo;
    }
//Metodos modificadores

    public void Titular(String titu) {
        titular = titu;
    }

    public void Saldo(double sald) {

        saldo = sald;
    }
}
