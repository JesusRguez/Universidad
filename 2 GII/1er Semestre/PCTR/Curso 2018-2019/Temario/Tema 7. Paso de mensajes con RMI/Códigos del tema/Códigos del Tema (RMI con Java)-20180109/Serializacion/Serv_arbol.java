/**
 * @(#)Serv_arbol.java
 *
 *
 * @author Antonio Tomeu
 * @version 1.00 2009/5/21
 */

import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.net.*;

public class Serv_arbol
  extends UnicastRemoteObject 
    implements IArbol 
{
	
  public Serv_arbol()
  throws RemoteException
  {super();} 
  	
  public void Listado_Remoto (Arbol t, int n) 
  	throws RemoteException
  {
  	
  	for (int i = 0; i < t.nivel; i++)
    System.out.print("  ");
    System.out.println("nodo " + t.id);

    if (t.nivel <= n && t.izq != null)
       Listado_Remoto(t.izq, n);

    if (t.nivel <= n && t.der != null)
       Listado_Remoto(t.der, n);
  }

  
 public static void main(String[] args)
  throws Exception 
{
  Serv_arbol ORemoto = new Serv_arbol();
  Naming.bind("Servidor", ORemoto);
  System.out.println("Servidor Remoto Preparado");
} 

}
