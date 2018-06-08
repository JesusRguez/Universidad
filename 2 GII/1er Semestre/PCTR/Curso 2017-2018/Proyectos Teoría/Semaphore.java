
import java.util.logging.Level;
import java.util.logging.Logger;

public class Semaphore {

    int contador, hilosBloqueados = 0;

    public Semaphore(int contador) {
        this.contador = contador;
    }

    public synchronized void Wait() throws InterruptedException { //Al ser synchronized, o se ejecuta el método por completo, o no se ejecuta.
        if (contador > 0) {
            --contador;
        } else {
            ++hilosBloqueados;
            this.wait();//Este es el wait de la clase object, que siempre va a bloquear al proceso que lo ejecuta e implica que se libere el cerrojo.
        }
    }

    public synchronized void Signal() { //Al ser un método sincronizado o se ejecuta por completo o no se ejecuta.
        if (hilosBloqueados > 0) {
            notify();
            --hilosBloqueados;
        } else {
            ++contador;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Semaphore mutex = new Semaphore(0);
        Hilo h1 = new Hilo(mutex);
        System.out.println("Lanzando hilos");
        h1.start();
        System.out.println("Esperando hilos");
        mutex.Signal();
        h1.join();
        System.out.println("Fin");
    }
}

class Hilo extends Thread {

    Semaphore mutex;

    public Hilo(Semaphore mutex) {
        this.mutex = mutex;
    }

    public void run() {
        System.out.println("Hilo " + getName() + " comienza.");
        try {
            mutex.Wait();
        } catch (InterruptedException ex) {
        }
        System.out.println("Hilo " + getName() + " finaliza.");
    }
}
