/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
Prioridad.cs
*/
using System;
using System.Threading;

class Prioridad{

    public static bool salto=true;
    public static long contador = 0;

    public void creador(){

        contador++;    
        Console.WriteLine("Hilo "+contador+" ejecutandose."); 
    }

     static public void Main (){

        Prioridad p = new Prioridad();

        ThreadStart del = new ThreadStart(p.creador);

        Thread hilo1 = new Thread(del);
        hilo1.Name ="Hilo 1";
        Thread hilo2 = new Thread(del);
        hilo2.Name ="Hilo 2";
        hilo2.Priority = ThreadPriority.BelowNormal;
        Thread hilo3 = new Thread(del);
        hilo3.Name ="Hilo 3";
        hilo3.Priority = ThreadPriority.AboveNormal;

        hilo1.Start();
        hilo2.Start();
        hilo3.Start();

        Thread.Sleep(10000);

        Console.ReadLine();
    }
}