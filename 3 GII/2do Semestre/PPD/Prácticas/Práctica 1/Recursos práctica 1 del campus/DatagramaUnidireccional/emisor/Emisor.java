package emisor;
import java.io.* ; 
import java.net.* ; 

public class Emisor {

	public static void main( String[] args ) {
			try { 
				InetAddress maquinaReceptora=InetAddress.getByName("localhost");
				String mensaje="Hola mundo";
				
				DatagramSocket miSocket=new DatagramSocket();
				byte[] almacen =mensaje.getBytes();
				DatagramPacket datagrama=new DatagramPacket(almacen,almacen.length,maquinaReceptora,5000);
				miSocket.send(datagrama);
				miSocket.close();
			}//try
			catch(Exception e) { e.printStackTrace();}
	}
}
