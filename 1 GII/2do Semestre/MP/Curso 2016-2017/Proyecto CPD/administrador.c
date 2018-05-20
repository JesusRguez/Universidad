#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "ficheros.h"
#include "administrador.h"

//procesador
//include
//define
//var globas y externas
// def de tipos
//declara de funcones
//implementacion de funiones y main al final (si hay)


//Cabecera: void mostrar_menu_admin();
//Precondición:
//Postcondición:
void mostrar_menu_admin(){                                              //Esta función es pública.
    int i;
    do{
        printf("Bienvenido al menu de administrador.\n¿Que grupos desea gestionar?\n1.-Usuarios.\n2.-Alumnos.\n3.-Materias.\n4.-Horarios.\n5.-Salir del menu.\nElija una opcion: ");
        scanf("%d",&i);
        system("cls");
    }while(i<1 || i>5);                                             //Control de que el usuario introduzca bien la opcion deseada.

    switch(i){
        case 1: gestionar_Usuarios(&v_usuarios,&n_act_usuarios); break;
        case 2: gestionar_Alumnos(&v_alumnos,&n_act_alumnos);  break;
        case 3: gestionar_Materias(&v_materias, &n_act_materias); break;
        case 4: gestionar_Horarios(&v_horarios, &n_act_horarios); break;
        case 5: printf("Has salido del menu del administrador."); break;
    }
                                                         //Repetición del menú hasta que el usuario decida salir de él.
}



static void gestionar_Usuarios(usuarios **v_usuarios,int *n_act_usuarios){
    int i,j,n_usuarios;



                                        // n_act_usuarios. Esta variable es global, ya que en cada llamada a esta función, se incrementará n_act_usuarios, con el valor anterior, así el vector se conservará hasta la finalización del programa.
    do{
        do{
            system("cls");
            printf("Menu de administracion de usuarios: ¿Que desea hacer?\n1.-Dar de alta un usuario.\n2.-Dar de baja un usuario.\n3.-Modificar un usuario existente.\n4.-Mostrar los usuarios existentes en el sistema.\n5.-Volver al menu anterior.\nSelecccione una opcion: ");
            scanf("%d",&i);
        }while(i<1 || i>5);   //Comprobamos que la opción elegida está en el rango aceptado por el sistema.
        switch(i){
            case 1: //Dar de alta un usuario.
                alta_Usuarios(v_usuarios);
                break;

            case 2:
                eliminarUsuario(v_usuarios, n_act_usuarios);
                break;

            case 3: //Modifica usuario.

                modifico_Usuarios(v_usuarios);

                break;


            case 4:
                n_usuarios=*n_act_usuarios;     //Variable usada para la muestra de usuarios.
                mostrar_Usuarios(*v_usuarios, n_usuarios);
                system("pause");
                break;
            case 5: system("cls"); mostrar_menu_admin(); break; //En vez de volver saliendo de ésta función, llama a mostrar menú.
        }
        }while(i!=5);
}





static void gestionar_Alumnos(alumnos **v_alumnos,int *n_act_alumnos){
    int n_alumnos,j,k,i;
    char opcion;

    do{
        do{
            system("cls");
            printf("Menu de gestion de alumnos: ¿Que desea hacer?\n1.-Dar de alta un alumno.\n2.-Dar de baja un alumno.\n3.-Modificar un alumno existente.\n4.-Mostrar los alumnos existentes en el sistema.\n5.-Gestionar las matriculas de un alumno.\n6.-Volver al menu anterior.\nSelecccione un numero valido correspondiente a la opcion deseada: ");
            scanf("%d",&i);
            printf("\n\n");
        }while(i<1 || i>6);
        switch(i){
            case 1: //Dar de alta un alumno.
                alta_Alumno(v_alumnos);

                break;


            case 2: //Dar de baja un alumno ya existente.

                eliminar_Alumno(v_alumnos,n_act_alumnos);   //Llamamos a la función encargada de eliminar el alumno deseado de la lista de matriculados.

                break;

            case 3://Modificar un alumno existente.

                modificar_Alumnos(v_alumnos);

                 break;
            case 4://Mostrar todos los alumnos del sistema.

                n_alumnos=*n_act_alumnos;     //Variable usada para la muestra de alumnos.
                mostrar_Alumnos(*v_alumnos, n_alumnos);
                system("pause");
                break;
            case 5: //Gestionamos las matriculas de los alumnos.
                gestionar_matriculas_alumnos(v_alumnos, v_materias, v_matriculas);

                break;
            case 6:
                system("cls"); mostrar_menu_admin(); break;
        }
    }while(i!=6);
}


static void gestionar_matriculas_alumnos(alumnos *v_alumnos, materias *v_materias,matriculas *v_matriculas){
    int opcion;
    do{
        do{
            system("cls");
            printf("1.-Matricular un alumno de una nueva asignatura.\n2.-Eliminar matricula de una asignatura de un alumno.\n3.-Realizar cambios en una matricula existente de un alumno.\n4.-Mostrar las matriculas los alumnos.\n5.-Volver al menu anterior.\nSeleccione la opcion valida que desee: ");
            fflush(stdin);
            scanf("%d",&opcion);
        }while(opcion<1 || opcion>5);
        switch(opcion){


        case 1: alta_matricula_alumno(v_materias,v_matriculas);
            break;
        case 2:eliminar_matricula_alumno();
            break;
        case 3: modificar_matricula_alumno();
            break;
        case 4:mostrar_matriculas_alumno();
            break;
        case 5:
            break;
        }
    }while(opcion!=5);
}

static void alta_matricula_alumno(){
    char identi_alumno[5];
    char identi_materia[5];
    int i,existe,existe1;

    printf("Vas a dar de alta una nueva asignatura en la matricula de un alumno ya existente.\n");
    system("pause");
    do{
        existe=0;


        mostrar_Alumnos(v_alumnos,n_act_alumnos);

        printf("Selecciona de la lista el alumno a modificar: ");
        fflush(stdin);
        fgets(identi_alumno,5,stdin);
        for(i=0;i<n_act_alumnos;i++){//¿Existe  el alumno que has introducido?
            if(strcmp(v_alumnos[i].id_alum,identi_alumno)==0) existe=1;

        }
        if(existe==0) printf("\nEl alumno que has introducido no existe en el sistema.\n");
        system("pause");
        system("cls");

    }while(existe==0);

    do{
        existe1=0;
        printf("Introduzca el identificador de la materia a matricular. (Maximo 4 digitos).\n");
        fflush(stdin);
        fgets(identi_materia,5,stdin);
        for(i=0;i<n_act_materias;i++){//¿Existe identificador de materia en el sistema?
            if(strcmp(v_materias[i].id_materia,identi_materia)==0){
                existe1=1;
            }

        }
         if(existe1==1) {
            printf("\nIdentificador de matricula ya existente.\n") ;
            system("pause");
         }

         system("cls");
    }while(existe1==1);


    v_matriculas=(matriculas *)realloc((v_matriculas),((n_act_matriculas)+1)*sizeof(matriculas));
    v_materias=(materias *)realloc((v_materias),((n_act_materias)+1)*sizeof(materias));
    //Añadimos los datos correspondientes nuevos en cuanto al vector matriculas respecta.

    strcpy(v_matriculas[n_act_matriculas].id_materia,identi_materia);
    strcpy(v_matriculas[n_act_matriculas].id_alum,identi_alumno);


    //Añadimos los datos correspondientes nuevos en cuanto al vector materias respecta.

    strcpy(v_materias[n_act_materias].id_materia,identi_materia);

    printf("Introduzca el nombre de la materia a matricular.(Maximo 50 caracteres): ");
    fflush(stdin);
    gets(v_materias[n_act_materias].Nombre_materia);

    printf("Introduzca la abreviatura de la materia a matricular.(Maximo 3 caracteres): ");
    fflush(stdin);
    gets(v_materias[n_act_materias].Abrev_materia);


    n_act_materias++;
    n_act_matriculas++;

}



