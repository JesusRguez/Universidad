#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float aleatorio(float a, float b);

int main()
{
    float n, a, b;

    srand(time(0));

    cout<<"Introudzca el primer numero:"<<endl;
    cin>>a;
    cout<<"Introduzca el segundo numero:"<<endl;
    cin>>b;

    n=aleatorio(a, b);

    cout<<n<<endl;

    return 0;
}

float aleatorio(float a, float b)
{
    float resultado;
    resultado=(a+((rand()/float(RAND_MAX))*(b-a)));
    return resultado;
}
