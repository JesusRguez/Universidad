/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

public class F100 extends combatStations{
    public static void main(String[] args) throws InterruptedException {
        Thread buques[] = new Thread[4];
        for (int i=0; i<4; ++i) {
            buques[i] = new Thread(new combatStations());
            buques[i].start();
        }
        for (int i=0; i<4; ++i) {
            buques[i].join();
        }
    }
}
