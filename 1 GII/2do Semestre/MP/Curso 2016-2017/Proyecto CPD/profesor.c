#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"
#include "profesor.h"
#include <time.h>
static int menu_grupos(){
    int opcion_grupo; //Almacenara la opcion elegida en el menu

do {
printf("Elige una opcion sobre el grupo elegido\n");
printf("1. Lista de alumnos\n");
printf("2. Cambiar de grupo\n");
printf("3. Salir\n");
scanf("%i", &opcion_grupo);
} while(opcion_grupo!=1 && opcion_grupo!=2 && opcion_grupo!=3); //comprobara que la opcion elegida sea la correcta.

return opcion_grupo;
}

static int menu_alumno(){
    int opcion_alumno; //almacenara la opcion elegida en el menu
do{
    printf("Elige una opcion sobre el alumno elegido\n");
    printf("1.Ficha del alumno.\n");
    printf("2.Calificaciones del alumno.\n");
    printf("3.Faltas de asistencia.\n");
    printf("0.Volver.\n");
    scanf("%i",&opcion_alumno);
}while(opcion_alumno<1 || opcion_alumno>4); //comprueba que la opcion elegida este entre los valores adecuados

return opcion_alumno;
}

static int mostrargrupos( materias *vmaterias, int profesor_id){
    system("cls");
    char prof_e[4];
    char hor[2];
    char mat[5];
    char gru[11];
    char id_mat[5];
    char fechayhora[100];
    char nombre_materia[51];
    int cont=0, opcion, i,j;
    time_t t;
    struct tm *tm;
//gracias a este fracmento de codigo podemos saber que numero representa el dia actual
  t=time(NULL);
  tm=localtime(&t);
  strftime(fechayhora, 100, "%w", tm);
 int dia_s=atoi(fechayhora); //en dia_s tenemos el dia que representa el dia actual siengo Lunes=1 y viernes=5

 if (dia_s<1 || dia_s>5){ //comprobamos que el dia actual esta entre lunes y viernes ( ya que la app no se puede usar los fines de semana)
    printf("\nError esta aplicacion solo esta operativa de lunes a viernes\n");
    return;
 }
 //si estamos en este punto estamos en uno de los dias en los que se permite el acceso a la App
  printf("Tus grupos para el dia de hoy:\n");

             system("cls");
                      v_profesorado=(info_profesor *)calloc(1, sizeof(info_profesor)); //creamos nuestro vector de nuestra structura auxiliar
                         v_profesorado=NULL;
                         n_asignatura=0;

                          printf("Tus grupos para el dia de hoy:\n");
    for(i=0; i<n_act_horarios; i++){ //cpmenzamos a mostrar los grupos del profesor en el dia de hoy

                strcpy(prof_e,v_horarios[i].id_profesor);
                 strcpy(hor,v_horarios[i].Dia_clase);
                if (atoi(prof_e)==profesor_id && atoi(hor)==dia_s ){ //comprobamos que en el vector v_horarios existe algun registro con el profesor actual en el dia de hoy
                        cont=cont+1;
                    strcpy(mat, v_horarios[i].id_materia);//añadimos a nuestro  vector de estructura auxiliar el id de la materia.
                    strcpy(gru, v_horarios[i].Grupo); //añadimos a nuestro  vector de estructura auxiliar el codigo del grupo.

                        for(j=0; j<n_act_materias;j++){ //buscamos el grupo en el vector v_materias para mostrar su nombre en lugar del codigo.
                                strcpy(id_mat, vmaterias[j].id_materia);
                                if (atoi(mat)==atoi(id_mat)){
                                     strcpy(nombre_materia, vmaterias[j].Nombre_materia);// y almacenamos ek nombre de la materia en la variable nombre_materia
                                }
                        }
                    printf("%d- Grupo: %s || Materia: %s \n",n_asignatura+1,gru,nombre_materia); //Mostramos por pantalla el grupo y materias que tiene el profesor

                v_profesorado=realloc((info_profesor *)(v_profesorado),((n_asignatura)+1)*sizeof(info_profesor)); //aumentamos el tamaño del vector auxiliar
               //rellenamos el vector auxiliar v_profesorado.
               v_profesorado[n_asignatura].id=n_asignatura+1; //damos un id identificativo a cada fila mostrada, esto nos permitira encontrar rapidamente el grupo seleccionado
               strcpy(v_profesorado[n_asignatura].grupo,gru);
                strcpy(v_profesorado[n_asignatura].materia,mat);
                strcpy(v_profesorado[n_asignatura].hora,hor);
                n_asignatura++; //Aumentamos el numero de grupos del profesor.

                }
    }
            if(cont==0){ //comprobamos que el profesor tiene almenos un grupo en el dia de hoy
            printf("No tienes ningun horario para el dia de hoy\n");
        system("Pause");
            main();
            exit(0);
           }
           //preguntar al usuario que grupo quiere modificar. la opcion elegida sera el id del vector auxiliar que para eso fue creado.
            printf("Indique el numero del grupo al que quiere acceder o pulse 0 para salir\n");

           // scanf("%i",&opcion);
            do {
                    scanf("%i", &opcion);
                } while(opcion<0 || opcion>n_asignatura);
            return opcion;
}

