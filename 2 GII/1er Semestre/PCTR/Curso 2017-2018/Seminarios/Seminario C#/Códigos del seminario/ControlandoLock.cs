/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ControlandoLock.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;
 
public class ControlandoLock
{
	public static int num = 0;
	public static Object Locker = new Object();

	private static void HiloEjecutandose(){
		for(int i=0; i<10000; i++){
		   	Console.WriteLine("Me estoy ejecutando "+num+".");
		   	lock (Locker){
                num++;
            }
		}
    }

    static public void Main ()
    {
    	//ThreadStart delegado = new ThreadStart(HiloEjecutandose);
    	int N = 10;
        //Thread[] hilos = new Thread[N];

    	//for(int i= 0 ; i<N; i++)
        	//hilos[i] = new Thread(delegado);
        
    	for(int i= 0 ; i<N; i++)
        	//hilos[i].Start();
            Task.Factory.StartNew(HiloEjecutandose);    

    	//for(int i= 0 ; i<N; i++)
        	//hilos[i].Join();

        Console.ReadLine();
    }
}