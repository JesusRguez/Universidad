/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.concurrent.*;
import java.util.*;

public class algEisenbergMcGuire implements Runnable{

    public static enum estado {IDLE, ESPERANDO, ACTIVO};
    public static estado flags[];
    public static int turno, n, variable = 0;
    public int i;

    public algEisenbergMcGuire(int n, int i){
        flags = new estado[n];
        turno = 0;
        this.n = n;
        this.i = i;
        for (int j=0; j<n; ++j) {
            flags[j] = estado.IDLE;
        }
    }

    public void run(){
        //int i = 0;
        int indice;
        do{
            flags[i] = estado.ESPERANDO;
            indice = turno;
            while(indice != i){
                if(flags[indice] != estado.IDLE){
                    indice = turno;
                }else{
                    indice = (indice+1)%n;
                }
            }
            flags[i] = estado.ACTIVO;
            indice = 0;
            while((indice < n) && ((indice == i) || (flags[indice] != estado.ACTIVO))){
                indice++;
            }
        }while(!((indice >= n) && ((turno == i) || (flags[turno] == estado.IDLE))));
        //Entramos en la sección crítica
        turno = i;

        // AQUÍ VA LA SECCIÓN crítica

        if(i == 1){
            variable++;
        }else{
            variable--;
        }

        indice = (turno + 1) % n;
        while(flags[indice] == estado.IDLE){
            indice = (indice + 1) % n;
        }
        turno = indice;
        flags[i] = estado.IDLE;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de iteraciones:");
        int n = teclado.nextInt();

        ExecutorService ejecutor = Executors.newFixedThreadPool(2);
        for (int i=0; i<2; ++i) {
            ejecutor.execute(new algEisenbergMcGuire(n, i));
        }
        ejecutor.shutdown();
        while(!ejecutor.isTerminated());
        System.out.println("Variable: "+variable);
    }
}
