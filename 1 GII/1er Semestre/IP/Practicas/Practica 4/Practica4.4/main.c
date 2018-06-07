#include <stdio.h>
#include <stdlib.h>

void leer_vector (int*);
void maximo (int*,int*);

int main()
{
    int v[10],m;
    leer_vector(v);
    maximo(v,&m);
    printf("El maximo elemento del vector es %d.\n",m);
    return 0;
}
void leer_vector(int *v)
{
    int i;
    for (i=0;i<10;i++)
    {
        printf("Intoruzca el elemento %d\n",i);
        scanf("%d",&v[i]);
    }

}
void maximo(int *v, int *m)
{
    int i;
    *m=*v;
    for (i=1;i<10;i++)
    {
        if (*(v+i)>*m)
            *m=*(v+i);
    }
}
