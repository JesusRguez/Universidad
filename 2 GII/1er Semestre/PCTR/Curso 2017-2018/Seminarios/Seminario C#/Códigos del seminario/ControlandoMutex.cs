/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ControlandoMutex.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;
 
public class ControlandoMutex
{
	public static int num = 0;
	public static Mutex mut = new Mutex();

	private static void HiloEjecutandose(){
	   	mut.WaitOne();
        Console.WriteLine("Me estoy ejecutando "+num+".");
        num++;
        mut.ReleaseMutex();
	}

    static public void Main ()
    {
    	int N = 10000;
        
    	for(int i= 0 ; i<N; i++)
            Task.Factory.StartNew(HiloEjecutandose);    

        Console.ReadLine();
    }
}