public class E34 extends Thread{
private String s;
private static Object o = new Object();
public E34(String s){this.s = s;}
public void run(){
synchronized(o){
switch(this.s){
case "ping":for(int i=0; i<10; i++){
System.out.print(this.s+" ");
o.notify();
try{o.wait();}catch(InterruptedException e){}
}
case "pong":for(int i=0; i<5; i++){
try{o.wait();}catch(InterruptedException e){}
System.out.print(this.s+" ");
o.notify();
}
}
}
}
public static void main(String[] args)throws InterruptedException{
    E34 Lendl = new E34("pong");
E34 McEnroe = new E34("ping");
Lendl.start();
McEnroe.start();
Lendl.join();
McEnroe.join();
}
}
