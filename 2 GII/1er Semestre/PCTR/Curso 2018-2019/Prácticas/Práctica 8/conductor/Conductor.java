/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package conductor;

public class Conductor{

    private String nombre, apellido1, apellido2, dni;
    private int puntos;

    /**
     * Constructor de la clase Conductor
     * @param nombre    Nombre del conductor
     * @param apellido1 Primer apellido del conductor
     * @param apellido2 Segundo apellido del conductor
     * @param dni       DNI del conductor
     * @param puntos    Puntos del conductor
     */
    public Conductor(String nombre, String apellido1, String apellido2, String dni, int puntos){
        this.nombre = nombre;
        this.apellido1 = apellido1;
        this.apellido2 = apellido2;
        this.dni = dni;
        this.puntos = puntos;
    }

    /**
     * Método para obtener el nombre de un conductor
     * @return Retorna el nombre del conductor
     */
    public String getNombre(){
        return nombre;
    }

    /**
     * Método para establecer el nombre de un conductor
     * @param nombre Nombre del conductor
     */
    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    /**
     * Método para obtener el primer apellido de un conductor
     * @return Retorna el primer apellido del conductor
     */
    public String getApellido1(){
        return apellido1;
    }

    /**
     * Método para establecer el primer apellido de un conductor
     * @param apellido1 Primer apellido del conductor
     */
    public void setApellido1(String apellido1){
        this.apellido1 = apellido1;
    }

    /**
     * Método para obtener el segundo apellido de un conductor
     * @return Retorna el segundo apellido del condcutor
     */
    public String getApellido2(){
        return apellido2;
    }

    /**
     * Método para establecer el segundo apellido de un conductor
     * @param apellido2 Segundo apellido del conductor
     */
    public void setApellido2(String apellido2){
        this.apellido2 = apellido2;
    }

    /**
     * Método para obtener el DNI de un conductor
     * @return Retorna el DNI del conductor
     */
    public String getDni(){
        return dni;
    }

    /**
     * Método para establecer el DNI de un condcutor
     * @param dni DNI del conductor
     */
    public void setDni(String dni){
        this.dni = dni;
    }

    /**
     * Método para obtener los puntos de un conductor
     * @return Retorna los puntos del condcutor
     */
    public int getPuntos(){
        return puntos;
    }

    /**
     * Método para establecer los puntos de un conductor
     * @param puntos Puntos del conductor
     */
    public void setPuntos(int puntos){
        this.puntos = puntos;
    }

    /**
     * Método para sumar puntos a un conductor
     * @param puntos Puntos a sumar al conductor
     */
    public void sumarPuntos(int puntos){
        this.puntos += puntos;
    }

    /**
     * Método para restar puntos a un conductor
     * @param puntos Puntos a restar al conductor
     */
    public void restarPuntos(int puntos){
        this.puntos -= puntos;
    }

    /**
     * Método toString de la clase Conductor
     * @return Retorna un conductor como un String
     */
    public String toString(){
        return "El conductor "+nombre+" "+apellido1+" "+apellido2+" con dni "+dni+" tiene "+puntos+" puntos.";
    }
}
