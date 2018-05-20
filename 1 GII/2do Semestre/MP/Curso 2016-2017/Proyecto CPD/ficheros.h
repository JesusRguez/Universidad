#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FICHEROS_H_INCLUDED
#define FICHEROS_H_INCLUDED

typedef struct{
    char dia[3];
    char mes[3];
    char ano[5];
}fecha;

typedef struct{
    char id_usuario[4];
    char Nomb_usuario[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];
}usuarios;

typedef struct{
    char id_alum[7];
    char Nombre_alum[21];
    char Direc_alum[31];
    char Local_alum[31];
    char Curso[31];
    char Grupo[11];
}alumnos;

typedef struct{
    char id_materia[5];
    char Nombre_materia[51];
    char Abrev_materia[4];
}materias;

typedef struct{
    char id_materia[5];
    char id_alum[7];
}matriculas;

typedef struct{
    fecha Fecha_calif;
    char Descrip_calif[31];
    char id_materia[5];
    char id_alum[7];
    char Valor_calif[3];
}calificaciones;

typedef struct{
    fecha Fecha_falta;
    char Hora_falta[2];
    char Descrip_falta[31];
    char Estado_falta[15];
    char id_alum[7];
}faltas;

typedef struct{
    char id_profesor[4];
    char Dia_clase[2];
    char Hora_clase[2];
    char id_materia[5];
    char Grupo[11];
}horarios;

usuarios *v_usuarios;                   //Vector de tipo usuarios
alumnos *v_alumnos;                     //Vector de tipo alumnos
materias *v_materias;                   //Vector de tipo materias
matriculas *v_matriculas;               //Vector de tipo matriculas
calificaciones *v_calificaciones;       //Vector de tipo calificaciones
faltas *v_faltas;                       //Vector de tipo faltas
horarios *v_horarios;                   //Vector de tipo horarios

FILE *f_usuarios;                       //Puntero al fichero usuarios.txt
FILE *f_alumnos;                        //Puntero al fichero alumnos.txt
FILE *f_materias;                       //Puntero al fichero materias.txt
FILE *f_matriculas;                     //Puntero al fichero matriculas.txt
FILE *f_calificaciones;                 //Puntero al fichero calificaciones.txt
FILE *f_faltas;                         //Puntero al fichero faltas.txt
FILE *f_horarios;                       //Puntero al fichero horarios.txt

//Cabecera: void volcar_memoria();
//Precondición: La función debe ser llamada desde el main
//Postcondición: Abre los ficheros en modo lectura y copia su información en la memoria principal. Luego, cierra los ficheros.
void volcar_memoria();

//Cabecera: void volcar_disco();
//Precondición: La función debe ser llamada desde el main
//Postcondición: Abre los ficheros en modo escritura y copia la información de la memoria principal en ellos. Luego, cierra los ficheros.
void volcar_disco();


//Funciones para el volcado de disco a memoria principal

//Cabecera: static void rellenar_usuarios(FILE*, usuarios **, int *);
//Precondición: El fichero usuarios.txt ha de estar abierto en modo lectura y el vector v_usuarios ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero usuarios.txt en la estructura de datos de la memoria principal y devuelve el número actual de usuarios en el sistema.
static void rellenar_usuarios(FILE*, usuarios **, int *);

//Cabecera: static void rellenar_alumnos(FILE*, alumnos **, int *);
//Precondición: El fichero alumnos.txt ha de estar abierto en modo lectura y el vector v_alumnos ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero alumnos.txt en la estructura de datos de la memoria principal y devuelve el número actual de alumnos en el sistema..
static void rellenar_alumnos(FILE*, alumnos **, int *);

//Cabecera: static void rellenar_materias(FILE*, materias **, int *);
//Precondición: El fichero materias.txt ha de estar abierto en modo lectura y el vector v_materias ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero materias.txt en la estructura de datos de la memoria principal y devuelve el número actual de materias en el sistema..
static void rellenar_materias(FILE*, materias **, int *);

//Cabecera: static void rellenar_matriculas(FILE*, matriculas **, int *);
//Precondición: El fichero matriculass.txt ha de estar abierto en modo lectura y el vector v_matriculas ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero matriculas.txt en la estructura de datos de la memoria principal y devuelve el número actual de matriculas en el sistema..
static void rellenar_matriculas(FILE*, matriculas **, int *);

