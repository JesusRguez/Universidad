#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double aleatorio(int a, int b);

int main()
{
    srand(time(0));
    int a, b;
    double res;

    cout<<"Introduzca un numero entero:"<<endl;
    cin>>a;
    cout<<"Introduzca otro numero entero:"<<endl;
    cin>>b;

    res=aleatorio(a, b);
    cout<<"El numero generado es: "<<res<<endl;
    return 0;
}


double aleatorio(int a, int b){
    return a+((rand()/float(RAND_MAX))*(b-a));
}