mostrar_matriculas_alumno(){
    int i;
    printf("Se mostraran en pantalla a continuacion todas las matriculas de los alumnos:\n");
    system("pause");
    for(i=0;i<n_act_matriculas;i++){
        printf("%s-%s\n",v_matriculas[i].id_materia,v_matriculas[i].id_alum);

    }

    printf("Se mostrara a continuacion la lista de materias existente en el sistema:\n\n ");
    system("pause");


    for(i=0;i<n_act_materias;i++){
        printf("%s-%s-%s\n",v_materias[i].id_materia,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);

    }
    system("pause");
}

static void eliminar_matricula_alumno(){
    int i,existe,existe2,existe3=0,j;
    char identi_alumno[5];
    char identi_materia[5];


    do{ // Controlamos la existencia del identificador del alumno introducido.
            existe=0;

            mostrar_Alumnos(v_alumnos,n_act_alumnos);

            printf("Selecciona de la lista el alumno a eliminar: ");
            fflush(stdin);
            fgets(identi_alumno,5,stdin);
            for(i=0;i<n_act_alumnos;i++){//¿Existe  el alumno que has introducido?
                if(strcmp(v_alumnos[i].id_alum,identi_alumno)==0) existe=1;

            }
            if(existe==0) printf("\nEl alumno que has introducido no existe en el sistema.\n");
            system("pause");
            system("cls");

        }while(existe==0);

    for(i=0;i<n_act_matriculas;i++){//Impresión por pantalla de las materias en las que se ha matriculado el alumno.
            if(strcmp(v_matriculas[i].id_alum,identi_alumno)==0){
                printf("%s-%s : correspondiente a ",v_matriculas[i].id_materia,v_matriculas[i].id_alum);
                for(j=0;j<n_act_materias;j++){
                    if(strcmp(v_matriculas[i].id_materia,v_materias[j].id_materia)==0){
                        printf("%s\n",v_materias[j].Nombre_materia);
                        existe3=1;
                    }
                }
            }

    }

if(existe3==1){

    do{ //Comprobamos que el identificador de la materia existe en el sistema y es correcto.
            existe=0;

            printf("\nIntroduzca el identificador de la materia a eliminar de la matricula del alumno seleccionado:");
            fflush(stdin);
            fgets(identi_materia,5,stdin);
            for(i=0;i<n_act_materias;i++){//¿Existe  el identificador que has introducido?
                if(strcmp(v_materias[i].id_materia,identi_materia)==0) existe=1;

            }
            if(existe==0) printf("\nEl identificador que has introducido no existe en el sistema.\n");
            system("pause");
            system("cls");

        }while(existe==0);

        //Eliminamos de los vectores matricula y materias: la materia seleccionada.
        //Vector matriculas.

        for(i=0; i<n_act_matriculas;i++){//Buscamos en el vector matriculas el alumno matriculado de tal asignatura.
                if(strcmp(v_matriculas[i].id_materia,identi_materia)==0 && strcmp(v_matriculas[i].id_alum,identi_alumno))
                    j=i;

        }

        for(i=j;i+1<n_act_matriculas;i++){//Eliminamos la matricula encontrada anteriormente.
            strcpy(v_matriculas[i].id_materia,v_matriculas[i+1].id_materia);
            strcpy(v_matriculas[i].id_alum,v_matriculas[i+1].id_alum);
        }


        n_act_matriculas--;
        v_matriculas=(matriculas *)realloc((v_matriculas),(n_act_matriculas)*sizeof(matriculas));
        printf("\nSe ha eliminado con exito del vector matricula\n");
        system("pause");

        //Vector materias.Eliminamos del vector la materia asociada si y solo si no existen mas alumnos
        //matriculados de esa materia.


        existe2=0;
        for(i=0;i<n_act_matriculas;i++){
                    if(strcmp(v_matriculas[i].id_materia,identi_materia)==0){
                        existe2=1;
                    }
        }
        if(existe2==1){ printf("\nExisten mas usuarios en el sistema matriculados de esa asignatura.\n");

        }else{
                    printf("\nNo existen en el sistema usuarios con esa asignatura ahora que has eliminado tal matricula, por lo que se procedera a eliminar dicha materia del sistema.\n");
                    for(i=0;i<n_act_materias;i++){
                        if(strcmp(v_materias[i].id_materia,identi_materia)==0) j=i;

                    }

                     for(i=j;i+1<n_act_materias;i++){
                        strcpy(v_materias[i].id_materia,v_materias[i+1].id_materia);
                        strcpy(v_materias[i].Nombre_materia,v_materias[i+1].Nombre_materia);
                        strcpy(v_materias[i].Abrev_materia,v_materias[i+1].Abrev_materia);
                    }
                    n_act_materias--;
                    v_materias=(materias *)realloc((v_materias),(n_act_materias)*sizeof(materias));
            }


        printf("\nProceso de eliminacion con exito.\n");
        system("pause");
        system("cls");

}else printf("\nEste alumno no tiene matriculas en el sistema.\n");
system("pause");

}

static void modificar_matricula_alumno(){
    int i,existe,existe2,j;
    char identi_alumno[5];
    char identi_materia[5];
    char identi_materia1[5];

    do{ // Controlamos la existencia del identificador del alumno introducido.
            existe=0;

            mostrar_Alumnos(v_alumnos,n_act_alumnos);

            printf("Selecciona de la lista el alumno a eliminar: ");
            fflush(stdin);
            fgets(identi_alumno,5,stdin);
            for(i=0;i<n_act_alumnos;i++){//¿Existe  el alumno que has introducido?
                if(strcmp(v_alumnos[i].id_alum,identi_alumno)==0) existe=1;

            }
            if(existe==0) printf("\nEl alumno que has introducido no existe en el sistema.\n");
            system("pause");
            system("cls");

        }while(existe==0);

        for(i=0;i<n_act_matriculas;i++){//Impresión por pantalla de las materias en las que se ha matriculado el alumno.
                if(strcmp(v_matriculas[i].id_alum,identi_alumno)==0){
                    printf("%s-%s : correspondiente a ",v_matriculas[i].id_materia,v_matriculas[i].id_alum);
                    for(j=0;j<n_act_materias;j++){
                        if(strcmp(v_matriculas[i].id_materia,v_materias[j].id_materia)==0){
                            printf("%s\n",v_materias[j].Nombre_materia);
                        }
                    }
                }

        }

        do{ //Comprobamos que el identificador de la materia existe en el sistema y es correcto.
            existe=0;

            printf("\nIntroduzca el identificador de la materia a eliminar de la matricula del alumno seleccionado:");
            fflush(stdin);
            fgets(identi_materia,5,stdin);
            for(i=0;i<n_act_matriculas;i++){//¿Existe  el identificador que has introducido relacionado con el alumno que has introducido?
                if(strcmp(v_matriculas[i].id_materia,identi_materia)==0){
                    if(strcmp(v_matriculas[i].id_alum,identi_alumno)==0){
                            existe=1;
                    }
                }

            }
            if(existe==0) printf("\nEl identificador que has introducido no existe en el sistema o no estar relacionado con el alumno que has introducido.\n");
            system("pause");
            system("cls");

        }while(existe==0);

        printf("\nIntroduce el nuevo identificador de materia (maximo 4 caracteres):");
        fflush(stdin);
        fgets(identi_materia1,5,stdin);

        for(i=0;i<n_act_matriculas;i++){
            if(strcmp(v_matriculas[i].id_alum,identi_alumno)==0){
                if(strcmp(v_matriculas[i].id_materia,identi_materia)==0){

                    strcpy(v_matriculas[i].id_materia,identi_materia1);
                    printf("\nMatricula cambiada con exito.\n");
                    system("pause");
                    system("cls");
                }
            }

        }




    existe2=0; //Comprobamos si quedan asignaturas no asignadas a alumnos y si tal, las eliminamos del sistema.
            for(i=0;i<n_act_matriculas;i++){
                        if(strcmp(v_matriculas[i].id_materia,identi_materia)==0){
                            existe2=1;
                        }
            }
            if(existe2==1) printf("\nExisten mas usuarios en el sistema matriculados de esa asignatura y no se puede prescindir de dicha materia en el sistema.\n");
            else{
                    printf("\nNo existen en el sistema usuarios con la asignatura anterior ahora que la has cambiado la matricula, por lo que se procedera a eliminar dicha materia del sistema.\n");
                    for(i=0;i<n_act_materias;i++){
                        if(strcmp(v_materias[i].id_materia,identi_materia)==0) j=i;

                    }

                     for(i=j;(i+1)<n_act_materias;i++){
                        strcpy(v_materias[i].id_materia,v_materias[i+1].id_materia);
                        strcpy(v_materias[i].Nombre_materia,v_materias[i+1].Nombre_materia);
                        strcpy(v_materias[i].Abrev_materia,v_materias[i+1].Abrev_materia);
                    }
                    n_act_materias--;
                    v_materias=(materias *)realloc((v_materias),(n_act_materias)*sizeof(materias));
            }


            printf("\nProceso de eliminacion con exito.\n");
            system("pause");
            system("cls");

            //Ahora que hemos cambiado la matricula, es posible que la nueva asignatura no exista en el sistema; si es así, debemos añadirla.

            existe=0;
            for(i=0;i<n_act_materias;i++){
                if(strcmp(v_materias[i].id_materia,identi_materia1)==0) existe=1;

            }

            if(existe==0){
                printf("\nLa asignatura nueva que has introducido anteriormente, no existe en el sistema. Se procedera a cargarla en la base de datos.\n");
                system("pause");

                v_materias=(materias *)realloc((v_materias),((n_act_materias)+1)*sizeof(materias));
                strcpy(v_materias[n_act_materias].id_materia,identi_materia1);

                printf("Introduzca el nombre de la materia a matricular.(Maximo 50 caracteres): ");
                fflush(stdin);
                gets(v_materias[n_act_materias].Nombre_materia);

                printf("Introduzca la abreviatura de la materia a matricular.(Maximo 3 caracteres): ");
                fflush(stdin);
                gets(v_materias[n_act_materias].Abrev_materia);


                n_act_materias++;

            }else{
                printf("La asignatura nueva que has introducido ya existe en el sistema, por lo que no es necesario hacer mas cambios.");
                system("pause");
                system("cls");

            }

}










