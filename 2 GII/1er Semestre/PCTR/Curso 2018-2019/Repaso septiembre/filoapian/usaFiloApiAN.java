package filoapian;

public class usaFiloApiAN implements Runnable{

    public static filoApiAN monitor = new filoApiAN();
    public int id;

    public usaFiloApiAN(int id){
        this.id = id;
    }

    public void run(){
        while (true) {
            monitor.take_forks(id);
            comer();
            monitor.release_forks(id);
            pensar();
        }
    }

    public void comer(){
        try {
            System.out.println("Filosofo "+Thread.currentThread().getId()+" comiendo.");
            Thread.sleep(100);
        } catch(Exception e) {
            System.out.println("Error en comer...");
        }
    }

    public void pensar(){
        try {
            System.out.println("Filosofo "+Thread.currentThread().getId()+" pensando.");
            Thread.sleep(200);
        } catch(Exception e) {
            System.out.println("Error en pensar...");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[5];
        for (int i=0; i<5; ++i) {
            hilos[i] = new Thread(new usaFiloApiAN(i));
            hilos[i].start();
        }
        for (int i=0; i<5; ++i) {
            hilos[i].join();
        }
    }
}
