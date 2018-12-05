/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package lectorescritor;

public class usalectorEscritor implements Runnable{

    private static final lectorEscritor monitor = new lectorEscritor();
    public static RandomAccessFile fichero;
    public int tipoHilo;

    public usalectorEscritor(int tipoHilo){
        this.tipoHilo = tipoHilo;
    }

    public void run(){
        if (tipoHilo == 1) {
            while(true){
                try {

                } catch(Exception e) {

                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        try {
            fichero = new RandomAccessFile("datos", "rw");
        } catch(Exception e) {
            System.out.println("No se ha podido abrir el fichero");
        }
        usalectorEscritor personas[] = usalectorEscritor[10];
        for (int i=0; i<5; ++i) {
            personas[i] = new usalectorEscritor(1);
            personas[i].start();
        }
        for (int i=5; i<10; ++i) {
            personas[i] = new usalectorEscritor(2);
            personas[i].start();
        }
        for (int i=0; i<10; ++i) {
            personas[i].join();
        }
        fichero.close();
    }
}
