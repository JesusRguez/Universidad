package tablero;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Jesus
 */
import java.util.Scanner;

public class Juego {

    public static void main(String[] args) {
        Tablero t = new Tablero(5, 6);
        int columna;
        Scanner teclado = new Scanner(System.in);

        do {
            //Turno jugador 1
            t.imprimir();
            do {
                System.out.print("Jugador 1. Elija una columna libre:");
                columna = teclado.nextInt();
            } while (columna < 0 || columna > t.tablero[0].length || !t.huecoLibre(columna));
            //Al salir de este bucle, sabemos que el usuario ha elegido una columna válida

            t.introducirFicha(columna, 'x');

            if (t.ganador()) {
                t.imprimir();
                System.out.println("El jugador 1 ha ganado.");
            } else if (t.espacio()) {
                //Turno jugador 2
                t.imprimir();
                do {
                    System.out.print("Jugador 2. Elija una columna libre:");
                    columna = teclado.nextInt();
                } while (columna < 0 || columna > t.tablero[0].length || !t.huecoLibre(columna));
                //Al salir de este bucle, sabemos que el usuario ha elegido una columna válida

                t.introducirFicha(columna, 'o');

                if (t.ganador()) {
                    t.imprimir();
                    System.out.println("El jugador 2 ha ganado.");
                }
            }

        } while (!t.ganador() && t.espacio());
    }
}
