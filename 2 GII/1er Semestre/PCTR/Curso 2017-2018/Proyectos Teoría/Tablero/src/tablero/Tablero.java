/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

/**
 *
 * @author Jesus
 */
public class Tablero {

    //final int filas = 5, columnas = 6;
    char[][] tablero;
    int huecosDisponibles;
    //filas=tablero.length       columnas=tablero[i].length

    public Tablero(int filas, int columnas) {
        huecosDisponibles = filas * columnas;
        tablero = new char[filas][columnas];
        for (int i = 0; i < filas; i++) {   //Si algún dia me da por cambiar el valor de filas y columnas dejar el tablero.length y en el j, tablero[i].length
            for (int j = 0; j < columnas; j++) {
                tablero[i][j] = ' ';
            }
        }
    }

    public boolean ganador() {
        //Comprobar si hay 4 'x' horizontales seguidas
        int fichasDelMismoColorSeguidas = 0;
        for (int i = 0; i < tablero.length; i++) {
            for (int j = 0; j < tablero[i].length; j++) {
                if (tablero[i][j] == 'x') {
                    ++fichasDelMismoColorSeguidas;
                    if (fichasDelMismoColorSeguidas == 4) {
                        return true;
                    }
                } else {
                    fichasDelMismoColorSeguidas = 0;
                }
            }
        }
        //Comprobar si hay 4 'o' horizontales seguidas
        for (int i = 0; i < tablero.length; i++) {
            for (int j = 0; j < tablero[i].length; j++) {
                if (tablero[i][j] == 'o') {
                    ++fichasDelMismoColorSeguidas;
                    if (fichasDelMismoColorSeguidas == 4) {
                        return true;
                    }
                } else {
                    fichasDelMismoColorSeguidas = 0;
                }
            }
        }
        //Comprobar si hay 4 'x' verticales seguidas
        for (int i = 0; i < tablero.length; i++) {
            for (int j = 0; j < tablero.length; j++) {
                if (tablero[j][i] == 'x') {
                    ++fichasDelMismoColorSeguidas;
                    if (fichasDelMismoColorSeguidas == 4) {
                        return true;
                    }
                } else {
                    fichasDelMismoColorSeguidas = 0;
                }
            }
        }
        //Comprobar si hay 4 'o' verticales seguidas

        for (int i = 0; i < tablero.length; i++) {
            for (int j = 0; j < tablero.length; j++) {
                if (tablero[j][i] == 'o') {
                    ++fichasDelMismoColorSeguidas;
                    if (fichasDelMismoColorSeguidas == 4) {
                        return true;
                    }
                } else {
                    fichasDelMismoColorSeguidas = 0;
                }
            }
        }

        return false;
    }

    public boolean espacio() {
        return huecosDisponibles != 0;
    }

    public void imprimir() {
        for (int i = 0; i < tablero.length; i++) {
            System.out.println("---------------------");
            for (int j = 0; j < tablero[i].length; j++) {
                System.out.print("|" + tablero[i][j]);
            }
            System.out.println("|");
        }
        System.out.println("---------------------");
    }

    public boolean huecoLibre(int columna) {
        return tablero[0][columna] == ' ';
    }

    public void introducirFicha(int columna, char simbolo) {
        int filaDondeColoarLaFicha = tablero.length - 1;
        while (tablero[filaDondeColoarLaFicha][columna] != ' ') {
            --filaDondeColoarLaFicha;
        }
        tablero[filaDondeColoarLaFicha][columna] = simbolo;
    }
}
