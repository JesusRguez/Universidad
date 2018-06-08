
public class Pasarela {

    public static void main(String[] args) throws InterruptedException {
        Peaton.pasarela = new Object();
        Peaton[] peatones = new Peaton[10];
        for (int i = 0; i < peatones.length; ++i) {
            peatones[i] = new Peaton();
        }
        for (int i = 0; i < peatones.length; ++i) {
            peatones[i].start();
        }
        for (int i = 0; i < peatones.length; ++i) {
            peatones[i].join();
        }
    }
}

class Peaton extends Thread {

    static Object pasarela;

    public void run() {
        System.out.println("Peatón " + getName() + " en la cola");
        synchronized (pasarela) {
            System.out.println("Peatón " + getName() + " en la pasarela");
            try {
                sleep(1000);
            } catch (Exception e) {
            }
            System.out.println("Peatón " + getName() + " sale de la pasarela");
        }
    }
}
