/**
* Programa en Java que escribe si el n�mero es par o impar en la pantalla.
*
* @author Jes�s Rodr�guez Heras
* @version 1.0
*/
import java.io.*;
public class ParImpar
{
    void parimpar(int a)
    {
        if(a%2==0)
            System.out.println("El n�mero " + a + " es par.");
        else
            System.out.println("El n�mero " + a + " es impar");
    }
    public static void main (String[] args) throws IOException
    {
        int a, b, c;
        
        ParImpar pi;
        pi = new ParImpar();
        
        BufferedReader dato = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Introduzca el primer n�mero");
        a = Integer.parseInt(dato.readLine());
        System.out.println("Introduzca el segundo n�mero");
        b = Integer.parseInt(dato.readLine());
        System.out.println("Introduzca el tercer n�mero");
        c = Integer.parseInt(dato.readLine());
        
        pi.parimpar(a);
        pi.parimpar(b);
        pi.parimpar(c);  
    }
}
