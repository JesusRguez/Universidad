
/**
 * @author Jes�s Rodr�guez Heras
 * @version 1.0
 */
public class aleatorios {

    /**
     * @param args = Argumento leido por la l�nea de comandos
     */
    public static void numerosAleatorios(String[] args) {
        int numeros = Integer.parseInt(args[0]), i = 1;
        while (i <= numeros) {
            System.out.println("N�mero " + i + ": " + Math.random());
            //Solo imprimir� valores entre 0 y 1 debido a que el m�todo
            //Math.random() solo devuelve valores aleatorios entre 0 y 1
            i++;
        }
    }

    public static void main(String[] args) {
        numerosAleatorios(args);
    }
}
