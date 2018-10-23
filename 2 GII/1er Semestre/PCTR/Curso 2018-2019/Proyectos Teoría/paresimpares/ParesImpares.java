package paresimpares;

public class ParesImpares extends Thread{

    int veces;
    boolean par;

    public ParesImpares(int veces, boolean par){
        this.veces = veces;
        this.par = par;
    }

    public void run(){
        if(par){
            for (int i=0; i<2*veces; i+=2) {
                System.out.println(i);
            }
        }else{
            for (int i=1; i<2*veces; i+=2) {
                System.out.println(i);
            }
        }
    }

    public static void main(String[] args) throws InterruptedException{
        ParesImpares h1 = new ParesImpares(10, true);
        ParesImpares h2 = new ParesImpares(10, false);
        h1.start();
        h2.start();

        h1.join();
        h2.join();
    }
}
