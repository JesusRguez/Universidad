/**Ejemplo de implementacion de un cliente para RMI
 * @author Antonio Tomeu
 */
import java.rmi.*;
import java.rmi.registry.*;

public class ClienteEjemploRMI0
{
	public static void main(String[] args)
	  throws Exception
	{
			
		//En esta ocasion trabajamos sin gestor de seguridad
		//System.setSecurityManager(new RMISecurityManager());
		
		//Se obtiene una referencia a la interfaz del objeto remoto
		//SIEMPRE debe convertirse el retorno del metodo Naming.lookup
		//a un objeto de interfaz remoto
		
		IEjemploRMI0 RefObRemoto = 
		  (IEjemploRMI0)Naming.lookup("//localhost:3005/miholamundo2");
		  	
		 System.out.println(RefObRemoto.Hola_Mundo());	
		 		
	}	
}	