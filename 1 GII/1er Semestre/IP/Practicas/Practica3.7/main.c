#include <stdio.h>
#include <stdlib.h>

void swap (int *x,int *y);

int main()
{
    int x,y;
    printf("Introduce el primer numero:");
    scanf("%d",&x);
    printf("Introduce el segundo numero:");
    scanf("%d",&y);
    swap(&x,&y);
    printf("a=%d  b=%d",x,y);

    return 0;
}
//Cabecera: void swap(int *x,int *y)
//Precondición: x e y han de estar inicializadas en el main
//Postcondición: Intercambia los valores de x e y
void swap(int *x, int *y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}
