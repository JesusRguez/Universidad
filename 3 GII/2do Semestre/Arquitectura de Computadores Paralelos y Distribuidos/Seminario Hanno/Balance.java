import java.util.*;

public class Balance{
    public static Scanner teclado = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Introduce el número de contenedores: ");
        int n = teclado.nextInt();
        System.out.print("Introduce el número de bolas: ");
        int m = teclado.nextInt();
        int v = 2;
        int[] c = new int[n];
        c[0] = m;
        for (int i=1; i<n; ++i) {
            c[i] = 0;
        }

        int i, j, counter = 0;
        while(true){
            i = (int)(Math.random()*(n));
            j = (int)(Math.random()*(n));
            if (((Math.random()*(c[i]+c[j])) < c[i]) /*&& (STDEV(c) < c[i])*/) {
                c[i]--;
                c[j]++;
                counter++;
                System.out.println(STDEV(c));
                for (int x=0; x<n; ++x) {
                    System.out.print(c[x] + " ");
                }
                System.out.println(" ");
            }
            /*if (((Math.random()*(c[i]+c[j])) > c[i]) && (STDEV(c) > c[i])) {
                c[i]++;
                c[j]--;
                counter++;
                System.out.println(STDEV(c));
            }*/
        }
    }

    public static double STDEV(int[] c){
        int sumatoria = 0;
        for (int i=0; i<c.length; ++i) {
            sumatoria += c[i];
        }
        int media = sumatoria / c.length;
        double varianza = 0;
        double desviacion = 0;
        for (int i=0; i<c.length; ++i) {
            double rango = Math.pow(c[i] - media, 2);
            varianza +=rango;
        }
        varianza /= c.length;

        desviacion = Math.sqrt(varianza);

        return desviacion;
    }
}
