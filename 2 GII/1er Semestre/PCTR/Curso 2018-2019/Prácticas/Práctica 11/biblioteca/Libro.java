/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package biblioteca;

import java.io.*;

public class Libro implements java.io.Serializable{

    String titulo, autor, editorial, isbn;

    /**
     * Constructor vacío de Libro
     */
    public Libro(){}

    /**
     * Constructor de la clase Libro
     * @param t Título
     * @param a Autor
     * @param e Editorial
     * @param i ISBN
     */
    public Libro(String t, String a, String e, String i){
        this.titulo = t;
        this.autor = a;
        this.editorial = e;
        this.isbn = i;
    }

    /**
     * Método toString de la clase Libro
     * @return Retorna un String con la información del libro
     */
    public String toString(){
        return "Título: "+this.titulo+"\nAutor: "+this.autor+"\nEditorial: "+this.editorial+"\nISBN: "+this.isbn;
    }
}
