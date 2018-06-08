/**
* Programa en Java que escribe la media de dos n�meros en la pantalla.
*
* @author Jes�s Rodr�guez Heras
* @version 1.0
*/
import java.util.Scanner;
public class Media
{
    static Scanner Teclado = new Scanner(System.in);
    //La funci�n anterior de teclado tambi�n se puede poner dentro del main como: Scanner teclado = new Scanner(System.in);
    float media(float a, float b)
    {
        return (a+b)/2;
    }
    public static void main (String[] args)
    {
        float a, b, m;
        Media med;
        med = new Media();
        System.out.println("Introduce el primer n�mero:");
        a = Teclado.nextFloat();
        System.out.println("Introduce el segundo n�mero:");
        b = Teclado.nextFloat();
        
        m = med.media(a, b);
        
        System.out.println("La media de ambos valores es " + m);
    }
}
