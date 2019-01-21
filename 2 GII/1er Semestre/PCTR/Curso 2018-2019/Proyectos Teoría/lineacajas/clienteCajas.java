package lineacajas;

import java.util.concurrent.*;

public class clienteCajas implements Runnable{

    public lineaCajas monitor = new lineaCajas();
    public int cliente;

    public clienteCajas(){}

    public void run(){
        while(true){
            cliente = monitor.take_client();
            System.out.println("Cliente procesado");
            monitor.drop_client(cliente);
        }
    }

    public static void main(String[] args) throws InterruptedException{
        int h = 20;
        ExecutorService ejecutor = Executors.newFixedThreadPool(h);
        for (int i=0; i<h; ++i) {
            ejecutor.execute(new clienteCajas());
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
    }
}
