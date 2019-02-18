// Modulo Palabra

#ifndef __PALABRA__
#define __PALABRA__


#define MAX_P 21
#define FIN_PAL '\0'

typedef enum{falso,verdadero} logico;
typedef char palabra[MAX_P];

// Funciones exportables
logico palabra_es_permut(palabra pal1, palabra pal2);


#endif