static void alta_Usuarios(usuarios **v_usuarios){
    int j,i,condicion,condicion2;
    char id_user[4];

    condicion=1;
    condicion2=0;
    while(condicion!=0){

        system("cls");
        printf("Introduzca un identificador de usuario disponible: ");
        fflush(stdin);
        scanf("%3s",id_user);
        condicion2=0;
        for(i=0;i<n_act_alumnos;i++){       //Controlamos la introduccion en el sistema de identificadores de usuarios ya existentes.
            if(strcmp((*v_usuarios)[i].id_usuario,id_user)==0){
                printf("ERROR: Usuario ya existente\n");
                system("pause");
                condicion2=1;
            }
        }
        if(condicion2==0) condicion=0;
    }

    printf("Identificador disponible. \n");
    system("pause");

    *v_usuarios=(usuarios *)realloc((*v_usuarios),((n_act_usuarios)+1)*sizeof(usuarios)); //Le añadimos el +1 puesto que estamos reservando memoria dinámicamiente para un nuevo usuario, teniendo en cuenta que existe ya un vector reservado dinámicamente previamente.

    system("cls");

    //Dar de alta identificador de usuario.
    strcpy((*v_usuarios)[n_act_usuarios].id_usuario,id_user);
    system("cls");
    //Dar de alta nombre de usuario.
    printf("Por favor, introduzca el nombre del usuario: (20 caracteres como maximo)\n");
    fflush(stdin);
    gets((*v_usuarios)[n_act_usuarios].Nomb_usuario);

    system("cls");
    //Dar de alta tipo de perfil de usuario.
    printf("Elija el perfil de usuario que esta creando.Seleccione la opcion deseada:\n1.-Administrador.\n2.-Profesor.\nSeleccionar: ");
    scanf("%d",&j);
    if(j==1){
        strcpy((*v_usuarios)[n_act_usuarios].Perfil_usuario,"Administrador");}
    if(j==2){
        strcpy((*v_usuarios)[n_act_usuarios].Perfil_usuario,"Profesor");}

    system("cls");
    //Dar de alta nombre de usuario.
    printf("Por favor, introduzca el nombre de usuario con el que se identificara en el sistema: (Tiene un maximo de 5 caracteres.)\n");
    fflush(stdin);
    gets((*v_usuarios)[n_act_usuarios].Usuario);

    system("cls");
    //Dar de alta contrasena de usuario.
    printf("Finalmente, introduzca la contrasena del usuario: (Tiene un maximo de 8 caracteres y/o digitos)\n");
    fflush(stdin);
    gets((*v_usuarios)[n_act_usuarios].Contrasena);

    puts("Usuario anadido correctamente.");
    Sleep(2000);
    system("cls");

                (n_act_usuarios)++;    //Al haber un usuario más en el sistema, se incrementa la variable global.


}





static void modifico_Usuarios(usuarios **v_usuarios){

    int l,k,j,i;
    int existe=0;
    char id_user[4];
    char opcion;
    int condicion,condicion2;
    condicion=0;

    system("cls");

    for(i=0;i<n_act_usuarios;i++){
        printf("%s-%s-%s-%s-%s\n", (*v_usuarios)[i].id_usuario, (*v_usuarios)[i].Nomb_usuario, (*v_usuarios)[i].Perfil_usuario, (*v_usuarios)[i].Usuario, (*v_usuarios)[i].Contrasena);
    }

    while(existe!=1){
        printf("\nIntroduzca un identificador existente del usuario a modificar y pulse enter: ");
        fflush(stdin);
        fgets(id_user,4,stdin);

        for (l=0;l<n_act_usuarios;l++){                // Este bucle busca la posicion del registro en el vector de registros en la que se encuentre el registro cuyo campo identificador de usuario, coincida con el introducido por el usuario.
            if(strcmp((*v_usuarios)[l].id_usuario,id_user)==0){
                k=l;
                existe=1;
            }

        }
        if(existe==0){
            printf("\nHasta introducido un identificador inexistente.\n");
            system("pause");
            system("cls");
        }
    }
    system("cls");

    printf("Vas a modificar:\n %s-%s-%s-%s-%s\n", (*v_usuarios)[k].id_usuario, (*v_usuarios)[k].Nomb_usuario, (*v_usuarios)[k].Perfil_usuario, (*v_usuarios)[k].Usuario, (*v_usuarios)[k].Contrasena);

    //Modifica el identificador de usuario.
    printf("¿Quieres cambiar el identificador de este usuario (s/n): ");

        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");

            if (opcion=='s'){

                while(condicion!=1){

                    printf("Introduce el nuevo identificador de usuario: ");
                    fflush(stdin);
                    gets((*v_usuarios)[k].id_usuario);
                    condicion2=0;
                    for(i=0;i<n_act_usuarios;i++){
                        if(i!=k){
                            if(strcmp((*v_usuarios)[i].id_usuario,(*v_usuarios)[k].id_usuario)==0){
                                printf("ERROR : Identificador ya existente. Introduzca otro que este disponible. \n");
                                condicion2=1;
                            }

                        }

                    }
                if(condicion2==0) condicion=1;
                }

                }else printf("No has modificado el identificador de usuario.\n");
                system("cls");

        //Modifica el nombre de usuario del sistema.
        printf("¿Quieres modificar el nombre de usuario del sistema? (s/n): ");
        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");
        if (opcion=='s'){
            printf("Introduce el nuevo nombre de usuario del sistema:\n ");
            fflush(stdin);
            gets((*v_usuarios)[k].Nomb_usuario);
        }else printf("No has modificado el nombre de usuario del sistema.\n");
    system("cls");

    //Modifica el perfil de usuario.
    printf("¿Quieres modificar el perfil del usuario (s/n):  ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if(opcion=='s'){
        printf("¿Profesor (1) o Administrador (2) (Escribe el numero del perfil que desee:" );
        scanf("%d",&j);
        if(j==1)
            strcpy((*v_usuarios)[k].Perfil_usuario,"Profesor");
        if(j==2)
            strcpy((*v_usuarios)[k].Perfil_usuario,"Administrador");
    }else printf("No has modificado el perfil de usuario. \n");
    system("cls");

    //Modificar el nombre de usuario.
    printf("¿Quieres cambiar el nombre de este usuario (s/n):  ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){
        printf("Introduce el nuevo nombre de usuario: ");
        fflush(stdin);
        gets((*v_usuarios)[k].Usuario);
    }else printf("No has modificado el nombre de usuario.\n");
    system("cls");

    //Modificamos la contraseña.
    printf("¿Quieres cambiar la contrasena de este usuario (s/n): ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){
        printf("Introduce la nueva contrasena de este usuario: ");
        fflush(stdin);
        gets((*v_usuarios)[k].Contrasena);
    }else printf("No has modificado la contrasena de este usuario.\n");
    system("cls");
    printf("Usuario modificado correctamente.");
    Sleep(2000);
}


