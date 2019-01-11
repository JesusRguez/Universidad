/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package biblioteca;

import java.io.*;

public class Libro implements java.io.Serializable{

    String titulo, autor, editorial, isbn;

    public Libro(){}

    public Libro(String t, String a, String e, String i){
        this.titulo = t;
        this.autor = a;
        this.editorial = e;
        this.isbn = i;
    }

    public String getTitulo(){
        return this.titulo;
    }

    public String getAutor(){
        return this.autor;
    }

    public String getEditorial(){
        return this.editorial;
    }

    public String getISBN(){
        return this.isbn;
    }

    public String toString(Libro l){
        return "Título: "+l.getTitulo()+"\nAutor: "+l.getAutor()+"\nEditorial: "+l.getEditorial()+"\nISBN: "+l.getISBN();
    }
}
