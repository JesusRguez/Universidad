/**
 * @(#)Control.java
 *
 *
 * @author AT
 * @version 1.00 2011/11/10
 */

import java.io.*;
import java.util.*; 
public class Control extends Thread
{
//No declara constructor explicito. Usa el disponible por defecto
	
 public void run()
 {
	for(;;)
	  System.out.println("Trabajando");
 }
	
 public static void main(String[] args)
   throws IOException
 {
    int c;
    //usando el constructor implicito
    Control Hilo = new Control(); 
    Hilo.start();
//un poquito de entrelazado
   for(int i=1; i<=100; i++)
     System.out.println("Hola soy el padre");
   for(int i=1; i<=1000000; i++);
   //Ahora el hilo padre bloquea al hijo.
  Hilo.suspend(); //USO DE METODO DEROGADO
  System.out.println("Hijo suspendido");
  //Ahora reactivamos al hijo, que pasa a listo.  
  Hilo.resume(); //USO DE METODO DEROGADO
  //Ahora destruimos al hijo. Esto no debe hacerse NUNCA

  }	  	
}
