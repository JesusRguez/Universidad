/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;

public class algoLamport implements Runnable{

    public static int numero[];
    public static boolean eligiendo[];
    public static int h = 0;
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
                while((numero[j] != 0) && ((numero[j] < numero[i]) || ((numero[j] == numero[i]) && (j < i)))){}
            }
            //SECCIÓN CRÍTICA
            h++;
            Thread.yield();
            System.out.println("Número de procesos en la sección crítica: "+h);
            h--;
            //fin
            numero[i] = 0;
        }
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de iteraciones:");
        int n = teclado.nextInt();

        ExecutorService ejecutor = Executors.newFixedThreadPool(4);
        for (int i=0; i<n; ++i) {
            ejecutor.execute(new algoLamport(n, i));
        }
        ejecutor.shutdown();
        while(!ejecutor.isTerminated());
    }
}
