package monitorimpresion;

public class monitorImpresion{
    int n, impresoras;
    boolean libre[];

    public monitorImpresion(int h){
        libre = new boolean[h];
        for (int i=0; i<h; ++i) {
            libre[i] = true;
        }
        impresoras = h;
    }

    public synchronized int take_print(){
        while(impresoras == 0){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Fallo en take_print...");
            }
        }

        n = 1;
        while (!libre[n]) {
            n++;
        }
        libre[n] = false;
        impresoras--;
        return n;
    }

    public synchronized void drop_print(int n){
        libre[n] = true;
        impresoras++;
        notifyAll();
    }
}
