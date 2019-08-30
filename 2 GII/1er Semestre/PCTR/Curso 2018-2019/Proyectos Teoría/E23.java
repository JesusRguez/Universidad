import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.atomic.AtomicInteger;
public class E23 extends Thread {
static AtomicInteger x = new AtomicInteger(0);
static CyclicBarrier barrera = new CyclicBarrier(5);
public void run(){
System.out.print(x.incrementAndGet());
try{ barrera.await(); } catch(Exception ex){}
System.out.print("a");
}
public static void main(String[] args) throws Exception{
E23[] lista = new E23[5];
for(int i=0;i<lista.length;i++){
lista[i] = new E23();
lista[i].start();}
for(int i=0;i<lista.length;i++){
lista[i].join();}
}
}
