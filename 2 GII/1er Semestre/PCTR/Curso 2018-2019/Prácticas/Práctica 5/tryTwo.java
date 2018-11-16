/**
 * @(#)tryTwo.java
 * @author  A.T.
 * @version 1.00 2012/11/9
 * Pre-solucion al control de la e.m. con variables comunes mediante flag de señalización
 * No preserva la e.m. sobre el recurso común.
 */

public class tryTwo
  extends Thread
{
	private int tipoHilo;

	private static volatile int nVueltas = 1000000;
	private static volatile int n = 0;
	private static volatile boolean C1 = false;
	private static volatile boolean C2 = false;


    public tryTwo(int tipoHilo)
    {this.tipoHilo=tipoHilo;}
    public void run()
    {
      switch(tipoHilo){
          //Si seguimos el número de los comentarios como orden de ejecución, una vez que C1 se pone a true ya es tarde para que en el caso 2, el segundo hilo pueda verlo, por eso no se verifica ni siquiera la propiedad de seguridad
        case 1:{for(int i=0; i<nVueltas; i++){
        	      while(C2==true);//(1)
        	      C1 = true;//(3)
        	      n++;//(5)
        	      C1 = false;

        	    }
        	    break;}
        case 2: {for(int i=0; i<nVueltas;i++){
        	      while(C1==true);//(2)
        	      C2 = true;//(4)
        	      n--;//(6)
        	      C2 = false;
                }
        	    }break;
      }
    }

    public static void main(String[] args)
      throws InterruptedException
    {
      tryTwo h1 = new tryTwo(1);
      tryTwo h2 = new tryTwo(2);
      h1.start(); h2.start();
      h1.join(); h2.join();
      System.out.println(n);
    }
}
