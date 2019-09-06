package punto;

import java.io.*;

public class punto implements java.io.Serializable {

    public float x, y;

    /**
     * Constructor de punto
     * @param x Coordenada x del punto
     * @param y Coordenada y del punto
     */
    public punto(float x, float y){
        this.x = x;
        this.y = y;
    }

    /**
     * Método x
     * @return Devuelve la coordenada x del punto
     */
    public float x(){
        return this.x;
    }

    /**
     * Método x
     * @param x Establece el valor de la coordenada X
     */
    public void x(float x){
        this.x = x;
    }

    /**
     * Método y
     * @return Devuelve la coordenada y del punto
     */
    public float y(){
        return this.y;
    }

    /**
     * Método y
     * @param y Establece el vlaor de la coorednada Y
     */
    public void y(float y){
        this.y = y;
    }
}
