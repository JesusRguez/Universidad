
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

    private final static QName _Mensaje_QNAME = new QName("http://clases/", "mensaje");
    private final static QName _MensajeResponse_QNAME = new QName("http://clases/", "mensajeResponse");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: clases
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link MensajeResponse }
     * 
     */
    public MensajeResponse createMensajeResponse() {
        return new MensajeResponse();
    }

    /**
     * Create an instance of {@link Mensaje }
     * 
     */
    public Mensaje createMensaje() {
        return new Mensaje();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Mensaje }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://clases/", name = "mensaje")
    public JAXBElement<Mensaje> createMensaje(Mensaje value) {
        return new JAXBElement<Mensaje>(_Mensaje_QNAME, Mensaje.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link MensajeResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://clases/", name = "mensajeResponse")
    public JAXBElement<MensajeResponse> createMensajeResponse(MensajeResponse value) {
        return new JAXBElement<MensajeResponse>(_MensajeResponse_QNAME, MensajeResponse.class, null, value);
    }

}
