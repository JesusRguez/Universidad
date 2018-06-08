
package incremento;



/**
 *
 * @author Juan Pedro
 */
public class Incremento extends Thread  {
    static int x=0;
    
    public void run()
    {   
        
        x++;
        System.out.println(x);
    }
    public static void main(String[] args) throws InterruptedException{ // CORRUTINA
        Incremento hilo1 = new Incremento();
        System.out.println("A");
        hilo1.start(); // NO LANZA UN HILO
        
        System.out.println("B");
        
        Incremento hilo2 = new Incremento();
        System.out.println("C");
        //EL UNO PUEDE IMPRIMIRSE ANTES O DEPSUES DE LA B
        hilo2.start();
        System.out.println("D");
        hilo1.join(); // EL HILO PRINCIPAL SE PARA HASTA QUE EL HILO1 TERMINE
        hilo2.join();
        System.out.println("E");
    }
    
}
