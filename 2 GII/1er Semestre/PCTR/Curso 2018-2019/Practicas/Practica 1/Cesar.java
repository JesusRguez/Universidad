import java.util.*;

class Cesar{

    public static String cifrar(String cadena, int n){
        StringBuilder res = new StringBuilder();
        int valorASCII;

        for (int i = 0; i < cadena.length(); ++i) {
            valorASCII = (int) (cadena.charAt(i));
            valorASCII = valorASCII + (n % 27);
            res.append((char) (valorASCII));
        }
        return res.toString();
    }

    public static void main(String[] args) {
        System.out.println("Intrduce la cadena a cifrar:");
        Scanner teclado = new Scanner(System.in);
        String cadena = teclado.nextLine();
        System.out.println("Introduce la semilla:");
        int n = teclado.nextInt();
        System.out.println("La cadena cifrada es: "+cifrar(cadena, n));
    }
}
