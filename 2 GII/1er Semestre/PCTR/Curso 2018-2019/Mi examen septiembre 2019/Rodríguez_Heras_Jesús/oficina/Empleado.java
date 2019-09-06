package oficina;

public class Empleado implements Runnable{

    public static Oficina monitor;

    /**
     * Constructor de Empleado
     * @param monitor Monitor de la clase
     */
    public Empleado(Oficina monitor){
        this.monitor = monitor;
    }

    public void run(){
        int mesa;
        while (true) {
            mesa = monitor.cogerMesa();
            System.out.println("Empleado "+Thread.currentThread().getName()+" trabajando");
            try {
                Thread.sleep(100);
            } catch(Exception e) {

            }
            monitor.soltarMesa(mesa);
        }
    }
}
