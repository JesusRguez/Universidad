/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ControlandoMonitor.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;
 
public class ControlandoMonitor
{
	public static int num = 0;
	public static Object monitor = new Object();

	private static void HiloEjecutandose(){
		for(int i=0; i<10000; i++){
		   	Console.WriteLine("Me estoy ejecutando "+num+".");
		   	Monitor.Enter(monitor);
		   	try{
		   		num++;
		   	}
		   	finally{
		   		Monitor.Exit(monitor);
		   	}
		}
    }

    static public void Main ()
    {
    	ThreadStart delegado = new ThreadStart(HiloEjecutandose);
    	int N = 10;
        Thread[] hilos = new Thread[N];

    	for(int i= 0 ; i<N; i++)
        	hilos[i] = new Thread(delegado);
        
    	for(int i= 0 ; i<N; i++)
        	hilos[i].Start();

    	for(int i= 0 ; i<N; i++)
        	hilos[i].Join();

        Console.ReadLine();
    }
}