import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.Callable;
import java.lang.Math;

public class intParaleloFutureCont implements Callable<Integer> {

    public int puntos;

    public intParaleloFutureCont(int p){
        this.puntos = p;
    }

    public Integer call(){
        double x, y;
        int res = 0;
        Random r = new Random();
        for (int i=0; i<puntos; ++i) {
            x = r.nextDouble();
            y = r.nextDouble();
            if (y <= Math.sin(x)) {
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de puntos: ");
        int p = teclado.nextInt();
        int h = Runtime.getRuntime().availableProcessors();
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        int cont = 0;
        int sol = 0;
        ArrayList<Future<Integer>> contParciales = new ArrayList<Future<Integer>>();
        long time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            contParciales.add(ejecutor.submit(new intParaleloFutureCont(p/h)));
        }
        for (Future<Integer> iterator:contParciales) {
            try {
                sol += iterator.get();
            } catch(Exception e) {
                System.out.println("Error en Future");
            }
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();
        System.out.println("El resultado es: "+(double)sol/p);
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
