package punto;

import java.rmi.Naming;
import java.util.*;

public class longClient {
    public static void main(String[] args) throws Exception {
        longInterface ORemoto = (longInterface)Naming.lookup("punto");
        punto datos[] = new punto[20];
        int rango;
        System.out.println("Introduzca los 20 puntos del plano:");
        Scanner teclado = new Scanner(System.in);
        for (int i=0; i<20; ++i) {
            System.out.print("Introduzca la coordenada X del punto "+(i+1)+": ");
            float x = teclado.nextFloat();
            System.out.print("Introduzca la coordenada Y del punto "+(i+1)+": ");
            float y = teclado.nextFloat();
            datos[i] = new punto(x, y);
        }
        System.out.println("¿Cuántos subrangos desea hacer?");
        int subrangos = teclado.nextInt();

        int inicio = 0;
        float resultado[] = new float[subrangos];
        for (int i=0; i<subrangos; ++i) {
            resultado[i] = 0;
        }

        float res = 0;
        for (int i=0; i<subrangos; ++i) {
            int n = 20/subrangos;
            punto[] subdatos = new punto[n];
            for (int j=0; j<n; ++j) {
                subdatos[j] = datos[inicio*j];
            }
            inicio++;
            resultado[i] = ORemoto.lonSubSegmento(n, subdatos);
        }

        for (int i=0; i<subrangos; ++i) {
            res += resultado[i];
        }

        System.out.println("La longitud del segmento es: "+res);
    }
}
