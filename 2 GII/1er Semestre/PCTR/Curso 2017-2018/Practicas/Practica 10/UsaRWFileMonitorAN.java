
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class UsaRWFileMonitorAN {

    private static RWMonitorANnuevo monitor = new RWMonitorANnuevo();

    static class Reader extends Thread {

        private int hilo;

        /**
         * @param hilo
         */
        public Reader(int hilo) {
            this.hilo = hilo;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    monitor.StartRead(hilo);
                    sleep(200);
                    monitor.EndRead(hilo);
                    sleep(200);
                } catch (Exception e) {
                }
            }
        }
    }

    static class Writer extends Thread {

        private int hilo;

        /**
         * @param hilo
         */
        public Writer(int hilo) {
            this.hilo = hilo;
        }

        @Override
        public void run() {
            int value;
            while (true) {
                try {
                    value = (int) (Math.random() * 9);
                    monitor.StartWrite(hilo, value);
                    sleep(300);
                    monitor.EndWrite(hilo);
                    sleep(50);
                } catch (Exception e) {
                }
            }
        }
    }

    public static void main(String[] args) {
        Reader[] lectores = new Reader[5];
        Writer[] escritores = new Writer[2];
        for (int i = 0; i < 5; i++) {
            lectores[i] = new Reader(i);
            lectores[i].start();
        }
        for (int i = 0; i < 2; i++) {
            escritores[i] = new Writer(i);
            escritores[i].start();
        }
    }
}
