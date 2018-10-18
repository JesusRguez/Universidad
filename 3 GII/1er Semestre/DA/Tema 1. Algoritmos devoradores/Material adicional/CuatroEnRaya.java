
import java.util.Scanner;

/**
 * Esta es una clase para jugar al 4 en Raya
 * @author Alberto Salguero alberto.salguero@uca.es
 */
public class CuatroEnRaya {
    char[][] tablero;
    int casillasDisponibles = 0;

    public CuatroEnRaya(int filas, int columnas) {
        casillasDisponibles = filas * columnas;
        tablero = new char[filas][columnas];
        for(int i = 0 ; i < tablero.length ; ++i) {
            for(int j = 0 ; j < tablero[i].length ; ++j) {
                tablero[i][j] = ' ';
            }
        }
    }
    
    /**
     * Imprime el tablero
     */
    void imprimir() {
        for(int j = 0 ; j < tablero[0].length ; ++j) { 
            System.out.print(" " + j);
        }
        System.out.println("");
        for(int i = 0 ; i < tablero.length ; ++i) {            
            for(int j = 0 ; j < tablero[i].length ; ++j) { 
                System.out.print("--");
            }
            System.out.println("-");
            System.out.print("|");
            for(int j = 0 ; j < tablero[i].length ; ++j) {
                System.out.print(tablero[i][j] + "|");
            }
            System.out.println("");
        }
        for(int j = 0 ; j < tablero[0].length ; ++j) { 
            System.out.print("--");
        }
        System.out.println("-");
    }
    
    /**
     * Comprueba si un jugador ha ganado
     * @return el jugador ganador ó ' ' en caso contrario
     * @see https://stackoverflow.com/questions/39062111/java-how-to-check-diagonal-connect-four-win-in-2d-array
     */
    public char ganador() {
        int maxx = tablero.length;
        int maxy = tablero[0].length;
        int[][] directions = {{1,0}, {1,-1}, {1,1}, {0,1}};
        for (int[] d : directions) {
            int dx = d[0];
            int dy = d[1];
            for (int x = 0; x < maxx; x++) {
                for (int y = 0; y < maxy; y++) {
                    int lastx = x + 3*dx;
                    int lasty = y + 3*dy;
                    if (0 <= lastx && lastx < maxx && 0 <= lasty && lasty < maxy) {
                        char w = tablero[x][y];
                        if (w != ' ' && w == tablero[x+dx][y+dy] 
                                     && w == tablero[x+2*dx][y+2*dy] 
                                     && w == tablero[lastx][lasty]) {
                            return w;
                        }
                    }
                }
            }
        }
        
        return ' ';
    }
    
    public void introducirFicha(int columna, char simbolo) {
        int filaAComprobar = tablero.length-1;
        while(tablero[filaAComprobar][columna] != ' ') {
            --filaAComprobar;
        }
        tablero[filaAComprobar][columna] = simbolo;
    }
    
    public int altura(int columna) {
        int filaAComprobar = tablero.length-1;
        while(tablero[filaAComprobar][columna] != ' ') {
            --filaAComprobar;
        }
        
        return tablero.length - filaAComprobar - 1;
    }
    
    public boolean cabeFicha(int columna) {
        return tablero[0][columna] == ' ';
    }    

    public static void main(String[] args) {
        CuatroEnRaya t = new CuatroEnRaya(5, 6);
        Scanner teclado = new Scanner(System.in);
        do {
            // Turno jugador 1
            t.imprimir();
            int columna;
            do {
                System.out.print("Jugador 1, seleccione una columna libre: ");
                columna = teclado.nextInt();
            } while(columna >= 0 && columna < t.tablero[0].length 
                    && !t.cabeFicha(columna));
            
            t.introducirFicha(columna, 'x');
            
            if(t.ganador() == ' ') {
                // Turno jugador 2
                t.imprimir();
                do {
                    System.out.print("Jugador 2, seleccione una columna libre: ");
                    columna = teclado.nextInt();
                } while(columna >= 0 && columna < t.tablero[0].length 
                        && !t.cabeFicha(columna));

                t.introducirFicha(columna, 'o');
            }
            
        } while( t.casillasDisponibles > 0 && t.ganador() == ' ');
        
        t.imprimir();
        System.out.println("Ha ganado el jugador: " + t.ganador());
    }
    
}
