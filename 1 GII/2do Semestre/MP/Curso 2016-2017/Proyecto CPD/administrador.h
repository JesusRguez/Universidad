#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED

//Cabecera: void mostrar_menu_admin();
//Precondición:
//Postcondición:
void mostrar_menu_admin();

//Cabecera: static void gestionar_Usuarios(usuarios **,int *);
//Precondición: las variables v_usuarios y n_act_usuarios deben de estar previamente inicializadas.
//Postcondición: esta función muestra los usuarios existentes en el sistema, permite modificar usuarios existentes, añadir nuevos usuarios y eliminar usuarios existentes.
static void gestionar_Usuarios(usuarios **,int *);

//Cabecera: static void gestionar_Alumnos(alumnos **,int *);
//Precondición: v_alumnos y n_act_alumnos son variables existentes en el sistema.
//Postcondición: permite mostrar los alumnos registrados, eliminarlos del sistema, modificarlos y dar de alta nuevos.
static void gestionar_Alumnos(alumnos **,int *);

//Cabecera: static void eliminarUsuario(usuarios **v_usuarios, int *n_act_usuarios);
//Precondición: v_usuarios y n_act_usuarios son variables previamente inicializadas.
//Postcondición: elimina un usuario de la base de datos del sistema.
static void eliminarUsuario(usuarios **, int *);
//Cabecera: static void mostrar_Usuarios(usuarios **v_usuarios,int *n_act_usuarios);
//Precondición: Las variable v_usuarios y n_usuario debe estar inicializadas.
//Postcondición: muestra si hay, los nombres de los usuarios existentes en el sistema.
static void mostrar_Usuarios(usuarios *, int );

//Cabecera: static void modifico_Usuarios(usuarios **);
//Precondición: v_usuarios es un vector previmente inicializado y declarado.
//Postcondición: devuelve el mismo vector con un registro modificado (el que haya elegido el usuario que esté usando el sistema).
static void modifico_Usuarios(usuarios **);

//Cabecera:static void alta_Usuarios(usuarios **v_usuarios);
//Precondición: v_alumnos debe ser un vector previamente inicializado.
//Postcondición: crea un nuevo usuario en el sistema, es decir, añade una posición más al vector v_alumnos.
static void alta_Usuarios(usuarios **);

//Cabecera: void static mostrar_Alumnos(alumnos *v_alumnos, int n_alumnos);
//Precondición: v_alumnos y n_alumnos son variables previamente inicializadas.
//Postcondición: muestra los alumnos existentes en el sistema.
static void mostrar_Alumnos(alumnos *, int);

//Cabecera:void static eliminar_Alumno(v_alumnos, n_act_alumnos);
//Precondición: v_alumnos y n_act_alumnos son variables previamente inicializadas.
//Postcondición: v_alumnos tiene un elemento menos, que será aquel que haya seleccionado el usuario, es decir, el sistema tendría un alumno menos.
static void eliminar_Alumno(alumnos **, int *);

//Cabecera: static void modificar_Alumnos(alumnos **);
//Precondición: v_alumnos debe ser un vector previamente inicialiado.
//Postcondición: modifica un alumno ya existente en el sistema, así como todos sus subcampos.
static void modificar_Alumnos(alumnos **);

//static void gestionar_matriculas_alumnos( alumnos *v_alumnos,materias *v_materias, matriculas *v_matriculas);
//Precondición:el usuario debe elegir la opcion de gestionar matriculas para que se ejecute la funcion.
//Postcondición:muestra un menu que permite al usuario a su elección, dar de alta, modificar, mostrar y eliminar matriculas del sistema.
static void gestionar_matriculas_alumnos( alumnos *v_alumnos,materias *v_materias, matriculas *v_matriculas);


//static void alta_matricula_alumno();
//Precondición:el usuario debe elegir la opcion de dar de alta una matricula para que se ejecute la funcion.
//Postcondición: una nueva matricula se almacena en el sistema, con los datos correspondientes.
static void alta_matricula_alumno();

//static void eliminar_matricula_alumno();
//Precondición:el usuario debe elegir la opcion de eliminar una matricula para que se ejecute la funcion.
//Postcondición:se elimina del sistema la matricula del alumno que haya elegido el usuario.
static void eliminar_matricula_alumno();

//static void modificar_matricula_alumno();
//Precondición:el usuario debe elegir la opcion de modificar una matricula para que se ejecute la funcion.
//Postcondición: los campos seleccionados por el usuario, son modificados con la información que haya introducido éste, y posteriormente, la información es almacenada en el sistema.
static void modificar_matricula_alumno();

//mostrar_matriculas_alumno();
//Precondición: el usuario debe elegir la opcion de mostrar matriculas para que se ejecute la funcion.
//Postcondicion: se muestran en pantalla todas las matriculas existentes ademas de todas las materias del sistema.
static void mostrar_matriculas_alumno();

//Cabecera; static void alta_Alumno(alumnos **v_alumnos);
//Precondición: v_alumnos debe de ser un vector previamente inicializado y declarado.
//Postcondición: devuelve el mismo vector pero con una posición más.
static void alta_Alumno(alumnos **v_alumnos);

//Cabecera: static void gestionar_Materias();
//Precondición: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondición: muestra el menú de seleccion de opciones de edición de materias
static void gestionar_Materias();

//Cabecera: static void anadir_Materia();
//Precondición: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondición: añade la materia proporcionada por el usuario al vector v_materias, incrementa el numero de materias en 1
static void anadir_Materia();

//Cabecera: static void eliminar_Materia();
//Precondición: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondición: elimina la materia indicada por el usuario del vector v_materias, decrementa el numero de materias en 1
static void eliminar_Materia();

//Cabecera: static void modificar_Materia();
//Precondición: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondición: modifica uno o varios de los campos de una materia indicada por el usuario del vector v_materias
static void modificar_Materia();

//Cabecera: static void mostrar_Materias();
//Precondición: v_materias y n_act_materias son variables globales previamente inicializadas
//Poscondición: muestra las materias existentes en el sistema del vector v_materias
static void mostrar_Materias();

//Cabecera: static void gestionar_Horarios();
//Precondición: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondición: muestra el menú de seleccion de opciones de edición de horarios
static void gestionar_Horarios();

//Cabecera: static void anadir_Horario();
//Precondición: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondición: añade la clase del horario proporcionada por el usuario al vector v_horarios, incrementa el numero de horarios en 1
static void anadir_Horario();

//Cabecera: static void eliminar_Horario();
//Precondición: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondición: elimina la clase del horario indicada por el usuario del vector v_horarios, decrementa el numero de horarios en 1
static void eliminar_Horario();

//Cabecera: static void modificar_Horario();
//Precondición: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondición: modifica uno o varios de los campos de una clase del horario indicada por el usuario del vector v_horarios
static void modificar_Horario();

//Cabecera: static void mostrar_Horarios();
//Precondición: v_horarios y n_act_horarios son variables globales previamente inicializadas
//Poscondición: muestra las clases del horario existentes en el sistema del vector v_horarios
static void mostrar_Horarios();

#endif // ADMINISTRADOR_H_INCLUDED
