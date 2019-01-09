/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filoapian;

public class usaFiloApiAN implements Runnable {

    public static filoApiAN monitor = new filoApiAN();
    public int id;

    /**
     * Constructor de usafiloApiAN
     * @param id Identificador de hilo
     */
    public usaFiloApiAN(int id){
        this.id = id;
    }

    public void run(){
        while(true){
            monitor.take_forks(id);
            comer();
            monitor.release_forks(id);
            pensar();
        }
    }

    /**
     * Método comer
     */
    public void comer(){
        try {
            System.out.println("Filosofo "+Thread.currentThread().getId()+" comiendo");
            Thread.sleep(100);
        } catch(Exception e) {
            System.out.println("Error en comer...");
        }
    }

    /**
     * Método pensar
     */
    public void pensar(){
        try {
            System.out.println("Filosofo "+Thread.currentThread().getId()+" pensando");
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
