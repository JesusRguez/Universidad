
import java.io.Serializable;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Libro implements Serializable {

    public String ISBN, titulo, autor;
    public boolean reservado;

    public Libro(String ISBN, String titulo, String autor, boolean reservado) {
        this.ISBN = ISBN;
        this.titulo = titulo;
        this.autor = autor;
        this.reservado = reservado;
    }

}
