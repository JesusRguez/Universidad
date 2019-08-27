import java.util.*;
public class piMonteCarlo{
    public static void main(String[] args) {
        int aciertos=0;
        double x,y;
        int intentos=0;
        Scanner s = new Scanner(System.in);
        long ini,fin;
        System.out.println("Introduzca numero de intentos");
        intentos=s.nextInt();
        ini=System.currentTimeMillis();
        for (int i=0;i<intentos ;++i ) {
            x=Math.random();
            y=Math.random();
            if((Math.pow(x,2)+Math.pow(y,2))<=1)
            {
                aciertos++;
            }
        }
        fin=System.currentTimeMillis()-ini;
        double porcentaje=(double)aciertos/(double)intentos;
        double pi=4*porcentaje;
        System.out.println("El numero pi es "+pi);
        System.out.println("El tiempo es de "+fin+" ms");
    }
}
