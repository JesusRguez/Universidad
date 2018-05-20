#include "tipos.h"
#include "cargar.h"
#include "registro.h"
#include "acceso.h"
#include "menus.h"
#include "participante.h"
#include "cronista.h"
#include "admin.h"
#include "guardar.h"
#include "confPlant.h"


void menuInicio(){

    int n;

    while(n!=3){

        system("cls");

        puts("Bienvenido a la Liga Fantastica MP");
        puts("----------------------------------");
        puts("Seleccione una opcion:");
        puts("1. Registro");
        puts("2. Acceso al sistema");
        puts("3. Salir del programa");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                anadirUsuario(&vUsuarios,&nUsuarios,0);
                break;

            case 2:
                acceso(vUsuarios,nUsuarios);
                break;

            case 3:
                break;

        }

    }

}

void menuParticipante(char *id){

    int n=0;

    contarPlantillas(id,vPlantillas,nPlantillas,&nPlantillasUsuario);

    system("pause");

    while(n!=6){

        system("cls");

        puts("MENU PARTICIPANTE");
        puts("------------------------------");
        puts("Seleccione una opcion:");
        puts("1. Crear Plantilla");
        puts("2. Configurar Plantilla");
        puts("3. Listar Plantillas");
        puts("4. Eliminar Plantilla");
        puts("5. Ranking");
        puts("6. Salir del programa");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                puts("CREAR PLANTILLA");
                puts("---------------");
                crearPlantilla(id,&vPlantillas,&nPlantillas,&vJugplants,&nJugplants,&nPlantillasUsuario);
                system("pause");
                break;

            case 2:
                puts("MODIFICAR PLANTILLA");
                puts("-------------------");
                menuParticipantePlantilla(id);
                system("pause");
                break;

            case 3:
                puts("\n----------------------MIS PLANTILLAS---------------------\n");
                puts("ID_PROPIETARIO-ID_PLANTILLA-NOMBRE-PRESUPUESTO-PUNTUACION\n");
                listarplantillas(id, vPlantillas, nPlantillas, nPlantillasUsuario);
                puts("\n---------------------------------------------------------\n");
                system("pause");
                break;

            case 4:
                puts("ELIMINAR PLANTILLA");
                puts("------------------");
                eliminarPlantilla(id,&vPlantillas,&nPlantillas,&nPlantillasUsuario);
                system("pause");
                break;

            case 5:
                puts("TOP 3");
                puts("-----");
                ranking(vPlantillas,nPlantillas);
                system("pause");
                break;

            case 6:
                break;
        }

    }

    guardar();

}

void menuParticipantePlantilla(char *id){

    int n=0;
    char idPlant[4];

    puts("Elija id plantilla:");
    listarplantillas(id, vPlantillas, nPlantillas, nPlantillasUsuario);

    fflush(stdin);
    scanf("%3s",idPlant);

    system("pause");

    while(n!=5){

        system("cls");

        puts("CONFIGURAR PLANTILLA");
        puts("------------------------------");
        puts("Seleccione una opcion:");
        puts("1. Listar futbolistas de plantilla");
        puts("2. Listar futbolistas disponibles");
        puts("3. Añadir futbolista a plantilla");
        puts("4. Eliminar jugador de plantilla");
        puts("5. Volver");

        fflush(stdin);
        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                puts("Listar futbolistas de plantilla");
                puts("---------------");
                listarFutbPlant(idPlant, vJugplants, nJugplants);
                system("pause");
                break;

            case 2:
                puts("Listar futbolistas disponibles");
                puts("-------------------");
                listarFutbDisp(idPlant, vJugplants, nJugplants, vFutbolistas, nFutbolistas);
                system("pause");
                break;

            case 3:
                puts("Añadir futbolista a plantilla");
                puts("-------------------");
                ficharFutb(idPlant,&vJugplants, &nJugplants, vFutbolistas, nFutbolistas);
                system("pause");
                break;

            case 4:
                puts("Eliminar jugador de plantilla");
                puts("------------------");
                despedirFutb(idPlant, &vJugplants, &nJugplants, vFutbolistas ,nFutbolistas);
                system("pause");
                break;


        }

    }

}

