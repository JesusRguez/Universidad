public class pruebaMonitor implements Runnable {
    public static monitorSem sem;
    public int id;
    public static int n = 0;

    public pruebaMonitor(int id){
        this.id = id;
    }

    public void run(){
        sem.waitSem();
        for (int i=0; i<100; ++i){
            if (id%2 == 0) {
                n++;
                //System.out.println(n);
            }else{
                n--;
                //System.out.println(n);
            }
        }
        sem.signalSem();
    }

    public static void main(String[] args) throws InterruptedException {
        sem = new monitorSem(0);
        Thread hilos[] = new Thread[2];
        for (int i=0; i<2; ++i) {
            hilos[i] = new Thread(new pruebaMonitor(i));
            hilos[i].start();
        }
        for (int i=0; i<2; ++i) {
            hilos[i].join();
        }
        System.out.println("El valor final de n es: "+n);
    }
}
