import java.util.*;

class aleatorios{
    public static void main(String[] args) {
        System.out.println("Introduzca la longitudo de la secuencia de números aleatorios:");
        Scanner teclado = new Scanner(System.in);
        int longitud=teclado.nextInt();
        for (int i=0; i<longitud; ++i) {
            Random n = new Random();
            System.out.println(n.nextInt());
        }
    }
}
