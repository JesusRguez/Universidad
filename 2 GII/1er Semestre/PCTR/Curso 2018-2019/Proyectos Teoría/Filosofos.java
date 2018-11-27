public class Filosofos{

    boolean[] T = new boolean[5]; //true=libre   false=ocupado

    public synchronized void comer(int i){
        while(!T[i] || !T[(i+1)%5]){
            wait();
        }
        T[i] = T[(i+1)%5] = false;
        System.out.println("Filosofo "+i+" comiendo");
        T[i] = T[(i+1)%5] = true;
        notifyAll();
    }

    public static void main(String[] args) {
        // Aquí lanzariamos los filosofos a comer
    }
}
