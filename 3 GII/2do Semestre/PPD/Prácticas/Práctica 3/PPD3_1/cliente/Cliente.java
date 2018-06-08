package cliente;

import java.io.*;
import java.util.Scanner;

public class Cliente {

    public static void main(String[] args) {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        Scanner teclado = new Scanner(System.in);
        try {
            System.out.println("Bienvenido al cliente de la suma.\n");
            String nombreMaquina = "localhost"; // usa el nombre de maquina por defecto
            int numPuerto = 13; // numero de puerto por defecto
            MiSocketStream miSocket = new MiSocketStream(nombreMaquina, numPuerto);

            System.out.println(miSocket.recibeMensaje());

            System.out.print("Introduce el primer numero: ");
            Integer a = teclado.nextInt();
            System.out.print("Introduce el segundo numero: ");
            Integer b = teclado.nextInt();

            String dato1 = a.toString();
            miSocket.enviaMensaje(dato1);
            String dato2 = b.toString();
            miSocket.enviaMensaje(dato2);

            String resultado = miSocket.recibeMensaje();
            System.out.println("El resultado es " + resultado);
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        } // fin de catch
    } // fin de main
} // fin de class

