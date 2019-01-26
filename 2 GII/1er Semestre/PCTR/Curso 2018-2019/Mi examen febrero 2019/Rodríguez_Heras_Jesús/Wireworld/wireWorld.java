/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;
import java.util.concurrent.*;

public class wireWorld implements Runnable{

    public static int reticula[][];
    public static Scanner teclado = new Scanner(System.in);
    public int id;
    public int rango;
    public int t;
    public int g;
    public static Object o = new Object();

    /**
     * Constructor de wireWorld
     * @param i Identificador del hilo
     * @param d Rango de actuación del hilo
     * @param t Tamaño máximo de la reticula
     * @param g Número de generaciones
     */
    public wireWorld(int i, int d, int t, int g){
        this.id = i;
        this.rango = d;
        this.t = t;
        this.g = g;
    }

    // Estados de cada celda:
    // 0 = vacio;
    // 1 = frente de electron;
    // 2 = cola de electron;
    // 3 = conductor
    // Una célula es vecina de otra por arriba o por debajo, nunca por izquierda o derecha

    public void run(){
        for (int n=0; n<g; ++n) {
            for (int i=id*rango + 1; i<id*rango + rango - 2; ++i) {
                for (int j=1; j<t-1; ++j) {
                    if (reticula[i][j] == 0) {
                        reticula[i][j] = 0;
                    }else{
                        if (reticula[i][j] == 1) {
                            reticula[i][j] = 2;
                        }else{
                            if (reticula[i][j] == 2) {
                                reticula[i][j] = 3;
                            }else{
                                if (reticula[i][j] == 3) {
                                    if ((reticula[i][j-1] == 1 || reticula[i][j+1] == 1) ||
                                         (reticula[i-1][j] == 1 || reticula[i+1][j] == 1) ||
                                         (reticula[i-1][j-1] == 1 || reticula[i+1][j-1] == 1) ||
                                         (reticula[i+1][j+1] == 1 || reticula[i+1][j-1] == 1)) {
                                        reticula[i][j] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            synchronized (o){
                for (int i=0; i<id*rango; ++i) {
                    for (int j=0; j<t; ++j) {
                        System.out.print(reticula[i][j]+"\t");
                    }
                    System.out.print("\n");
                }
            }
        }
    }

    public static void cargarAleatoriamente(int d){
        reticula = new int[d][d];
        for (int i=0; i<d; ++i) {
            for (int j=0; j<d; ++j) {
                reticula[i][j] = (int)(Math.random()*5);
            }
        }
    }

    public static void cargarManualmente(int d){
        reticula = new int[d][d];
        int valor;
        for (int i=0; i<d; ++i) {
            for (int j=0; j<d; ++j) {
                do {
                    System.out.print("Valor para la celda ("+i+", "+j+"): ");
                    valor = teclado.nextInt();
                } while (valor < 0 || valor > 4);
                reticula[i][j] = valor;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {

        System.out.print("Introduzca el número de generaciones: ");
        int n = teclado.nextInt();
        System.out.print("Introduzca la dimensión de la retícula: ");
        int d = teclado.nextInt();
        System.out.print("Introduzca el número de tareas paralelas: ");
        int m = teclado.nextInt();
        int h = Runtime.getRuntime().availableProcessors();//Coeficiente de bloqueo = 0

        int opcion;
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        do {
            System.out.println("Introduzca la opcion que desea:\n1. Cargar retícula con datos aleatorios\n2. Cargar retícula manualmente\n3. Salir");
            opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    cargarAleatoriamente(d);
                    for (int i=0; i<h; ++i) {
                        ejecutor.execute(new wireWorld(i, d/h, d, n));
                    }
                    ejecutor.shutdown();
                    ejecutor.awaitTermination(1, TimeUnit.HOURS);
                break;
                case 2:
                    cargarManualmente(d);
                    for (int i=0; i<h; ++i) {
                        ejecutor.execute(new wireWorld(i, d/h, d, n));
                    }
                    ejecutor.shutdown();
                    ejecutor.awaitTermination(1, TimeUnit.HOURS);
                break;
                case 3:
                    System.exit(0);
                break;
                default:
                    System.out.println("Introduzca una opción correcta");
            }
        } while (opcion != 3);
    }
}
