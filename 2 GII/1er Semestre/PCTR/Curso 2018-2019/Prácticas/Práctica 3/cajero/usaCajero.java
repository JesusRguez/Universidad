/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package cajero;

public class usaCajero extends Cajero implements Runnable{

    public int tipoOperacion, id;
    public double cantidad;

    /**
     * Constructor de usaCajero
     * @param tipoOperacion Tipo de la operación a realizar: deposito/reintegro
     * @param id            Id del cliente al que se le va a realizar la operación
     * @param cantidad      Cantidad con la que se va a trabajar
     */
    public usaCajero(int tipoOperacion, int id, double cantidad){
        this.tipoOperacion = tipoOperacion;
        this.id = id;
        this. cantidad = cantidad;
    }

    /**
     * Método run
     */
    public void run(){
        switch(tipoOperacion){
            case 0:
                deposito(id, cantidad);
                break;
            case 1:
                reintegro(id, cantidad);
                break;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread h1 = new Thread(new usaCajero(0, 1, 100));
        Thread h2 = new Thread(new usaCajero(1, 2, 100));
        Thread h3 = new Thread(new usaCajero(1, 2, 1200));
        Thread h4 = new Thread(new usaCajero(0, 2, 500));

        h1.start();
        h2.start();
        h3.start();
        h4.start();

        h1.join();
        h2.join();
        h3.join();
        h4.join();
    }
}
