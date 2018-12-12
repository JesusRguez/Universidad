/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorcadena;

public class monitorCadena_1 {

    public int lectores = 0;
    public boolean escribiendo = false;
    public int max_elem = 100;
    public int n_elem = 0;

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
