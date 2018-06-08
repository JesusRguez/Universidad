
public class MisDatos2 {

    String nombre = "Lucia";
    String apellido = "Caro";
    String ciudad = "Jerez de la frontera";
    String ocupacion = "Estudiante";
    int asignaturasAprobadas = 13;
    int asignaturasCursadas = 15;

    int asigSuspensas(int a, int b) {
        return a - b;
    }

    public static void main(String[] args) {
        MisDatos2 datos;
        datos = new MisDatos2();
        System.out.println("Buenas, soy " + datos.nombre + datos.apellido + " vivo en " + datos.ciudad + " y soy " + datos.ocupacion + ". He cursado " + datos.asignaturasCursadas + " y he aprobado " + datos.asignaturasAprobadas + " ");
        System.out.println("Enhorabuena Lucia, has suspendido " + (datos.asignaturasCursadas - datos.asignaturasAprobadas) + ".");
    }
}
