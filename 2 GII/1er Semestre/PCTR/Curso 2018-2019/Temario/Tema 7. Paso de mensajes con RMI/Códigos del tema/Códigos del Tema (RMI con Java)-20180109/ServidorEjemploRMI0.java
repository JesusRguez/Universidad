/**
 * @(#)ServidorEjemploRMI0.java
 *
 *
 * @author Antonio Tomeu 
 * @version 1.00 2010/5/20
 */
 
 //se importan los paquetes necesarios
 import java.rmi.*;
 import java.rmi.server.*;
 import java.rmi.registry.*;
 import java.net.*;


public class ServidorEjemploRMI0 
{
	public static void main (String args[])
	{
		try {
			  EjemploRMI0 ObjExport = new EjemploRMI0();
			  Naming.rebind("//localhost:3005/miholamundo1", ObjExport);
			  Naming.rebind("//localhost:3005/miholamundo2", ObjExport);
			  Naming.rebind("//localhost:3005/miholamundo3", ObjExport);
			  System.out.println("Servidor Hola Mundo preparado con varios objetos remotos activos...");
			}catch (Exception excr){System.out.println("Error en servidor");}
	}
    
}