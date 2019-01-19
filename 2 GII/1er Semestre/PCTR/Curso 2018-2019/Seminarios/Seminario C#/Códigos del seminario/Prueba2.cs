/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
Prueba2.cs
*/
using System;
using System.Threading;
 
public class SegundoHilo
{
	public static int num = 0;

	SegundoHilo(){}

	private static void HiloEjecutandose(){
		for(int i=0; i<100; i++){
		   	Console.WriteLine("Me estoy ejecutando "+num+".");
		   	num++;
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