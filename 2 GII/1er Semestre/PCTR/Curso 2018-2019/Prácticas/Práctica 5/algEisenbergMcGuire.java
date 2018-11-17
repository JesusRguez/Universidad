/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.concurrent.*;
import java.util.*;

public class algEisenbergMcGuire implements Runnable{

    public static volatile boolean flags[];
    public static volatile int turno, n, variable = 0;
    public int i;

    public algEisenbergMcGuire(int n, int i){
        flags = new boolean[n];
        turno = 0;
        this.n = n;
        this.i = i;
        for (int j=0; j<n; ++j) {
            flags[j] = false;
        }
    }

    public void run(){
        int indice;
        do{
            flags[i] = false;
            indice = turno;
            while(indice != i){
                if(flags[indice] != false){
                    indice = turno;
                }else{
                    indice = (indice+1)%n;
                }
            }
            flags[i] = true;
            indice = 0;
            while((indice < n) && ((indice == i) || (flags[indice] != true))){
                indice++;
            }
        }while(!((indice >= n) && ((turno == i) || (flags[turno] == false))));
        //Entramos en la sección crítica
        turno = i;

        // AQUÍ VA LA SECCIÓN crítica
        if(i%2 == 0){
            variable++;
        }else{
            variable--;
        }

        indice = (turno + 1) % n;
        while(flags[indice] == false){
            indice = (indice + 1) % n;
        }
        turno = indice;
        flags[i] = false;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de iteraciones:");
        int n = teclado.nextInt();

        ExecutorService ejecutor = Executors.newFixedThreadPool(2);
        for (int i=0; i<n; ++i) {
            ejecutor.execute(new algEisenbergMcGuire(n, i));
        }
        ejecutor.shutdown();
        while(!ejecutor.isTerminated());
        System.out.println("La variable compartida vale: "+variable);
    }
}
