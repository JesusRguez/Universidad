/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package cajero;

import java.util.*;

public class Cajero {

    ArrayList<Cuenta_Banca2> cuentas = new ArrayList<Cuenta_Banca2>();

    public Cajero(){
        cuentas.add(new Cuenta_Banca2(1, 20000, "pepe"));
        cuentas.add(new Cuenta_Banca2(2, 30000, "juan"));
        cuentas.add(new Cuenta_Banca2(3, 40000, "pedro"));
        cuentas.add(new Cuenta_Banca2(4, 10000, "antonio"));
    }

    public void deposito(int id, double cantidad){
        boolean encontrado = false;
        int i = 0;

        Cuenta_Banca2 resultado = new Cuenta_Banca2();
        while(!encontrado && i<cuentas.size()){
            resultado = cuentas.get(i);
            if(resultado.Codigo_Cuenta == id){
                encontrado = true;
                System.out.println("Saldo inicial: "+cuentas.get(i).Saldo());
                resultado.Deposito(cantidad);
                System.out.println("Saldo final: "+cuentas.get(i).Saldo());
            }
            i++;
        }
    }

    public void reintegro(int id, double cantidad){
        boolean encontrado = false;
        int i = 0;

        Cuenta_Banca2 resultado = new Cuenta_Banca2();
        while(!encontrado && i<cuentas.size()){
            resultado = cuentas.get(i);
            if(resultado.Codigo_Cuenta == id){
                encontrado = true;
                System.out.println("Saldo inicial: "+cuentas.get(i).Saldo());
                resultado.Reintegro(cantidad);
                System.out.println("Saldo final: "+cuentas.get(i).Saldo());
            }
            i++;
        }
    }
}
