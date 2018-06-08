package clases;

import javax.jws.WebService;

@WebService(targetNamespace = "http://clases/", portName = "PrincipalPort", serviceName = "PrincipalService")
public class Principal {
	public String mensaje(){
		return "Este es mi primer servicio web";
	}
}