static void eliminarUsuario(usuarios **v_usuarios, int *n_act_usuarios){

    int i,u,condicion,existe=0,profesor=0,existe3,j,k,num_prof=0,existe1;
    char resp=' ';
    char id[4];
    char id_cop[4];
    char Profesor[]="Profesor";
    system("cls");


    do{
        system("cls");
        puts("Estos son los usuarios actuales en el sistema:");

        for(i=0;i<*n_act_usuarios;i++){
                printf("%s-%s-%s-%s-%s\n", (*v_usuarios)[i].id_usuario, (*v_usuarios)[i].Nomb_usuario, (*v_usuarios)[i].Perfil_usuario, (*v_usuarios)[i].Usuario, (*v_usuarios)[i].Contrasena);
            }

        printf("Introduzca el id del usuario a eliminar: ");
        fflush(stdin);
        scanf("%3s",id);
        system("cls");

        if(strcmp(id,id_act)==0){
                printf("Estas eliminando un usuario con una sesion de usuario ya iniciada. ERROR. \n");
                system("pause");
                condicion=1;

        }else condicion=0;


     }while(condicion!=0);
     //WHAT?


    for(i=0; i <(*n_act_usuarios);i++){//Comprobamos si el usuario introducido existe en el sistema.

            if(strcmp((*v_usuarios)[i].id_usuario,id)==0){

                u=i;
                existe=1;


            }

        }



        for(i=0; i<(*n_act_usuarios);i++){//Comprobamos si es profesor el identificador introducido.

            if(strcmp((*v_usuarios)[i].id_usuario,id)==0){

                    if(strcmp((*v_usuarios)[i].Perfil_usuario,Profesor)==0){
                        profesor=1;
                    }


                }


        }

    if(existe==1){
        while(resp!='s' && resp!='n'){

            printf("Se va a eliminar el siguiente usuario: %s-%s-%s-%s-%s\n",(*v_usuarios)[u].id_usuario,(*v_usuarios)[u].Nomb_usuario,(*v_usuarios)[u].Perfil_usuario,(*v_usuarios)[u].Usuario,(*v_usuarios)[u].Contrasena);
            printf("Confirmar eliminar usuario? (s/n)\n");
            fflush(stdin);
            scanf("%c",&resp);

        }

        if(resp=='s'){

            for(i=u;i+1<(*n_act_usuarios);i++){

                strcpy((*v_usuarios)[i].id_usuario,(*v_usuarios)[i+1].id_usuario);
                strcpy((*v_usuarios)[i].Nomb_usuario,(*v_usuarios)[i+1].Nomb_usuario);
                strcpy((*v_usuarios)[i].Perfil_usuario,(*v_usuarios)[i+1].Perfil_usuario);
                strcpy((*v_usuarios)[i].Usuario,(*v_usuarios)[i+1].Usuario);
                strcpy((*v_usuarios)[i].Contrasena,(*v_usuarios)[i+1].Contrasena);

            }

            printf("Usuario eliminado correctamente.");
            Sleep(2000);
            system("cls");
            (*n_act_usuarios)--;

            *v_usuarios=(usuarios *)realloc((*v_usuarios),(*n_act_usuarios)*sizeof(usuarios));

            if(profesor==1){//Si corresponde a un profesor el usuario que hemos eliminado, debemos eliminar los horarios asociados a tal profesor.



//AQUI ESTA EL PROBLEMA.


do{
                    existe1=0;
                    for(i=0;i<n_act_horarios;i++){//Busqueda del horario asociado al profesor.
                        if(strcmp(v_horarios[i].id_profesor,id)==0){
                            existe1=1;
                            u=i;

                        }

                    }

                    for(j=u;j+1<n_act_horarios;j++){//Eliminación del horario seleccionado y encontrado anteriormente.
                            strcpy(v_horarios[j].id_profesor, v_horarios[j+1].id_profesor);
                            strcpy(v_horarios[j].Dia_clase, v_horarios[j+1].Dia_clase);
                            strcpy(v_horarios[j].Hora_clase, v_horarios[j+1].Hora_clase);
                            strcpy(v_horarios[j].id_materia, v_horarios[j+1].id_materia);
                            strcpy(v_horarios[j].Grupo, v_horarios[j+1].Grupo);

                    }

                    if(existe1==1) n_act_horarios--;


            }while(existe1==1);

             v_horarios=(horarios *)realloc((v_horarios),(n_act_horarios)*sizeof(horarios));

        }


        }else{

            printf("Se ha cancelado la eliminacion del usuario\n");
            Sleep(2000);

        }
    }else {
        printf("Usuario no existente en el sistema");
        Sleep(2000);
        system("cls");

    }


}



static void mostrar_Usuarios(usuarios *v_usuarios, int n_usuarios){
    int i;
    system("cls");
    puts("Estos son los usuarios actuales en el sistema:");
    for(i=0;i<n_usuarios;i++){
        printf("%s-%s-%s-%s-%s\n", v_usuarios[i].id_usuario, v_usuarios[i].Nomb_usuario, v_usuarios[i].Perfil_usuario, v_usuarios[i].Usuario, v_usuarios[i].Contrasena);
    }

}

void static mostrar_Alumnos(alumnos *v_alumnos, int n_alumnos){
    int i;
    system("cls");
    puts("Estos son los alumnos actuales en el sistema:");
    for(i=0;i<n_alumnos;i++){
        printf("%s-%s-%s-%s-%s-%s\n", v_alumnos[i].id_alum, v_alumnos[i].Nombre_alum, v_alumnos[i].Direc_alum, v_alumnos[i].Local_alum, v_alumnos[i].Curso, v_alumnos[i].Grupo);
    }

}


