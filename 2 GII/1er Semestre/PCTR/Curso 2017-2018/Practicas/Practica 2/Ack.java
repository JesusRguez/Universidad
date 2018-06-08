
/**
 * @author Jes�s Rodr�guez Heras
 * @version 1.0
 */
public class Ack {

    /**
     * @param m
     * @param n
     */
    public static int Ackermann(int m, int n) { //Funci�n recursiva que devuelve el valor de la funci�n de Ackermann al finalizar
        if (m == 0) {
            return n + 1;
        } else {
            if (m > 0 && n == 0) {
                return Ackermann(m - 1, 1);
            } else {
                if (m > 0 && n > 0) {
                    return Ackermann(m - 1, Ackermann(m, n - 1));
                }
            }
        }
        return n;
    }

    public static void main(String[] args) {
        int n, m, resultado;
        if (args.length != 2) { //Comprobamos que el usuario mete solo dos argumentos, ni m�s ni menos
            System.out.println("Vuelve a ejecutar el programa con dos par�metros en la l�nea de comandos.");
        } else {
            n = Integer.parseInt(args[0]);
            m = Integer.parseInt(args[1]);
            resultado = Ackermann(m, n);
            System.out.println("El resultado es " + resultado);
        }
    }
}