void menuCronista(){

    int n=0;

    system("cls");

    while(n!=3){

        puts("MENU CRONISTA");
        puts("----------------------");
        puts("Seleccione una opcion:");
        puts("1. Listar equipos");
        puts("2. Valorar Equipos");
        puts("3. Salir del programa");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                listarEquipos(vEquipos,nEquipos);
                system("pause");
                system("cls");
                break;

            case 2:
                valorarEquipos(&vFutbolistas,nFutbolistas,vEquipos,nEquipos);
                system("cls");
                break;

            case 3:
                break;
        }

    }

   guardar();

}

void menuAdministrador(){

    int n=0;

    while(n!=4){

        system("cls");

        puts("MENU ADMINISTRADOR");
        puts("----------------------");
        puts("Seleccione una opcion:");
        puts("1. Equipos");
        puts("2. Usuarios");
        puts("3. Configuracion");
        puts("4. Salir del programa");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                menuAdminEquipos();
                break;

            case 2:
                menuAdminUsuarios();
                break;

            case 3:
                editConfig(&vConfigs,nConfigs);
                break;

            case 4:
                break;
        }

    }

    guardar();

}

void menuAdminEquipos(){

    int n=0;

    while(n!=9){

        system("cls");

        puts("--------------ADMINISTRAR EQUIPOS-------------");
        puts("Seleccione una opcion:");
        puts("1. Listar equipos");
        puts("2. Modificar equipo");
        puts("3. Añadir equipo");
        puts("4. Eliminar equipo");
        puts("5. Listar futbolistas");
        puts("6. Modificar futbolista");
        puts("7. Añadir futbolista");
        puts("8. Eliminar futbolista");
        puts("9. Volver a menu administrador");
        puts("----------------------------------------------");
        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                listarEquipos(vEquipos,nEquipos);
                system("pause");
                break;

            case 2:
                modificarEquipo(&vEquipos,nEquipos);
                system("pause");
                break;

            case 3:
                puts("AÑADIR NUEVO EQUIPO");
                puts("-------------------");
                anadirEquipo(&vEquipos,&nEquipos);
                system("pause");
                break;

            case 4:
                eliminarEquipo(&vEquipos,&nEquipos);
                system("pause");
                break;

            case 5:
                listarFutbolistas(vFutbolistas,nFutbolistas);
                system("pause");
                break;

            case 6:
                modificarFutbolista(&vFutbolistas,nFutbolistas);
                system("pause");
                break;

            case 7:
                puts("AÑADIR NUEVO FUTBOLISTA");
                puts("-----------------------");
                anadirFutbolista(&vFutbolistas,&nFutbolistas);
                system("pause");
                break;

            case 8:
                eliminarFutbolista(&vFutbolistas,&nFutbolistas);
                system("pause");
                break;

            case 9:
                break;
        }

    }

}

void menuAdminUsuarios(){

    int n=0;

    while(n!=5){

        system("cls");

        puts("-------------ADMINISTRAR USUARIOS-------------");
        puts("Seleccione una opcion:");
        puts("1. Listar usuarios");
        puts("2. Modificar usuario");
        puts("3. Añadir usuario");
        puts("4. Eliminar usuario");
        puts("5. Volver a menu administrador");
        puts("----------------------------------------------");
        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                listarUsuarios(vUsuarios,nUsuarios);
                system("pause");
                break;

            case 2:
                modificarUsuario(&vUsuarios,nUsuarios);
                break;

            case 3:
                puts("REGISTRO DE NUEVO USUARIO");
                puts("-------------------------");
                anadirUsuario(&vUsuarios,&nUsuarios,1);
                system("pause");
                break;

            case 4:
                eliminarUsuario(&vUsuarios,&nUsuarios);
                system("pause");
                break;

            case 5:
                break;
        }

    }

}
