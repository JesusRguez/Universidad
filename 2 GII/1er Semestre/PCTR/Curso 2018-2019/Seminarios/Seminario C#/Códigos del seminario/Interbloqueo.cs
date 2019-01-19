/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
Interbloqueo.cs
*/
using System;
using System.Threading;

public class Deadlock{

	static object Obj1 = new object();
	static object Obj2 = new object();

	public static void Operacion1(){
		lock(Obj1){
			Thread.Sleep(1000);
			lock(Obj2){
				Console.WriteLine("Operacion 1 ejecutandose.");
			}
		}
	}

	public static void Operacion2(){
		lock(Obj2){
			Thread.Sleep(1000);
			lock(Obj1){
				Console.WriteLine("Operacion 2 ejecutandose.");
			}
		}
	}

	static public void Main(){
		Thread Hilo1 = new Thread((ThreadStart)Operacion1);
		Thread Hilo2 = new Thread((ThreadStart)Operacion2);

		Hilo1.Start();
		Hilo2.Start();
	}
}