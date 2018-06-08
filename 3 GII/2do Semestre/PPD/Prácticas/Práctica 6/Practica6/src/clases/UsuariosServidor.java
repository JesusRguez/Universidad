package clases;

import java.util.ArrayList;

import javax.jws.WebService;

@WebService(targetNamespace = "http://clases/", portName = "UsuariosServidorPort", serviceName = "UsuariosServidorService")
public class UsuariosServidor {
	
	private ArrayList<Usuario> lista = new ArrayList<Usuario>();

	public void anadirUsuario(Usuario u) {
		lista.add(u);
	}
	
	public ArrayList<Usuario> listarUsuarios(){
		return lista;
	}	
}
