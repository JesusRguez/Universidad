import java.util.*;

public class filtroMedio implements Runnable{
    public static int[][] M;
    public static int[][] J;
    public static int tam, hilos;
    public int idHilo;

    public filtroMedio(int idHilo, int h, int tam){
        this.idHilo = idHilo;
        this.hilos = h;
        this.tam = tam;
    }

    public void run(){
        for (int i=0; i<tam; ++i) {
            for (int j=idHilo*tam/hilos; j<(idHilo+1)*tam/hilos; ++j) {
                //J[i][j] = (4*M[i][j] - M[(i+1)%M.length][j] - M[i][(j+1)%M.length] - M[(i+M.length-1)%M.length][j] - M[i][(j+M.length-1)%M.length])/8;

                J[i][j] = (M[i][j]+M[i][(j+1)%M.length]+M[i][(j+M.length-1)%M.length]+
                M[i-1][j]+M[i-1][(j+1)%M.length]+M[(i+1)%M.length][j]+
                M[(i+1)%M.length][j]+M[(i+1)%M.length][(j+1)%M.length]+M[(i+1)%M.length][(j+M.length-1)%M.length])/9;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Scanner teclado = new Scanner(System.in);
        System.out.print("Introduzca las dimensiones NxN de la matriz: ");
        int n = teclado.nextInt();
        M = new int[n][n];
        J = new int[n][n];

        int opcion;
        do {
            System.out.println("¿Cómo desea cargar la retícula?\n1. Aleatoriamente\n2. Manualmente");
            opcion = teclado.nextInt();

            switch (opcion) {
                case 1:
                    for (int i=0; i<n; ++i) {
                        for (int j=0; j<n; ++j) {
                            M[i][j] = (int)(Math.random()*255);
                        }
                    }
                break;
                case 2:
                    for (int i=0; i<n; ++i) {
                        for (int j=0; j<n; ++j) {
                            System.out.print("Introduzca el valor de la posición ("+i+", "+j+"):" );
                            M[i][j] = teclado.nextInt();
                        }
                    }
                break;
                default:
                    System.out.println("Por favor, introduzca 1 ó 2");
            }
        } while (opcion < 1 || opcion > 2);


        System.out.print("Introduzca el número de tareas paralelas: ");
        int h = teclado.nextInt();

        if (opcion == 2) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    System.out.print(M[i][j]+" ");
                }
                System.out.print("\n");
            }
        }

        //Al ser un problema del ámbito matemático su coeficiente de bloqueo es 0.
        Thread hilos[] = new Thread[h];
        long time_start = System.currentTimeMillis();
        for (int i=0; i<h; ++i) {
            hilos[i] = new Thread(new filtroMedio(i, h, n));
            hilos[i].start();
        }
        for (int i=0; i<h; ++i) {
            hilos[i].join();
        }
        long time_end = System.currentTimeMillis();
        if (opcion == 2) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    System.out.print(J[i][j]+" ");
                }
                System.out.print("\n");
            }
        }
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
