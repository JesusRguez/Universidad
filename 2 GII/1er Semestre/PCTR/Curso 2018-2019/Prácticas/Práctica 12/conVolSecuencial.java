/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.*;

public class conVolSecuencial{

    public static int[][] m = new int[10000][10000];
    public static int[][] r = new int[10000][10000];
    public static int[][] f = new int[3][3];

    public static int[][] convolucion(int[][] m, int[][] f){
        int[][] a = new int[3][3];
        int v = 0;
        for (int i=1; i<9999; ++i) {
            for (int j=1; j<9999; ++j) {
                a[0][0] = m[i-1][j-1];
                a[0][1] = m[i-1][j];
                a[0][2] = m[i-1][j+1];
                a[1][0] = m[i][j-1];
                a[1][1] = m[i][j];
                a[1][2] = m[i][j+1];
                a[2][0] = m[i+1][j-1];
                a[2][1] = m[i+1][j];
                a[2][2] = m[i+1][j+1];
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        v += a[k][l] * f[k][l];
                    }
                }
                if (v < -20) {
                    v = -20;
                }
                if (v > 20) {
                    v = 20;
                }
                r[i][j] = v;
            }
        }
        return r;
    }

    public static void main(String[] args) {
        for (int i=0; i<10000; ++i) {
            for (int j=0; j<10000; ++j) {
                m[i][j] = (int)(Math.random()*(-41)+21);
            }
        }
        Scanner teclado = new Scanner(System.in);
        int opcion;
        long time_start, time_end;
        do {
            System.out.println("Introduzca el filtro a aplicar o salir:\n1. Enfocar\n2. Realzar bordes\n3. Detectar bordes\n4. Filtro de Sobel\n5. Filtro de Sharpen\n6. Salir");
            opcion = teclado.nextInt();
            switch (opcion) {
                case 1:
                    f[0][0] = 0;
                    f[0][1] = -1;
                    f[0][2] = 0;
                    f[1][0] = -1;
                    f[1][1] = 5;
                    f[1][2] = -1;
                    f[2][0] = 0;
                    f[2][1] = -1;
                    f[2][2] = 0;
                    r = convolucion(m, f);
                break;
                case 2:
                    f[0][0] = 0;
                    f[0][1] = 0;
                    f[0][2] = 0;
                    f[1][0] = -1;
                    f[1][1] = 1;
                    f[1][2] = 0;
                    f[2][0] = 0;
                    f[2][1] = 0;
                    f[2][2] = 0;
                    r = convolucion(m, f);
                break;
                case 3:
                    f[0][0] = 0;
                    f[0][1] = 1;
                    f[0][2] = 0;
                    f[1][0] = 1;
                    f[1][1] = -4;
                    f[1][2] = 1;
                    f[2][0] = 0;
                    f[2][1] = 1;
                    f[2][2] = 0;
                    r = convolucion(m, f);
                break;
                case 4:
                    f[0][0] = -1;
                    f[0][1] = 0;
                    f[0][2] = 1;
                    f[1][0] = -2;
                    f[1][1] = 0;
                    f[1][2] = 2;
                    f[2][0] = -1;
                    f[2][1] = 0;
                    f[2][2] = 1;
                    r = convolucion(m, f);
                break;
                case 5:
                    f[0][0] = 1;
                    f[0][1] = -2;
                    f[0][2] = 1;
                    f[1][0] = -2;
                    f[1][1] = 5;
                    f[1][2] = -2;
                    f[2][0] = 1;
                    f[2][1] = -2;
                    f[2][2] = 1;
                    r = convolucion(m, f);
                break;
                case 6:
                    System.exit(0);
                break;
                default:
                    System.out.println("Por favor, introduzca una opción válida");
            }
        } while (opcion < 1 || opcion > 6);
    }
}
