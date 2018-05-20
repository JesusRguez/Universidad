#include "ficheros.h"

void volcar_memoria(){

    if((f_usuarios=fopen("usuarios.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "usuarios.txt" en modo lectura.
    if((f_alumnos=fopen("alumnos.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "alumnos.txt" en modo lectura.
    if((f_materias=fopen("materias.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "materias.txt" en modo lectura.
    if((f_matriculas=fopen("matriculas.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "matriculas.txt" en modo lectura.
    if((f_calificaciones=fopen("calificaciones.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "calificaciones.txt" en modo lectura.
    if((f_faltas=fopen("faltas.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "faltas.txt" en modo lectura.
    if((f_horarios=fopen("horarios.txt", "r"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "horarios.txt" en modo lectura.

    v_usuarios=(usuarios *)calloc(1, sizeof(usuarios));                                 //Inicializacion del vector v_usuarios.
    v_alumnos=(alumnos *)calloc(1, sizeof(alumnos));                                    //Inicializacion del vector v_alumnos.
    v_materias=(materias *)calloc(1, sizeof(materias));                                 //Inicializacion del vector v_materias.
    v_matriculas=(matriculas *)calloc(1, sizeof(matriculas));                           //Inicializacion del vector v_matriculas.
    v_calificaciones=(calificaciones *)calloc(1, sizeof(calificaciones));               //Inicializacion del vector v_calificaciones.
    v_faltas=(faltas *)calloc(1, sizeof(faltas));                                       //Inicializacion del vector v_faltas.
    v_horarios=(horarios *)calloc(1, sizeof(horarios));                                 //Inicializacion del vector v_horarios.

    rellenar_usuarios(f_usuarios, &v_usuarios, &n_act_usuarios);                           //Numero actual de usuarios y llamada a la función encargada de volcar la información del fichero usuarios.txt en memoria.
    rellenar_alumnos(f_alumnos, &v_alumnos, &n_act_alumnos);                               //Numero actual de alumnos y llamada a la función encargada de volcar la información del fichero alumnos.txt en memoria.
    rellenar_materias(f_materias, &v_materias, &n_act_materias);                           //Numero actual de materias y llamada a la función encargada de volcar la información del fichero materias.txt en memoria.
    rellenar_matriculas(f_matriculas, &v_matriculas, &n_act_matriculas);                   //Numero actual de matriculas y llamada a la función encargada de volcar la información del fichero matriculas.txt en memoria.
    rellenar_calificaciones(f_calificaciones, &v_calificaciones, &n_act_calificaciones);   //Numero actual de calificaciones y llamada a la función encargada de volcar la información del fichero calificaciones.txt en memoria.
    rellenar_faltas(f_faltas, &v_faltas, &n_act_faltas);                                   //Numero actual de faltas y llamada a la función encargada de volcar la información del fichero faltas.txt en memoria.
    rellenar_horarios(f_horarios, &v_horarios, &n_act_horarios);                           //Numero actual de horarios y llamada a la función encargada de volcar la información del fichero horarios.txt en memoria.

    fclose(f_usuarios);         //Cerramos el fichero usuarios.txt
    fclose(f_alumnos);          //Cerramos el fichero alumnos.txt
    fclose(f_materias);         //Cerramos el fichero materias.txt
    fclose(f_matriculas);       //Cerramos el fichero matriculas.txt
    fclose(f_calificaciones);   //Cerramos el fichero calificaciones.txt
    fclose(f_faltas);           //Cerramos el fichero faltas.txt
    fclose(f_horarios);         //Cerramos el fichero horarios.txt

}

static void rellenar_usuarios(FILE* f_usuarios, usuarios **v_usuarios, int *n_act_usuarios){
    char cadena[54];        //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones.
    *v_usuarios=NULL;
    *n_act_usuarios=0;      //Cuenta el número de líneas que tiene el fichero que será el número de usuarios que haya en el sistema

    while(!feof(f_usuarios))
    {

        fgets(cadena,54,f_usuarios);

        if (strcmp(cadena,"\0"))
        {
            *v_usuarios=realloc((usuarios *)(*v_usuarios),((*n_act_usuarios)+1)*sizeof(usuarios));

            token=strtok(cadena,"-");
            strcpy((*v_usuarios)[*n_act_usuarios].id_usuario,token);

            token=strtok(NULL,"-");
            strcpy((*v_usuarios)[*n_act_usuarios].Nomb_usuario,token);

            token=strtok(NULL,"-");
            strcpy((*v_usuarios)[*n_act_usuarios].Perfil_usuario,token);

            token=strtok(NULL,"-");
            strcpy((*v_usuarios)[*n_act_usuarios].Usuario,token);

            token=strtok(NULL,"\n");
            strcpy((*v_usuarios)[*n_act_usuarios].Contrasena,token);

            (*n_act_usuarios)++;

        }

    }
}

static void rellenar_alumnos(FILE* f_alumnos, alumnos **v_alumnos, int *n_act_alumnos){
    char cadena[132];       //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones.
    *v_alumnos=NULL;
    *n_act_alumnos=0;       //Cuenta el número de líneas que tiene el fichero que será el número de alumnos que haya en el sistema


    while(!feof(f_alumnos))
    {
        fgets(cadena,132,f_alumnos);

        if (strcmp(cadena,"\0"))
        {
            *v_alumnos=realloc((alumnos *)(*v_alumnos), ((*n_act_alumnos)+1)*sizeof(alumnos));

            token=strtok(cadena,"-");
            strcpy((*v_alumnos)[*n_act_alumnos].id_alum,token);

            token=strtok(NULL,"-");
            strcpy((*v_alumnos)[*n_act_alumnos].Nombre_alum,token);

            token=strtok(NULL,"-");
            strcpy((*v_alumnos)[*n_act_alumnos].Direc_alum,token);

            token=strtok(NULL,"-");
            strcpy((*v_alumnos)[*n_act_alumnos].Local_alum,token);

            token=strtok(NULL,"-");
            strcpy((*v_alumnos)[*n_act_alumnos].Curso,token);

            token=strtok(NULL,"\n");
            strcpy((*v_alumnos)[*n_act_alumnos].Grupo,token);

            (*n_act_alumnos)++;

        }

    }
}

static void rellenar_materias(FILE* f_materias, materias **v_materias, int *n_act_materias){
    char cadena[60];        //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones.
    *v_materias=NULL;
    *n_act_materias=0;           //Cuenta el número de líneas que tiene el fichero que será el número de materias que haya en el sistema


    while(!feof(f_materias))
    {
        fgets(cadena,60,f_materias);

        if (strcmp(cadena,"\0"))
        {
            *v_materias=realloc((materias *)(*v_materias), ((*n_act_materias)+1)*sizeof(materias));

            token=strtok(cadena,"-");
            strcpy((*v_materias)[*n_act_materias].id_materia,token);

            token=strtok(NULL,"-");
            strcpy((*v_materias)[*n_act_materias].Nombre_materia,token);

            token=strtok(NULL,"\n");
            strcpy((*v_materias)[*n_act_materias].Abrev_materia,token);

            (*n_act_materias)++;

        }

    }
}

static void rellenar_matriculas(FILE* f_matriculas, matriculas **v_matriculas, int *n_act_matriculas){
    char cadena[12];        //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones.
    *v_matriculas=NULL;
    *n_act_matriculas=0;           //Cuenta el número de líneas que tiene el fichero que será el número de matrículas que haya en el sistema


    while(!feof(f_matriculas))
    {
        fgets(cadena,12,f_matriculas);

        if (strcmp(cadena,"\0"))
        {
            *v_matriculas=realloc((matriculas *)(*v_matriculas), ((*n_act_matriculas)+1)*sizeof(matriculas));

            token=strtok(cadena,"-");
            strcpy((*v_matriculas)[*n_act_matriculas].id_materia,token);

            token=strtok(NULL,"\n");
            strcpy((*v_matriculas)[*n_act_matriculas].id_alum,token);

            (*n_act_matriculas)++;

        }

    }
}

static void rellenar_calificaciones(FILE* f_calificaciones, calificaciones **v_calificaciones, int *n_act_calificaciones){
    char cadena[57];        //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones o barras (en el caso de la fecha).
    *v_calificaciones=NULL;
    *n_act_calificaciones=0;           //Cuenta el número de líneas que tiene el fichero que será el número de calificaciones que haya en el sistema


    while(!feof(f_calificaciones))
    {
        fgets(cadena,57,f_calificaciones);

        if (strcmp(cadena,"\0"))
        {
            *v_calificaciones=realloc((calificaciones *)(*v_calificaciones), ((*n_act_calificaciones)+1)*sizeof(calificaciones));

            token=strtok(cadena,"/");
            strcpy((*v_calificaciones)[*n_act_calificaciones].Fecha_calif.dia, token);

            token=strtok(NULL,"/");
            strcpy((*v_calificaciones)[*n_act_calificaciones].Fecha_calif.mes, token);

            token=strtok(NULL,"-");
            strcpy((*v_calificaciones)[*n_act_calificaciones].Fecha_calif.ano, token);

            token=strtok(NULL,"-");
            strcpy((*v_calificaciones)[*n_act_calificaciones].Descrip_calif,token);

            token=strtok(NULL,"-");
            strcpy((*v_calificaciones)[*n_act_calificaciones].id_materia,token);

            token=strtok(NULL,"-");
            strcpy((*v_calificaciones)[*n_act_calificaciones].id_alum,token);

            token=strtok(NULL,"\n");
            strcpy((*v_calificaciones)[*n_act_calificaciones].Valor_calif,token);

            (*n_act_calificaciones)++;

        }

    }
}

static void rellenar_faltas(FILE* f_faltas, faltas **v_faltas, int *n_act_faltas){
    char cadena[65];        //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones o barras (en el caso de la fecha).
    *v_faltas=NULL;
    *n_act_faltas=0;           //Cuenta el número de líneas que tiene el fichero que será el número de faltas que haya en el sistema


    while(!feof(f_faltas))
    {
        fgets(cadena,65,f_faltas);

        if (strcmp(cadena,"\0"))
        {
            *v_faltas=realloc((faltas *)(*v_faltas), ((*n_act_faltas)+1)*sizeof(faltas));

            token=strtok(cadena,"/");
            strcpy((*v_faltas)[*n_act_faltas].Fecha_falta.dia, token);

            token=strtok(NULL,"/");
            strcpy((*v_faltas)[*n_act_faltas].Fecha_falta.mes, token);

            token=strtok(NULL,"-");
            strcpy((*v_faltas)[*n_act_faltas].Fecha_falta.ano, token);

            token=strtok(NULL,"-");
            strcpy((*v_faltas)[*n_act_faltas].Hora_falta,token);

            token=strtok(NULL,"-");
            strcpy((*v_faltas)[*n_act_faltas].Descrip_falta,token);

            token=strtok(NULL,"-");
            strcpy((*v_faltas)[*n_act_faltas].Estado_falta,token);

            token=strtok(NULL,"\n");
            strcpy((*v_faltas)[*n_act_faltas].id_alum,token);

            (*n_act_faltas)++;

        }

    }
}

static void rellenar_horarios(FILE* f_horarios, horarios **v_horarios, int *n_act_horarios){
    char cadena[24];        //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones.
    *v_horarios=NULL;
    *n_act_horarios=0;           //Cuenta el número de líneas que tiene el fichero que será el número de horarios que haya en el sistema


    while(!feof(f_horarios))
    {
        fgets(cadena,24,f_horarios);

        if (strcmp(cadena,"\0"))
        {
            *v_horarios=realloc((horarios *)(*v_horarios), ((*n_act_horarios)+1)*sizeof(horarios));

            token=strtok(cadena,"-");
            strcpy((*v_horarios)[*n_act_horarios].id_profesor,token);

            token=strtok(NULL,"-");
            strcpy((*v_horarios)[*n_act_horarios].Dia_clase,token);

            token=strtok(NULL,"-");
            strcpy((*v_horarios)[*n_act_horarios].Hora_clase,token);

            token=strtok(NULL,"-");
            strcpy((*v_horarios)[*n_act_horarios].id_materia,token);

            token=strtok(NULL,"\n");
            strcpy((*v_horarios)[*n_act_horarios].Grupo,token);

            (*n_act_horarios)++;

        }

    }
}

void acceso(usuarios *v_usuarios, int n_act_usuarios){
    char user[21];
    char pass[9];
    int i, existe=0;

    printf("Usuario: ");
    fflush(stdin);
    scanf("%20s",user);

    printf("Contrasena: ");
    fflush(stdin);
    scanf("%8s",pass);

    system("cls");

    for(i=0;i<n_act_usuarios;i++){

        if(strcmp(v_usuarios[i].Usuario,user)==0) {

            existe=1;

            if(strcmp(v_usuarios[i].Contrasena,pass)==0){
                strcpy(id_act,v_usuarios[i].id_usuario);

                if(strcmp(v_usuarios[i].Perfil_usuario,"Administrador")==0){
                    puts("Has sido identificado como administrador.");
                    mostrar_menu_admin();
                }
                if(strcmp(v_usuarios[i].Perfil_usuario,"Profesor")==0){
                    puts("Has sido identificado como profesor.");
                    codigo_profesor=atoi(v_usuarios[i].id_usuario);
                    modulo_profesor();
                }

            }else{

                puts("ERROR: Contrasena incorrecta.");

                acceso(v_usuarios,n_act_usuarios);

            }

        }

    }

    if(existe==0)
        puts("El usuario no esta registrado en el sistema.");
}



void volcar_disco(){
    if((f_usuarios=fopen("usuarios.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "usuarios.txt" en modo escritura.
    if((f_alumnos=fopen("alumnos.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "alumnos.txt" en modo escritura.
    if((f_materias=fopen("materias.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "materias.txt" en modo escritura.
    if((f_matriculas=fopen("matriculas.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "matriculas.txt" en modo escritura.
    if((f_calificaciones=fopen("calificaciones.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "calificaciones.txt" en modo escritura.
    if((f_faltas=fopen("faltas.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "faltas.txt" en modo escritura.
    if((f_horarios=fopen("horarios.txt", "w"))==NULL)
        puts("No se pudo abrir.");                                  //Comprobacion de apertura del fichero "horarios.txt" en modo escritura.

    rellenar_fichero_usuarios(f_usuarios, v_usuarios, n_act_usuarios);                          //LLamada a la función encargada de volcar los datos de la memoria en el fichero usuarios.txt.
    rellenar_fichero_alumnos(f_alumnos, v_alumnos, n_act_alumnos);                              //LLamada a la función encargada de volcar los datos de la memoria en el fichero alumnos.txt.
    rellenar_fichero_materias(f_materias, v_materias, n_act_materias);                          //LLamada a la función encargada de volcar los datos de la memoria en el fichero materias.txt.
    rellenar_fichero_matriculas(f_matriculas, v_matriculas, n_act_matriculas);                  //LLamada a la función encargada de volcar los datos de la memoria en el fichero matriucals.txt.
    rellenar_fichero_calificaciones(f_calificaciones, v_calificaciones, n_act_calificaciones);  //LLamada a la función encargada de volcar los datos de la memoria en el fichero calificaciones.txt.
    rellenar_fichero_faltas(f_faltas, v_faltas, n_act_faltas);                                  //LLamada a la función encargada de volcar los datos de la memoria en el fichero faltas.txt.
    rellenar_fichero_horarios(f_horarios, v_horarios, n_act_horarios);                          //LLamada a la función encargada de volcar los datos de la memoria en el fichero horarios.txt.

    fclose(f_usuarios);         //Cerramos el fichero usuarios.txt
    fclose(f_alumnos);          //Cerramos el fichero alumnos.txt
    fclose(f_materias);         //Cerramos el fichero materias.txt
    fclose(f_matriculas);       //Cerramos el fichero matriculas.txt
    fclose(f_calificaciones);   //Cerramos el fichero calificaciones.txt
    fclose(f_faltas);           //Cerramos el fichero faltas.txt
    fclose(f_horarios);         //Cerramos el fichero horarios.txt
}

static void rellenar_fichero_usuarios(FILE* f_usuarios, usuarios *v_usuarios, int n_act_usuarios){
    int i=0;
    while(i<n_act_usuarios-1)                                    // recorremos el vector de usuarios
    {
        fprintf(f_usuarios, "%s-%s-%s-%s-%s\n", v_usuarios[i].id_usuario, v_usuarios[i].Nomb_usuario, v_usuarios[i].Perfil_usuario, v_usuarios[i].Usuario, v_usuarios[i].Contrasena);           //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_usuarios, "%s-%s-%s-%s-%s", v_usuarios[i].id_usuario, v_usuarios[i].Nomb_usuario, v_usuarios[i].Perfil_usuario, v_usuarios[i].Usuario, v_usuarios[i].Contrasena);                 //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.
}

static void rellenar_fichero_alumnos(FILE* f_alumnos, alumnos *v_alumnos, int n_act_alumnos){
    int i=0;
    while(i<n_act_alumnos-1)
    {
        fprintf(f_alumnos, "%s-%s-%s-%s-%s-%s\n", v_alumnos[i].id_alum, v_alumnos[i].Nombre_alum, v_alumnos[i].Direc_alum, v_alumnos[i].Local_alum, v_alumnos[i].Curso, v_alumnos[i].Grupo);    //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_alumnos, "%s-%s-%s-%s-%s-%s", v_alumnos[i].id_alum, v_alumnos[i].Nombre_alum, v_alumnos[i].Direc_alum, v_alumnos[i].Local_alum, v_alumnos[i].Curso, v_alumnos[i].Grupo);          //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.

}

static void rellenar_fichero_materias(FILE* f_materias, materias *v_materias, int n_act_materias){
    int i=0;
    while(i<n_act_materias-1)
    {
        fprintf(f_materias, "%s-%s-%s\n", v_materias[i].id_materia, v_materias[i].Nombre_materia, v_materias[i].Abrev_materia);     //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_materias, "%s-%s-%s", v_materias[i].id_materia, v_materias[i].Nombre_materia, v_materias[i].Abrev_materia);           //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.

}

static void rellenar_fichero_matriculas(FILE* f_matriculas, matriculas *v_matriculas, int n_act_matriculas){
    int i=0;
    while(i<n_act_matriculas-1)
    {
        fprintf(f_matriculas, "%s-%s\n", v_matriculas[i].id_materia, v_matriculas[i].id_alum);              //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_matriculas, "%s-%s", v_matriculas[i].id_materia, v_matriculas[i].id_alum);                    //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.

}

static void rellenar_fichero_calificaciones(FILE* f_calificaciones, calificaciones *v_calificaciones, int n_act_calificaciones){
    int i=0;
    while(i<n_act_calificaciones-1)
    {
        fprintf(f_calificaciones, "%s/%s/%s-%s-%s-%s-%s\n", v_calificaciones[i].Fecha_calif.dia, v_calificaciones[i].Fecha_calif.mes, v_calificaciones[i].Fecha_calif.ano, v_calificaciones[i].Descrip_calif, v_calificaciones[i].id_materia, v_calificaciones[i].id_alum, v_calificaciones[i].Valor_calif);    //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_calificaciones, "%s/%s/%s-%s-%s-%s-%s", v_calificaciones[i].Fecha_calif.dia, v_calificaciones[i].Fecha_calif.mes, v_calificaciones[i].Fecha_calif.ano, v_calificaciones[i].Descrip_calif, v_calificaciones[i].id_materia, v_calificaciones[i].id_alum, v_calificaciones[i].Valor_calif);          //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.

}

static void rellenar_fichero_faltas(FILE* f_faltas, faltas *v_faltas, int n_act_faltas){
    int i=0;
    while(i<n_act_faltas-1)
    {
        fprintf(f_faltas, "%s/%s/%s-%s-%s-%s-%s\n", v_faltas[i].Fecha_falta.dia, v_faltas[i].Fecha_falta.mes, v_faltas[i].Fecha_falta.ano, v_faltas[i].Hora_falta, v_faltas[i].Descrip_falta, v_faltas[i].Estado_falta, v_faltas[i].id_alum);       //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_faltas, "%s/%s/%s-%s-%s-%s-%s", v_faltas[i].Fecha_falta.dia, v_faltas[i].Fecha_falta.mes, v_faltas[i].Fecha_falta.ano, v_faltas[i].Hora_falta, v_faltas[i].Descrip_falta, v_faltas[i].Estado_falta, v_faltas[i].id_alum);             //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.

}

static void rellenar_fichero_horarios(FILE* f_horarios, horarios *v_horarios, int n_act_horarios){
    int i=0;
    while(i<n_act_horarios-1)
    {
        fprintf(f_horarios, "%s-%s-%s-%s-%s\n", v_horarios[i].id_profesor, v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].id_materia, v_horarios[i].Grupo);   //Imprimimos en el fichero línea por línea.
        i++;
    }
    fprintf(f_horarios, "%s-%s-%s-%s-%s", v_horarios[i].id_profesor, v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].id_materia, v_horarios[i].Grupo);         //Imprimimos en el fichero línea por línea dejando la última sin retroceso de carro.

}
