#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float resultado;
    int cociente;
    float a;
    float b;
    int c;
    int d;
    int opcion;
    do
    {
        printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\n         บ               :: C A L C U L A D O R A ::                 บ");
		printf("\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
		printf("\n         บ                                                           บ");
		printf("\n         บ       1.- Suma                     5.- Multiplicacion     บ");
		printf("\n         บ                                                           บ");
		printf("\n         บ       2.- Resta                    6.- Division           บ");
		printf("\n         บ                                                           บ");
		printf("\n         บ       3.- Raiz Cuadrada            7.- Division y resto   บ");
		printf("\n         บ                                                           บ");
		printf("\n         บ       4.- Potencia                 8.- Salir...           บ");
		printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
		printf("\n");
		printf("\n                              Elija una opcion: ");
        scanf("%i",&opcion);
        switch(opcion)
        {
            case 1:
            printf("\n      -> Introduzca el primer sumando:");
            scanf("%f",&a);
            printf("\n      -> Introduzxa el segundo sumando:");
            scanf("%f",&b);
            resultado=a+b;
            printf("\n      -> El resultado es %.2f",resultado);
            break;

            case 2:
            printf("\n      -> Introduzca el primer numero:");
            scanf("%f",&a);
            printf("\n      -> Introduzca el segundo numero:");
            scanf("%f",&b);
            resultado=a-b;
            printf("\n      -> El resultado es %.2f",resultado);
            break;

            case 3:
            printf("\n      -> Introduzca el numero al que efectuar la raiz:");
            scanf("%f",&a);
            if (a>0)
            {
                resultado=sqrt(a);
                printf("\n      -> La raiz cuadrada de %f es: %.2f",a,resultado);
            }
            else printf("\n      -> No se puede hacer la raiz cuadrada de un numero negativo.");
            break;

            case 4:
            printf("\n      -> Introduzca el numero que hara de base:");
            scanf("%f",&a);
            printf("\n      -> Introduzca el numero que hara de exponente:");
            scanf("%f",&b);
                if (b>=0)
            {
                resultado=pow(a,b);
                printf("\n      -> El resultado es %.2f",resultado);
            }
            break;

            case 5:
            printf("\n      -> Introduzca el primer numero:");
            scanf("%f",&a);
            printf("\n      -> Introduzca el segundo numero:");
            scanf("%f",&b);
            resultado=a*b;
            printf("\n      -> El resultado es %.2f",resultado);
            break;

            case 6:
            printf("\n      -> Introduzca el primer numero:");
            scanf("%f",&a);
            printf("\n      -> Introduzca el segundo numero:");
            scanf("%f",&b);
            if (b!=0)
            {
                resultado=a/b;
                printf("\n      -> El resultado de la division de %f entre %f es: %.2f",a,b,resultado);

            }
            else printf("\n      -> No se puede realizar dicha division porque el divisor es 0.");
            break;

            case 7:
            printf("\n      -> Introduzca el primer numero:");
            scanf("%i",&c);
            printf("\n      -> Introduzca el segundo numero:");
            scanf("%i",&d);
            if (d!=0)
            {
                cociente=c/d;
                printf("\n      -> El cociente de la division de %i entre %i es: %i",c,d,cociente);
                printf(" y su resto es: %d", c%d);
            }
            else printf("\n      -> No se puede realizar dicha division porque el divisor es 0.");
            break;

            case 8:
            printf("\n     Pulse ENTER para salir...");
            break;
        }
    getch();
    }
    while (opcion!=8);

    return 0;
}