static void profesor_alumnos(int opcion){
system("cls");
int i,j, cont=0, alumno, opcion_menu_alumno;
for (i=0; i<n_act_alumnos;i++){ //buscamos el grupo elegido en vector de estructura v_profesorado
    if(strcmp(v_profesorado[opcion-1].grupo,v_alumnos[i].Grupo)==0){ //Es del grupo

            for (j=0; j<n_act_matriculas;j++){ // buscamos el alumno en el vector de v_alumnos

                 if (strcmp(v_alumnos[i].id_alum,v_matriculas[j].id_alum)==0 && strcmp(v_matriculas[j].id_materia,v_profesorado[opcion-1].materia)==0){ //esta matriculado en la materia
                    cont=+1; //chivato para saber si a habido alumnos
                    printf("Codigo alumno: %s  - Alumno: %s\n",v_alumnos[i].id_alum,v_alumnos[i].Nombre_alum); // mostramos el codigo y el nombre del alumno
                }
            }


    }
}
    if (cont==0){ // comprobamos si a habia alumnos.
                //si no hay alumnos en el grupo.
                system("cls");
                printf("No existen Alumnos en este grupo\n");
                system("pause");
                //vuelve al princupio del modulo
                modulo_profesor();
    }
    //Preguntaremos el alumno
    printf("Indique el codigo del alumno al que quieres acceder o pulse 0 para volver:\n");
    scanf("%i",&alumno);
    if (alumno==0){ //comprobar si no a fulsado salir.
        modulo_profesor(); //si a pulsado salir volvera al principio del modulo.

    }else{
        //en caso de no haber pulsado 0 y salir.
   opcion_menu_alumno=menu_alumno(); //mostramos el menu del alumno.
   switch(opcion_menu_alumno){ //comprobamos la opcion elegida y llamamos a la funcion adecuada
    case 0: //opcion volver
            //Volver a mostrar todos los alumnos.
            profesor_alumnos(opcion);
        break;

    case 1:
        // opcion Ficha del alumno
        datos_alumno(alumno, opcion);
        break;
    case 2:
        //Opcion Calificaciones del alumno
        calificaciones_alumnos(alumno,opcion);
        break;
    case 3:
        //opcion falta de asistencia
        faltas_alumnos(alumno, opcion);
        break;

   }

}}

