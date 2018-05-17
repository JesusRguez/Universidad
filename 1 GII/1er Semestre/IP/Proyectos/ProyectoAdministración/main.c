#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int d, a;
    char m[10];
}fecha;
typedef struct
{
    char nombre[50];
    int edad;
    fecha nacimiento;
}alumno;

int main()
{
    alumno al;
    int a,i;
    FILE *f;


    if ((f=fopen("Alumnos.txt","a"))==NULL)
        puts("El fichero no se puede abrir.");
    else
    {
        printf("Introduzca el numero de alumnos a anadir:");
    scanf("%d",&a);
    for (i=1;i<=a;i++)
    {
        printf("Introduzca el nombre del alumno %d:\n",i);
        fflush(stdin);
        scanf("%s", al.nombre);

        printf("Introduzca el dia de nacimiento del alumno %d:\n",i);
        scanf("%d",&al.nacimiento.d);
        printf("Introduzca el mes de nacimiento del alumno %d:\n",i);
        scanf("%s", al.nacimiento.m);
        printf("Introduzca el año de nacimiento del alumno %d:\n",i);
        scanf("%d",&al.nacimiento.a);

        printf("Introduzca la edad del alumno %d:\n",i);
        scanf("%d",&al.edad);

        fprintf(f,"El nombre del alumno es: %s\t",al.nombre);
        fprintf(f,"Nacio el dia %d",al.nacimiento.d);
        fprintf(f," de %s",al.nacimiento.m);
        fprintf(f," de %d\t",al.nacimiento.a);
        fprintf(f,"La edad del alumno es: %d anos\n\n\n",al.edad);


    }

        puts("Datos introducidos correctamente.");
        fclose(f);
    }


    return 0;
}
