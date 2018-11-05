/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class escalaVectorParalelo extends Thread{

    public static int t;
    static int[] v;
    static int[] r;
    static int eleccion, f;

    /**
     * Constructor de escalaVectorParalelo
     * @param n        Número de elementos del vector
     * @param eleccion Eleccion de suma/resta
     * @param f        Factor de escalado
     */
    public escalaVectorParalelo(int n, int eleccion, int f){
        v = new int[n];
        this.eleccion = eleccion;
        this.f = f;
        t = n;
    }

    /**
     * Método run
     */
    public void run(){
        r = new int[t];

        switch(eleccion){
            case 1:
                for (int i=0; i<t/4; ++i) {
                    r[i] = f*v[i];
                }
                break;
            case 2:
                for (int i=t/4; i<t/2; ++i) {
                    r[i] = f*v[i];
                }
                break;
            case 3:
                for (int i=t/2; i<(3/4)*t; ++i) {
                    r[i] = f*v[i];
                }
                break;
            case 4:
                for (int i=(3/4)*t; i<t; ++i) {
                    r[i] = f*v[i];
                }
                break;
        }
    }

    public static void main(String[] args) throws InterruptedException{
        Scanner teclado = new Scanner(System.in);
        System.out.println("Introduzca el número de elementos:");
        int n = teclado.nextInt();
        System.out.println("Introduzca el factor:");
        int f = teclado.nextInt();

        escalaVectorParalelo hilo1 = new escalaVectorParalelo(n, 1, f);
        escalaVectorParalelo hilo2 = new escalaVectorParalelo(n, 2, f);
        escalaVectorParalelo hilo3 = new escalaVectorParalelo(n, 3, f);
        escalaVectorParalelo hilo4 = new escalaVectorParalelo(n, 4, f);

        for (int i=0; i<n; ++i) {
            v[i] = (int)(Math.random()*10);
        }

        hilo1.start();
        hilo2.start();
        hilo3.start();
        hilo4.start();

        hilo1.join();
        hilo2.join();
        hilo3.join();
        hilo4.join();
    }
}
