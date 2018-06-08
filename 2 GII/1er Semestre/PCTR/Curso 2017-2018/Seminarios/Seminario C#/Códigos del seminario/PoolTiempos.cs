/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
PoolTiempos.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;

public class PoolThreads{

	public static int num = 0;
	
	private static void Sumador(){
		for(int i=0; i<1000; i++){
		   	//Console.WriteLine("Me estoy ejecutando "+num+".");
		   	num++;
		}
    }

    private static void Restador(){
		for(int i=0; i<1000; i++){
		   	//Console.WriteLine("Me estoy ejecutando "+num+".");
		   	num--;
		}
    }

    static public void Main (String[] args){
    	ThreadStart delegado = new ThreadStart(Sumador);
    	
    	int N = int.Parse(args[0]);
        Thread[] hilos = new Thread[N];

        DateTime tiempoHilosInicio = DateTime.Now;

    	for(int i= 0 ; i<N; i++)
        	hilos[i] = new Thread(delegado);
        
    	for(int i= 0 ; i<N; i++)
        	hilos[i].Start();    

    	for(int i= 0 ; i<N; i++)
        	hilos[i].Join();

        DateTime tiempoHilosFinal = DateTime.Now;

        DateTime tiempoPoolInicio = DateTime.Now;

        Task[] tareas = new Task[N];

        for(int i= 0 ; i<N; i++)
            tareas[i] = Task.Factory.StartNew(Restador);    
	
        Task.WaitAll(tareas);
       
		DateTime tiempoPoolFinal = DateTime.Now;
        
		TimeSpan totalHilos = new TimeSpan(tiempoHilosFinal.Ticks - tiempoHilosInicio.Ticks);

		Console.WriteLine("Tiempo total en hilos:"+totalHilos.ToString());

		TimeSpan totalPool = new TimeSpan(tiempoPoolFinal.Ticks - tiempoPoolInicio.Ticks);

		Console.WriteLine("Tiempo total en el Pool:"+totalPool.ToString());
		
        Console.ReadLine();
    }
}