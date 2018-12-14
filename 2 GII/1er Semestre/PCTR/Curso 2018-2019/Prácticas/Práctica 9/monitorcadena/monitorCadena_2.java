/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorcadena;

public class monitorCadena_2 {

    private int lectores;
    private boolean escribiendo;
    private int max_elem;
    private int n_elem;

    public monitorCadena_2(){
        this.lectores = 0;
        this.escribiendo = false;
        this.max_elem = 50;
        this.n_elem = 0;
    }

    /**
     * Método para iniciar la lectura
     */
    public synchronized void inicioLectura(){
        while(escribiendo == true || n_elem == 0){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en inicioLectura...");
            }
        }
        ++lectores;
        ++n_elem;
        notifyAll();
    }

    /**
     * Método para finalizar la lectura
     */
    public synchronized void finLectura(){
        --lectores;
        while(lectores == 0){
            notifyAll();
        }
    }

    /**
     * Método para iniciar la escritura
     */
    public synchronized void inicioEscritura(){
        while((escribiendo == true || (lectores != 0)) || n_elem == max_elem){
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en inicioEscritura...");
            }
        }
        ++n_elem;
        escribiendo = false;
    }

    /**
     * Método para finalizar la escritura
     */
    public synchronized void finEscritura(){
        escribiendo = false;
        notifyAll();
    }
}
