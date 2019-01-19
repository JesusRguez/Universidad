/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
Pi.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;

class PiMonteCarlo{
	public static int SumaTotal = 0;
	public static Object Locker = new Object();
	public static int contador;

	private static void coRutina(){
		
		Random r = new Random();
		int parcial = 0;

		for(int i=0; i<contador; i++){
			double x = r.NextDouble();
			double y = r.NextDouble();
			if(x*x + y*y <=1)
				parcial++;
		}

		lock(Locker){
			SumaTotal+=parcial;
		}
	}
	
	static public void Main(){
		double Lanzamientos  = int.Parse(args[0]);
		int nTareas = Environment.ProcessorCount;
		contador = (int) Lanzamientos/nTareas;
		
		DateTime tiempoPoolInicio = DateTime.Now;

        Task[] tareas = new Task[(int)nTareas];

        for(int i= 0 ; i<nTareas; i++)
            tareas[i] = Task.Factory.StartNew(coRutina);    
	
        Task.WaitAll(tareas);
       
		DateTime tiempoPoolFinal = DateTime.Now;
		    
		Console.WriteLine("Resultado:" + (4*SumaTotal)/Lanzamientos + "\nRealizado en " + (tiempoPoolFinal - tiempoPoolInicio) + " segundos.");
        Console.ReadLine();
	}
}