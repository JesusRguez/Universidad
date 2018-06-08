package receptor;

import java.io.* ;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Receptor {
	public static void main( String[] args ) {
			final int MAX_LON=20;
			try { 
				DatagramSocket miSocket=new DatagramSocket(5000);
				byte[] almacen =new byte[MAX_LON];
				DatagramPacket datagrama=new DatagramPacket(almacen,MAX_LON);
				miSocket.receive(datagrama);
				String mensaje =new String(almacen);
				System.out.println(mensaje);
				miSocket.close();
				
				InetAddress maquinaReceptora=InetAddress.getByName("localhost");
				String respuesta = "Hola persona";
				miSocket=new DatagramSocket();
				byte[] almacen2 =respuesta.getBytes();
				DatagramPacket datagrama2=new DatagramPacket(almacen2,almacen2.length,maquinaReceptora,4000);
				miSocket.send(datagrama2);
				miSocket.close();
			}//try
			catch(Exception e) { e.printStackTrace();}
	}
}
