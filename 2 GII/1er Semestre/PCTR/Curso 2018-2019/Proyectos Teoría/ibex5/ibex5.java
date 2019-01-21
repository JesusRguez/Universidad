package ibex5;

import java.io.*;

public class ibex5 implements java.io.Serializable{
    String nombre, acronimo;
    double valor;

    public ibex5(String n, String a, double v){
        this.nombre = n;
        this.acronimo = a;
        this.valor = v;
    }

    public String toString(){
        return "Nombre: "+this.nombre+" "+this.acronimo+"\tValor: "+this.valor;
    }

}
