package receptor;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Receptor {
	public static void main( String[] args ) {
			final int MAX_LON=10;
			try { 
				DatagramSocket miSocket=new DatagramSocket(5000);
				byte[] almacen =new byte[MAX_LON];
				DatagramPacket datagrama=new DatagramPacket(almacen,MAX_LON);
				miSocket.receive(datagrama);
				String mensaje =new String(almacen);
				System.out.println(mensaje);
				miSocket.close();
			}//try
			catch(Exception e) { e.printStackTrace();}
	}
}
