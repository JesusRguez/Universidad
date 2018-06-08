/**Ejemplo del interfaz remoto para implementar un RMI
 * @author Antonio Tomeu
 *Es un servidor remoto básico Hola Mundo.
 */
 
 
 //se importan las clases del paquete rmi 
 import java.rmi.*;
 
 //toda interface remota debe extender la clase Remote
 interface IEjemploRMI0 extends Remote
 {
 	//todo metodo de la interfaz remota debe declarar la excepcion 
 	//RemoteException
 	String Hola_Mundo ()throws RemoteException; 
 	
 }	