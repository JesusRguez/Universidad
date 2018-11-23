/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

 import java.util.*;
 import java.lang.Math;
 import java.util.concurrent.*;
 import java.util.concurrent.Callable;

public class piParaleloFutureCont implements Callable<Integer>{
    public int puntos;

    public piParaleloFutureCont(int p){
        this.puntos = p;
    }

    public Integer call(){
        double x, y;
        int res = 0;
        Random r = new Random();
        for (int i=0; i<puntos; ++i) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (Math.pow(x,2)+Math.pow(y,2) <= 1) {
                res+=1;
            }
        }
        return res;
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de puntos:");
        int p = teclado.nextInt();
        int h = Runtime.getRuntime().availableProcessors();//Usando la ecuación de subramanian el coeficiente de bloque es 0 para este problema debido a que es de tipología numérica.
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        int cont = 0;
        int sol = 0;
        ArrayList<Future<Integer>> contParciales = new ArrayList<Future<Integer>>();
        long time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            contParciales.add(ejecutor.submit(new piParaleloFutureCont(p/h)));
        }
        for (Future<Integer> iterador:contParciales) {
            try {
                sol += iterador.get();
            }catch (Exception e) {
                System.out.println("Error en el Future");
            }
        }
        ejecutor.shutdown();
        long time_end = System.currentTimeMillis();
        System.out.println("El resultado es: "+4*(double)sol/p);
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos.");
    }
}