void static eliminar_Alumno(alumnos **v_alumnos, int *n_act_alumnos){

    int i,existe=0,existe1=0,existe2;
    int u;
    char resp=' ';
    char id[7];
    system("cls");


    puts("Estos son los alumnos actuales en el sistema:");

    for(i=0;i<(*n_act_alumnos);i++){
            printf("%s-%s-%s-%s-%s-%s\n", (*v_alumnos)[i].id_alum, (*v_alumnos)[i].Nombre_alum, (*v_alumnos)[i].Direc_alum, (*v_alumnos)[i].Local_alum, (*v_alumnos)[i].Curso,(*v_alumnos)[i].Grupo);
        }

    printf("Introduzca el id del alumno a eliminar: ");
    fflush(stdin);
    scanf("%6s",id);
    system("cls");
    for(i=0; i <(*n_act_alumnos);i++){

            if(strcmp((*v_alumnos)[i].id_alum,id)==0){

                u=i;
                existe=1;
            }

        }
    if(existe==1){
        while(resp!='s' && resp!='n'){

            printf("Se va a eliminar el siguiente alumno: %s-%s-%s-%s-%s-%s\n", (*v_alumnos)[u].id_alum, (*v_alumnos)[u].Nombre_alum, (*v_alumnos)[u].Direc_alum, (*v_alumnos)[u].Local_alum, (*v_alumnos)[u].Curso,(*v_alumnos)[u].Grupo);
            printf("Confirmar eliminar alumno? (s/n)\n");
            fflush(stdin);
            scanf("%c",&resp);

        }

        if(resp=='s'){

            for(i=u;i+1<(*n_act_alumnos);i++){

                strcpy((*v_alumnos)[i].id_alum,(*v_alumnos)[i+1].id_alum);
                strcpy((*v_alumnos)[i].Nombre_alum,(*v_alumnos)[i+1].Nombre_alum);
                strcpy((*v_alumnos)[i].Direc_alum,(*v_alumnos)[i+1].Direc_alum);
                strcpy((*v_alumnos)[i].Local_alum,(*v_alumnos)[i+1].Local_alum);
                strcpy((*v_alumnos)[i].Curso,(*v_alumnos)[i+1].Curso);
                strcpy((*v_alumnos)[i].Grupo,(*v_alumnos)[i+1].Grupo);
            }

            printf("Alumno eliminado correctamente.");
            Sleep(2000);
            system("cls");
            (*n_act_alumnos)--;

            *v_alumnos=(alumnos *)realloc((*v_alumnos),(*n_act_alumnos *sizeof(alumnos)));

            //Debemos también eliminar toda la información relacionada con ese alumno, como las faltas, horarios y calificaciones.
            //Calificaciones.

            do{
                    existe2=0;
                    for(i=0;i<n_act_calificaciones;i++){//Busqueda de la calificacion asociada al alumno.
                        if(strcmp(v_calificaciones[i].id_alum,id)==0){
                            existe2=1;
                            u=i;

                        }

                    }


                    for(i=u;i+1<n_act_calificaciones;i++){//Eliminación de la calificación seleccionada y encontrada anteriormente.
                            strcpy(v_calificaciones[i].Descrip_calif,v_calificaciones[i+1].Descrip_calif);
                            strcpy(v_calificaciones[i].Fecha_calif.ano,v_calificaciones[i+1].Fecha_calif.ano);
                            strcpy(v_calificaciones[i].Fecha_calif.dia,v_calificaciones[i+1].Fecha_calif.dia);
                            strcpy(v_calificaciones[i].Fecha_calif.mes,v_calificaciones[i+1].Fecha_calif.mes);
                            strcpy(v_calificaciones[i].id_alum,v_calificaciones[i+1].id_alum);
                            strcpy(v_calificaciones[i].id_materia,v_calificaciones[i+1].id_materia);

                    }
                    if(existe2==1){  n_act_calificaciones--;}


            }while(existe2==1);


             v_calificaciones=(calificaciones *)realloc((v_calificaciones),(n_act_calificaciones)*sizeof(calificaciones));


             //Faltas.



              do{
                    existe1=0;
                    for(i=0;i<n_act_faltas;i++){//Busqueda de la falta asociada al alumno.
                        if(strcmp(v_faltas[i].id_alum,id)==0){
                            existe1=1;
                            u=i;

                        }

                    }

                    for(i=u;i+1<n_act_faltas;i++){//Eliminación de la calificación seleccionada y encontrada anteriormente.
                            strcpy(v_faltas[i].Descrip_falta,v_faltas[i+1].Descrip_falta);
                            strcpy(v_faltas[i].Estado_falta,v_faltas[i+1].Estado_falta);
                            strcpy(v_faltas[i].Fecha_falta.ano,v_faltas[i+1].Fecha_falta.ano);
                            strcpy(v_faltas[i].Fecha_falta.dia,v_faltas[i+1].Fecha_falta.dia);
                            strcpy(v_faltas[i].Fecha_falta.mes,v_faltas[i+1].Fecha_falta.mes);
                            strcpy(v_faltas[i].Hora_falta,v_faltas[i+1].Hora_falta);
                            strcpy(v_faltas[i].id_alum,v_faltas[i+1].id_alum);

                    }
                    if(existe1==1) n_act_faltas--;


            }while(existe1==1);

             v_faltas=(faltas *)realloc((v_faltas),(n_act_faltas)*sizeof(faltas));

             //Matriculas asociadas.

             do{
                                existe1=0;
                                for(i=0;i<n_act_matriculas;i++){//Busqueda de la matricula asociada al alumno.
                                    if(strcmp(v_matriculas[i].id_alum,id)==0){
                                        existe1=1;
                                        u=i;

                                    }

                                }

                                for(i=u;i+1<n_act_matriculas;i++){//Eliminación de la matricula seleccionada y encontrada anteriormente.
                                        strcpy(v_matriculas[i].id_materia,v_matriculas[i+1].id_materia);
                                        strcpy(v_matriculas[i].id_alum,v_matriculas[i+1].id_alum);


                                }
                                if(existe1==1) n_act_matriculas--;


                        }while(existe1==1);

                        v_matriculas=(matriculas *)realloc((v_matriculas),(n_act_matriculas)*sizeof(matriculas));


        }else{

            printf("Se ha cancelado la eliminacion del alumno\n");
            Sleep(2000);

        }

    }else{
        printf("Alumno no existente en el sistema.");
        Sleep(2000);
        system("cls");
    }
}


static void modificar_Alumnos(alumnos **v_alumnos){
    char id_alumno[7];
    int j,k,i;
    int existe=0;
    char opcion;
    int condicion=0;
    int condicion2;
    system("cls");

    while(existe!=1){
        for(i=0;i<n_act_alumnos;i++){
            printf("%s-%s-%s-%s-%s-%s\n", (*v_alumnos)[i].id_alum, (*v_alumnos)[i].Nombre_alum, (*v_alumnos)[i].Direc_alum, (*v_alumnos)[i].Local_alum, (*v_alumnos)[i].Curso, (*v_alumnos)[i].Grupo);
        }

        printf("Vas a modificar un alumno. Introduzca el identificador del alumno a modificar (maximo 6 digitos): ");
        fflush(stdin);
        gets(id_alumno);

        for (j=0;j<n_act_alumnos;j++){                // Este bucle busca la posicion del registro en el vector de registros en la que se encuentre el registro cuyo campo identificador de alumno, coincida con el introducido por el usuario.
            if(strcmp((*v_alumnos)[j].id_alum,id_alumno)==0){
                k=j;
                existe=1;
            }
        }
        if(existe==0){
            printf("\nEl alumno no existe en el sistema.\n");
            system("pause");
            system("cls");
        }
    }
    printf("Vas a modificar:\n %s-%s-%s-%s-%s-%s\n", (*v_alumnos)[k].id_alum, (*v_alumnos)[k].Nombre_alum, (*v_alumnos)[k].Direc_alum,(*v_alumnos)[k].Local_alum, (*v_alumnos)[k].Curso, (*v_alumnos)[k].Grupo);


    //Modifica el identificador del alumno.
    printf("¿Quieres cambiar el identificador de este alumno (s/n): ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){

        while(condicion!=1){

            printf("Introduce el nuevo identificador del alumno: ");
            fflush(stdin);
            gets((*v_alumnos)[k].id_alum);
            condicion2=0;
            //Comprueba si el identificador ya existe en el sistema.
            for(i=0;i<n_act_alumnos;i++){
                if(i!=k){
                    if(strcmp((*v_alumnos)[i].id_alum,(*v_alumnos)[k].id_alum)==0){
                        printf("ERROR : Identicador ya existente. Introduzca otro que este disponible.\n");
                        condicion2=1;
                    }
                }
            }
            if(condicion2==0) condicion=1;
        }


    }else printf("No has modificado el identificador del alumno.\n");
    system("cls");


    //Modifica el nombre del alumno.
    printf("¿Quieres cambiar el nombre de este alumno (s/n): ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){
        printf("Introduce el nuevo nombre del alumno: ");
        fflush(stdin);
        gets((*v_alumnos)[k].Nombre_alum);
    }else printf("No has modificado el nombre del alumno.\n");
    system("cls");


    //Modifica la direccion del alumno.
    printf("¿Quieres cambiar la direccion de este alumno (s/n): ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){
        printf("Introduce la nueva direccion del alumno: ");
        fflush(stdin);
        gets((*v_alumnos)[k].Direc_alum);
    }else printf("No has modificado la direccion del alumno.\n");
    system("cls");


    //Modifica el curso del alumno.
    printf("¿Quieres cambiar el curso asociado a este alumno (s/n): ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){
    printf("Introduce el nuevo curso del alumno: ");
    fflush(stdin);
    gets((*v_alumnos)[k].Curso);
    }else printf("No has modificado el curso asocial a este alumno.\n");
    system("cls");

    //Modifica el grupo del alumno.
    printf("¿Quieres cambiar el grupo de este alumno (s/n): ");
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");
    if (opcion=='s'){
        printf("Introduce el nuevo grupo del alumno: ");
        fflush(stdin);
        gets((*v_alumnos)[k].Grupo);
    }else printf("No has modificado el grupo del alumno.\n");

    system("cls");
    printf("Alumno modificado correctamente.");
    Sleep(2000);



}


