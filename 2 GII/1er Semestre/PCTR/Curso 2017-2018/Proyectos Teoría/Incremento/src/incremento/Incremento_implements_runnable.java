
package incremento;



/**
 *
 * @author Juan Pedro
 */
public class Incremento_implements_runnable extends Thread  {//Solo se hereda de una clase "extends"
    public static int x=0;
    
    public void run()
    {   
        for(int i =0;i<10000;i++)
            x++;
        
    }
    public static void main(String[] args) throws InterruptedException{ // CORRUTINA
        Incremento hilo1 = new Incremento(); // Acepta como argumento un objeto de runnable
        Incremento hilo2 = new Incremento();
        
        hilo1.start(); // NO LANZA UN HILO     
        hilo2.start();

        hilo1.join(); // EL HILO PRINCIPAL SE PARA HASTA QUE EL HILO1 TERMINE
        hilo2.join();
        System.out.println(hilo1.x);
    }
    
}
