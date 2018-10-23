package paresimpares;

public class ParesImparesrun implements Runnable{

    int veces;
    boolean par;

    public ParesImparesrun(int veces, boolean par){
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
        Thread h1 = new Thread(new ParesImparesrun(10, true));
        Thread h2 = new Thread(new ParesImparesrun(10, false));
        h1.start();
        h2.start();

        h1.join();
        h2.join();
    }
}
