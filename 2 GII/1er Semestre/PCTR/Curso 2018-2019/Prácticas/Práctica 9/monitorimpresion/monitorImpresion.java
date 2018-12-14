/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorimpresion;

public class monitorImpresion{

    private int n, impresoras;
    private boolean libre[];

    /**
     * Constructor del monitorImpresion
     * @param n Número de impresoras en el sistema
     */
    public monitorImpresion(){
        libre = new boolean[3];
        for (int i=0; i<3; ++i) {
            this.libre[i] = true;
        }
        this.impresoras = 3;
    }

    /**
     * Método que permite imprimir a una impresora
     * @return Retorna el identificador de la impresora que tiene permitido imprimir
     */
    public synchronized int take_print(){
        while (impresoras == 0) {
            try {
                wait();
            } catch(Exception e) {
                System.out.println("Error en take_print...");
            }
        }
        n = 0;
        while(!libre[n]){
            ++n;
        }
        libre[n] = false;
        --impresoras;
        return n;
    }

    /**
     * Método que libera a una impresora de su tarea después de imprimir
     * @param n Identificador de la impresora que deja de imprimir
     */
    public synchronized void drop_print(int n){
        libre[n] = true;
        ++impresoras;
        notifyAll();
    }
}
