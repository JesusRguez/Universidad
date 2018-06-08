/* Fichero Cuenta_Banca.java 
  *@author Antonio J. Tomeu
  *@version 1.0 
  *Dpto. Lenguajes y Sistemas Inform�ticos
  *�rea de CC. de la Computaci�n e I.A.
  *Ejemplo de clase...
 */
import java.util.concurrent.*;

public class Cuenta_Banca implements Runnable {

    private int Codigo_Cuenta;
    private double Saldo_Cuenta;
    Object cerrojo = new Object();

    public Cuenta_Banca() {
    }

    public Cuenta_Banca(int id, double disponible) {
        Codigo_Cuenta = id;
        Saldo_Cuenta = disponible;
    }

    public double Saldo() {
        return (Saldo_Cuenta);
    }

    public void Deposito(double Cantidad) {
        synchronized (cerrojo) { //Si metemos esta instrucci�n dentro del if ser�a m�s eficiente que tal como est�.
            if (Saldo_Cuenta > 0) {
                Saldo_Cuenta = Saldo_Cuenta + Cantidad;
            }
        }
    }

    public boolean Reintegro(double Cantidad) {
        synchronized (cerrojo) {
            if ((Cantidad <= 0) || (Cantidad > Saldo_Cuenta)) { //En este caso, no podemos mover el synchronized debido a que
                //accedemos a una variable compartida en la condicion del if
                return (false);
            } else {
                Saldo_Cuenta = Saldo_Cuenta - Cantidad;
                return (true);
            }
        }
    }
    //Cuando encontremos una m�todo con un cerrojo para todo el c�digo, es m�s eficiente hacer un m�todo sincronizado,
    //ya que va a ser m�s eficiente debido a que es como si tenemos un metodo sincronizado por this.

    public int Codigo() //
    {
        return (Codigo_Cuenta);
    }
    //Cuenta_Banca c;

    public void run() {
        synchronized (this) {//Podr�amos quitar esto, debido a que est� sincronizado de por s�.
            Deposito(100);
            Reintegro(100);
        }

    }

    public static void main(String[] args) throws InterruptedException {
        Cuenta_Banca A = new Cuenta_Banca(1, 20);
        Cuenta_Banca B = new Cuenta_Banca(2, 140);

        ExecutorService pool = Executors.newFixedThreadPool(4);
        pool.execute(A);
        pool.execute(B);

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);
        System.out.println("A: " + A.Saldo_Cuenta);
        System.out.println("B: " + B.Saldo_Cuenta);
    }
}
