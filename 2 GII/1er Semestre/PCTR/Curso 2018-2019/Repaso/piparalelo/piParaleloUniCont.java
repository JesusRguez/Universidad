import java.util.*;
import java.util.concurrent.*;
public class piParaleloUniCont implements Runnable{
    public static Integer aciertos=0;
    int intentos,cores;
    piParaleloUniCont(int intentos,int cores)
    {
        this.intentos=intentos;
        this.cores=cores;
    }
    public void run() {
        double x,y;
        for (int i=0;i<intentos/cores;++i ) {
            x=Math.random();
            y=Math.random();
            if((Math.pow(x,2)+Math.pow(y,2))<=1)
            {
                synchronized(aciertos){
                    aciertos++;
                }
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
        for (int i=0;i<cores;++i ) {
            hilos.execute(new piParaleloUniCont(intentos,cores));
        }
        hilos.shutdown();
        hilos.awaitTermination(1,TimeUnit.HOURS);
        fin=System.currentTimeMillis()-ini;
        double porcentaje=(double)aciertos/(double)intentos;
        double pi=4*porcentaje;
        System.out.println("El numero pi es "+pi);
        System.out.println("El tiempo es de "+fin+" ms");
    }
}
