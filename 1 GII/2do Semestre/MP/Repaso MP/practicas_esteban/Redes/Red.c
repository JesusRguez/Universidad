// Modulo Red

#include <stdio.h>
#include <stdlib.h>
                        /*                  ERROR                   */
#include "Mac.c"        /* Estas dos líneas no deberían añadirse,   */
#include "Ip.c"         /*  ya que están en el mismo projecto...    */
#include "Red.h"


red CrearRed(int n) {
    red r= (struct T_Red*) malloc(n*sizeof(struct T_Red));
    if(r==NULL) {
        printf("Error en la reserva de memoria\n");
        exit(1);
    }  
}

void DestruirRed(red r) {
    free(r);
}

void MostrarEquipos(red r, int n, ip prt, ip mascara) {
    int i;
    
    for(i=0 ; i<n ; i++) {
        if(PerteneceRed(prt,mascara,(r+i)->pr))
            MostrarIp((r+i)->pr);
    }
}

void ActivarPuertos(red r, int n, ip prt, ip mascara) {
    int i;
    for(i=0 ; i<n ; i++) {
        if(PerteneceRed(prt,mascara,(r+i)->pr))
            (r+i)->c= 'a';
    }
}

void MostrarMac(red r, int n, ip puesto) {
    int i, aux;
    for(i=0 ; i<n ; i++) {
        if(CompararIp(puesto,(r+i)->pr)) {
            if((r+i)->c=='a')
                printf("Dirección MAC: %s\n",(r+i)->m);
            else
                printf("El puesto se encuentra desactivado\n");
            break;
        }
    }
    printf("El puesto no se encuentra en la red\n");
}

void IntroducirRed(red r, int i, char *cad) {
    int j,k,aux;
    char cadaux[T_IP_CAD+TAM_MAC+4];
    
    aux=0;
    k=0;
    for(j=0 ; cad[j]!='\n' ; j++) {
        cadaux[k]= cad[j];
        if(cad[j]==' ' || cad[j+1]=='\n') {
            cadaux[j]= '\0';
            switch(aux) {
                case 0: IntroducirMac((r+i)->m,cadaux); break;
                case 1: IntroducirIp((r+i)->pr,cadaux); break;
                case 2: (r+i)->c= cad[j]; break;
            }
            aux++;
            k= 0;
        }
        k++;
    }
    
}
