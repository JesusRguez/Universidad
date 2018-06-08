/**
* Programa en Java que pide al usuario el lado de
* un cuadrado, y muestra su area y su permetro.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
import java.util.*;
public class Cuadrado
{
    /**El metodo main recibe como argumento
    * un array de cadenas de caracteres.
    *@param args array de cadenas de caracteres
    */

    public static void main (String[] args)
    {
        System.out.println("El lado del cuadrado mide: ");
        Scanner teclado = new Scanner(System.in);
        double lado = teclado.nextDouble();
        System.out.println("El perimetro del cuadrado es " + lado * 4);
        System.out.println("El area del cuadrado es " + lado * lado);
    }
}
