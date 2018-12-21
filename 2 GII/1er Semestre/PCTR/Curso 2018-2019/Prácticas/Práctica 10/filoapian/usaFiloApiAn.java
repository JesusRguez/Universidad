/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filoapian;

public class usafiloApiAN implements Runnable {

    public static filoApiAN monitor = new filoApiAN();
    public int id;

    public usafiloApiAN(int id){
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

    public static void main(String[] args) throws InterruptedException {
        Thread hilos[] = new Thread[5];
        for (int i=0; i<5; ++i) {
            hilos[i] = new Thread(new usafiloApiAN(i));
            hilos[i].start();
        }
        for (int i=0; i<5; ++i) {
            hilos[i].join();
        }
    }
}
