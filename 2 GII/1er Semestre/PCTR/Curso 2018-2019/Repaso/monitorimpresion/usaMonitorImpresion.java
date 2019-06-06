package monitorimpresion;

public class usaMonitorImpresion implements Runnable {
    public static monitorImpresion monitor;

    public usaMonitorImpresion(int h){
        monitor = new monitorImpresion(h);
    }

    public void run(){
        while (true) {
            int impresora = monitor.take_print();
            System.out.println("Imprimiendo desde la impresora "+impresora+" lanzada por el hilo "+Thread.currentThread().getName());
            try {
                Thread.sleep(100);
            } catch(Exception e) {
                System.out.println("Error en sleep...");
            }
            monitor.drop_print(impresora);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int h = (int) (Runtime.getRuntime().availableProcessors()/(1-0.5));
        Thread hilos[] = new Thread[h];
        for (int i=0; i<hilos.length; ++i) {
            hilos[i] = new Thread(new usaMonitorImpresion(h));
            hilos[i].start();
        }
        for (int i=0; i<hilos.length; ++i) {
            hilos[i].join();
        }
    }
}
