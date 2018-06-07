#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int aleatorio(int a, int b);

int main()
{
    srand(time(0));
    int a, b, res;
    cout<<"Introduzca un numero entero:"<<endl;
    cin>>a;
    cout<<"Introduzca otro numero entero:"<<endl;
    cin>>b;

    res=aleatorio(a,b);
    cout<<"El numero generado es: "<<res<<endl;

    return 0;
}

int aleatorio(int a, int b){
    return a+rand()%((b-a)+1);
}
