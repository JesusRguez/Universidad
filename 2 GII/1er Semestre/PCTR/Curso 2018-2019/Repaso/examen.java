import java.util.concurrent.locks.*;
public class examen implements Runnable
{
public static Integer p = new Integer(0);
public static ReentrantLock r = new ReentrantLock();
public int vMax;
public examen(int v) {vMax = v;}
public void run()
{
Object q=p;
for(int cont=0;cont<vMax; cont++)
{ r.lock(); p++; r.unlock();
/*synchronized(q){try{q.wait();} //quitando esto sale 1001 y si lo dejamos, 11 por el wait()
catch(InterruptedException e){}}*/}
}
public static void main(String[] args)
throws InterruptedException
{
Thread [] h = new Thread[10];
for(int i=0;i<h.length;i++)h[i]=new Thread(new examen(100));
for(int i=0;i<h.length;i++)h[i].start();
Thread j = Thread.currentThread();
j.sleep(1000);
p++;
System.out.print(p);
}
}
