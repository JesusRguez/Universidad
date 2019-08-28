package monitorimpresion;

public class monitorImpresion{

    private int impresoras;
    private boolean[] libre;
    private int n;

    public monitorImpresion(){
        this.impresoras = 3;
        libre = new boolean[3];
        for (int i=0; i<3; ++i) {
            libre[i] = true;
        }
    }

    public synchronized int take_print(){
        while(impresoras == 0){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en take_print...");
            }
        }
        n = 0;
        while (!libre[n]) {
            n++;
        }
        libre[n] = false;
        impresoras--;
        return n;
    }

    public synchronized void drop_print(int imp){
        libre[imp] = true;
        impresoras++;
        notifyAll();
    }
}
