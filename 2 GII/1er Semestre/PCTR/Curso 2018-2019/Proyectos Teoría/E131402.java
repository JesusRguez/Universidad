public class E131402 extends Thread{
public static Object[] locks;
public static Integer n= new Integer(0);
private int id;
public E131402(int id){
this.id=id;
}
public void run(){
synchronized(locks[id]){
n++;
if(id%2==0)
try{locks[id].wait();
}catch(InterruptedException e){}
System.out.println(n);
}
}
public static void main(String[] args){
locks = new Object[4];
for(int i=0; i<4; i++)
locks[i] = new Object();
for(int i=0; i<4; i++)
new E131402(i).start();
}
}
