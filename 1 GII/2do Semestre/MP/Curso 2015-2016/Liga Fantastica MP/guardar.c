#include "guardar.h"

void guardarUsuario(usuario *u, size_t tam)
{
    FILE *fich;
    int i;

    //Escribe en el fichero toda la ristra de usuario

    fich=fopen("DATA/usuarios.txt","w+");

    i = 0;
    if (fich==NULL)
            puts("No se ha podido modificar el fichero");
        else
            while( i < tam-1 )                                    // recorremos el vector de usuarios
            {
                fprintf( fich, "%s-%s-%s-%s-%s\n", u[i].id, u[i].nombre, u[i].perfil, u[i].login, u[i].pass );          // impr en el fichero linea por linea
                i++;
            }
            fprintf( fich, "%s-%s-%s-%s-%s", u[i].id, u[i].nombre, u[i].perfil, u[i].login, u[i].pass );

    puts("Se ha guardado los usuarios correctamente");

}

void guardarEquipo(equipo *e, size_t tam)
{
    FILE *fich;
    int i;

    //Escribe en el fichero toda la ristra de usuario

    fich=fopen("DATA/equipos.txt","w+");

    i = 0;
    if (fich==NULL)
            puts("No se ha podido modificar el fichero");
        else
            while( i < tam-1 )                                    // recorremos el vector de usuarios
            {
                fprintf( fich, "%s-%s\n", e[i].id, e[i].nombre );          // impr en el fichero linea por linea
                i++;
            }
            fprintf( fich, "%s-%s", e[i].id, e[i].nombre );

    puts("Se ha guardado los equipos correctamente");

}

void guardarFutbolistas(futbolista *f, size_t tam)
{
    FILE *fich;
    int i;

    //Escribe en el fichero toda la ristra de usuario

    fich=fopen("DATA/futbolistas.txt","w+");

    i = 0;
    if (fich==NULL)
            puts("No se ha podido modificar el fichero");
        else
            while( i < tam-1)                                    // recorremos el vector de usuarios
            {
                fprintf( fich, "%s-%s-%s-%d-%d\n", f[i].id, f[i].ideq, f[i].nombre, f[i].precio, f[i].valor );          // impr en el fichero linea por linea
                i++;
            }
            fprintf( fich, "%s-%s-%s-%d-%d", f[i].id, f[i].ideq, f[i].nombre, f[i].precio, f[i].valor );

    puts("Se ha guardado los futbolistas correctamente");

}

void guardarPlantillas(plantilla *p, size_t tam)
{
    FILE *fich;
    int i;

    //Escribe en el fichero toda la ristra de plantillas
    fich=fopen("DATA/plantillas.txt","w+");

    i = 0;
    if (fich==NULL)
            puts("No se ha podido modificar el fichero");
        else
            while( i < tam-1 )                                    // recorremos el vector de usuarios
            {
                fprintf( fich, "%s-%s-%s-%d-%d\n", p[i].idprop, p[i].idplant, p[i].nombre, p[i].presup, p[i].punt );          // impr en el fichero linea por linea
                i++;
            }
            fprintf( fich, "%s-%s-%s-%d-%d", p[i].idprop, p[i].idplant, p[i].nombre, p[i].presup, p[i].punt );

    puts("Se ha guardado las plantilla correctamente");

}

void guardarJugPlant(jugplant *jp, size_t tam)
{
    FILE *fich;
    int i;

    //Escribe en el fichero toda la ristra de plantillas
    fich=fopen("DATA/jugadores_plantillas.txt","w+");

    i = 0;
    if (fich==NULL)
            puts("No se ha podido modificar el fichero");
        else
            while( i < tam-1 )                                    // recorremos el vector de usuarios
            {
                fprintf( fich, "%s-%s-%s\n", jp[i].idjug, jp[i].ideq ,jp[i].idplant );          // impr en el fichero linea por linea
                i++;
            }
            fprintf( fich, "%s-%s-%s", jp[i].idjug, jp[i].ideq ,jp[i].idplant );

    puts("Se ha guardado los jugadoresplantilla correctamente");

}

void guardarConf(config *c, size_t tam)
{
    FILE *fich;
    int i;

    //Escribe en el fichero toda la ristra de plantillas
    fich=fopen("DATA/configuracion.txt","w+");

    i = 0;
    if (fich==NULL)
            puts("No se ha podido modificar el fichero");
        else
            while( i < tam-1 )                                    // recorremos el vector de usuarios
            {
                fprintf( fich, "%s-%d\n", c[i].config, c[i].valor );          // impr en el fichero linea por linea
                i++;
            }
            fprintf( fich, "%s-%d", c[i].config, c[i].valor );

    puts("Se ha guardado la configuracion correctamente");

}

void guardar()
{

    char resp=' ';

    while(resp!='s' && resp!='n'){

        printf("Va a salir del programa. Desea guardar los cambios realizados? (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);

    }

    if(resp=='s'){

        guardarUsuario(vUsuarios, nUsuarios);
        guardarEquipo(vEquipos, nEquipos );
        guardarFutbolistas(vFutbolistas, nFutbolistas);
        guardarPlantillas(vPlantillas, nPlantillas);
        guardarJugPlant(vJugplants, nJugplants);
        guardarConf(vConfigs, nConfigs);

        exit(0);

    }else{

        printf("No se han guardado los cambios realizados\n");

    }

}
