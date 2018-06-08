/**
 * @(#)IArbol.java
 *
 *
 * @author Antonio Tomeu
 * @version 1.00 2009/5/21
 */

import java.rmi.*;
public interface IArbol 
	extends Remote
{
   public void Listado_Remoto (Arbol t, int n) throws RemoteException; 
     
}