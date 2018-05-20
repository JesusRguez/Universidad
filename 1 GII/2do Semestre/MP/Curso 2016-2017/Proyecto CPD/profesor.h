#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED
typedef struct{
int id;
char grupo[11];
char materia[5];
char hora[2];
}info_profesor; //Estructura auxiliar para almacenar los grupos del profesor en el dia concreto
info_profesor *v_profesorado;
int n_asignatura; //N de grupos del profesor.

//Cabecera: static int menu_grupos();
//Precondición: no necesita valores de entrada.
//Poscondición: Muestra el menu de los grupos del profesor.
    static int menu_grupos();
//Cabecera: static int menu_alumno();
//Precondición: no necesita valores de entrada.
//Poscondición: Muestra el menu que aparecera por pantalla al seleccionar un alumno.
    static int menu_alumno();
//Cabecera: static int mostrar_grupos(materias *, int profesor_id);
//Precondición: como entrada necesita un puntero de tipo materias y un entero que representa el id del profesor.
//Poscondición: Muestra todos los grupos de un profesor en concreto en un día en concreto. y devuelve la opcion elegida en el menu.
    static int mostrar_grupos(materias *, int profesor_id);
//Cabecera:  static void profesor_alumnos(int opcion);
//Precondición: Como entrada necesita un entero que representa el grupo elegido.
//Poscondición: Muestra los alumnos de un grupo en concreto. y muestra el menu.
    static void profesor_alumnos(int opcion);
//Cabecera: static void datos_alumno(int alumno, int opcion);
//Precondición: Como entrada necesita un entero que representa el id del alumno elegido y un entero que representa el grupo elegido.
//Poscondición: Muestra los datos del alumno y su modificacion.
    static void datos_alumno(int alumno, int opcion);
//Cabecera: static void calificaciones_alumnos(int alumno,int opcion);
//Precondición: Como entrada necesita un entero que representa el id del alumno elegido y un entero que representa el grupo elegido.
//Poscondición: Muestra las calificaciones de los alumnos y permite su modificacion, eliminacion y creacion de calificaciones.
    static void calificaciones_alumnos(int alumno,int opcion);
//Cabecera: static void mostrar_faltas(int alumno, int opcion);
//Precondición: Como entrada necesita un entero que representa el id del alumno elegido y un entero que representa el grupo elegido.
//Poscondición: Muestra las faltas de un alumno en concreto.
    static void mostrar_faltas(int alumno, int opcion);
//Cabecera: static void faltas_alumnos(int alumno, int opcion);
//Precondición: Como entrada necesita un entero que representa el id del alumno elegido y un entero que representa el grupo elegido.
//Poscondición: permite ejecutar las opciones de modificacion, eliminacion y creacion de faltas.
    static void faltas_alumnos(int alumno, int opcion);
//Cabecera: void modulo_profesor();
//Precondición: No necesita datos de entrada
//Poscondición: Integra todas las funciones de este modulo.
    void modulo_profesor();

#endif // PROFESOR_H_INCLUDED
