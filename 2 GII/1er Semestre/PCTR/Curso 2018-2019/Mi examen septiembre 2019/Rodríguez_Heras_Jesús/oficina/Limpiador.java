package oficina;

public class Limpiador implements Runnable {

    public static Oficina monitor;

    /**
     * Constructor de Limpiador
     * @param monitor Monitor de la clase
     */
    public Limpiador(Oficina monitor){
        this.monitor = monitor;
    }

    public void run(){
        int mesa;
        while (true) {
            mesa = monitor.limpiarMesa();
            System.out.println("Limpiador "+Thread.currentThread().getName()+" limpiando");
            try {
                Thread.sleep(100);
            } catch(Exception e) {

            }
        }
    }
}
