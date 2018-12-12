/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package monitorimpresion;

public class monitorImpresion{

    int i, impresoras;
    boolean libre[];

    /**
     * Constructor del monitorImpresion
     * @param n Número de impresoras en el sistema
     */
    public monitorImpresion(int n){
        libre = new boolean[n];
        for (int i=0; i<n; ++i) {
            this.libre[i] = false;
        }
        this.impresoras = n;
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
        int n = 1;
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