static void datos_alumno(int alumno, int opcion){
    int i,pos,modificar,chivato=0;
    char n_nombre[21], n_direccion[31], n_localidad[31];
    int modificar_alumno;
    //Muestra los datos del alumno selecccionado
    for (i=0;i<n_act_alumnos;i++){
        if (atoi(v_alumnos[i].id_alum)==alumno){
            system("cls");
            printf("Nombre: %s \nDireccion: %s \nLocalidad: %s \n", v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum, v_alumnos[i].Local_alum);
            pos=i;
            chivato=1; //chivato para saber que se a mostrado los datos
        }
    }
    if (chivato==0){ //si El numero de usuario no existe
        printf("EL usuario no existe\n");
        system("pause");
        profesor_alumnos(opcion); //volver a mostrar todos loa alumnos.
    }
    printf("¿Quieres modificar algun dato del alumno?\n 1- Si\n 2-No, volver\n"); //preguntamos si quieres modicar algun dato

       scanf("%i", &modificar);
    switch (modificar){ //comprobamos que opcion modificar
                case 1:
//Modificar algun dato.
                        printf("¿Que dato desea modificar?\n1- Nombre \n2- Direccion \n3- Localidad \n4- Volver\n");
                        scanf("%i",&modificar_alumno);
                        switch(modificar_alumno){ //saber que dato a elegido modificar
                        case 1:
                            //Modificar el nombre del alumno
                                printf("Indique el nuevo nombre:\n");
                                fflush(stdin);
                                gets(v_alumnos[pos].Nombre_alum);
                                printf("Nombre cambiado\n");
                                system("pause");
                                datos_alumno(alumno,opcion);
                                //Volver a mostrar los datos del alumno ya modificado
                            break;
                        case 2:
                            //Modificar la direccion del alumno
                                printf("Indique la nueva direccion:\n");
                                 fflush(stdin);
                                gets(v_alumnos[pos].Direc_alum);
                                printf("Direccion cambiada\n");
                                system("pause");
                                 datos_alumno(alumno,opcion);
                                //Volver a mostrar los datos del alumno ya modificado
                            break;
                        case 3:
                            //Modificar la localidad del alumno
                                printf("Indique la nueva localidad:\n");
                                 fflush(stdin);
                                gets(v_alumnos[pos].Local_alum);
                                printf("Localidad cambiada\n");
                                system("pause");
                                datos_alumno(alumno,opcion);
                                //Volver a mostrar los datos del alumno ya modificado
                            break;
                        case 4:
                            //volver a mostrar los alumnos
                                profesor_alumnos(opcion);
                            break;
                        default:
                            //Opcion no valida
                                printf("Opcion no valida\n");
                                system("Pause");
                                datos_alumno(alumno,opcion); //volver a llamar a la funcion.

                            break;

                        }
                    break;
                case 2:
                    //volver a mostrar los alumnos.
                    profesor_alumnos(opcion);
                    break;
                default:
                    //opcion no valida
                    printf("opcion no valida\n");
                    system("pause");
                    datos_alumno(alumno, opcion); //volver a llamar a la funcion
            }

}
static void calificaciones_alumnos(int alumno, int opcion){
    system("cls");
    int i,j, menu_calificacion, chivato=0;
    char n_alumno[7];
    char b_descripcion[31], n_calificacion[3];
     for (i=0;i<n_act_calificaciones;i++){ //Mostrar las calificaciones del alumno
    if(atoi(v_calificaciones[i].id_alum)==alumno && strcmp(v_calificaciones[i].id_materia,v_profesorado[opcion-1].materia)==0){
//Comprobarl el id del alumno y la materia corresponde con algun regrsito de v_calificacione
              printf("Fecha: %s/%s/%s - Descripcion: %s - Calificacion: %s \n",v_calificaciones[i].Fecha_calif.dia,v_calificaciones[i].Fecha_calif.mes,v_calificaciones[i].Fecha_calif.ano, v_calificaciones[i].Descrip_calif, v_calificaciones[i].Valor_calif );
            }
    }
    //Mostrar el menu para modificar las calificaciones
    printf("Menu Calificaciones:\n 1- Modificar una calificacion\n 2- Borrar una calificacion\n 3- anadir una calificacion\n 0- Volver\n");
    do{
        scanf("%i", &menu_calificacion);
    }while(menu_calificacion<0 || menu_calificacion>3); //comprobamos que a marcado una opcion valida
    switch(menu_calificacion){
        case 0:
            //volver a mostrar los alumnos
            profesor_alumnos(opcion);
            break;
        case 1:
            //Modificar una calificacion
            printf("-Modificar una calificacio-\n");
            printf("Introduce la descripcion de la calificacion\n");
            scanf("%s", &b_descripcion);
            printf("\nIntroduce la nueva calificacion:\n");
            scanf("%s", &n_calificacion);
            for (i=0; i<n_act_calificaciones;i++){
                if (strcmp(v_calificaciones[i].Descrip_calif,b_descripcion)==0){ //Comprobar que coincide la descripcion de la calificacion y poder cambiarla
                    strcpy(v_calificaciones[i].Valor_calif,n_calificacion);
                    printf("Calificacion cambiada\n");
                    system("pause");
                    calificaciones_alumnos(alumno,opcion); //volver a mostrar las calificaciones
                }
            }
            break;
        case 2:
            //Eliminar una calificacion
            printf("-Eliminar una calificacion-\n");
            printf("Introduce la descripcion de la calificacion a borrar\n");
            scanf("%s",&b_descripcion);
            for(i=0;i<n_act_calificaciones;i++){
                if (strcmp(v_calificaciones[i].Descrip_calif,b_descripcion)==0  && atoi(v_calificaciones[i].id_alum)==alumno && strcmp(v_calificaciones[i].id_materia,v_profesorado[opcion-1].materia)==0){
                  //comprobar que la descripcion de la calificacion coincide
                    for (j=i;j<n_act_calificaciones-1;j++){
                            chivato=1;
                        strcmp(v_calificaciones[j].Descrip_calif,v_calificaciones[j+1].Descrip_calif);
                        strcmp(v_calificaciones[j].Fecha_calif.ano,v_calificaciones[j+1].Fecha_calif.ano);
                        strcmp(v_calificaciones[j].Fecha_calif.dia,v_calificaciones[j+1].Fecha_calif.dia);
                        strcmp(v_calificaciones[j].Fecha_calif.mes,v_calificaciones[j+1].Fecha_calif.mes);
                        strcmp(v_calificaciones[j].id_alum,v_calificaciones[j+1].id_alum);
                        strcmp(v_calificaciones[j].id_materia,v_calificaciones[j+1].id_materia);
                        strcmp(v_calificaciones[j].Valor_calif,v_calificaciones[j+1].Valor_calif);
                    }
                }
            }
            // si a eliminado alguna calificacion reducimos en 1 el tamaño de v_calificaciones
            if (chivato==1){
                 v_calificaciones=realloc((calificaciones *)(v_calificaciones), ((n_act_calificaciones)-1)*sizeof(calificaciones));
                    n_act_calificaciones=n_act_calificaciones-1;
            }
           break;
        case 3:
            //Añadir una nueva calificacion
            //Pedimos todos los dato y actualizamos:
            printf("-Nueva calificacion-\n");
            v_calificaciones=realloc((calificaciones *)(v_calificaciones), ((n_act_calificaciones)+1)*sizeof(calificaciones));
            printf("Introduce el dia:\n");
            fflush(stdin);
            gets(v_calificaciones[n_act_calificaciones].Fecha_calif.dia);
             printf("Introduce el mes:\n");
            fflush(stdin);
            gets(v_calificaciones[n_act_calificaciones].Fecha_calif.mes);
             printf("Introduce el Ano:\n");
            fflush(stdin);
            gets(v_calificaciones[n_act_calificaciones].Fecha_calif.ano);
             printf("Introduce la descripcion del examen:\n");
            fflush(stdin);
            gets(v_calificaciones[n_act_calificaciones].Descrip_calif);
             printf("Introduce la nota:\n");
            fflush(stdin);
            gets(v_calificaciones[n_act_calificaciones].Valor_calif);
            itoa(alumno,n_alumno,10); //transformamos el valor del id del alumno de int a char
            strcpy(v_calificaciones[n_act_calificaciones].id_alum,n_alumno);
            strcpy(v_calificaciones[n_act_calificaciones].id_materia,v_profesorado[opcion-1].materia);
            n_act_calificaciones=n_act_calificaciones+1;
            printf("Calificacion anadida\n");
            system("pause");
            calificaciones_alumnos(alumno,opcion); //Volvemos a mostrar las calificaciones

            break;
        default:
            break;

    }
}
static void mostrar_faltas(int alumno, int opcion){
int i, chivato=0;
//Mostramos las faltas de un alumno

    for (i=0;i<n_act_faltas;i++){
            if (atoi(v_faltas[i].id_alum)==alumno){
                    printf("Fecha: %s/%s/%s - Hora: %s - Motivo: %s - Estado: %s \n", v_faltas[i].Fecha_falta.dia,v_faltas[i].Fecha_falta.mes, v_faltas[i].Fecha_falta.ano, v_faltas[i].Hora_falta, v_faltas[i].Descrip_falta, v_faltas[i].Estado_falta);
            chivato=1; //saber si a mostrado aluna falta
            }
    }
    if (chivato==0){ //si hay faltas mostramos el mensaje
        printf("Ningun alumno tiene falta de asistencia en este grupo\n");
        system("pause");
        modulo_profesor(); //Volver a
    }
}
static void faltas_alumnos(int alumno, int opcion){
    system("cls");
    printf("\n\n");
    int i,opcion_menu_faltas, opcion_modificar_falta,b_hora,chivato=0, n_hora;
    fecha b_fecha;
    char n_estado[31], nu_hora[2], n_alumno[7];
    mostrar_faltas(alumno,opcion); //Mostramos las faltas de un alumno llamando al procedimiento mostrar_faltas
    printf("Menu Faltas.\n 1-Modificar una falta.\n 2-Eliminar una falta.\n 3-Crear una falta.\n 4-Volver.\n");
    scanf("%i",&opcion_menu_faltas);
    switch(opcion_menu_faltas){ //Comprobamos la opcion marcada en el menu
        case 1:
            //Modificar falta
            printf("Introduzca el dia\n");
            scanf("%s", &b_fecha.dia);
            printf("Introduzca el mes\n");
            scanf("%s", &b_fecha.mes);
            printf("Introduzca el Ano\n");
            scanf("%s", &b_fecha.ano);
             printf("Introduzca la Hora\n");
             do{
                scanf("%i", &b_hora);
             }while(b_hora<=0 || b_hora>5);//Comprobamos que la hora este comprendida entre 11 y 6
             system("cls");

                for (i=0;i<n_act_faltas;i++){
                    if (atoi(v_faltas[i].Hora_falta)==b_hora && strcmp(v_faltas[i].Fecha_falta.dia,b_fecha.dia)==0 && strcmp(v_faltas[i].Fecha_falta.mes,b_fecha.mes)==0 && strcmp(v_faltas[i].Fecha_falta.ano,b_fecha.ano)==0){
                    //Buscamos la falta seleccionada
                    chivato=1; //Chivato para saber que se a encontrado la falta
                       //Mostramos la falta que se va a modificar
                       printf("Fecha: %s/%s/%s - Hora: %s - Motivo: %s - Estado: %s \n", v_faltas[i].Fecha_falta.dia,v_faltas[i].Fecha_falta.mes, v_faltas[i].Fecha_falta.ano, v_faltas[i].Hora_falta, v_faltas[i].Descrip_falta, v_faltas[i].Estado_falta);
                        printf("\n¿Que dato de la falta quieres modificar?\n1.Motivo\n2.Estado\n3.No hacer cambios\n");
                        do{
                              scanf("%i", &opcion_modificar_falta);
                        }while(opcion_modificar_falta<=0 || opcion_modificar_falta>3); //Comprobamso que la opcion elegida sea la correcta
                        switch(opcion_modificar_falta){
                        case 1:
                            //Modificar el motivo de la falta
                                printf("Introduce el nuevo motivo:\n");
                                fflush(stdin);
                                gets(v_faltas[i].Descrip_falta);
                                printf("\nMotivo modificado\n");
                                system("pause");
                                faltas_alumnos(alumno,opcion); //Volver a mostrar las faltas del alumno

                            break;
                        case 2:
                            //Modificar el estado de la falta
                                printf("Introduce el nuevo Estado (justificada, injustificada, retraso):\n");
                                fflush(stdin);
                                scanf("%s",&n_estado);
                                if (strcmp(n_estado,"injustificada")==0 || strcmp(n_estado,"justificada")==0 || strcmp(n_estado,"retraso")==0){
                                  //Comprobamos que el estado sea unoa de los permitidos
                                    strcpy(v_faltas[i].Estado_falta,n_estado); //Actualizamos el estado
                                     printf("\n Estado modificado\n");
                                system("pause");
                                faltas_alumnos(alumno,opcion); //Volver a mostrar las faltas
                                }else{
                                    printf("\nEstado errono\n"); //A introducido un estado incorrecto
                                   system("pause");
                                    faltas_alumnos(alumno,opcion);
                                }


                            break;
                        case 3:
                            //volver
                            faltas_alumnos(alumno,opcion); //Mostrar las faltas de los alumnos
                            break;
                        }

                    }
                }
                if (chivato==0){ //si no se a encontrado ninguna falta para modificar con los datos introducido
                    printf("\nDatos erroneos\n");
                    system("pause");
                    faltas_alumnos(alumno,opcion); //Volver a mostrar las faltas del alumno
                }

            break;
        case 2:

            //eliminar
            break;
        case 3:
            //Introducir una falta
            printf("-Introducir una falta al sistema-\n");
            printf("%i", n_act_faltas);
             v_faltas=realloc((faltas *)(v_faltas), ((n_act_faltas)+1)*sizeof(faltas));
             printf("Introduce el dia:\n");
             fflush(stdin);
            gets(v_faltas[n_act_faltas].Fecha_falta.dia);
            printf("Introduce el mes:\n");
             fflush(stdin);
            gets(v_faltas[n_act_faltas].Fecha_falta.mes);
            printf("Introduce el ano:\n");
             fflush(stdin);
            gets(v_faltas[n_act_faltas].Fecha_falta.ano);
            printf("Introduce la hora(1 al 6):\n");
            do{
               scanf("%i",&n_hora);
            }while(n_hora<1 || n_hora>6); //Comprobamos que la hora se encuentra entre los imes [1-6]
             itoa(n_hora,nu_hora,10); //Combertimos la hora de int a char
            strcpy(v_faltas[n_act_faltas].Hora_falta,nu_hora);
            printf("Introduce el motivo:\n");
             fflush(stdin);
            gets(v_faltas[n_act_faltas].Descrip_falta);
            printf("Introduce el estado(justificada, injustificada, retraso:\n");
             fflush(stdin);
                                scanf("%s",&n_estado);
                                if (strcmp(n_estado,"injustificada")==0 || strcmp(n_estado,"justificada")==0 || strcmp(n_estado,"retraso")==0){
                                   //Comprobamos que el estado es uno de los permitidos
                                    strcpy(v_faltas[n_act_faltas].Estado_falta,n_estado);

                                }else{
                                    //Si el estado es uno de los no permitidos
                                    printf("\nEstado errono\n");
                                    system("pause");
                                    faltas_alumnos(alumno,opcion);
                                }
                                itoa(alumno,n_alumno,10);
            strcpy(v_faltas[n_act_faltas].id_alum,n_alumno);
            n_act_faltas=n_act_faltas+1;
            printf("\nFalta creada\n");
            system("pause");
            faltas_alumnos(alumno,opcion); //Volver a mostrar las faltas

            //crear
            break;
        case 4:
                modulo_profesor(); // voler a principio del modulo

            break;
    }

}

