public class E131408 extends Thread
{
Integer I;
public E131408(Integer I) {this.I=I;}
public void run(){
System.out.println(this.getName());
synchronized(I){
try{I.wait();}catch (InterruptedException e){}
System.out.println(this.getName()+" diCE: Hola...");}
}
public void m1(){synchronized (I){I.notify();}}
public void m2(){synchronized (I){I.notifyAll();}}
public static void main(String[] args) throws InterruptedException{
Integer I = new Integer(0);
E131408 [] AliBaba = new E131408[10];
for(int i=0; i<10;i++){
    AliBaba[i]=new E131408(I); AliBaba[i].start();}
/*for (int i=0; i<10; ++i) {
    AliBaba[i].join();
}*/
AliBaba[5].m1();
Thread SpeedyGonzalez = currentThread();
SpeedyGonzalez.sleep(2000);
AliBaba[5].m2();
System.out.print("Todos terminaron...");
}
}
