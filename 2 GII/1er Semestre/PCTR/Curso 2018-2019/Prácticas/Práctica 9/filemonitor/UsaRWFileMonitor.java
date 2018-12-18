/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package filemonitor;

public class UsaRWFileMonitor {

    private static RWFileMonitor monitor = new RWFileMonitor();

    static class Lector extends Thread{

        private int hilo;

        /**
         * Constructor de la clase Lector
         * @param hilo Identificador de hilo lector
         */
        public Lector(int hilo){
            this.hilo = hilo;
        }

        public void run(){
            while(true){
                try {
                    monitor.inicioLectura(hilo);
                    sleep(200);
                    monitor.finLectura(hilo);
                    sleep(200);
                } catch(Exception e) {
                    System.out.println("Error en run de Lector...");
                }
            }
        }
    }

    static class Escritor extends Thread{

        private int hilo;

        /**
         * Constructor de la clase Escritor
         * @param hilo Identificador de hilo escritor
         */
        public Escritor(int hilo){
            this.hilo = hilo;
        }

        public void run(){
            int valor;
            while(true){
                try {
                    valor = (int) (Math.random()*10);
                    monitor.inicioEscritura(hilo, valor);
                    sleep(300);
                    monitor.finEscritura(hilo);
                    sleep(50);
                } catch(Exception e) {
                    System.out.println("Error en run de Escritor...");
                }
            }
        }
    }

    public static void main(String[] args){
        Lector[] lectores = new Lector[5];
        Escritor[] escritores = new Escritor[2];
        for (int i=0; i<2; ++i) {
            escritores[i] = new Escritor(i);
            escritores[i].start();
        }
        for (int i=0; i<5; ++i) {
            lectores[i] = new Lector(i);
            lectores[i].start();
        }
    }
}
