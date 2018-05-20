#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, m, s, H, M, S;
    printf("Introduzca el valor de la hora:");
    scanf("%d",&h);
    printf("Introduzca el valor de los minutos:");
    scanf("%d",&m);
    printf("Introduzca el valor de los segundos:");
    scanf("%d",&s);

    if ((h<0 && h>23) || (m<0 && m>59) || (s<0 && s>59))
        printf("Introduzca una hora correcta.");
        else
    S=s+1;
    if (s==59)
    {
        S=00;
        M=m+1;
        if (m==59)
        {
            M=0;
            H=h+1;
            if (H==24)
                H=00;
        }
    }
    else
    M=m;
    H=h;
    printf("La hora dentro de un segundo es %d:%d:%d",H,M,S);

    return 0;
}
