/**
* Programa en Java que recibe dos parámetros para la libreria java.math en la pantalla.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
import java.util.Scanner;
import java.math.*;
public class Paquetes
{
    public static void main (String[] args)
    {
        double base, potencia;
        int exponente;
        double radicando, raiz;
        
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca los siguientes datos: ");
        System.out.print("Base: ");
        base = teclado.nextDouble();
        System.out.print("Exponente: ");
        exponente = teclado.nextInt();
        potencia = Math.pow(base, exponente);
        System.out.println(base + " elevado a " + exponente + " = " + potencia);
        System.out.print("Radicando: ");
        radicando = teclado.nextDouble();
        raiz = Math.sqrt(radicando);
        System.out.println("La raíz cuadrada de " + radicando + " es " + raiz);
    }
}