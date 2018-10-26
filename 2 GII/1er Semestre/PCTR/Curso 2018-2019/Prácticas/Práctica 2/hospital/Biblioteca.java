/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package hospital;

import java.util.*;

public class Biblioteca{

    public static ArrayList<Paciente> consulta;
    public static Scanner teclado = new Scanner(System.in);

    /**
     * Constructor de Biblioteca
     */
    public Biblioteca() {
        consulta = new ArrayList<Paciente>();
    }

    /**
     * Método para insertar pacientes
     */
    public void insertarPaciente(){
        teclado.nextLine(); //Limpiamos el buffer de entrada
        System.out.println("Introduzca el nombre del paciente:");
        String nombre = teclado.nextLine();
        System.out.println("Introduzca el dni del paciente:");
        String dni = teclado.nextLine();
        System.out.println("Introduzca la dirección del paciente:");
        String direccion = teclado.nextLine();
        System.out.println("Introduzca el teléfono del paciente:");
        int telefono = teclado.nextInt();
        teclado.nextLine();
        System.out.println("Introduzca la aseguradora del paciente:");
        String aseguradora = teclado.nextLine();
        System.out.println("Introduzca el diagnóstico del paciente:");
        String diagnostico = teclado.nextLine();
        System.out.println("Introduzca la edad del paciente:");
        int edad = teclado.nextInt();
        teclado.nextLine();
        System.out.println("Introduzca el sexo del paciente:");
        String sexo = teclado.nextLine();
        System.out.println("Introduzca el número de la seguridad social del paciente:");
        int nss = teclado.nextInt();

        Paciente nuevo = new Paciente(dni, nombre, direccion, telefono, aseguradora, diagnostico, sexo, edad, nss);
        consulta.add(nuevo); //Introducimos el paciente en la lista
    }

    /**
     * Método para consultar pacientes
     */
    public void consultarPaciente(){
        teclado.nextLine();
        System.out.println("Introduzca el DNI del paciente a buscar:");
        String dni = teclado.nextLine();
        Paciente buscado = new Paciente();
        int i = 0;
        boolean encontrado = false;
        while(i<consulta.size() && encontrado == false){
            buscado = consulta.get(i);
            if (buscado.getDNI().equals(dni)) {
                System.out.println("Nombre: "+buscado.getNombre()+"\nDNI: "+buscado.getDNI()+"\nDirección: "+buscado.getDireccion()+"\nTeléfono : "+buscado.getTelefono()+"\nCompañía de seguros: "+buscado.getAseguradora()+"\nDiagnóstico: "+buscado.getDiagnostico()+"\nSexo: "+buscado.getSexo()+"\nEdad: "+buscado.getEdad()+"\nNSS: "+buscado.getNSS());
                encontrado = true;
            }
            i++;
        }
        if(encontrado == false){
            System.out.println("Paciente no encontrado.");
        }
    }

    /**
     * Método para borrar pacientes
     */
    public void borrarPaciente(){
        teclado.nextLine();
        System.out.println("Introduzca el DNI del paciente a borrar:");
        String dni = teclado.nextLine();
        Paciente buscado = new Paciente();
        int i = 0;
        boolean borrado = false;
        while(i<consulta.size() && borrado == false){
            buscado = consulta.get(i);
            if (buscado.getDNI().equals(dni)) {
                consulta.remove(i);
                System.out.println("Paciente borrado.");
                borrado = true;
            }
            i++;
        }
        if (borrado == false) {
            System.out.println("Paciente no encontrado y, por lo tanto, no borrado.");
        }
    }

    public static void main(String[] args) {
        Biblioteca consulta = new Biblioteca();
        int opcion;
        do {
            System.out.println("¿Qué desea hacer?\n1. Insertar nuevo paciente\n2. Consultar paciente\n3. Borrar paciente\n4. Salir");
            opcion=teclado.nextInt();
            switch(opcion){
                case 1: consulta.insertarPaciente();
                    break;
                case 2: consulta.consultarPaciente();
                    break;
                case 3: consulta.borrarPaciente();
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay cuatro opciones, por favor, seleccione 1, 2, 3 ó 4.");
            }
        } while (opcion != 4);
    }
}
