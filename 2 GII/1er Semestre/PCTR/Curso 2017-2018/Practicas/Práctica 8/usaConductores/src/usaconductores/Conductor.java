package usaconductores;

/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Conductor {

    private String dni, nombre, apellidos;
    private int puntos;

    /**
     * @param dni DNI del conductor
     * @param nombre Nombre del conductor
     * @param apellidos Apellidos del conductor
     * @param puntos Puntos restantes del conductor
     */
    public Conductor(String dni, String nombre, String apellidos, int puntos) {
        this.dni = dni;
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.puntos = puntos;
    }

    /**
     * @return DNI del conductor
     */
    public String mostrarDni() {
        return dni;
    }

    /**
     * @return nombre del conductor
     */
    public String mostrarNombre() {
        return nombre;
    }

    /**
     * @return apellidos del conductor
     */
    public String mostrarApellidos() {
        return apellidos;
    }

    /**
     * @return puntos restantes del conductor
     */
    public int mostrarPuntos() {
        return puntos;
    }

    /**
     * @param dni Nuevo DNI del conductor
     */
    public void insertarDni(String dni) {
        this.dni = dni;
    }

    /**
     * @param nombre Nuevo nombre del conductor
     */
    public void insertarNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * @param apellidos Nuevos apellidos del conductor
     */
    public void insertarApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    /**
     * @param puntos Puntos restantes del conductor
     */
    public void insertarPuntos(int puntos) {
        this.puntos = puntos;
    }

    public void sumarPunto() {
        puntos++;
    }

    /**
     * @param puntos Cantidad de puntos a quitar
     */
    public void quitarPuntos(int puntos) {
        this.puntos -= puntos;
    }

    public String toString() {
        return dni + " | " + apellidos + ", " + nombre + " | " + puntos + " puntos.";
    }
}
