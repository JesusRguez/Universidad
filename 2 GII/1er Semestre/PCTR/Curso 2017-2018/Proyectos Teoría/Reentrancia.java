
public class Reentrancia extends Thread {

    void metodo(int iteraciones) {
        synchronized (this) {
            System.out.println("Iteraciones: " + iteraciones);
            if (iteraciones > 0) {
                metodo(iteraciones - 1);
            }
        }
    }

    public void run() {
        metodo(5);
    }

    public static void main(String[] args) throws InterruptedException {
        Reentrancia h1 = new Reentrancia();
        h1.start();
        h1.join();
    }
}

//Debido al comportamiento de este programa podemos afirmar que la instrucción synchronized es reentrante.
//De hecho, todas las instrucciones de java son reentrantes. Sin embargo, hay otros lenguajes como C++ en los que existen
//instrucciones reentrantes y no reentrantes.
