
/**
 * Ejercicio 17
 *
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.Scanner;

public class ConsumoMedio {

    static float v1_precio_litro, v1_total_pagado, v1_km, v2_precio_litro, v2_total_pagado, v3_km;

    static void leer() {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Primera vez que repostamos:");
        System.out.print("Precio por litro: ");
        v1_precio_litro = teclado.nextFloat();
        System.out.print("Total pagado: ");
        v1_total_pagado = teclado.nextFloat();
        System.out.print("Kilómetros en el contakilómetros: ");
        v1_km = teclado.nextFloat();
        System.out.println("Segunda vez que repostamos:");
        System.out.print("Precio por litro: ");
        v2_precio_litro = teclado.nextFloat();
        System.out.print("Total pagado: ");
        v2_total_pagado = teclado.nextFloat();
        System.out.println("Tercera vez que repostamos:");
        System.out.print("Kilómetros en el cuentakilómetros: ");
        v3_km = teclado.nextFloat();
    }

    static void imprime() {
        float litros1 = (v1_total_pagado / v1_precio_litro);
        float litros2 = (v2_total_pagado / v2_precio_litro);
        float litros_totales = litros1 + litros2;
        float km_totales = v3_km - v1_km;
        float l_km = litros_totales / km_totales; //Te da x litros por km
        System.out.println("Consumo por cada 100km: " + l_km / 100);

        float total_pagado = v1_total_pagado + v2_total_pagado;
        System.out.println("El coste por km es: " + total_pagado / km_totales);
    }

    public static void main(String[] args) {
        leer();
        imprime();
    }
}