void modulo_profesor(){
    int opcion_mostrar_grupo;
    int opcion_menu_grupos;
    int i=0;
    int alumno;
    opcion_mostrar_grupo=mostrargrupos(v_materias, codigo_profesor); //Muestra los grupos del profe y devuelve el id del grupo
   if(opcion_mostrar_grupo!=0){ //comprobamos que no a pulsado la opcion salir
    for (i=0;i<n_asignatura;i++){
            //printf("%i",v_profesorado[i].id);
if (v_profesorado[i].id==opcion_mostrar_grupo){
        system("cls");
    printf("Grupo: %s y Materia: %s\n",v_profesorado[i].grupo,v_profesorado[i].materia );
}
    }
    opcion_menu_grupos=menu_grupos(); //mostrar menu de las opciones de los grupos mostrados por pantalla

    switch (opcion_menu_grupos) // comprobar la opcion seleccionada
            {
                case 1:
                    // mostrar los alumnos del grupo elegido
                   profesor_alumnos(opcion_mostrar_grupo); // Procedimiento cqe gestiona los alumnos
                    break;
                case 2:
                    //Cambiar de grupo
                    system("cls");
                    modulo_profesor(); //vuelve a mostrar los grupos
                    break;
                case 3:

                    break;
            }


   }
   volcar_disco();
}
