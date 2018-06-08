/**
 * @(#)ObjetoSerializable.java
 *
 *
 * @author El Pupas
 * @version 1.00 2009/5/13
 */

import java.io.*;

public class ObjetoSerializable 
	implements java.io.Serializable 
{
  public ObjetoSerializable izq;
  public ObjetoSerializable der;
  public int id;
  public int nivel;
  private static int cont = 0;
  
  public ObjetoSerializable(int l) {
    id = cont++;
    nivel = l;
    if (l > 0) {
       izq = new ObjetoSerializable(l-1);
       der = new ObjetoSerializable(l-1);
    }
  }
  public void print(int niveles) {
  for (int i = 0; i < nivel; i++)
    System.out.print("  ");
    System.out.println("nodo " + id);

    if (nivel <= niveles && izq != null)
       izq.print(niveles);

    if (nivel <= niveles && der != null)
       der.print(niveles);
  }

  public static void main (String args[]) {

    try {
       
       FileOutputStream Salida = new FileOutputStream("arbolillo.tmp");
       ObjectOutputStream p = new ObjectOutputStream(Salida);
       ObjetoSerializable raiz = new ObjetoSerializable(3);
	   p.writeObject(raiz);
       p.flush();
       Salida.close();
       FileInputStream Entrada = new FileInputStream("arbolillo.tmp");
       ObjectInputStream q = new ObjectInputStream(Entrada);
       ObjetoSerializable otra_raiz = (ObjetoSerializable)q.readObject();
	   otra_raiz.print(3);  // Print out the top 3 levels of the tree
    } catch (Exception ex) {
       ex.printStackTrace();
    }
  }
}
