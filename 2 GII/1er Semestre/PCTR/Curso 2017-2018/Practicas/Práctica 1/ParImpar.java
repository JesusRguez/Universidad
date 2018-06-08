/**
* Programa en Java que escribe si el número es par o impar en la pantalla.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
import java.io.*;
public class ParImpar
{
    void parimpar(int a)
    {
        if(a%2==0)
            System.out.println("El número " + a + " es par.");
        else
            System.out.println("El número " + a + " es impar");
    }
    public static void main (String[] args) throws IOException
    {
        int a, b, c;
        
        ParImpar pi;
        pi = new ParImpar();
        
        BufferedReader dato = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Introduzca el primer número");
        a = Integer.parseInt(dato.readLine());
        System.out.println("Introduzca el segundo número");
        b = Integer.parseInt(dato.readLine());
        System.out.println("Introduzca el tercer número");
        c = Integer.parseInt(dato.readLine());
        
        pi.parimpar(a);
        pi.parimpar(b);
        pi.parimpar(c);  
    }
}
