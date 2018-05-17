#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota;
    printf("Introduzca la nota del alumno:");
    scanf("%f",&nota);
    if (nota<0)
    {
        printf("No existen notas negativas.");
    }
    else if (nota<5)
    {
        printf("SUSPENSO.");
    }
    else if (nota>=5 && nota<=6.5)
    {
        printf("APROBADO.");
    }
    else if (nota>6.5 && nota<=8)
    {
        printf("NOTABLE.");
    }
    else if (nota>8 && nota<=9)
    {
        printf("SOBRESALIENTE.");
    }
    else if (nota>10)
    {
        printf("Nota superior a 10, introduzca una nota entre 0 y 10.");
    }
    else
        printf("MATRICULA DE HONOR.");

    return 0;
}
