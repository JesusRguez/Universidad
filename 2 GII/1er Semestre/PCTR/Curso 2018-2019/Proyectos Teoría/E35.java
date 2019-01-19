public class E35{
    private static final int VMAX = 10;
    private static final int VMIN = 0;
    private static int valor = 0;

    public synchronized int incremento(){
        while(valor == VMAX){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en incremento...");
            }
        }
        notifyAll();
        return valor++;
    }

    public synchronized int decremento(){
        while(valor == VMIN){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en decremento...");
            }
        }
        notifyAll();
        return valor--;
    }
}
