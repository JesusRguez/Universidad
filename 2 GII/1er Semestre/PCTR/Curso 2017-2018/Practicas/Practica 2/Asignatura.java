
import java.util.Scanner;

/**
 * Programa que usa administra asignaturas.
 *
 * @author Jes�s Rodr�guez Heras
 * @version 1.0
 */
public class Asignatura {

    private String nombre, departamento, tipo;
    private int codigo, numeroCreditos, curso, cuatrimestre;

    public String Nombre() {
        return nombre;
    }

    public String Departamento() {
        return departamento;
    }

    public String Tipo() {
        return tipo;
    }

    public int Codigo() {
        return codigo;
    }

    public int NumeroCreditos() {
        return numeroCreditos;
    }

    public int Curso() {
        return curso;
    }

    public int Cuatrimestre() {
        return cuatrimestre;
    }

    public void CambiarCodigo(int nuevoCodigo) {
        codigo = nuevoCodigo;
    }

    public void CambiarNumeroCreditos(int nuevoNumeroCreditos) {
        numeroCreditos = nuevoNumeroCreditos;
    }

    public void CambiarNombre(String nuevoNombre) {
        nombre = nuevoNombre;
    }

    public void CambiarDepartamento(String nuevoDepartamento) {
        departamento = nuevoDepartamento;
    }

    public void CambiarTipo(String nuevoTipo) {
        tipo = nuevoTipo;
    }

    public void CambiarCurso(int nuevoCurso) {
        curso = nuevoCurso;
    }

    public void CambiarCuatrimestre(int nuevoCuatrimestre) {
        cuatrimestre = nuevoCuatrimestre;
    }

    public static void main(String args[]) {
        Scanner teclado = new Scanner(System.in);
        Asignatura a = new Asignatura();
        System.out.println("�Qu� desea hacer?\n1.) Ver asignaturas\n2.)Modificar asignaturas");
        int opcion = teclado.nextInt();

        switch (opcion) {
            case 1:
                System.out.println(a.nombre + a.codigo + a.cuatrimestre + a.curso + a.departamento + a.numeroCreditos + a.tipo);
                break;
            case 2:

                System.out.println("�Qu� desea modificar?\n1.)Nombre\n2.)C�digo\n3.)Cuatrimestre\n4.)Curso\n5.)Departamento\n6.)Numero de cr�ditos\n7.Tipo");
                int seleccion = teclado.nextInt();
                switch (seleccion) {
                    case 1:
                        System.out.println("Escribe el nuevo nombre:");
                        String nuevoNombre = teclado.nextLine();
                        a.CambiarNombre(nuevoNombre);
                        break;
                    case 2:
                        System.out.println("Escribe el nuevo c�digo:");
                        int nuevoCodigo = teclado.nextInt();
                        a.CambiarCodigo(nuevoCodigo);
                        break;
                    case 3:
                        System.out.println("Escribe el nuevo cuatrimestre:");
                        int nuevoCuatrimestre = teclado.nextInt();
                        a.CambiarCuatrimestre(nuevoCuatrimestre);
                        break;
                    case 4:
                        System.out.println("Escribe el nuevo curso:");
                        int nuevoCurso = teclado.nextInt();
                        a.CambiarCurso(nuevoCurso);
                        break;
                    case 5:
                        System.out.println("Escribe el nuevo departamento:");
                        String nuevoDepartamento = teclado.nextLine();
                        a.CambiarDepartamento(nuevoDepartamento);
                        break;
                    case 6:
                        System.out.println("Escribe el nuevo n�mero de cr�ditos:");
                        int nuevoNumeroCreditos = teclado.nextInt();
                        a.CambiarNumeroCreditos(nuevoNumeroCreditos);
                        break;
                    case 7:
                        System.out.println("Escribe el nuevo tipo:");
                        String nuevoTipo = teclado.nextLine();
                        a.CambiarTipo(nuevoTipo);
                        break;
                }
                break;
            default:
                System.out.println("Vuelva a ejecutar el programa para seleccionar una opci�n correcta.");
                break;
        }
    }
}
