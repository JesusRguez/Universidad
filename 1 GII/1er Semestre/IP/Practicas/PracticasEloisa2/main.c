#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *sal;
    int entero;
    float real;
    if ((sal=fopen("entrada.txt","r"))==NULL)
        puts("El fichero no se puede abrir");
    else
    {
       fscanf(sal,"%d %f",&entero, &real);
       while (!feof(sal))
       {
           printf("%d %f\n",entero, real);
           fscanf(sal,"%d %f",&entero, &real);
       }
       fclose(sal);
    }

    return 0;
}
