
/**
 * Programa que usa cuentas bancarias.
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class UsaCuentaBancaria {

    public static void main(String args[]) {
//Declaracion de variables
        CuentaBancaria c1, c2;
//Creacion e inicializacion de c1
        c1 = new CuentaBancaria("Pepito Grillo", 1234567890, 1500.85);
//Observamos los valores de c1
        System.out.println("La cuenta c1 es de " + c1.Titular() + ".");
        System.out.println("El codigo de la cuenta c1 es " + c1.Codigo()
                + " y su saldo es de " + c1.Saldo() + " euros.");
//Hacemos que c2 y c1 apunten al mismo objeto
        c2 = c1;
//Observamos los valores de c2
        System.out.println("La cuenta c2 es de " + c2.Titular() + ".");
        System.out.println("El codigo de la cuenta c2 es " + c2.Codigo()
                + " y su saldo es de " + c2.Saldo() + " euros.");
//Modificamos los valores de c2
        c2.Titular("Pinocho");
        c2.Saldo(c2.Saldo() - 350.65);
//Observamos los valores actuales de c2
        System.out.println("La cuenta c2 ha sufrido cambios.");
        System.out.println("Ahora la cuenta c2 es de " + c2.Titular() + ".");
        System.out.println("El codigo de la cuenta c2 es " + c2.Codigo()
                + " y su saldo ahora es de " + c2.Saldo() + " euros.");
//Observamos los valores actuales de c1
        System.out.println("Comprobamos la cuenta c1.");
        System.out.println("La cuenta c1 es de " + c1.Titular() + ".");
        System.out.println("El codigo de la cuenta c1 es " + c1.Codigo()
                + " y su saldo es de " + c1.Saldo() + " euros.");
    }
}
