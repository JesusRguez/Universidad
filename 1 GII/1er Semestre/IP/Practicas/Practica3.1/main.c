#include <stdio.h>
#include <stdlib.h>

int cuadrante (int,int);

int main()
{
    int x,y,r;
    printf("Introduce la coordenada X:");
    scanf("%d",&x);
    printf("Introduce la coordenada Y:");
    scanf("%d",&y);
    r=cuadrante(x,y);
    printf("El punto se encuentra en el cuadrante %d",r);

    return 0;
}

//cabecera: int cuadrante (int a, int b)
//precondición: a y b están inicializados
//postcondición: Devuelve el cuadrante donde está el punto

int cuadrante(int a, int b){
    int s;
    if (a>0 && b>0)
        s=1;
    if (a<0 && b>0)
        s=2;
    if (a<0 && b<0)
        s=3;
    if (a>0 && b<0)
        s=4;
    if (a==0 || b==0){
        s=0;
        printf("El punto se encuentra en un eje.");
    }
    return (s);

}
