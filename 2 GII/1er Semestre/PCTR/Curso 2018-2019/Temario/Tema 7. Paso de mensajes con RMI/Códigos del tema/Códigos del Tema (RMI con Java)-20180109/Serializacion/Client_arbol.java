/**
 * @(#)Client_arbol.java
 *
 *
 * @author Antonio Tomeu
 * @version 1.00 2009/5/21
 */

import java.rmi.*;
import java.rmi.registry.*;

public class Client_arbol
{
  public static void main(String[] args)
    throws Exception
  {
    int niveles = 3;
    Arbol arb = new Arbol (niveles);
    
    IArbol RefObRemoto = 
     (IArbol)Naming.lookup("//localhost/Servidor");

    RefObRemoto.Listado_Remoto (arb, niveles);

  }
}
