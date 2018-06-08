/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
Pool.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;

public class PoolThreads{

	public static int num = 0;
	
	private static void Sumador(){
		for(int i=0; i<1000; i++){
		   	Console.WriteLine("Me estoy ejecutando "+num+".");
		   	num++;
		}
    }

    private static void Restador(){
		for(int i=0; i<1000; i++){
		   	Console.WriteLine("Me estoy ejecutando "+num+".");
		   	num--;
		}
    }

    static public void Main (){
    	ThreadStart delegado = new ThreadStart(Sumador);
    	
    	int N = 100;
        Thread[] hilos = new Thread[N];

    	for(int i= 0 ; i<N; i++)
        	hilos[i] = new Thread(delegado);
        
    	for(int i= 0 ; i<N; i++)
        	hilos[i].Start();    

    	for(int i= 0 ; i<N; i++)
        	hilos[i].Join();

        for(int i= 0 ; i<N; i++)
            Task.Factory.StartNew(Restador);    
	
        Console.ReadLine();
    }
}