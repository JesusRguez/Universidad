package oficina;

public class Oficina{
    private int mesas;
    private boolean[] libre;
    private boolean[] limpia;
    private int n;

    /**
     * Constructor de Oficina
     */
    public Oficina(){
        this.mesas = 10;
        libre = new boolean[10];
        limpia = new boolean[10];
        for (int i=0; i<10; ++i) {
            libre[i] = true;
            limpia[i] = true;
        }
    }

    /**
     * Método cogerMesa
     * @return Devuelve la mesa en la que está trabajando un empleado
     */
    public synchronized int cogerMesa(){
        while(mesas == 0){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en take_print...");
            }
        }
        n = 0;
        while (!libre[n] && limpia[n]) {
            n++;
        }
        libre[n] = false;
        limpia[n] = false;
        mesas--;
        return n;
    }

    /**
     * Método soltarMesa
     * @param m Mesa que deja libre el empleado
     */
    public synchronized void soltarMesa(int m){
        libre[m] = true;
        if (limpia[m] = true) {
            mesas++;
        }
        notifyAll();
    }

    /**
     * Método limpiarMesa
     * @return Devuelve la mesa que limpia un Limpiador
     */
    public synchronized int limpiarMesa(){
        n = 0;
        while (n < 10 && limpia[n]) {
            n++;
        }
        if (n < 10) {
            limpia[n] = true;
        }
        return n;
    }
}
