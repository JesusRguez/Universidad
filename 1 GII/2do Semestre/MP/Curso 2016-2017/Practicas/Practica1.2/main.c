#include <stdio.h>
#include <stdlib.h>

int conj(int n, int k);

int main()
{
    int g, n, k;

    puts("Introduce el numero de personas totales:");
    scanf("%d",&n); //Se introduce en la variable n el numero de personas totales
    puts("Introduce el numero maximo de personas por grupo:");
    scanf("%d",&k); //Se introduce en la variable k el numero de personas por grupo

    if(n<k)         //Se comprueba que no haya menos gente que la que cabe en un grupo, si es as�, el programa muestra el error y termina, si hay m�s gente que la que caben en un grupo, contin�a con la ejecuci�n del programa.
        puts("No es posible debido a que hay menos personas que las que caben en un grupo.");
    else{
        g=conj(n, k);    //Se introduce en la variable g el numero de grupos posibles que se pueden formar con el numero de personas introducidas anteriormente

        printf("Se pueden hacer %d grupos", g);
    }

    return 0;
}

//Cabecera: int conj(int, int);
//Precondici�n: n y k han de estar inicializados
//Postcondici�n: Devuelve el numero maximo de personas por grupo
int conj(int n, int k)
{
    if (k==1)
        return n;   //Si el  n�mero de grupos es 1, se devuelve el numero maximo de personas
    else
        if (n==k)
            return 1; //Si el numero de personas es igual al numero de grupos, se devuelve 1 (una persona por grupo)
        else
            return conj(n-1, k) + conj(n-1, k-1); //En otro caso se realiza esta formula que nos dar� las posibles combinaciones de personas en los grupos
}
