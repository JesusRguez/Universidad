#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

float aleatorio(float a, float b);

int main()
{
    float n=0, y, a=0.0, b=1.0, resultado, numero=10000000;

    srand(time(0));

    while(numero>0)
    {
        resultado=aleatorio(a, b);
        y=4*sqrt(1-resultado*resultado);
        n=n+y;
        numero--;
    }


    cout<<n/10000000<<endl;

    return 0;
}

float aleatorio(float a, float b)
{
    srand(time(0));
    float resultado;
    resultado=(a+((rand()/float(RAND_MAX))*(b-a)));
    return resultado;
}
