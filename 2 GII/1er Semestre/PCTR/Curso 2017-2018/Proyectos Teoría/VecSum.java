
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.logging.Level;
import java.util.logging.Logger;

public class VecSum extends Thread {

    static int[] buffer = new int[100];
    int inicio, fin;
    int suma = 0;
    static CyclicBarrier barrera = new CyclicBarrier(2);

    public VecSum(int inicio, int fin) {
        this.inicio = inicio;
        this.fin = fin;
    }

    public void run() {
        for (int i = inicio; i < fin; i++) {
            buffer[i] = buffer[i] * buffer[i];
        }
        try {
            barrera.await();
        } catch (InterruptedException | BrokenBarrierException ex) {
            Logger.getLogger(VecSum.class.getName()).log(Level.SEVERE, null, ex);
        }
        for (int i = inicio; i < fin; i++) {
            suma = suma + buffer[i];
        }
    }

    public static void main(String[] args) throws InterruptedException {
        for (int i = 0; i < buffer.length; i++) {
            buffer[i] = 1;
        }
        VecSum h1 = new VecSum(0, 50);
        VecSum h2 = new VecSum(50, 100);
        h1.start();
        h2.start();
        h1.join();
        h2.join();
        int suma = h1.suma + h2.suma;
        System.out.println(suma);
    }
}
