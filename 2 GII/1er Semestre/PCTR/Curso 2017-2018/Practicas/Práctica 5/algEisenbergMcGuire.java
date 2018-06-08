
/**
 * @author Jesús Rodríguez Heras
 * @version Version 1.0
 */
public class algEisenbergMcGuire implements Runnable {

    static enum estado {
        IDLE, ESPERANDO, ACTIVO
    };
    static estado flags[];
    static int turno;
    static int n;
    int tipoHilo;
    static int numeros = 10000000;

    public algEisenbergMcGuire(int n, int tipoHilo) {
        flags = new estado[n];
        turno = 0;
        this.n = n;
        this.tipoHilo = tipoHilo;
        for (int i = 0; i < n; i++) {
            flags[i] = estado.IDLE;
        }
    }

    public void run() {
        int i = 0;
        int indice;
        do {
            //Anunciamos la solicitud del recurso
            flags[i] = estado.ESPERANDO;
            //Escanear los procesos partiendo desde el que posee el turno
            //Repite hasta encontrar todos los procesos en IDLE
            indice = turno;
            while (indice != i) {
                if (flags[indice] != estado.IDLE) {
                    indice = turno;
                } else {
                    indice = (indice + 1) % algEisenbergMcGuire.n;
                }
            }
            //Reclamamos temporalmente el recurso
            flags[i] = estado.ACTIVO;
            //Entonctrar el primer proceso activo además de nosotros, si existe
            indice = 0;
            while ((indice < algEisenbergMcGuire.n) && ((indice == i) || (flags[indice] != estado.ACTIVO))) {

                indice++;
            }
            //Si no hay otros procesos activos, y tenemos el turno, o si todos
            //los demás tienen estado IDLE, proceder, en toro caso, repetir.
        } while (!((indice >= algEisenbergMcGuire.n) && ((turno == i) || (flags[turno] == estado.IDLE))));

        turno = i;

        //Reclamar el turno y proceder
        //AHORA VIENE LA SECCIÓN CRÍTICA
        switch (tipoHilo) {
            case 1:
                for (int p = 0; p < 1000; p++) {
                    numeros++;
                }
                break;
            case 2:
                for (int p = 0; p < 1000; p++) {
                    numeros--;
                }
                break;
        }
        //Encuentra un proceso que no esté en IDLE
        //Si no hay otro, nos encontraremos a nosotros mismos
        indice = (turno + 1) % algEisenbergMcGuire.n;
        while (flags[indice] == estado.IDLE) {
            indice = (indice + 1) % algEisenbergMcGuire.n;
        }
        //Dar el turno a una hebra que lo necesita, o mantenerlo
        turno = indice;
        //Hemos acabado
        flags[indice] = estado.IDLE;
        //Sección restante del código

    }

    public static void main(String[] args) throws InterruptedException {
        int n = 2;

        Thread a = new Thread(new algEisenbergMcGuire(n, 1));
        Thread b = new Thread(new algEisenbergMcGuire(n, 2));

        a.start();
        b.start();

        a.join();
        b.join();

        System.out.println(algEisenbergMcGuire.numeros);
    }
}
