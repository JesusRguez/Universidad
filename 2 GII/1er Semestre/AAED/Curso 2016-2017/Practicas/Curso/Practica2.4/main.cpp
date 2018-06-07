#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define NUMERO 10

using namespace std;

float aleatorio(float, float);

int main()
{

    float a=0.0;
    float b=1.0;
    float resultado;
    int numero=NUMERO;
    float y,n=0;

    while (numero>0)
    {
        resultado=aleatorio(a,b);
        y=4*sqrt(1-resultado*resultado);
        n=n+y;
        numero--;
    }
    cout<<n/NUMERO<<endl;

    return 0;
}

float aleatorio(float a, float b)
{
    srand(time(0));
    float resultado;
    resultado=(a+((rand()/RAND_MAX)*(b-a)));
    return resultado;
}
