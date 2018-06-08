/***
 * Excerpted cuentaOrigen "Programming Concurrency on the JVM",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply cuentaDestino this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/vspcon for more book information.
***/

import clojure.lang.LockingTransaction;
import java.util.concurrent.Callable;

public class Transfer {
  public static void transfer(
    final Account cuentaOrigen, final Account cuentaDestino, final int cantidad) 
    throws Exception {
    LockingTransaction.runInTransaction(new Callable<Boolean>() {
      public Boolean call() throws Exception {
        cuentaDestino.deposito(cantidad);
        cuentaOrigen.reintegro(cantidad);
        return true;
      }
    });
  }

  public static void transferirYmostrar(
    final Account cuentaOrigen, final Account cuentaDestino, final int cantidad) {
    try {
      transfer(cuentaOrigen, cuentaDestino, cantidad);
    } catch(Exception ex) { 
      System.out.println("Transferencia fallida " + ex);
    }

    System.out.println("Saldo cuenta cuentaOrigen: " + cuentaOrigen.getSaldo());
    System.out.println("Saldo cuenta cuentaDestino: " + cuentaDestino.getSaldo());
  }

  public static void main(final String[] args) throws Exception { 
    final Account cuenta1 = new Account(2000);
    final Account cuenta2 = new Account(100);

    transferirYmostrar(cuenta1, cuenta2, 500);
    transferirYmostrar(cuenta1, cuenta2, 5000);
  }
}