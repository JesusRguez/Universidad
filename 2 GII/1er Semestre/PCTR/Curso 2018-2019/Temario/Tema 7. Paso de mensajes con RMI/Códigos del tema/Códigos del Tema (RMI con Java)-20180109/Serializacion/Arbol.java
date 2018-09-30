/**
 * @(#)Arbol.java
 *
 *
 * @author El Pupas
 * @version 1.00 2009/5/21
 */


import java.io.*;

public class Arbol 
	implements java.io.Serializable 
{
  public Arbol izq;
  public Arbol der;
  public int id;
  public int nivel;
  private static int cont = 0;
  
  public Arbol(int l) {
    id = cont++;
    nivel = l;
    if (l > 0) {
       izq = new Arbol(l-1);
       der = new Arbol(l-1);
    }
  }
} 