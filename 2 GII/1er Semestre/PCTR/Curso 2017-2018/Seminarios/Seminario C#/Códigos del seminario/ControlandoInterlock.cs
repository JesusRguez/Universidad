/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ControlandoInterlock.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;
 
public class ControlandoInterlocked
{
	public static int num = 0;

    static void control(){
        if(Interlocked.Exchange(ref num, 1)==0){
            Console.WriteLine("Tomando control.");
            Thread.Sleep(500);
            Console.WriteLine("Liberando control.");
            Interlocked.Exchange(ref num, 0);
        }
        else
            Console.WriteLine("Sin acceso a num.");
    }

	private static void HiloEjecutandose(){
       	for(int i=0; i<10; i++){
            control();
            Thread.Sleep(1000);
        }
	}

    static public void Main ()
    {
    	int N = 10000;
        
    	for(int i= 0 ; i<N; i++){
            Thread.Sleep(250);
            Task.Factory.StartNew(HiloEjecutandose);
        }    

        Console.ReadLine();
    }
}