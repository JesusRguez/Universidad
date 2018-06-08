
package clases;

/**
 * Please modify this class to meet your needs
 * This class is not complete
 */

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import javax.xml.namespace.QName;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.ws.RequestWrapper;
import javax.xml.ws.ResponseWrapper;

/**
 * This class was generated by Apache CXF 2.7.18
 * 2018-04-13T13:17:32.760+02:00
 * Generated source version: 2.7.18
 * 
 */
public final class UsuariosServidor_UsuariosServidorPort_Client {

    private static final QName SERVICE_NAME = new QName("http://clases/", "UsuariosServidorService");

    private UsuariosServidor_UsuariosServidorPort_Client() {
    }

    public static void main(String args[]) throws java.lang.Exception {
        URL wsdlURL = UsuariosServidorService.WSDL_LOCATION;
        if (args.length > 0 && args[0] != null && !"".equals(args[0])) { 
            File wsdlFile = new File(args[0]);
            try {
                if (wsdlFile.exists()) {
                    wsdlURL = wsdlFile.toURI().toURL();
                } else {
                    wsdlURL = new URL(args[0]);
                }
            } catch (MalformedURLException e) {
                e.printStackTrace();
            }
        }
      
        UsuariosServidorService ss = new UsuariosServidorService(wsdlURL, SERVICE_NAME);
        UsuariosServidor port = ss.getUsuariosServidorPort();  
        
        {
        System.out.println("Invoking anadirUsuario...");
        clases.Usuario _anadirUsuario_arg0 = new clases.Usuario();
        _anadirUsuario_arg0.setApellido1("Rodriguez");
        _anadirUsuario_arg0.setApellido2("Heras");
        _anadirUsuario_arg0.setCodigoPostal(11406);
        _anadirUsuario_arg0.setDireccion("Barriada La Teja, Calle Canal N18");
        _anadirUsuario_arg0.setDni("32088516C");
        _anadirUsuario_arg0.setEdad(21);
        _anadirUsuario_arg0.setNombre("Jesus");
        _anadirUsuario_arg0.setTelefono(628576107);
        port.anadirUsuario(_anadirUsuario_arg0);


        }
        {
        System.out.println("Invoking listarUsuarios...");
        java.util.List<clases.Usuario> _listarUsuarios__return = port.listarUsuarios();
        
        //System.out.println("listarUsuarios.result=" + _listarUsuarios__return);

        System.out.println("Estos son los usuarios presentes en el sistema:");
        
        for(int i=0; i<_listarUsuarios__return.size();i++) {
        	System.out.println(_listarUsuarios__return.get(i).nombre+" "+_listarUsuarios__return.get(i).apellido1+" "+_listarUsuarios__return.get(i).apellido2+" con dni "+_listarUsuarios__return.get(i).dni+" tiene "+_listarUsuarios__return.get(i).edad+" años y vive en "+_listarUsuarios__return.get(i).direccion+" con codigo postal "+_listarUsuarios__return.get(i).codigoPostal+" y número de teléfono "+_listarUsuarios__return.get(i).telefono+"\n");
        }

        }

        System.exit(0);
    }

}