static void alta_Alumno(alumnos **v_alumnos){
    int i,id_alum[7];
    int condicion=1;
    int condicion2;

    while(condicion!=0){
        system("cls");
        printf("Introduzca un identificador disponible en el sistema: ");
        fflush(stdin);
        scanf("%6s",id_alum);
        condicion2=0;

        for(i=0;i<n_act_alumnos;i++){       //Controlamos la introduccion en el sistema de identificadores de alumnos ya existentes.
            if(strcmp((*v_alumnos)[i].id_alum,id_alum)==0){
                printf("ERROR:Alumno ya existente\n");
                system("pause");
                condicion2=1;
            }
        }if(condicion2==0) condicion=0;
    }
    system("cls");

    printf("Identificador disponible. \n");
    system("pause");

    *v_alumnos=(alumnos *)realloc((*v_alumnos),((n_act_alumnos)+1)*sizeof(alumnos)); //Le añadimos el +1 puesto que estamos reservando memoria dinámicamiente para un nuevo alumno, teniendo en cuenta que existe ya un vector reservado dinámica y previamente.

    system("cls");
    printf("Va a dar de alta un nuevo alumno en el sistema. Siga las instrucciones indicadas, por favor.\n");

    //Dar de alta el identificador escolar del alumno.
    strcpy((*v_alumnos)[n_act_alumnos].id_alum,id_alum);
    system("cls");

    //Dar de alta el nombre del alumno.
    printf("\nIntroduzca el nombre del alumno (maximo 20 caracteres contando espacios):\n");
    fflush(stdin);
    gets((*v_alumnos)[n_act_alumnos].Nombre_alum);
    system("cls");

    //Dar de alta la direccion del alumno.
    printf("Introduzca a continuacion la direccion asociada al alumno (maximo 30 caracteres contando espacios):\n");
    fflush(stdin);
    gets((*v_alumnos)[n_act_alumnos].Direc_alum);
    system("cls");

    //Dar de alta la localidad del alumno.
    printf("Introduzca la localidad asociada al alumno (maximo 30 caracteres contando espacios):\n");
    fflush(stdin);
    gets((*v_alumnos)[n_act_alumnos].Local_alum);
    system("cls");

    //Dar de alta el curso academico del alumno.
    printf("Introduzca el curso asociado al alumno (maximo 30 caracteres contando espacios):\n");
    fflush(stdin);
    gets((*v_alumnos)[n_act_alumnos].Curso);
    system("cls");

    //Dar de alta el grupo academico del alumno.
    printf("Introduzca el grupo asociado al alumno (maximo 30 caracteres contando espacios):\n");
    fflush(stdin);
    gets((*v_alumnos)[n_act_alumnos].Grupo);
    system("cls");

    printf("\nAlumno registrado.\n");
    (n_act_alumnos)++;   //Se ha creado un nuevo alumnos en el sistema, por lo que esta variable global se debe de incrementar.
    system("pause");
    system("cls");
}

static void gestionar_Materias()
{
    int i = 0;  //Selector de opciones

    do
    {
        do  //Menú de selección de opciones
        {
            system("cls");
            puts("Menu de administracion de materias.");
            puts("1.-Dar de alta una materia.");
            puts("2.-Dar de baja una materia.");
            puts("3.-Modificar una materia existente.");
            puts("4.-Mostrar las materias existentes en el sistema.");
            puts("5.-Volver al menu anterior.");
            puts("Selecccione una opcion: ");
            scanf("%d", &i);
        }while (i < 1 || i > 5);    //Comprobación de que la opción elegida esté dentro del rango

        switch(i)   //Salto a cada una de las funciones de edición de materias
        {
        case 1: anadir_Materia(); break;
        case 2: eliminar_Materia(); break;
        case 3: modificar_Materia(); break;
        case 4:
            mostrar_Materias();
            system("pause");
            break;
        case 5:
            system("cls");
            mostrar_menu_admin();
            break;
        }
    }while (i != 5);    //Tras cada llamada a una de las funciones de edición se volverá al menú principal de materias
}

static void anadir_Materia()
{
    int i = 0;
    char id_aux[5], resp;

    do
    {
        //Segmento de solicitudes al usuario y almacenamiento en variable auxiliar y v_materias

        mostrar_Materias(); //Llamadas a mostrar_Materias para facilitar la visualización de las materias existentes en el sistema

        printf("Va a dar de alta una nueva materia en el sistema. Por favor, introduzca el identificador de la materia deseada. (4 digitos):\n");
        fflush(stdin);
        scanf("%4s", id_aux);

        for (i = 0; i < n_act_materias; i++)  //Comprobación de errores. Si la id introducida ya existe se vuelve al menú de materias
        {
            if (strcmp(id_aux, v_materias[i].id_materia) == 0)
            {
                system("cls");
                puts("Materia ya existente en el sistema.\n");
                system("pause");
                return;
            }
        }

        v_materias = (materias *)realloc(v_materias, (n_act_materias+1)*sizeof(materias));  //Incremento del espacio del vector v_materias para dar cabida a una nueva materia
        strcpy(v_materias[n_act_materias].id_materia, id_aux);  //Los nuevos datos se colocan en la última posición del vector realocado

        mostrar_Materias();

        printf("Por favor, introduzca el nombre de la materia (50 caracteres como maximo):\n");
        fflush(stdin);
        gets(v_materias[n_act_materias].Nombre_materia);

        mostrar_Materias();

        printf("Por favor, introduzca el nombre abreviado de la materia (siglas) (3 caracteres):\n");
        fflush(stdin);
        scanf("%3s", v_materias[n_act_materias].Abrev_materia);

        (n_act_materias)++;    //Número de materias + 1

        system("cls");
        puts("Materia anadida correctamente.\n");
        puts("Anadir otra materia? (s/n)");
        fflush(stdin);
        scanf("%c", &resp);
    }while (resp == 's' || resp == 'S');
}

static void eliminar_Materia()
{
    int i = 0, u = -2;
    char resp, id[4];

    if (n_act_materias == 0)
    {
        system("cls");
        puts("No hay materias actualmente en el sistema.\n");
        system("pause");
        return;
    }
    else
    {
        mostrar_Materias(); //Llamada a mostrar_Materias para facilitar la selección de la materia a eliminar

        printf("Introduzca el ID de la materia a eliminar: ");
        fflush(stdin);
        scanf("%4s", &id);

        for(i = 0; i < (n_act_materias) && i != u+1; i++)   //Búsqueda iterativa de la id introducida por el usuario
        {
            if(strcmp(v_materias[i].id_materia, id) == 0)
            {
                u = i;  //u es un auxiliar que almacena la posición de la materia encontrada dentro del vector
            }
        }

        if (i != u+1)   //Comprobación de errores. Si la id introducida no existe se vuelve al menú de materias
        {
            system("cls");
            puts("ID no encontrada. Vuelva a introducir la materia.\n");
            system("pause");
            return;
        }

        do  //Confirmación de la eliminación de la materia
        {
            printf("\nSe va a eliminar la siguiente materia: %s-%s-%s\n", v_materias[u].id_materia, v_materias[u].Nombre_materia, v_materias[u].Abrev_materia);
            puts("Confirmar eliminar materia? (s/n)");
            fflush(stdin);
            scanf("%c", &resp);
        }while(resp != 's' && resp != 'n');

        if(resp == 's')
        {
            for(i = u; i+1 < (n_act_materias); i++) //Se mueven a la izquierda en el vector cada una de las materias desde la materia seleccionada
            {
                strcpy(v_materias[i].id_materia, v_materias[i+1].id_materia);
                strcpy(v_materias[i].Nombre_materia, v_materias[i+1].Nombre_materia);
                strcpy(v_materias[i].Abrev_materia, v_materias[i+1].Abrev_materia);
            }

            system("cls");
            printf("Se ha eliminado la materia satisfactoriamente.\n\n");
            system("pause");
            (n_act_materias)--; //Número de materias - 1

            v_materias = (materias *)realloc(v_materias, n_act_materias*sizeof(materias));  //Decremento del espacio del vector v_materias para eliminar el espacio sin usar
        }

        else    //Mensaje en caso de que se cancele la eliminación
        {
            puts("\nSe ha cancelado la eliminacion de la materia.\n");
            system("pause");
        }
    }
}

