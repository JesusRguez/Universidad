// Modulo Mac

#include "Mac.h"

// Cabecera: IntroducirMac(mac m,char *cad)
// Precondici�n: direcci�n MAC y una cadena de caracteres de longitud TAM_MAC
// Postcondici�n: no devuelve nada, pero inicializa la direcci�n MAC m.
void IntroducirMac(mac m,char *cad) {
    int i;
    
    for(i=0; i<TAM_MAC+1 ; i++)
        m[i]= cad[i];
}

// Cabecera: LeerMac(mac m)
// Precondici�n: direcci�n MAC si necesidad de estar inicialziada
// Postcondici�n: no devuelve nada, pero inicializa la direcci�n MAC m.
void LeerMac(mac m) {
    char cad[TAM_MAC];
    
    printf("Direccion MAC (sin guiones): ");
    gets(cad);
    IntroducirMac(m,cad);
}
