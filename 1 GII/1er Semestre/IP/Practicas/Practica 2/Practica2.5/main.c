#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, s, r, p, d;
    char o;
    printf("Introduce el primer numero:");
    scanf("%f",&a);
    printf("Introduce el segunod numero:");
    scanf("%f",&b);
    printf("Introduce el signo de la operacion a realizar para ejercutar dicha operacion:");
    scanf(" %c",&o);
    switch (o)
    {
    case '+':
        s=a+b;
        printf("El resultado es %f",s);
        break;

    case '-':
        r=a-b;
        printf("El resultado es %f",r);
        break;

    case '*':
        p=a*b;
        printf("El resultado es %f",p);
        break;

    case '/':
        if (b==0)
            printf("No se puede dividir por 0.");
        else
        {
            d=a/b;
            printf("El resultado es %f",d);
        }
        break;
    default:
        printf("Haz otra operacioncita.");
        break;

    }

    return 0;
}
