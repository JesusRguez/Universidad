import java.util.*;
import java.util.concurrent.*;

public class acGreenbergHastings implements Runnable{

    public static int reticula[][];
    public static Scanner teclado = new Scanner(System.in);
    public int id;
    public int rango;
    public int t;
    public int e;
    public static final CyclicBarrier barrera = new CyclicBarrier(Runtime.getRuntime().availableProcessors());

    /**
     * Constructor de acGreenbergHastings
     * @param i Identificador del hilo
     * @param d Rango de actuación del hilo
     * @param t Tamaño máximo de la reticula
     * @param e Número de etapas
     */
    public acGreenbergHastings(int i, int d, int t, int e){
        this.id = i;
        this.rango = d;
        this.t = t;
        this.e = e;
    }

    // Estados de cada celda:
    // 0 = estable;
    // 1 = excitado;
    // 2 = refractario;

    public void run(){
        for (int n=0; n<e; ++n) {
            for (int i=id*rango + 1; i<id*rango + rango - 2; ++i) {
                for (int j=1; j<t-1; ++j) {
                    if (reticula[i][j] == 1) {
                        reticula[i][j] = 2;
                    }else{
                        if (reticula[i][j] == 2) {
                            reticula[i][j] = 0;
                        }else{
                            if (reticula[i][j] == 0) {
                                if ((reticula[i][j-1] == 1 || reticula[i][j+1] == 1) ||
                                     (reticula[i-1][j] == 1 || reticula[i+1][j] == 1) ||
                                     (reticula[i-1][j-1] == 1 || reticula[i+1][j-1] == 1) ||
                                     (reticula[i+1][j+1] == 1 || reticula[i-1][j+1] == 1)) {
                                    reticula[i][j] = 1;
                                }
                            }
                        }
                    }
                }
            }

            try {
                barrera.await();
            } catch(Exception e) {
                System.out.println("Fallo en la barrera");
            }
        }
    }

    /**
     * Método para cargar automáticamente la retícula
     * @param d Tamaño de la retícula
     */
    public static void cargarAleatoriamente(int d){
        reticula = new int[d][d];
        for (int i=0; i<d; ++i) {
            for (int j=0; j<d; ++j) {
                reticula[i][j] = (int)(Math.random() * 3);
            }
        }
    }

    /**
     * Método para cargar manualmente la retícula
     * @param d Tamaño de la retícula
     */
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

        System.out.print("Introduzca la dimensión de la retícula: ");
        int n = teclado.nextInt();
        System.out.print("Introduzca el número de tareas paralelas: ");
        int m = teclado.nextInt();
        System.out.print("Introduzca el número de etapas: ");
        int t = teclado.nextInt();
        //int h = Runtime.getRuntime().availableProcessors();//Coeficiente de bloqueo = 0 por ser un problema de ámbito matemático

        int opcion;
        ExecutorService ejecutor = Executors.newFixedThreadPool(m);
        long time_start, time_end;
        do {
            System.out.println("Introduzca la opcion que desea:\n1. Cargar retícula con datos aleatorios\n2. Cargar retícula manualmente\n3. Salir");
            opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    cargarAleatoriamente(n);
                    time_start = System.currentTimeMillis();
                    for (int i=0; i<m; ++i) {
                        ejecutor.execute(new acGreenbergHastings(i, n/m, n, t));
                    }
                    ejecutor.shutdown();
                    ejecutor.awaitTermination(1, TimeUnit.HOURS);
                    time_end = System.currentTimeMillis();
                    System.out.println("Ha tardado "+(time_end-time_start)/(double)10+" microsegundos");
                break;
                case 2:
                    cargarManualmente(n);
                    System.out.println("La reticula inicial es:");
                    for (int i=0; i<n; ++i) {
                        for (int j=0; j<n; ++j) {
                            System.out.print(reticula[i][j]+"\t");
                        }
                        System.out.print("\n");
                    }
                    time_start = System.currentTimeMillis();
                    for (int i=0; i<m; ++i) {
                        ejecutor.execute(new acGreenbergHastings(i, n/m, n, t));
                    }
                    ejecutor.shutdown();
                    ejecutor.awaitTermination(1, TimeUnit.HOURS);
                    time_end = System.currentTimeMillis();
                    System.out.println("Ha tardado "+(time_end-time_start)/(double)10+" microsegundos");

                    System.out.println("La reticula final es:");
                    for (int i=0; i<n; ++i) {
                        for (int j=0; j<n; ++j) {
                            System.out.print(reticula[i][j]+"\t");
                        }
                        System.out.print("\n");
                    }
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
