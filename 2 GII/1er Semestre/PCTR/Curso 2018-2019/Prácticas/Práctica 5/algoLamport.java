/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;

public class algoLamport implements Runnable{

    public static int numero[];
    public static boolean eligiendo[];
    public static int variable = 0;
    public int iteraciones;
    public int i;

    public algoLamport(int n, int i){
        numero = new int[n];
        eligiendo = new boolean[n];
        for (int j=0; j<n; ++j) {
            numero[j] = 0;
            eligiendo[j] = false;
        }
        this.iteraciones = n;
        this.i = i;
    }

    /**
     * Método para calcular el máximo de un vector
     * @param  v Vector al que se desea calcular su máximo elemento
     * @return   Retorna el máximo elemento del vector v
     */
    public int maximo(int[] v){
        int m=0;
        for (int i=0; i<v.length; ++i) {
            if(v[i] > m){
                m = v[i];
            }
        }
        return m;
    }

    public void run(){
        for(int k=0;k<iteraciones;++k){
            eligiendo[i] = true;
            numero[i] = 1 + maximo(numero);
            eligiendo[i] = false;

            for (int j=0; j<numero.length; ++j) {
                while(eligiendo[i]){
                    Thread.yield();
                }
                while((numero[j] != 0) && ((numero[j] < numero[i]) || ((numero[j] == numero[i]) && (j < i)))){
                    Thread.yield();
                }
            }
            //SECCIÓN CRÍTICA
            if(i%2 == 0){
                variable++;
            }else{
                variable--;
            }
            //fin
            numero[i] = 0;
        }
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de iteraciones:");
        int n = teclado.nextInt();

        int hilos = Runtime.getRuntime().availableProcessors();

        ExecutorService ejecutor = Executors.newFixedThreadPool(hilos);
        for (int i=0; i<hilos; ++i) {
            ejecutor.execute(new algoLamport(n, i));
        }
        ejecutor.shutdown();
        while(!ejecutor.isTerminated());
        System.out.println("La variable compartida vale "+variable);
    }
}
