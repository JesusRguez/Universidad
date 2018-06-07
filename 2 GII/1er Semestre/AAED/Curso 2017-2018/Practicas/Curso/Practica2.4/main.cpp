#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#define TIRADAS 10000000

using namespace std;

double aleatorio(int a, int b);

int main()
{
    int a=0, b=1;
    double suma=0,media;
    for(int i=0;i<TIRADAS;i++){
        suma=suma+4*sqrt(1-pow(aleatorio(a,b),2));
    }
    media=suma/TIRADAS;

    cout<<"La media de las tiradas es: "<<media<<endl;
    return 0;
}

double aleatorio(int a, int b){
    return a+((rand()/float(RAND_MAX))*(b-a));
}
