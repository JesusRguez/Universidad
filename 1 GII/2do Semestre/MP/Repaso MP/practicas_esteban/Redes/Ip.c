// Modulo Ip

#include <stdlib.h>

#include "Ip.h"

// Cabecera: IntroducirIp(ip prt,char * cad)
// Precondición: recibe una dirección ip y una cadena de caracteres
// Postcondición: no devuelve nada, pero almacena la dirección ip que estaba en la cadena en prt.
void IntroducirIp(ip prt, char *cad) {
    int i,j=0,k=0;
    
    for(i=0 ; cad[i]!='\0' ; i++) {
        if(cad[i]=='.' && j<TAM_IP) {
            cad[i]= '\0';
            prt[j]= atoi(cad+k);
            j++;
            k= i+1;
        }
    }
    prt[j]= atoi(cad+k);
}

// Cabecera: LeerIp(ip prt)
// Precondición: recibe una dirección ip sin necesidad de estar inicializada
// Postcondición: no devuelve nada, pero almacena la dirección ip que capura por teclado
void LeerIp(ip prt) {
    char cad[T_IP_CAD+1];
    
    printf("Direccion IP (con puntos): ");
    gets(cad);
    IntroducirIp(prt,cad);
}

// Cabecera: MostrarIp(ip prt)
// Precondición: recibe una dirección ip inicializada
// Postcondición: no devuelve nada, sólo visualiza la dirección ip
void MostrarIp(ip prt) {
    int i;
    for(i=0 ; i<TAM_IP ; i++) {
        printf("%d",prt[i]);
        if(i<TAM_IP-1)
            printf(".");
    }
    printf("\n");
}

// Cabecera: CompararIp(ip prt1, prt2)
// Precondición: recibe dos direcciones de ips inicializadas
// Postcondición: devuelve 1 si ambas ips son iguales, 0 en caso contrario
int CompararIp(ip prt1, ip prt2) {
    int i;
    for(i=0 ; i<TAM_IP ; i++) {
        if(prt1[i]!=prt2[i])
            return 0;
    }
    return 1;
}

// Cabecera: PerteneceRed(ip red, ip mascara, ip puesto)
// Precondición: recibe la dirección de ip de red, máscara de la red y la dirección ip de un puesto de una red
// Postcondición: devuelve 1 si la dirección ip del puesto pertenece a la red, ó 0 en caso contrario.
int PerteneceRed(ip prt, ip mascara, ip puesto) {
    int i;
    ip diraux;
    
    for(i=0; i<TAM_IP ; i++)
        diraux[i]= puesto[i] & mascara[i];
    
    for(i=0; i<TAM_IP ; i++) {
        if(diraux[i]!=prt[i])
            return 0;
    }
    return 1;
}
