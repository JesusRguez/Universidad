#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,l,f,c,n;
    int A[100][100], B[100][100],C[100][100];
    puts("Introduzca el valor de las filas y las columnas de la ambas matrices (al ser una matriz cuadrada basta solo con poner el numero de filas ya que este sera igual al de columnas):");
    scanf("%d",&n);
    f=n;
    c=n;
    puts("Introduzca los valores de la primera matriz:");
    for(i=0;i<f;i++)

        for(j=0;j<c;j++){
            printf ("%d %d ",i,j);
            scanf("%d",&A[i][j]);
    }

    puts("Introduzca los valores de la segunda matriz:");
    for(k=0;k<f;k++)
            for(l=0;l<c;l++)
            scanf("%d",&B[k][l]);


    for (i=0;i<f;i++)
    for (j=0;j<c;j++)
       { C[i][j]=0;
         for (k=0;k<f;k++)
          C[i][j]=C[i][j]+A[i][k]*B[k][j];
          }


    puts("La multiplicacion de las matrices es:");
    for (i=0;i<f;i++)

        for (j=0;j<c;j++)
         printf("C(%d,%d) %d\n",i,j,C[i][j]);



    return 0;
}
