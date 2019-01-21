import java.util.*;
import java.util.concurrent.*;
import java.math.BigInteger;
import java.util.concurrent.locks.ReentrantLock;

public class facEGrandesParalelo implements Runnable{

    public static BigInteger f = new BigInteger("1");
    public int rango;
    public int id;
    public static ReentrantLock l = new ReentrantLock();

    public facEGrandesParalelo(int id, int r){
        this.id = id;
        this.rango = r;
    }

    public void run(){
        BigInteger s = new BigInteger("1");
        for (int i=1+id*rango; i<id*rango+rango+1; ++i) {
            Integer I = new Integer(i);
            s = s.multiply(new BigInteger(I.toString()));
        }
        l.lock();
        f = f.multiply(s);
        l.unlock();
    }

    public static void main(String[] args) throws InterruptedException{
        Scanner teclado = new Scanner(System.in);
        System.out.print("Introduzca el número al que desea calcular el factorial: ");
        int n = teclado.nextInt();
        Integer a = new Integer(n);
        BigInteger m = new BigInteger(a.toString());
        int h = Runtime.getRuntime().availableProcessors();
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        long time_start, time_end;
        time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            ejecutor.execute(new facEGrandesParalelo(i, n/h));
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        time_end = System.currentTimeMillis();
        System.out.println("El valor es "+f);
        System.out.println("Ha tardado "+(time_end-time_start)/(double)1000+" segundos");
    }
}
