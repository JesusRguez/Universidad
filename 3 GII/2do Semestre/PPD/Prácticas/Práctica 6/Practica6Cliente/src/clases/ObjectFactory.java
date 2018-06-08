
package clases;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the clases package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _AnadirUsuario_QNAME = new QName("http://clases/", "anadirUsuario");
    private final static QName _ListarUsuarios_QNAME = new QName("http://clases/", "listarUsuarios");
    private final static QName _AnadirUsuarioResponse_QNAME = new QName("http://clases/", "anadirUsuarioResponse");
    private final static QName _ListarUsuariosResponse_QNAME = new QName("http://clases/", "listarUsuariosResponse");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: clases
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link AnadirUsuario }
     * 
     */
    public AnadirUsuario createAnadirUsuario() {
        return new AnadirUsuario();
    }

    /**
     * Create an instance of {@link ListarUsuariosResponse }
     * 
     */
    public ListarUsuariosResponse createListarUsuariosResponse() {
        return new ListarUsuariosResponse();
    }

    /**
     * Create an instance of {@link ListarUsuarios }
     * 
     */
    public ListarUsuarios createListarUsuarios() {
        return new ListarUsuarios();
    }

    /**
     * Create an instance of {@link AnadirUsuarioResponse }
     * 
     */
    public AnadirUsuarioResponse createAnadirUsuarioResponse() {
        return new AnadirUsuarioResponse();
    }

    /**
     * Create an instance of {@link Usuario }
     * 
     */
    public Usuario createUsuario() {
        return new Usuario();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link AnadirUsuario }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://clases/", name = "anadirUsuario")
    public JAXBElement<AnadirUsuario> createAnadirUsuario(AnadirUsuario value) {
        return new JAXBElement<AnadirUsuario>(_AnadirUsuario_QNAME, AnadirUsuario.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ListarUsuarios }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://clases/", name = "listarUsuarios")
    public JAXBElement<ListarUsuarios> createListarUsuarios(ListarUsuarios value) {
        return new JAXBElement<ListarUsuarios>(_ListarUsuarios_QNAME, ListarUsuarios.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link AnadirUsuarioResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://clases/", name = "anadirUsuarioResponse")
    public JAXBElement<AnadirUsuarioResponse> createAnadirUsuarioResponse(AnadirUsuarioResponse value) {
        return new JAXBElement<AnadirUsuarioResponse>(_AnadirUsuarioResponse_QNAME, AnadirUsuarioResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ListarUsuariosResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://clases/", name = "listarUsuariosResponse")
    public JAXBElement<ListarUsuariosResponse> createListarUsuariosResponse(ListarUsuariosResponse value) {
        return new JAXBElement<ListarUsuariosResponse>(_ListarUsuariosResponse_QNAME, ListarUsuariosResponse.class, null, value);
    }

}
