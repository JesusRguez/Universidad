/**
 * @author Jesús Rodríguez Heras
 */

package hospital;

import java.util.*;

class Biblioteca{

    public static ArrayList<Paciente> consulta;
    public static Scanner teclado = new Scanner(System.in);

    public Biblioteca() {
        consulta = new ArrayList<Paciente>();
    }

    public void insertarPaciente(){
        Paciente nuevo = new Paciente();
        System.out.println("Introduzca el nombre del paciente:");
        String nombre = teclado.nextLine();
        nuevo.nombre = nombre;
        System.out.println("Introduzca el dni del paciente:");
        String dni = teclado.nextLine();
        nuevo.dni = dni;
        System.out.println("Introduzca la dirección del paciente:");
        String direccion = teclado.nextLine();
        nuevo.direccion = direccion;
        System.out.println("Introduzca el teléfono del paciente:");
        String telefono = teclado.nextLine();
        nuevo.telefono = telefono;
        System.out.println("Introduzca la compañía de seguros del paciente:");
        String compseguros = teclado.nextLine();
        nuevo.compseguros = compseguros;

        consulta.add(nuevo); //Introducimos el paciente en la lista
    }

    public void consultarPaciente(){
        System.out.println("Introduzca el DNI del paciente a buscar:");
        String dni = teclado.nextLine();
        Paciente buscado = new Paciente();
        int i = 0;
        boolean encontrado = false;
        while(i<consulta.size() && encontrado == false){
            buscado = consulta.get(i);
            if (buscado.dni.equals(dni)) {
                System.out.println("Nombre: "+buscado.nombre+"\nDNI: "+buscado.dni+"\nDirección: "+buscado.direccion+"\nTeléfono : "+buscado.telefono+"\nCompañía de seguros: "+buscado.compseguros);
                encontrado = true;
            }
            i++;
        }
        if(encontrado == false){
            System.out.println("Paciente no encontrado.");
        }
    }

    public void borrarPaciente(){
        System.out.println("Introduzca el DNI del paciente a borrar:");
        String dni = teclado.nextLine();
        Paciente buscado= new Paciente();
        int i = 0;
        boolean borrado = false;
        while(i<consulta.size() && borrado == false){
            buscado = consulta.get(i);
            if (buscado.dni.equals(dni)) {
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
            System.out.println("¿Qué desea hacer?\n1. Insertar nuevo paciente\n2. Consultar paciente\n3. Borrar paciente");
            opcion=teclado.nextInt();
            if (opcion < 1 || opcion > 3) {
                System.out.println("Solo hay tres opciones disponibles, por favor, introduzca 1, 2 ó 3.");
            }
        } while (opcion < 1 && opcion > 3);

        switch(opcion){
            case 1: consulta.insertarPaciente();
                break;
            case 2: consulta.consultarPaciente();
                break;
            case 3: consulta.borrarPaciente();
                break;
        }

    }
}
