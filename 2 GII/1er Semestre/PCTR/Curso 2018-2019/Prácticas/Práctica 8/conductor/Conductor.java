/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package conductor;

public class Conductor{

    private String nombre, apellido1, apellido2, dni;
    private int puntos;

    public Conductor(String nombre, String apellido1, String apellido2, String dni, int puntos){
        this.nombre = nombre;
        this.apellido1 = apellido1;
        this.apellido2 = apellido2;
        this.dni = dni;
        this.puntos = puntos;
    }

    public String getNombre(){
        return nombre;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public String getApellido1(){
        return apellido1;
    }

    public void setApellido1(String apellido1){
        this.apellido1 = apellido1;
    }

    public String getApellido2(){
        return apellido2;
    }

    public void setApellido2(String apellido2){
        this.apellido2 = apellido2;
    }

    public String getDni(){
        return dni;
    }

    public void setDni(String dni){
        this.dni = dni;
    }

    public int getPuntos(){
        return puntos;
    }

    public void setPuntos(int puntos){
        this.puntos = puntos;
    }

    public void sumarPuntos(int puntos){
        this.puntos += puntos;
    }

    public void restarPuntos(int puntos){
        this.puntos -= puntos;
    }

    public String toString(){
        return "El conductor "+nombre+" "+apellido1+" "+apellido2+" con dni "+dni+" tiene "+puntos+" puntos.";
    }
}
