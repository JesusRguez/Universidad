#include <stdio.h>
#include <stdlib.h>

#include "Red.h"

#define FICHERO "redes.txt"
#define FICHERO2 "redes2.txt"

int ContarLineas(FILE *pf);
red CargarFichero();
int Menu();

int main()
{
    ip pr1,pr2;
    int n,aux=0;
    red r= CargarFichero(&n);
    
    do {
        switch(Menu()) {
            case 1:
            case 2:
                printf("Introducir Direccion IP de red: ");
                LeerIp(pr1);
                printf("Introducir Mascara de red: ");
                LeerIp(pr2);
                ActivarPuertos(r,n,pr1,pr2);
            case 3:
                printf("Introducir Direccion IP del equipo: ");
                LeerIp(pr1);
                MostrarMac(r,n,pr1);
                break;
            case 4:
            default: printf("\nOpcion erronea\n"); aux=1;
        }
    } while(aux);
    
    system("PAUSE");	
    return 0;
}

int ContarLineas(FILE *pf) {
    int linea=0;
    char c;
    
    rewind(pf);         // Se asegura que el indicador del archivo este en la posición inicial
    while(!feof(pf)) {
        c = fgetc(pf);
        if(c==10)       // 10 equivale en ASCII a '\n'
            ++linea;
    }
    rewind(pf);         // Lo vuelve a desplazar el indicador a la posición inicial del fichero
    
    return linea;
}

red CargarFichero(int *n) {
    red r;
    FILE * pf;
    int i;
    char cad[T_IP_CAD+TAM_MAC+4];
    
    pf= fopen(FICHERO,"r");
    if(pf==NULL) {
        printf("Error en la carga del fichero\n");
        exit(1);
    }
    *n= ContarLineas(pf);
    r= CrearRed(*n);
    
    for(i=0 ; !feof(pf) ; i++) {
        fgets(cad,T_IP_CAD+TAM_MAC+4,pf);
        IntroducirRed(r,i,cad);
    }
    
    return r;
}

int Menu() {
    int op;
    
    printf("Cargado fichero %s...\n\n",FICHERO);
    puts("1.-Mostrar equipos de una red");
    puts("2.-Activar los puertos de una red");
    puts("3.-Mostrar direccion MAC de un equipo");
    puts("4.-Guardar la nueva configuración");
    printf("\nOpcion: ");
    scanf("%d",&op);
    fflush(stdin);
    
    return op;
}


