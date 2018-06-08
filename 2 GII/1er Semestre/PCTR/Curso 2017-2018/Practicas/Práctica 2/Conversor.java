
import java.util.Scanner;

/**
 * Clase que realiza conversiones de dolares a euros.
 *
 * @author Natalia Partera 7
 * @version 1.0
 */
public class Conversor {
//Atributo privado: factor de conversion

    private double factorConver;
//Constructor

    public Conversor(double factor) {
        factorConver = factor;
    }
//Metodo observador

    public double VerFactor() {
        return factorConver;
    }
//Metodo modificador

    public void CambiarFactor(double nuevoFact) {
        factorConver = nuevoFact;
    }
//Metodo observador

    public double Convertir(double cantidad) {
        return cantidad * factorConver;
    }

    /*public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introudce una cifra a convertir: ");
        double f = teclado.nextDouble();
        Conversor c = new Conversor(f);

    }*/
    public static void main(String[] args) { //Este está hecho con metros y pulgadas, hacerlo con euros y dolares
        Conversor mInch;
        mInch = new Conversor(39.3700787);
        System.out.print("Conversor de metros a pulgadas");
        System.out.println("Factor de conversion: 1 metro = " + mInch.VerFactor()
                + " pulgadas");
        double metros = 0.25;
        System.out.println(metros + " metros son " + mInch.Convertir(metros)
                + " pulgadas");
        mInch.CambiarFactor(mInch.VerFactor() / 100);
        double cm = 25;
        System.out.println(cm + " cm son " + mInch.Convertir(cm) + " pulgadas");
    }
}
