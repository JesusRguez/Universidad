#include <stdio.h>
#include <stdlib.h>

int m_rusa (int, int);

int main()
{
    int a=15;
    int b=25;
    int res;

    res=m_rusa(a,b);

    printf("El resultado es: %d", res);

    return 0;
}

//Cabecera: int m_rusa(int, int)
//Precondición: Las variables a y b han de estar inicializadas
//Postcondición: Devuelve el resultado de la multiplicación de a*b
int m_rusa(int a, int b) {
    if(a==1){
        return (b);
    }
    if(a%2!=0){
        return(b+m_rusa(a/2 , b*2));
    }
    else{
        return(m_rusa(a/2 , b*2));
    }
}
