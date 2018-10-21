/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package hilo;

public class Hilo extends Thread{
    public static int n = 0, nVueltas;
    public boolean tipoHilo;

    /**
     * Constructor de la clase Hilo
     * @param tipoHilo Designa el tipo de hilo: sumador(true)/restador(false)
     * @param nVueltas Número de veces que se sumara/restará la variable n de la clase Hilo
     */
    public Hilo(boolean tipoHilo, int nVueltas){
        this.tipoHilo = tipoHilo;
        this.nVueltas = nVueltas;
    }

    public void run(){
        if(tipoHilo == true){
            for (int i=0; i<nVueltas; ++i) {
                n++;
            }
        }else{
            for (int i=0 ;i<nVueltas ; ++i) {
                n--;
            }
        }
    }
}
