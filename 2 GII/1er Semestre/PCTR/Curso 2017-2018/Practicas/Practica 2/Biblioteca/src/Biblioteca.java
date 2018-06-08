
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
import java.util.ArrayList;
import java.util.Scanner;

public class Biblioteca {

    public static ArrayList<Paciente> consulta; //Creamos una lista de consultas
    public static Scanner teclado = new Scanner(System.in);

    public Biblioteca() {
        this.consulta = new ArrayList();
    }

    public void insertarPaciente() {
        Paciente nuevoPaciente = new Paciente(); //Creamos el nuevo paciente que será posteriormente introducido en la lista

        System.out.println("Inroduzca el nombre del paciente:");
        teclado.nextLine();
        String nombre = teclado.nextLine();
        nuevoPaciente.nombre = nombre;
        System.out.println("Introduzca el dni del paciente:");
        String dni = teclado.nextLine();
        nuevoPaciente.dni = dni;
        System.out.println("Introduzca la dirección del paciente:");
        String direccion = teclado.nextLine();
        nuevoPaciente.direccion = direccion;
        System.out.println("Introduzca el teléfono del paciente:");
        String telefono = teclado.nextLine();
        nuevoPaciente.telefono = telefono;
        System.out.println("Introduzca la compañía de seguros del nuevo paciente:");
        String compañiaSeguro = teclado.nextLine();
        nuevoPaciente.direccion = compañiaSeguro;
        System.out.println("Introduzca el sexo del paciente:");
        String sexo = teclado.nextLine();
        nuevoPaciente.sexo = sexo;
        System.out.println("Introduzca la edad del paciente:");
        int edad = teclado.nextInt();
        nuevoPaciente.edad = edad;
        System.out.println("Introduzca en numero de la seguridad social del paciente:");
        int NSS = teclado.nextInt();
        nuevoPaciente.NSS = NSS;

        consulta.add(nuevoPaciente); //Introducimos un nuevo paciente en la lista
    }

    public void consultarPaciente() {
        System.out.println("Introduzca el dni del paciente:");
        String dni = teclado.nextLine();
        Paciente buscado = new Paciente();
        int i = 0;
        boolean flag = false;
        while (i < consulta.size() && flag == false) {
            buscado = consulta.get(i); //Obtenemos los pacientes de la lista
            if (buscado.dni.equals(dni)) {  //Si los dni coinciden, hemos encontrado el paciente y lo mostramos en pantalla
                System.out.println(buscado.nombre + buscado.dni + buscado.telefono + buscado.direccion + buscado.compañiaSeguros + buscado.sexo + buscado.edad + buscado.NSS);
                flag = true;
            }
            i++;
        }
        if (flag == false) { //Si no hemos encontrado ningún paciente, aparece este mensaje en pantalla
            System.out.println("Paciente no encontrado.");
        }
    }

    public void borrarPaciente() {
        System.out.println("Introduzca el dni del paciente que desea borrar:");
        String dni = teclado.nextLine();
        Paciente buscado = new Paciente();
        int i = 0;
        boolean borrado = false;
        while (i < consulta.size() && borrado == false) {
            buscado = consulta.get(i); //obtenemos los pacientes de la lista
            if (buscado.dni.equals(dni)) {  //Si los dni coinciden, hemos encontrado el paciente
                consulta.remove(i); //Borramos al paciente de la lista
                borrado = true;
            }
            i++;
        }
        if (borrado == true) { //Si la bandera "borrado" está en true, es que se ha borrado el paciente correctaente
            System.out.println("Paciente borrado.");
        } else {    //En caso contrario, no se ha encontrado el paciente
            System.out.println("Paciente no econtrado.");
        }
    }

    public static void main(String[] args) {
        int opcion;

        Biblioteca consulta = new Biblioteca();

        do {
            System.out.println("¿Qué desea hacer?\n1.) Insertar nuevo paciente.\n2.) Consultar paciente.\n3.) Borrar paciente");
            opcion = teclado.nextInt();
        } while (1 < opcion && opcion > 3); //Con esta condición verificamos que el usuario no se sale del rango de opciones a elegir

        switch (opcion) {
            case 1:
                consulta.insertarPaciente();
                break;
            case 2:
                consulta.consultarPaciente();
                break;
            case 3:
                consulta.borrarPaciente();
                break;
        }
    }
}
