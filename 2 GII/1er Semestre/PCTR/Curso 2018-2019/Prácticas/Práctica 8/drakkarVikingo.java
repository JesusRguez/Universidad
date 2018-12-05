/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

// Si hay anguilas, el cocinero se bloquea.
// Si no hay anguilas, los viquingos se bloquean.

public class drakkarVikingo implements Runnable {

    private static int marmita;
    private static int m = 10;
    public int tipoVikingo;

    public drakkarVikingo(int tipoVikingo){
        marmita = m;
        this.tipoVikingo = tipoVikingo;
    }

    public void run(){
        while (true){
            if (tipoVikingo == 0) {
                llenar_marmita();
            }else{
                comer();
            }
        }
    }

    public synchronized void comer(){
        while(marmita == 0){

            System.out.println("Marmita vacia");
            try{
                wait();
            }catch (InterruptedException e) {
                System.out.println("Fallo en comer...");
            }
        }
        --marmita;
        notifyAll();
        System.out.println("Anguilas en la marmita: "+marmita);
    }

    public synchronized void llenar_marmita(){
        while (marmita > 0) {
            try{
                wait();
            }catch (InterruptedException e) {
                System.out.println("Fallo en llenar_marmita...");
            }
        }
        marmita = m;
        System.out.println("Marmita rellenada");
        notifyAll();
    }

    public static void main(String[] args) throws InterruptedException {
        int h = Runtime.getRuntime().availableProcessors();
        Thread hilos[] = new Thread[h];
        hilos[0] = new Thread(new drakkarVikingo(0));
        for (int i=1; i<h; ++i) {
            hilos[i] = new Thread(new drakkarVikingo(1));
            hilos[i].start();
        }
        for (int i=0; i<h; ++i) {
            hilos[i].join();
        }
    }
}
