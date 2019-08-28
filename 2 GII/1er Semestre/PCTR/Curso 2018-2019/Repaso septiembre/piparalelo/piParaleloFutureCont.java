import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.Callable;
public class piParaleloFutureCont implements Callable<Integer>{

    public int intentos;

    piParaleloFutureCont(int intentos) {
        this.intentos = intentos;
    }

    public Integer call() {
        double x,y;
        int res = 0;
        for (int i=0; i<intentos; ++i) {
            x = Math.random();
            y = Math.random();
            if((Math.pow(x,2)+Math.pow(y,2))<=1) {
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args)throws Exception {
        long ini,fin;
        int intentos=0;
        Scanner s = new Scanner(System.in);
        System.out.println("Introduzca numero de intentos");
        intentos=s.nextInt();
        int cores=Runtime.getRuntime().availableProcessors();
        ExecutorService hilos= Executors.newFixedThreadPool(cores);
        int sol = 0;
        ArrayList<Future<Integer>> parciales = new ArrayList<Future<Integer>>();
        ini=System.currentTimeMillis();
        for (int i=0; i<cores; ++i) {
            parciales.add(hilos.submit(new piParaleloFutureCont(intentos/cores)));
        }
        hilos.shutdown();
        hilos.awaitTermination(1,TimeUnit.HOURS);
        fin=System.currentTimeMillis()-ini;
        int totales = 0;
        for (Future<Integer> iterator:parciales) {
            try {
                totales+=iterator.get();
            } catch(Exception e) {
                System.out.println("Error en future...");
            }
        }
        double porcentaje=(double)totales/(double)intentos;
        double pi=4*porcentaje;
        System.out.println("El numero pi es "+pi);
        System.out.println("El tiempo es de "+fin+" ms");
    }
}
