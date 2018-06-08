/**
* Programa en Java que escribe la media de dos números en la pantalla.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
import java.util.Scanner;
public class Media
{
    static Scanner Teclado = new Scanner(System.in);
    //La función anterior de teclado también se puede poner dentro del main como: Scanner teclado = new Scanner(System.in);
    float media(float a, float b)
    {
        return (a+b)/2;
    }
    public static void main (String[] args)
    {
        float a, b, m;
        Media med;
        med = new Media();
        System.out.println("Introduce el primer número:");
        a = Teclado.nextFloat();
        System.out.println("Introduce el segundo número:");
        b = Teclado.nextFloat();
        
        m = med.media(a, b);
        
        System.out.println("La media de ambos valores es " + m);
    }
}
