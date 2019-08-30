public class E30 extends Thread{
private static Integer i = new Integer(1);
private static int j=0;
private E30 h;
public E30(){j++;}
public void run(){
if(j<500)
{h=new E30();
synchronized(i){i++;}
h.start();
try{h.join();}catch (InterruptedException e){}
}
}
public static void main(String[] args) throws Exception{
E30 h = new E30();
h.start();
h.join();
System.out.println(i.toString());
}
}