//Cabecera: static void rellenar_calificaciones(FILE*, calificaciones **, int *);
//Precondición: El fichero calificaciones.txt ha de estar abierto en modo lectura y el vector v_calificaciones ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero calificaciones.txt en la estructura de datos de la memoria principal y devuelve el número actual de calificaciones en el sistema..
static void rellenar_calificaciones(FILE*, calificaciones **, int *);

//Cabecera: static void rellenar_faltas(FILE*, faltas **, int *);
//Precondición: El fichero faltas.txt ha de estar abierto en modo lectura y el vector v_faltas ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero faltas.txt en la estructura de datos de la memoria principal y devuelve el número actual de faltas en el sistema..
static void rellenar_faltas(FILE*, faltas **, int *);

//Cabecera: static void rellenar_horarios(FILE*, horarios **, int *);
//Precondición: El fichero horarios.txt ha de estar abierto en modo lectura y el vector v_horarios ha de estar inicializado en memoria.
//Postcondición: Copia la información del fichero horarios.txt en la estructura de datos de la memoria principal y devuelve el número actual de horarios en el sistema..
static void rellenar_horarios(FILE*, horarios **, int *);


//Funciones para el volcado de memoria principal a disco

//Cabecera: static void rellenar_fichero_usuarios(FILE*, usuarios*, int);
//Precondición: El fichero usuarios.txt ha de estar abierto en modo escritura, el vector v_usuarios ha de estar inicializado en memoria y el entero n_act_usuarios ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_usuarios(FILE*, usuarios*, int);

//Cabecera: static void rellenar_fichero_alumnos(FILE*, alumnos*, int);
//Precondición: El fichero alumnos.txt ha de estar abierto en modo escritura, el vector v_alumnos ha de estar inicializado en memoria y el entero n_act_alumnos ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_alumnos(FILE*, alumnos*, int);

//Cabecera: static void rellenar_fichero_materias(FILE*, materias*, int);
//Precondición: El fichero materias.txt ha de estar abierto en modo escritura, el vector v_materias ha de estar inicializado en memoria y el entero n_act_materias ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_materias(FILE*, materias*, int);

//Cabecera: static void rellenar_fichero_matriculas(FILE*, matriculas*, int);
//Precondición: El fichero matriculas.txt ha de estar abierto en modo escritura, el vector v_matriculas ha de estar inicializado en memoria y el entero n_act_matriculas ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_matriculas(FILE*, matriculas*, int);

//Cabecera: static void rellenar_fichero_calificaciones(FILE*, calificaciones*, int);
//Precondición: El fichero calificaciones.txt ha de estar abierto en modo escritura, el vector v_calificaciones ha de estar inicializado en memoria y el entero n_act_calificaciones ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_calificaciones(FILE*, calificaciones*, int);

//Cabecera: static void rellenar_fichero_faltas(FILE*, faltas*, int);
//Precondición: El fichero faltas.txt ha de estar abierto en modo escritura, el vector v_faltas ha de estar inicializado en memoria y el entero n_act_faltas ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_faltas(FILE*, faltas*, int);

//Cabecera: static void rellenar_fichero_horarios(FILE*, horarios*, int);
//Precondición: El fichero horarios.txt ha de estar abierto en modo escritura, el vector v_horarios ha de estar inicializado en memoria y el entero n_act_horarios ha de estar inicializado.
//Postcondición: Copia la información existente en memoria principal en el fichero.
static void rellenar_fichero_horarios(FILE*, horarios*, int);


//Función de acceso al sistema

//Cabecera: void acceso(usuarios *, int)
//Precondición: El vector de estructuras v_usuarios y la variable n_act_usuarios han de estar inicializados
//Postcondición: Dirige el control del programa en función de si el usuario es administrador o profesor
void acceso(usuarios *, int);


//Declaramos las variables que nos tendran informado del numero actual de vectores que estaremos manejando.
int n_act_usuarios, n_act_alumnos, n_act_materias, n_act_matriculas, n_act_calificaciones, n_act_faltas, n_act_horarios, codigo_profesor;

//Declaramos esta variable para saber cual es el id del usuario que está actualmente conectado al sistema
char id_act[4];

#endif // FICHEROS_H_INCLUDED
