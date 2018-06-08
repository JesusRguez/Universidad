/**
* Programa en Java que dibuja un rectángulo de las medidas dadas en la pantalla.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
import java.io.*;
public class Dibujo
{
    void dibujar(int a, int b)
    {
        String c = "*";
        String s = "+";
        int aux;
        
        if(b>a) //Dejamos en a el mayor de los dos, que será la base del rectángulo
        {
            aux = a;
            a = b;
            b = aux;
        }
        
        for(int i=0; i<a; i++) //Barra de arriba
        {
            System.out.print(c);
        }
        System.out.println(s);
        for(int i=1; i<(a-2); i++) //Barras de los lados
        {
            System.out.print(c);
            for(int j=1; j<b; j++)
            {
                System.out.print(s);
            }
            System.out.println(c);
        }
        for(int i=0; i<a; i++) //Barra de abajo
        {
            System.out.print(c);
        }
    }
    public static void main (String[] args) throws IOException
    {
        Dibujo d;
        d = new Dibujo();
        
        int a, b;
        
        BufferedReader dato = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Introduce el primer número:");
        a = Integer.parseInt(dato.readLine());
        System.out.println("Introduce el segudo número:");
        b = Integer.parseInt(dato.readLine());
        d.dibujar(a, b);
    }
}

