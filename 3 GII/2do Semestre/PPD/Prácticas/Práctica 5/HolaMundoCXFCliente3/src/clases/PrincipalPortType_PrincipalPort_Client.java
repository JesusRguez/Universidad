
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
import javax.jws.WebResult;
import javax.jws.WebService;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.ws.RequestWrapper;
import javax.xml.ws.ResponseWrapper;

/**
 * This class was generated by Apache CXF 2.7.18
 * 2018-04-10T20:29:49.707+02:00
 * Generated source version: 2.7.18
 * 
 */
public final class PrincipalPortType_PrincipalPort_Client {

    private static final QName SERVICE_NAME = new QName("http://clases/", "Principal");

    private PrincipalPortType_PrincipalPort_Client() {
    }

    public static void main(String args[]) throws java.lang.Exception {
        URL wsdlURL = Principal.WSDL_LOCATION;
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
      
        Principal ss = new Principal(wsdlURL, SERVICE_NAME);
        PrincipalPortType port = ss.getPrincipalPort();  
        
        {
        System.out.println("Invoking mensaje...");
        java.lang.String _mensaje__return = port.mensaje();
        System.out.println("mensaje.result=" + _mensaje__return);


        }

        System.exit(0);
    }

}
