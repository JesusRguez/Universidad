import java.util.concurrent.locks.*;
import java.util.concurrent.*;
public class E33 implements Runnable{
public static Integer val = new Integer(0);
public int s;
public static ReentrantLock lock = new ReentrantLock();
public E33(int s) {this.s = s;}
public void run(){
Object val2=val;
for(int i=0;i<s; i++){
lock.lock();
val++;
lock.unlock();
synchronized(val2){
try{val2.wait();
}catch(InterruptedException e){}
}
}
}
public static void main(String[] args)throws InterruptedException{
E33 [] h = new E33[10];
for(int i=0;i<h.length;i++)h[i]=new E33(100);
int nP = Runtime.getRuntime().availableProcessors();
ThreadPoolExecutor ept = new ThreadPoolExecutor(
nP*4, nP*4,
1000L,
TimeUnit.MILLISECONDS,
new LinkedBlockingQueue<Runnable>());
ept.prestartAllCoreThreads();
for(int i=0; i<h.length; i++) ept.execute(h[i]);
ept.shutdown();
do{} while(!ept.isTerminated());
val++;
System.out.print(val);
}
}
