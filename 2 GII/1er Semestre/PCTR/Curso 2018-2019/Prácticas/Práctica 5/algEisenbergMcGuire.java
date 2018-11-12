/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.concurrent.*;
import java.util.*;

public class algEisenbergMcGuire implements Runnable{

    public static boolean flags[];
    public static int turno, n;
    public static int h = 0;
    public int i;

    public algEisenbergMcGuire(int n, int i){
        flags = new boolean[n];
        turno = 0;
        this.i = i;
        this.n = n;
        for (int j=0; j<n; ++j) {
            flags[j] = false;
        }
    }

    public void run(){
        int indice = 0;

        do{
            flags[i]=false;
            indice=turno;
            while(indice != i){
                if (flags[i] != false) {
                    indice = turno;
                }else{
                    indice = (indice+1)%n;
                    Thread.yield();
                }
            }

            flags[i] = true;
            indice = 0;
            while((indice < n) && ((indice == i) || (flags[indice]!=true))){
                indice = indice+1;
                Thread.yield();
            }
        }while((indice >= n) && ((turno == i) || (flags[turno] == false)));
        //Entramos en la sección crítica
        turno = i;

        // AQUÍ VA LA SECCIÓN crítica
        h++;
        Thread.yield();
        System.out.println("Número de procesos en sección crítica: "+h);
        h--;
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
    }
}