static void modificar_Materia()
{
    int i = 0, u = -2, elect;
    char  id[4];

    if (n_act_materias == 0)
    {
        system("cls");
        puts("No hay materias actualmente en el sistema.\n");
        system("pause");
        return;
    }
    else
    {
        puts("Menu de modificacion de materias.\n");
        mostrar_Materias(); //Llamada a mostrar_Materias para facilitar la selección de la materia a modificar
        puts("Introduzca el ID de la materia a modificar:");
        fflush(stdin);
        scanf("%4s", &id);

        for(i = 0; i < (n_act_materias) && i != u+1; i++)   //Búsqueda iterativa de la id introducida por el usuario
        {
            if(strcmp(v_materias[i].id_materia, id) == 0)
            {
                u = i;  //u es un auxiliar que almacena la posición de la materia encontrada dentro del vector
            }
        }

        if (i != u+1)   //Comprobación de errores. Si la id introducida no existe se vuelve al menú de materias
        {
            system("cls");
            puts("ID no encontrada. Vuelva a introducir la materia.\n");
            system("pause");
            return;
        }

        do  //Menú de selección de opciones de modificación
        {
            mostrar_Materias();
            printf("Ha seleccionado la materia: %s-%s-%s\n\n", v_materias[u].id_materia, v_materias[u].Nombre_materia, v_materias[u].Abrev_materia);
            puts("Elija una opcion.");
            puts("1.-Cambiar el ID de la materia.");
            puts("2.-Cambiar el nombre de la materia.");
            puts("3.-Cambiar la abreviatura de la materia.");
            puts("4.-Salir.");

            scanf("%d", &elect);

            system("cls");
            printf("Ha seleccionado la materia: %s-%s-%s\n\n", v_materias[u].id_materia, v_materias[u].Nombre_materia, v_materias[u].Abrev_materia);

            switch(elect)   //Salto a cada una de las funcionalidades de modificación de materias
            {
            case 1:
                printf("Introduzca la nueva ID de la materia (4 digitos): ");
                fflush(stdin);
                scanf("%4s", v_materias[u].id_materia); //Se sobreescriben los datos introducidos directamente en el vector
                break;
            case 2:
                printf("Introduzca el nuevo nombre de la materia (50 caracteres como maximo): ");
                fflush(stdin);
                gets(v_materias[u].Nombre_materia);
                break;
            case 3:
                printf("Introduzca la nueva abreviatura de la materia (3 caracteres): ");
                fflush(stdin);
                scanf("%3s", v_materias[u].Abrev_materia);
                break;
            case 4:
                return;
                break;
            }
            printf("\nSe ha realizado el cambio correctamente. Materia resultante: %s-%s-%s\n\n", v_materias[u].id_materia, v_materias[u].Nombre_materia, v_materias[u].Abrev_materia); //Impresión del resultado
            system("pause");
        }while (elect != 4);    //Tras cada llamada a una de las funcionalidades de modificación se volverá al menú principal de modificación de materias
    }
}

static void mostrar_Materias()
{
    int i = 0;
    system("cls");  //Limpieza de la pantalla para facilitar la legibilidad

    if (n_act_materias == 0)
    {
        puts("No hay materias actualmente en el sistema.");
    }
    else
    {
        puts("Estas son las materias actuales en el sistema:\n");
        for(i = 0; i < n_act_materias; i++) //Búsqueda iterativa de cada una de las materias
        {
            printf("%s-%s-%s\n", v_materias[i].id_materia, v_materias[i].Nombre_materia, v_materias[i].Abrev_materia);  //Impresión por pantalla
        }
    }
    puts("");
}

static void gestionar_Horarios()
{
    int i = 0;  //Selector de opciones

    do
    {
        do  //Menú de selección de opciones
        {
            system("cls");
            puts("Menu de administracion de horarios.");
            puts("1.-Anadir horas de clase.");
            puts("2.-Eliminar horas de clase.");
            puts("3.-Modificar horas de clase.");
            puts("4.-Mostrar los horarios existentes en el sistema.");
            puts("5.-Volver al menu anterior.");
            puts("Selecccione una opcion: ");
            scanf("%d", &i);
        }while (i < 1 || i > 5);    //Comprobación de que la opción elegida esté dentro del rango

        switch(i)   //Salto a cada una de las funciones de edición de horarios
        {
        case 1: anadir_Horario(); break;
        case 2: eliminar_Horario(); break;
        case 3: modificar_Horario(); break;
        case 4:
            mostrar_Horarios();
            system("pause");
            break;
        case 5:
            system("cls");
            mostrar_menu_admin();
            break;
        }
    }while (i != 5);    //Tras cada llamada a una de las funciones de edición se volverá al menú principal de horarios
}

static void anadir_Horario()
{
    int i = 0;
    char id_aux[4], dia_aux[2], hora_aux[2], resp;

    do
    {
        //Segmento de solicitudes al usuario y almacenamiento en variables auxiliares y v_horarios

        mostrar_Horarios(); //Llamadas a mostrar_Horarios para facilitar la visualización de las clases existentes en el sistema

        printf("Va a anadir en el sistema una hora de clase a un profesor. Por favor, introduzca el identificador del profesor. (3 digitos):\n");
        fflush(stdin);
        scanf("%3s", id_aux);

        mostrar_Horarios();

        printf("Por favor, introduzca el dia de la clase (1-5):\n");
        fflush(stdin);
        scanf("%1s", dia_aux);

        mostrar_Horarios();

        printf("Por favor, introduzca la hora de la clase (1-6):\n");
        fflush(stdin);
        scanf("%1s", hora_aux);

        for (i = 0; i < n_act_horarios; i++)  //Comprobación de errores. Si la id, dia y hora introducidos ya existen se vuelve al menú de horarios
        {
            if (strcmp(id_aux, v_horarios[i].id_profesor) == 0)
            {
                if (strcmp(dia_aux, v_horarios[i].Dia_clase) == 0)
                {
                    if (strcmp(hora_aux, v_horarios[i].Hora_clase) == 0)
                    {
                        system("cls");
                        puts("Hora ya ocupada en el sistema. Para modificar la clase seleccionada, acceda al menu de modificacion.\n");
                        system("pause");
                        return;
                    }
                }
            }
        }

        v_horarios = (horarios *)realloc(v_horarios, (n_act_horarios+1)*sizeof(horarios));  //Incremento del espacio del vector v_horarios para dar cabida a una nueva clase en el horario
        strcpy(v_horarios[n_act_horarios].id_profesor, id_aux); //Los nuevos datos se colocan en la última posición del vector realocado
        strcpy(v_horarios[n_act_horarios].Dia_clase, dia_aux);
        strcpy(v_horarios[n_act_horarios].Hora_clase, hora_aux);

        mostrar_Horarios();

        printf("Por favor, introduzca el identificador de la materia: (4 digitos)\n");
        fflush(stdin);
        scanf("%4s", v_horarios[n_act_horarios].id_materia);

        mostrar_Horarios();

        printf("Por ultimo, introduzca el grupo de la clase (10 caracteres como maximo):\n");
        fflush(stdin);
        gets(v_horarios[n_act_horarios].Grupo);

        (n_act_horarios)++; //Número de horarios + 1

        system("cls");
        puts("Clase anadida correctamente.\n");
        puts("Anadir otra clase al horario? (s/n)");
        fflush(stdin);
        scanf("%c", &resp);
    }while (resp == 's' || resp == 'S');
}

