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

    public String toString(){
        return "Título: "+this.titulo+"\nAutor: "+this.autor+"\nEditorial: "+this.editorial+"\nISBN: "+this.isbn;
    }
}
