#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d, m, a;
    printf("Introduzca el día:");
    scanf("%d",&d);
    printf("Introduzca el mes:");
    scanf("%d",&m);
    printf("Introduzca el ano:");
    scanf("%d",&a);

    switch (m)
    {
    case 1:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 2:
        if (d>0 && d<=28)
            printf("Fecha correcta.");
            else if (d==29 && a%4==0)
                printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 3:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 4:
        if (d>0 && d<=30)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 5:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 6:
        if (d>0 && d<=30)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 7:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 8:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 9:
        if (d>0 && d<=30)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 10:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 11:
        if (d>0 && d<=30)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    case 12:
        if (d>0 && d<=31)
            printf("Fecha correcta.");
            else
            printf("Fecha incorrecta.");
        break;
    default:
        printf("Fecha incorrecta.");
    }


    return 0;
}
