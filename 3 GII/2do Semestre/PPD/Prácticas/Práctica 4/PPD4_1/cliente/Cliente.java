package cliente;

import java.io.*;
import java.util.Scanner;

public class Cliente {

    public static void main(String[] args) {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        Scanner teclado = new Scanner(System.in);
        try {
            System.out.println("Bienvenido al cliente de la calculadora.\n");
            String nombreMaquina = "localhost"; // usa el nombre de maquina por defecto
            int numPuerto = 13; // numero de puerto por defecto
            MiSocketStream miSocket = new MiSocketStream(nombreMaquina, numPuerto);

            System.out.println(miSocket.recibeMensaje());

            System.out.print("Introduce la operacion a realizar: ");
            String operacion = teclado.nextLine();


            miSocket.enviaMensaje(operacion);

            String resultado = miSocket.recibeMensaje();
            System.out.println("El resultado es " + resultado);
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        } // fin de catch
    } // fin de main
} // fin de class
