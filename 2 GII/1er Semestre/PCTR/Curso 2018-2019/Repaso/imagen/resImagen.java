import java.util.*;

public class resImagen{
    public static int[][] resaltado(int[][] m){
        for (int i=0; i<m.length; ++i) {
            for (int j=0; j<m[i].length; ++j) {
                m[i][j] = (4*m[i][j] - m[(i+1)%m.length][j] - m[i][(j+1)%m.length] - m[(i-1+m.length)%m.length][j] - m[i][(j-1+m.length)%m.length])/8;
            }
        }

        return m;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int m[][];
        System.out.println("Introduzca el tamaño de la matriz NxN:");
        int n = teclado.nextInt();
        m = new int[n][n];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                m[i][j] = (int)Math.random()*20;
            }
        }
        long time_start = System.currentTimeMillis();
        m = resaltado(m);
        long time_end = System.currentTimeMillis();
        System.out.println("Tarda "+(time_end-time_start)/(double)1000+" segundos");
    }
}
