#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int dado(int, int);

#define TIRADAS 10000000


int main()
{
    srand(time(0));
    float frecuencia_relativa, frecuencia_absoluta;
    int a=1;
    int b=6;
    int tiradas=TIRADAS;
    int resultado;
    int v[6]={0,0,0,0,0,0};
    int i;

    while (tiradas>0)
    {
        resultado=dado(a,b);

        switch(resultado)
        {
            case 1: v[0]++; break;
            case 2: v[1]++; break;
            case 3: v[2]++; break;
            case 4: v[3]++; break;
            case 5: v[4]++; break;
            case 6: v[5]++; break;
        }
        tiradas--;
    }

    cout<<"Frecuencia absoluta:"<<endl;
    for(i=0;i<6;i++)
        cout<<v[i]<<endl;

    cout<<"Frecuencia relativa:"<<endl;
    for(i=0;i<6;i++)
        cout<<(float)v[i]/TIRADAS<<endl;
    return 0;
}


int dado(int a, int b)
{
    int resultado;
    resultado=(a+rand()%((b-a)+1));
    return resultado;
}
