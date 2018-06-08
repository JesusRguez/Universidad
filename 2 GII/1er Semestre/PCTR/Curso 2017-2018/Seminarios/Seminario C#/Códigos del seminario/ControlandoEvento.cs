/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ControlandoEvento.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;
 
public class ControlandoEvento
{
	public static int num = 0;
	public static AutoResetEvent autoevento;

	private static void HiloEjecutandose(){
	   	Console.WriteLine("Me estoy ejecutando "+num+".");
        autoevento.WaitOne();
        num++;
	}

    static public void Main ()
    {
    	int N = 10000;
        autoevento = new AutoResetEvent(false);
        
    	for(int i= 0 ; i<N; i++){
            Task.Factory.StartNew(HiloEjecutandose);    
            autoevento.Set();
            Thread.Sleep(250);
        }

        Console.ReadLine();
    }
}