/**
* Programa en Java que escribe mis datos junto con las asignaturas que he suspendido en la pantalla.
*
* @author Jesús Rodríguez Heras
* @version 1.0
*/
public class MisDatos
{
    //Declaración de atributos
    String nombre = "Jesus";
    String apellidos = "Rodriguez Heras";
    String ciudad = "Jerez de la Frontera";
    String ocupacion = "Estudiante";
    int edad = 20;
    int asignaturasaprobadas = 16;
    int asignaturascursadas = 18;
    
    //Declaración de métodos
    int asignaturassuspensas(int cursadas, int aprobadas)
    {
        return cursadas-aprobadas;
    }
    
    public static void main (String[] args)
    {
        //Declaración de variables del método main
        MisDatos datos;
        datos = new MisDatos();
        int suspensas;
        
        //Sentencias de ejecución del método main
        suspensas=datos.asignaturassuspensas(datos.asignaturascursadas, datos.asignaturasaprobadas);
        System.out.println("Me llamo " + datos.nombre + " " + datos.apellidos + " y tengo " + datos.edad +" años.");
        System.out.println("Vivo en " + datos.ciudad + " y soy " + datos.ocupacion + ".");
        System.out.println("He cursado " + datos.asignaturascursadas + " asignaturas y he aprobado " + datos.asignaturasaprobadas + " asignaturas. Por lo tanto, he suspendido " + suspensas + " asignaturas.");        
    }
}
