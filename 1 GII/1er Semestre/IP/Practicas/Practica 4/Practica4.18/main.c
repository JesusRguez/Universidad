#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparar (char*, char*);
void copiar (char*, char*);
void concatenar (char*, char*);
char longitud (char, char);

int main()
{
    char a[100], b[100], c[200], opcion;
    a[100]=NULL;
    b[100]=NULL;
    puts("Introduce la primera cadena de caracteres:");
    fflush(stdin);
    fgets(a,100,stdin);
    puts("Introduce la segunda cadena de caracteres:");
    fflush(stdin);
    fgets(b,100,stdin);

    puts("Elija una opcion:\n");
    puts("\t1. Comparar");
    puts("\t2. Copiar");
    puts("\t3. Concatenar");
    puts("\t4. Longitud primera cadena");
    puts("\t5. Longitud segunda cadena");

    fflush(stdin);
    scanf("%c",&opcion);

    switch(opcion)
    {
        case '1':
            comparar(*a,*b);
            break;
        case '2':
            copiar(*a,*b);
            break;
        case '3':
            concatenar(*a,*b);
            break;
        //case
    }

    return 0;
}

void comparar (char *a, char *b)
{
    int n;

    n=strcmp(&a,&b);

    if (n==0)
        puts("Ambas cadenas son iguales.");
    if (n<0)
        puts("La primera cadena es mayor que la segunda.");
    if (n>0)
        puts("La segunda cadena es mayor que la primera.");

}

void copiar(char *a, char *b)
{
    strcpy(&b,&a);

    printf("%s",a);
}

void concatenar(char *a, char *b)
{
    strcat(&a,&b);

    printf("%s",a);

}
