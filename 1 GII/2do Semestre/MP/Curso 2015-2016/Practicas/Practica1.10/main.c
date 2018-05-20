#include <stdio.h>
#include <stdlib.h>

void llamada (int*, int);
void compara (int*, int, int, int, int, int);

int main()
{
    int A[10]={1,2,4,6,5,7,8,9,4,3};
    int n=10;

    llamada(A,n);

    return 0;
}
