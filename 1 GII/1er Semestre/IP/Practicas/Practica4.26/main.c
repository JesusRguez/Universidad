#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    char dni[10];
    int edad;
}persona;

int main()
{
    FILE *f;
    persona p[20];
    int i;

    for (i=0;i<20;i++)
    {
        if ((f=fopen("Personas.txt", "a"))==NULL)
            puts("El fichero no se pudo abrir.");
        else
        {
            printf("Introduzca el nombre de la persona %d\n",i+1);
            fflush(stdin);
            gets(p[i].nombre);
            printf("Introduzca el DNI de la persona %d\n",i+1);
            fflush(stdin);
            gets(p[i].dni);
            printf("Introduzca la edad de la persona %d\n",i+1);
            fflush(stdin);
            scanf("%d",p[i].edad);

            fprintf(f,"%s",p[i].nombre);
            fprintf(f,"\t%s",p[i].dni);
            fprintf(f,"\t%d\n",p[i].edad);

            fclose(f);
        }

    }

    return 0;
}
