
public class ParImpar implements Runnable {

    static boolean tipo; //Si declaramos esta variable como estática solo se imprime con el valor del ultimo objeto que se crea
    //Si quitamos el static, obtendremos un valor de la variable tipo por cada llamada al constructor, y tendremos impresiones
    //pares e impares

    public ParImpar(boolean tipo) {
        this.tipo = tipo;
    }

    public void run() {
        if (tipo) {
            for (int i = 0; i < 100; i += 2) {
                System.out.println(i);
            }
        } else {
            for (int i = 1; i < 100; i += 2) {
                System.out.println(i);
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread hiloPar = new Thread(new ParImpar(true));
        Thread hiloImpar = new Thread(new ParImpar(false));
        hiloPar.start();
        hiloPar.join();
        System.out.println("Cambia");
        hiloImpar.start();
        hiloImpar.join();
    }
}