static void eliminar_Horario()
{
    int i = 0, u = -2;
    char resp, id[4], Dia[2], Hora[2];

    if (n_act_horarios == 0)
    {
        system("cls");
        puts("No hay clases actualmente en el sistema.\n");
        system("pause");
        return;
    }
    else
    {
        mostrar_Horarios(); //Llamadas a mostrar_Horarios para facilitar la selección de la clase en el horario a eliminar

        //Segmento de solicitudes al usuario, se necesitan 3 datos para identificar una clase específica en el horario

        printf("Introduzca el ID del profesor de la clase a eliminar: ");
        fflush(stdin);
        scanf("%3s", &id);

        mostrar_Horarios();

        printf("Introduzca el dia de la clase a eliminar: ");
        fflush(stdin);
        scanf("%1s", &Dia);

        mostrar_Horarios();

        printf("Introduzca la hora de la clase a eliminar: ");
        fflush(stdin);
        scanf("%1s", &Hora);

        for(i = 0; i < (n_act_horarios) && i != u+1; i++)   //Búsqueda iterativa de la id, dia y hora introducidos por el usuario
        {
            if (strcmp(v_horarios[i].id_profesor, id) == 0)
            {
                if (strcmp(v_horarios[i].Dia_clase, Dia) == 0)
                {
                    if (strcmp(v_horarios[i].Hora_clase, Hora) == 0)
                    {
                        u = i;  //u es un auxiliar que almacena la posición de la clase del horario encontrada dentro del vector
                    }
                }
            }
        }

        if (i != u+1)   //Comprobación de errores. Si la id introducida no existe se vuelve al menú de horarios
        {
            system("cls");
            puts("Informacion incorrecta. Vuelva a introducir los datos.\n");
            system("pause");
            return;
        }

        do  //Confirmación de la eliminación de la clase del horario
        {
            printf("\nSe va a eliminar la siguiente clase: %s-%s-%s-%s-%s\n", v_horarios[u].id_profesor, v_horarios[u].Dia_clase, v_horarios[u].Hora_clase, v_horarios[u].id_materia, v_horarios[u].Grupo);
            puts("Confirmar eliminar clase? (s/n)");
            fflush(stdin);
            scanf("%c", &resp);
        }while(resp != 's' && resp != 'n');

        if(resp == 's')
        {
            for(i = u; i+1 < (n_act_horarios); i++) //Se mueven a la izquierda en el vector cada una de las materias desde la materia seleccionada
            {
                strcpy(v_horarios[i].id_profesor, v_horarios[i+1].id_profesor);
                strcpy(v_horarios[i].Dia_clase, v_horarios[i+1].Dia_clase);
                strcpy(v_horarios[i].Hora_clase, v_horarios[i+1].Hora_clase);
                strcpy(v_horarios[i].id_materia, v_horarios[i+1].id_materia);
                strcpy(v_horarios[i].Grupo, v_horarios[i+1].Grupo);
            }

            system("cls");
            printf("Se ha eliminado la clase satisfactoriamente.\n\n");
            system("pause");
            (n_act_horarios)--; //Número de horarios - 1

            v_horarios = (horarios *)realloc(v_horarios, n_act_horarios*sizeof(horarios));  //Decremento del espacio del vector v_materias para eliminar el espacio sin usar
        }

        else    //Mensaje en caso de que se cancele la eliminación
        {
            puts("\nSe ha cancelado la eliminacion del horario.\n");
            system("pause");
        }
    }
}

static void modificar_Horario()
{
    int i = 0, u = -2, elect;
    char  id[4], Dia[2], Hora[2];

    if (n_act_horarios == 0)
    {
        system("cls");
        puts("No hay clases actualmente en el sistema.\n");
        system("pause");
        return;
    }
    else
    {
        puts("Menu de modificacion de horarios.\n");

        mostrar_Horarios(); //Llamada a mostrar_Horarios para facilitar la selección de la clase del horario a modificar

        //Segmento de solicitudes al usuario, se necesitan 3 datos para identificar una clase específica en el horario

        printf("Introduzca el ID del profesor de la clase a modificar: ");
        fflush(stdin);
        scanf("%3s", &id);

        mostrar_Horarios();

        printf("Introduzca el dia de la clase a modificar: ");
        fflush(stdin);
        scanf("%1s", &Dia);

        mostrar_Horarios();

        printf("Introduzca la hora de la clase a modificar: ");
        fflush(stdin);
        scanf("%1s", &Hora);

        for(i = 0; i < (n_act_horarios) && i != u+1; i++)   //Búsqueda iterativa de la id, dia y hora introducidos por el usuario
        {
            if (strcmp(v_horarios[i].id_profesor, id) == 0)
            {
                if (strcmp(v_horarios[i].Dia_clase, Dia) == 0)
                {
                    if (strcmp(v_horarios[i].Hora_clase, Hora) == 0)
                    {
                        u = i;  //u es un auxiliar que almacena la posición de la clase del horario encontrada dentro del vector
                    }
                }
            }
        }

        if (i != u+1)   //Comprobación de errores. Si la id introducida no existe se vuelve al menú de horarios
        {
            system("cls");
            puts("Horario no encontrado. Vuelva a introducir el horario.\n");
            system("pause");
            return;
        }

        do  //Menú de selección de opciones de modificación
        {
            mostrar_Horarios();
            printf("Ha seleccionado el horario: %s-%s-%s-%s-%s\n\n", v_horarios[u].id_profesor, v_horarios[u].Dia_clase, v_horarios[u].Hora_clase, v_horarios[u].id_materia, v_horarios[u].Grupo);
            puts("Elija una opcion.");
            puts("1.-Cambiar el profesor de la clase.");
            puts("2.-Cambiar el dia de clase en el horario.");
            puts("3.-Cambiar la hora de clase en el horario.");
            puts("4.-Cambiar la materia dada en el horario.");
            puts("5.-Cambiar el grupo en el horario.");
            puts("6.-Salir.");

            scanf("%d", &elect);

            system("cls");
            printf("Ha seleccionado la clase: %s-%s-%s-%s-%s\n\n", v_horarios[u].id_profesor, v_horarios[u].Dia_clase, v_horarios[u].Hora_clase, v_horarios[u].id_materia, v_horarios[u].Grupo);

            switch(elect)   //Salto a cada una de las funcionalidades de modificación de horarios
            {
            case 1:
                printf("Introduzca el ID del nuevo profesor de la clase (3 digitos): ");
                fflush(stdin);
                scanf("%4s", v_horarios[u].id_profesor);    //Se sobreescriben los datos introducidos directamente en el vector
                break;
            case 2:
                printf("Introduzca el nuevo dia de la clase (1-5): ");
                fflush(stdin);
                scanf("%1s", v_horarios[u].Dia_clase);
                break;
            case 3:
                printf("Introduzca la nueva hora de la clase (1-6): ");
                fflush(stdin);
                scanf("%1s", v_horarios[u].Hora_clase);
                break;
            case 4:
                mostrar_Materias(v_materias);
                printf("Ha seleccionado la clase: %s-%s-%s-%s-%s\n\n", v_horarios[u].id_profesor, v_horarios[u].Dia_clase, v_horarios[u].Hora_clase, v_horarios[u].id_materia, v_horarios[u].Grupo);
                printf("Introduzca el ID de la nueva materia de la clase (4 digitos): ");
                fflush(stdin);
                scanf("%4s", v_horarios[u].id_materia);
                break;
            case 5:
                printf("Introduzca el nuevo grupo de la clase (10 caracteres como maximo): ");
                fflush(stdin);
                gets(v_horarios[u].Grupo);
                break;
            case 6:
                return;
                break;
            }
            printf("\nSe ha realizado el cambio correctamente. Horario resultante: %s-%s-%s-%s-%s\n\n", v_horarios[u].id_profesor, v_horarios[u].Dia_clase, v_horarios[u].Hora_clase, v_horarios[u].id_materia, v_horarios[u].Grupo);   //Impresión del resultado
            system("pause");
        }while (elect != 6);    //Tras cada llamada a una de las funcionalidades de modificación se volverá al menú principal de modificación de horarios
    }
}

static void mostrar_Horarios()
{
    int i = 0;
    system("cls");  //Limpieza de la pantalla para facilitar la legibilidad

    if (n_act_horarios == 0)
    {
        puts("No hay clases actualmente en el sistema.");
    }
    else
    {
        puts("Estas son las clases actuales en el horario:\n");
        puts("ID Profesor | Dia clase | Hora clase | ID Materia | Grupo");
        for(i = 0; i < n_act_horarios; i++) //Búsqueda iterativa de cada una de las clases del horario
        {
            printf("   %s      -     %s     -     %s      -    %s    - %s\n", v_horarios[i].id_profesor, v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].id_materia, v_horarios[i].Grupo); //Impresión por pantalla
        }
    }
    puts("");
}
