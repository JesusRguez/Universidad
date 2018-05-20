#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED

//Cabecera: void mostrar_menu_admin();
//Precondici�n:
//Postcondici�n:
void mostrar_menu_admin();

//Cabecera: static void gestionar_Usuarios(usuarios **,int *);
//Precondici�n: las variables v_usuarios y n_act_usuarios deben de estar previamente inicializadas.
//Postcondici�n: esta funci�n muestra los usuarios existentes en el sistema, permite modificar usuarios existentes, a�adir nuevos usuarios y eliminar usuarios existentes.
static void gestionar_Usuarios(usuarios **,int *);

//Cabecera: static void gestionar_Alumnos(alumnos **,int *);
//Precondici�n: v_alumnos y n_act_alumnos son variables existentes en el sistema.
//Postcondici�n: permite mostrar los alumnos registrados, eliminarlos del sistema, modificarlos y dar de alta nuevos.
static void gestionar_Alumnos(alumnos **,int *);

//Cabecera: static void eliminarUsuario(usuarios **v_usuarios, int *n_act_usuarios);
//Precondici�n: v_usuarios y n_act_usuarios son variables previamente inicializadas.
//Postcondici�n: elimina un usuario de la base de datos del sistema.
static void eliminarUsuario(usuarios **, int *);
//Cabecera: static void mostrar_Usuarios(usuarios **v_usuarios,int *n_act_usuarios);
//Precondici�n: Las variable v_usuarios y n_usuario debe estar inicializadas.
//Postcondici�n: muestra si hay, los nombres de los usuarios existentes en el sistema.
static void mostrar_Usuarios(usuarios *, int );

//Cabecera: static void modifico_Usuarios(usuarios **);
//Precondici�n: v_usuarios es un vector previmente inicializado y declarado.
//Postcondici�n: devuelve el mismo vector con un registro modificado (el que haya elegido el usuario que est� usando el sistema).
static void modifico_Usuarios(usuarios **);

//Cabecera:static void alta_Usuarios(usuarios **v_usuarios);
//Precondici�n: v_alumnos debe ser un vector previamente inicializado.
//Postcondici�n: crea un nuevo usuario en el sistema, es decir, a�ade una posici�n m�s al vector v_alumnos.
static void alta_Usuarios(usuarios **);

//Cabecera: void static mostrar_Alumnos(alumnos *v_alumnos, int n_alumnos);
//Precondici�n: v_alumnos y n_alumnos son variables previamente inicializadas.
//Postcondici�n: muestra los alumnos existentes en el sistema.
static void mostrar_Alumnos(alumnos *, int);

//Cabecera:void static eliminar_Alumno(v_alumnos, n_act_alumnos);
//Precondici�n: v_alumnos y n_act_alumnos son variables previamente inicializadas.
//Postcondici�n: v_alumnos tiene un elemento menos, que ser� aquel que haya seleccionado el usuario, es decir, el sistema tendr�a un alumno menos.
static void eliminar_Alumno(alumnos **, int *);

//Cabecera: static void modificar_Alumnos(alumnos **);
//Precondici�n: v_alumnos debe ser un vector previamente inicialiado.
//Postcondici�n: modifica un alumno ya existente en el sistema, as� como todos sus subcampos.
static void modificar_Alumnos(alumnos **);

//static void gestionar_matriculas_alumnos( alumnos *v_alumnos,materias *v_materias, matriculas *v_matriculas);
//Precondici�n:el usuario debe elegir la opcion de gestionar matriculas para que se ejecute la funcion.
//Postcondici�n:muestra un menu que permite al usuario a su elecci�n, dar de alta, modificar, mostrar y eliminar matriculas del sistema.
static void gestionar_matriculas_alumnos( alumnos *v_alumnos,materias *v_materias, matriculas *v_matriculas);


//static void alta_matricula_alumno();
//Precondici�n:el usuario debe elegir la opcion de dar de alta una matricula para que se ejecute la funcion.
//Postcondici�n: una nueva matricula se almacena en el sistema, con los datos correspondientes.
static void alta_matricula_alumno();

//static void eliminar_matricula_alumno();
//Precondici�n:el usuario debe elegir la opcion de eliminar una matricula para que se ejecute la funcion.
//Postcondici�n:se elimina del sistema la matricula del alumno que haya elegido el usuario.
static void eliminar_matricula_alumno();

//static void modificar_matricula_alumno();
//Precondici�n:el usuario debe elegir la opcion de modificar una matricula para que se ejecute la funcion.
//Postcondici�n: los campos seleccionados por el usuario, son modificados con la informaci�n que haya introducido �ste, y posteriormente, la informaci�n es almacenada en el sistema.
static void modificar_matricula_alumno();

//mostrar_matriculas_alumno();
//Precondici�n: el usuario debe elegir la opcion de mostrar matriculas para que se ejecute la funcion.
//Postcondicion: se muestran en pantalla todas las matriculas existentes ademas de todas las materias del sistema.
static void mostrar_matriculas_alumno();

//Cabecera; static void alta_Alumno(alumnos **v_alumnos);
//Precondici�n: v_alumnos debe de ser un vector previamente inicializado y declarado.
//Postcondici�n: devuelve el mismo vector pero con una posici�n m�s.
static void alta_Alumno(alumnos **v_alumnos);

//Cabecera: static void gestionar_Materias();
//Precondici�n: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondici�n: muestra el men� de seleccion de opciones de edici�n de materias
static void gestionar_Materias();

//Cabecera: static void anadir_Materia();
//Precondici�n: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondici�n: a�ade la materia proporcionada por el usuario al vector v_materias, incrementa el numero de materias en 1
static void anadir_Materia();

//Cabecera: static void eliminar_Materia();
//Precondici�n: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondici�n: elimina la materia indicada por el usuario del vector v_materias, decrementa el numero de materias en 1
static void eliminar_Materia();

//Cabecera: static void modificar_Materia();
//Precondici�n: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondici�n: modifica uno o varios de los campos de una materia indicada por el usuario del vector v_materias
static void modificar_Materia();

//Cabecera: static void mostrar_Materias();
//Precondici�n: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondici�n: muestra las materias existentes en el sistema del vector v_materias
static void mostrar_Materias();

//Cabecera: static void gestionar_Horarios();
//Precondici�n: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondici�n: muestra el men� de seleccion de opciones de edici�n de horarios
static void gestionar_Horarios();

//Cabecera: static void anadir_Horario();
//Precondici�n: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondici�n: a�ade la clase del horario proporcionada por el usuario al vector v_horarios, incrementa el numero de horarios en 1
static void anadir_Horario();

//Cabecera: static void eliminar_Horario();
//Precondici�n: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondici�n: elimina la clase del horario indicada por el usuario del vector v_horarios, decrementa el numero de horarios en 1
static void eliminar_Horario();

//Cabecera: static void modificar_Horario();
//Precondici�n: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondici�n: modifica uno o varios de los campos de una clase del horario indicada por el usuario del vector v_horarios
static void modificar_Horario();

//Cabecera: static void mostrar_Horarios();
//Precondici�n: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondici�n: muestra las clases del horario existentes en el sistema del vector v_horarios
static void mostrar_Horarios();

#endif // ADMINISTRADOR_H_INCLUDED
