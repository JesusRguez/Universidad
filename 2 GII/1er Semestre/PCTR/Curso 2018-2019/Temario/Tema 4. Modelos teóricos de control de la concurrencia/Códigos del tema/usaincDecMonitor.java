/**
 * @(#)usaincDecMonitor.java
 * @author A.T.
 * @version 1.00 2014/11/19
 * Diseño de hilos sobre un monitor de clase incDescMonitor
 */

public class usaincDecMonitor implements Runnable{
  public static incDecMonitor monitor = new incDecMonitor();
  public int    tipoHilo;
  public usaincDecMonitor(int tipoHilo)
  {this.tipoHilo = tipoHilo;}
  
  public void run(){
    switch(tipoHilo){
      case 0: for(int i=0; i<1000000; i++) monitor.inc(); break;
      case 1: for(int i=0; i<1000000; i++) monitor.dec(); break;
    }  	      
  }
  public static void main(String[] args){
    Thread p = new Thread(new usaincDecMonitor(0));
    Thread q = new Thread(new usaincDecMonitor(1));
    p.start(); q.start();
    try{
      p.join(); q.join();
    }catch(InterruptedException e){}
    System.out.println(monitor.ver());
  }
}
