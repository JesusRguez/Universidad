package clases;

import java.net.MalformedURLException;
import java.net.URL;
import javax.xml.namespace.QName;
import javax.xml.ws.WebEndpoint;
import javax.xml.ws.WebServiceClient;
import javax.xml.ws.WebServiceFeature;
import javax.xml.ws.Service;

/**
 * This class was generated by Apache CXF 2.7.18
 * 2018-04-13T13:17:32.846+02:00
 * Generated source version: 2.7.18
 * 
 */
@WebServiceClient(name = "UsuariosServidorService", 
                  wsdlLocation = "file:/root/eclipse-workspacePPD/Practica6/WebContent/wsdl/usuariosservidor.wsdl",
                  targetNamespace = "http://clases/") 
public class UsuariosServidorService extends Service {

    public final static URL WSDL_LOCATION;

    public final static QName SERVICE = new QName("http://clases/", "UsuariosServidorService");
    public final static QName UsuariosServidorPort = new QName("http://clases/", "UsuariosServidorPort");
    static {
        URL url = null;
        try {
            url = new URL("file:/root/eclipse-workspacePPD/Practica6/WebContent/wsdl/usuariosservidor.wsdl");
        } catch (MalformedURLException e) {
            java.util.logging.Logger.getLogger(UsuariosServidorService.class.getName())
                .log(java.util.logging.Level.INFO, 
                     "Can not initialize the default wsdl from {0}", "file:/root/eclipse-workspacePPD/Practica6/WebContent/wsdl/usuariosservidor.wsdl");
        }
        WSDL_LOCATION = url;
    }

    public UsuariosServidorService(URL wsdlLocation) {
        super(wsdlLocation, SERVICE);
    }

    public UsuariosServidorService(URL wsdlLocation, QName serviceName) {
        super(wsdlLocation, serviceName);
    }

    public UsuariosServidorService() {
        super(WSDL_LOCATION, SERVICE);
    }
    
    //This constructor requires JAX-WS API 2.2. You will need to endorse the 2.2
    //API jar or re-run wsdl2java with "-frontend jaxws21" to generate JAX-WS 2.1
    //compliant code instead.
    public UsuariosServidorService(WebServiceFeature ... features) {
        super(WSDL_LOCATION, SERVICE, features);
    }

    //This constructor requires JAX-WS API 2.2. You will need to endorse the 2.2
    //API jar or re-run wsdl2java with "-frontend jaxws21" to generate JAX-WS 2.1
    //compliant code instead.
    public UsuariosServidorService(URL wsdlLocation, WebServiceFeature ... features) {
        super(wsdlLocation, SERVICE, features);
    }

    //This constructor requires JAX-WS API 2.2. You will need to endorse the 2.2
    //API jar or re-run wsdl2java with "-frontend jaxws21" to generate JAX-WS 2.1
    //compliant code instead.
    public UsuariosServidorService(URL wsdlLocation, QName serviceName, WebServiceFeature ... features) {
        super(wsdlLocation, serviceName, features);
    }

    /**
     *
     * @return
     *     returns UsuariosServidor
     */
    @WebEndpoint(name = "UsuariosServidorPort")
    public UsuariosServidor getUsuariosServidorPort() {
        return super.getPort(UsuariosServidorPort, UsuariosServidor.class);
    }

    /**
     * 
     * @param features
     *     A list of {@link javax.xml.ws.WebServiceFeature} to configure on the proxy.  Supported features not in the <code>features</code> parameter will have their default values.
     * @return
     *     returns UsuariosServidor
     */
    @WebEndpoint(name = "UsuariosServidorPort")
    public UsuariosServidor getUsuariosServidorPort(WebServiceFeature... features) {
        return super.getPort(UsuariosServidorPort, UsuariosServidor.class, features);
    }

}
