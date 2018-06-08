/* Códigos de seminario de C# 
Ángel Luis Bayón Romero
Alumno colaborador de PCTR
ControlandoReaderWriterLock.cs
*/
using System;
using System.Threading;
using System.Threading.Tasks;
 
public class ControlandoReaderWriterLock{

	public static int num = 0;
    static Random rnd = new Random();
    static ReaderWriterLock rwl = new ReaderWriterLock();
    static int readerTimeouts = 0;
    static int writerTimeouts = 0;
    static int reads = 0;
    static int writes = 0;

   static void ReadFromResource(int timeOut){
        try{
            rwl.AcquireReaderLock(timeOut);
            try{
                Console.WriteLine("Leyendo dato " + num);
                Interlocked.Increment(ref reads);
            }
            finally{
                rwl.ReleaseReaderLock();
            }
        }
        catch (ApplicationException){
            Interlocked.Increment(ref readerTimeouts);
        }
    }

    static void WriteToResource(int timeOut){
        try{
            rwl.AcquireWriterLock(timeOut);
            try{
                num = rnd.Next(500);
                Console.WriteLine("Escribiendo dato " + num);
                Interlocked.Increment(ref writes);
            }
            finally{
                rwl.ReleaseWriterLock();
            }
        }
        catch(ApplicationException){
            Interlocked.Increment(ref writerTimeouts);
        }
    }

    static void UpgradeDowngrade(int timeOut){
        try{
            rwl.AcquireReaderLock(timeOut);
            try{
                Console.WriteLine("Leyendo dato" + num);
                Interlocked.Increment(ref reads);
                try {
                    LockCookie lc = rwl.UpgradeToWriterLock(timeOut);
                    try{
                        num = rnd.Next(500);
                        Console.WriteLine("Escribiendo dato " + num);
                        Interlocked.Increment(ref writes);
                    }
                    finally{
                        rwl.DowngradeFromWriterLock(ref lc);
                    }
                }
                catch (ApplicationException) {
                Interlocked.Increment(ref writerTimeouts);
                }
            Console.WriteLine("Leyendo dato " + num);
            Interlocked.Increment(ref reads);
            }
            finally {
            rwl.ReleaseReaderLock();
            }
        }
        catch (ApplicationException) {
            Interlocked.Increment(ref readerTimeouts);
        }
    }

    static void ReleaseRestore(int timeOut){
        int lastWriter;

        try{
            rwl.AcquireReaderLock(timeOut);
            try{
            int resourceValue = num;
            Console.WriteLine("Leyendo dato" + resourceValue);
            Interlocked.Increment(ref reads);

            lastWriter = rwl.WriterSeqNum;

            LockCookie lc = rwl.ReleaseLock();

            Thread.Sleep(rnd.Next(250));
            rwl.RestoreLock(ref lc);

            if (rwl.AnyWritersSince(lastWriter)) {
               resourceValue = num;
               Interlocked.Increment(ref reads);
               Console.WriteLine("dato cambiado" + resourceValue);
            }
            else
               Console.WriteLine("dato no cambiado" + resourceValue);
            
            }
            finally{
                rwl.ReleaseReaderLock();
            }
        }
        catch (ApplicationException){
            Interlocked.Increment(ref readerTimeouts);
        }
    }

    static void HiloEjecutandose(){
       	while (true){
         double action = rnd.NextDouble();
         if (action < .8)
            ReadFromResource(10);
         else if (action < .81)
                ReleaseRestore(50);
                else if (action < .90)
                        UpgradeDowngrade(100);
                    else
                        WriteToResource(100);
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