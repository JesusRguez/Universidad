/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
Prueba3.cs
*/
using System;
using System.Threading;
 
public class TercerHilo
{
	public static int num = 0;

	private static void HiloSumador(){
		for(int i=0; i<100; i++){
		   	Console.WriteLine("Me estoy ejecutando "+num+".");
		   	num++;
		}
    }

    private static void HiloRestador(){
        for(int i=0; i<100; i++){
            Console.WriteLine("Me estoy ejecutando "+num+".");
            num--;
        }
    }

    static public void Main ()
    {
    	ThreadStart delegado = new ThreadStart(HiloSumador);
        ThreadStart delegado2 = new ThreadStart(HiloRestador);

    	int N = 1000;
        Thread[] hilosSumadores = new Thread[N];
        Thread[] hilosRestadores = new Thread[N];

    	for(int i= 0 ; i<N; i++){
            hilosSumadores[i] = new Thread(delegado);
            hilosRestadores[i] = new Thread(delegado2);
        }

    	for(int i= 0 ; i<N; i++){
            hilosSumadores[i].Start();
            hilosRestadores[i].Start();
        }

    	for(int i= 0 ; i<N; i++){
            hilosSumadores[i].Join();
            hilosRestadores[i].Join();     
        }

        Console.ReadLine();
    }
}