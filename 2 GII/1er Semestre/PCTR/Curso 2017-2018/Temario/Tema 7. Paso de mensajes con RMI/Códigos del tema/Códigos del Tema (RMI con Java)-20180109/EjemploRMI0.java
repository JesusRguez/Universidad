/**Ejemplo de implementacion del interfaz remoto para  un RMI tipo Hola Mundo
 * @author Antonio Tomeu
 */
 
 //se importan los paquetes necesarios
 import java.rmi.*;
 import java.rmi.server.*;
 
 
 public class EjemploRMI0
   extends UnicastRemoteObject //el servidor debe siempre extender esta clase
     implements IEjemploRMI0   //el servidor debe simpre implementar la interfaz
                               //remota definida con caracter previo
 {
 	public EjemploRMI0()
 		throws RemoteException
 	{
 		super();
 	}		
 	public String Hola_Mundo ()
 	  throws RemoteException
 	{return "Hola Mundo cruel...";}  
 	
 	
}	                              
                               