/**
* Programa en Java que determina si una fecha es válida o no en la pantalla.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
import java.io.*;
public class Fecha
{
    boolean fecha(int dia, int mes, int año)
    {
        boolean flag = false;
        switch(mes)
        {
            case 1:                
            case 3:                
            case 5:                
            case 7:                
            case 8:                
            case 10:                
            case 12:
                if(1<=dia && dia<=31)
                {
                    flag = true;
                }else
                {
                    System.out.println("El día introducido está fuera del rango de días del mes seleccionado, 31.");
                }
                break;
            case 2:
                if(año%4==0&&(año%100!=0||año%400==0))
                {
                    if(1<=dia && dia<=29)
                    {
                        flag = true;
                    }else
                    {
                        System.out.println("El día introducido está fuera del rango de días del mes seleccionado, 29.");
                    }
                }else
                {
                    if(1<=dia && dia<=28)
                    {
                        flag = true;
                    }else
                    {
                        System.out.println("El día introducido está fuera del rango de días del mes seleccionado, 28.");
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(1<=dia && dia<=30)
                {
                    flag = true;
                }else
                {
                    System.out.println("El día introducido está fuera del rango de días del mes seleccionado, 30.");
                }
            default:
                System.out.println("El mes introducido está fuera del rango de meses del año, 12.");
                
        }
        return flag;
    }
    public static void main (String[] args) throws IOException
    {
        int dia, mes, año;
        boolean verdad = false;
        Fecha f;
        f = new Fecha();
        
        BufferedReader dato = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Introduzca el día:");
        dia = Integer.parseInt(dato.readLine());
        System.out.println("Introduzca el mes:");
        mes = Integer.parseInt(dato.readLine());
        System.out.println("Introduzca el año:");
        año = Integer.parseInt(dato.readLine());
        
        if(f.fecha(dia, mes, año)==true)
        {
            System.out.println("La fecha introducida es correcta.");
        }else
        {
            System.out.println("La fecha introducida no es correcta.");
        }
    }
}
