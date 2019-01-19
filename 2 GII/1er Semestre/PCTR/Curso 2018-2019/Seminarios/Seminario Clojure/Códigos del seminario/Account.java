/***
 * Excerpted from "Programming Concurrency on the JVM",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/vspcon for more book information.
***/


import clojure.lang.Ref;
import clojure.lang.LockingTransaction;
import java.util.concurrent.Callable;

public class Account {
  final private Ref saldo;

  public Account(final int saldoInicial) throws Exception {
    saldo = new Ref(saldoInicial);
  }

  public int getSaldo() { return (Integer) saldo.deref(); }

  public void deposito(final int cantidad) throws Exception {
    LockingTransaction.runInTransaction(new Callable<Boolean>() {
      public Boolean call()  {
        if(cantidad > 0) {
          final int saldoActual = (Integer) saldo.deref();
          saldo.set(saldoActual + cantidad);
          System.out.println("Deposito de " + cantidad + "... se va a realizar");
          return true;
        } else throw new RuntimeException("Operacion invalida");
      }
    });
  }

  public void reintegro(final int cantidad) throws Exception {
    LockingTransaction.runInTransaction(new Callable<Boolean>() {
      public Boolean call() {
        final int saldoActual = (Integer) saldo.deref();
        if(cantidad > 0 && saldoActual >= cantidad) {
          saldo.set(saldoActual - cantidad);
          return true;
        } else throw new RuntimeException("Operacion invalida");
      }
    });
  }
}
