// Modulo Palabra

#include <stdio.h>

#include "Palabra.h"


// Protitops de Funciones no exportables
static int longitud(palabra pal);
static int longitud_rec(palabra pal, int i);
static int pos_caracter(palabra pal, char c);
static int pos_caracter_rec(palabra pal, char c, int i, int n);
static void borrar(palabra pal, int pos);
static void copiar_min(palabra pal1, palabra pal2);

// Publica
// Cabecera: palabra_es_permut(palabra pal1, palabra pal2)
// Precondición: recibe dos palabras
// Postcondición: devuelve verdadero si pal2 es anagrama de pal1, falso en caso contrario
logico palabra_es_permut(palabra pal1, palabra pal2) {
    int i,p;
    logico permut= verdadero;
    palabra palaux1,palaux2;
    
    copiar_min(pal1,palaux1);
    copiar_min(pal2,palaux2);
    
    if(longitud(palaux1)!=longitud(palaux2))
        permut= falso;
    else {
        for(i=0 ; i<longitud(palaux1) && permut==verdadero ; i++) {
            p= pos_caracter(palaux2,palaux1[i]);
            if(p<longitud(palaux2))
                borrar(palaux2,p);
            else
                permut= falso;
        } 
    }
    
    return permut;
}

// Privada
// Cabecera: longitud(palabra pal)
// Precondición: pal inicializado
// Postcondición: devuelve la longitud de pal, llamando a función longitud_rec
static int longitud(palabra pal) {
    return longitud_rec(pal,0);
}

// Privada
// Cabecera: longitud(palabra pal, int i)
// Precondición: pal inicializado, 0<=i<=MAX_P
// Postcondición: devuelve la longitud de pal
static int longitud_rec(palabra pal, int i) {
    if(pal[i]==FIN_PAL)
        return i;
    else
        return longitud_rec(pal, i+1);
}

// Privada
// Cabecera: pos_caracter(palabra pal, char c)
// Precondición: pal y c inicializados
// Postcondición: devuelve la posición de la primera ocurriencia de c en pal. S c no aparece eb pal, devuelve longitud(pal).
static int pos_caracter(palabra pal, char c) {
    int n;
    
    n= longitud(pal);
    return pos_caracter_rec(pal,c,0,n);
}

// Privada
// Cabecera: pos_caracter_rec(palabra pal, char c, int i, int n)
// Precondición: pal y c inicializados, 0<=i<=n+1
// Postcondición: devuelve la posición de la primera ocurriencia de c en pal. S c no aparece en pal, devuelve longitud(pal).
static int pos_caracter_rec(palabra pal, char c, int i, int n) {
    if(i==n || pal[i]==c)
        return i;
    else
        return pos_caracter_rec(pal, c, i+1, n);
}

// Privada
// Cabecera: borrar(palabra pal, int pos)
// Precondición: pal inicializado, 0<=pos<=longitud(pal)
// Postcondición: no devuelve nada, pero suprime el contenido de pal[pos] desplazando siguientes posiciones a la izquierda
static void borrar(palabra pal, int pos) {
    int i,lon;
    lon= longitud(pal);
    for(i=pos ; i<lon ; i++)
        pal[i]= pal[i+1];
}

// Privada
// Cabecera: coiar(palabra pal1, palabra pal2)
// Precondición: recibe como parametros dos palabras pal1 y pal2 inicializadas
// Postcondición: copia pal1 en pal2 pero todo en minúscula
static void copiar_min(palabra pal1, palabra pal2) {
    int i;
    for(i=0 ; i<MAX_P ; i++) {
        if(pal1[i]>='A' && pal1[i]<='Z')
            pal2[i]= pal1[i]+'a'-'A';
        else
            pal2[i]= pal1[i];
        if(pal2[i]==FIN_PAL)
            break;
    }
}

