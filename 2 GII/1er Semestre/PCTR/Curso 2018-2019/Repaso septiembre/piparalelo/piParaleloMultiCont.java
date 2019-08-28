import java.util.*;
import java.util.concurrent.*;
public class piParaleloMultiCont implements Runnable{

    public static int aciertos[];
    public int intentos;
    public int idHilo;

    piParaleloMultiCont(int idHilo, int hilos, int intentos) {
        this.idHilo = idHilo;
        aciertos = new int[hilos];
        this.intentos = intentos;
    }

    public void run() {
        double x,y;
        for (int i=0; i<intentos; ++i) {
            x = Math.random();
            y = Math.random();
            if((Math.pow(x,2)+Math.pow(y,2))<=1) {
                aciertos[idHilo]++;
            }
        }
    }

    public static void main(String[] args)throws Exception {
        long ini,fin;
        int intentos=0;
        Scanner s = new Scanner(System.in);
        System.out.println("Introduzca numero de intentos");
        intentos=s.nextInt();
        int cores=Runtime.getRuntime().availableProcessors();
        ExecutorService hilos= Executors.newFixedThreadPool(cores);
        ini=System.currentTimeMillis();
        for (int i=0; i<cores; ++i) {
            hilos.execute(new piParaleloMultiCont(i, cores, intentos/cores));
        }
        hilos.shutdown();
        hilos.awaitTermination(1,TimeUnit.HOURS);
        fin=System.currentTimeMillis()-ini;
        int totales = 0;
        for (int i=0; i<cores; ++i) {
            totales += aciertos[i];
        }
        double porcentaje=(double)totales/(double)intentos;
        double pi=4*porcentaje;
        System.out.println("El numero pi es "+pi);
        System.out.println("El tiempo es de "+fin+" ms");
    }
}
