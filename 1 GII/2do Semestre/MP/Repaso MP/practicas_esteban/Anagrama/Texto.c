// Modulo Texto

#include <stdio.h>
#include <stdlib.h>

#include "Palabra.h"
#include "Texto.h"

// Cabecera: abrir_texto()
// Precondición: no recibe ningún parametro
// Postcondición: devuelve un texto inicializado
texto abrir_texto(const char *s) {
    texto txt;
    txt= fopen(s,"r");
    if(txt==NULL) {
        printf("ERROR. abrir_texto: apertura de fichero\n");
        system("PAUSE");
        exit(1);
    }
    return txt;
}

// Cabecera: crear_texto()
// Precondición: recibe un texto inicializado
// Postcondición: no devuelve nada, simplemente cierra el fichero.
void cerrar_texto(texto txt) {
    fclose(txt);
}

// Cabecera: leer_palabra(texto txt, palabra pal)
// Precondición: txt inicializado
// Postcondición: no devuelve nada, sin embargo pal almacena la palabra que empezaba en el indicador del fichero
void leer_palabra(texto txt, palabra pal) {
    int i; long int pos;
    char c;
    
    for(i=0 ; i<MAX_P ; i++) {
        pal[i]= fgetc(txt);
        if(fin_de_texto(txt) || pal[i]==' ' || pal[i]==10) {  // ASCII, '\n'==10
            pal[i]= FIN_PAL;
            break;
        }
    }
    while(!fin_de_texto(txt)) {
        pos= ftell(txt);                // Conoce la posición del indicador en ese momento, contando desde el principio
        c= fgetc(txt);
        if(c!=' ' && c!=10) {
            fseek(txt,pos,SEEK_SET);    // Posicina el indicador de txt desde SEEK_SET(el principio) a la posición pos
            break;
        }
    }
}


// Cabecera: fin_de_texto(texto txt)
// Precondición: txt inicializado
// Postcondición: devuelve verdadero si el fichero se ha acabado, falso en caso contrario
logico fin_de_texto(texto txt) {
    return (feof(txt)? verdadero : falso);
}
