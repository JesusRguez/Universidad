using System;
using System.Threading;
 
public class PrimerHilo
{
	private static void HiloEjecutandose(){
    	Console.WriteLine("Me estoy ejecutando.");
    }

    static public void Main ()
    {
        Thread hilo = new Thread(HiloEjecutandose);
        hilo.Start();

        Console.ReadLine();
    }
}