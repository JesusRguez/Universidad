package emisor;
import java.io.* ; 
import java.net.* ; 

public class Emisor {

	public static void main( String[] args ) {
			final int MAX_LON=20;
			try { 
				InetAddress maquinaReceptora=InetAddress.getByName("localhost");
				String mensaje="Hola mundo";
				
				DatagramSocket miSocket=new DatagramSocket();
				byte[] almacen =mensaje.getBytes();
				DatagramPacket datagrama=new DatagramPacket(almacen,almacen.length,maquinaReceptora,5000);
				miSocket.send(datagrama);
				miSocket.close();
				
				miSocket=new DatagramSocket(4000);
				byte[] almacen2 =new byte[MAX_LON];
				DatagramPacket datagrama2=new DatagramPacket(almacen2,MAX_LON);
				miSocket.receive(datagrama2);
				String respuesta =new String(almacen2);
				System.out.println(respuesta);
				miSocket.close();
			}//try
			catch(Exception e) { e.printStackTrace();}
	}
}
