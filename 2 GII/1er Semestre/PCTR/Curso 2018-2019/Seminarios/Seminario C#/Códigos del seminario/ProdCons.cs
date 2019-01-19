/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ProdCons.cs
*/
using System;
using System.Runtime.CompilerServices;
using System.Threading;
 
class Buffer {
	public const int tam = 3;
	int[] buffer = new int[tam];
	int Inipos = 0;
	int Finpos = 0;
	int elementos = 0;

	public void Produce(int valor) {
		lock(this){
			if(elementos == tam){
				Console.WriteLine("Buffer lleno.");
				Monitor.Wait(this);
			}

			elementos++;
			buffer[Inipos] = valor;
			Console.WriteLine("Produciendo "+valor+".");
			Inipos = (Inipos+1) % tam;
			if (elementos == 1) 
				Monitor.Pulse(this);
		}
	}
    
	public int Consume() {
		lock(this){
			if(elementos == 0){
				Console.WriteLine("Buffer vacío.");
				Monitor.Wait(this);
			}

			elementos--;
			int res = buffer[Finpos];
			Console.WriteLine("Consumiendo "+res+".");
			Finpos = (Finpos+1) % tam;
			if (elementos == tam - 1) 
				Monitor.Pulse(this);
			return res;
		}
	}
}

class Productor {
	Buffer buff;
	int n = 0;

	public Productor(Buffer b) {
		buff = b;
		Thread hilo = new Thread(new ThreadStart(Run));
		hilo.Start();
	}

	public void Run() {
		for (;;) {
			buff.Produce(n++);
			Thread.Sleep(1000);
		}
	}
}

class Consumidor {
	Buffer buff;

	public Consumidor(Buffer b) {
		buff = b;
		Thread hilo = new Thread(new ThreadStart(Run));
		hilo.Start();
	}

	public void Run() {
		for (;;) {
			buff.Consume();
			Thread.Sleep(1000);
		}
	}
}

public class ProdCons {
   	static public void Main (){
    	Buffer b = new Buffer();
    	Productor p = new Productor(b);
    	Consumidor c = new Consumidor(b);
    }
}