#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int a=0, b=6, n;
    double t;
    float frecuencia_abs[6]={0,0,0,0,0,0}, frecuencia_rel[6]={0,0,0,0,0,0};

    srand(time(0));

    for(t=0; t<10000000; t++)
    {
        n=a+(rand()%(b-a)+1);


        switch(n)
        {
        case 1:
            frecuencia_abs[0]++;
            break;
        case 2:
            frecuencia_abs[1]++;
            break;
        case 3:
            frecuencia_abs[2]++;
            break;
        case 4:
            frecuencia_abs[3]++;
            break;
        case 5:
            frecuencia_abs[4]++;
            break;
        case 6:
            frecuencia_abs[5]++;
            break;
        }
    }

    cout<<t<<endl;

    for(int i=0; i<6; i++)
    {
        cout<<"Frecuencia absoluta de "<<i+1<<" es "<<frecuencia_abs[i]<<endl;
        frecuencia_rel[i]=frecuencia_abs[i]/10000000;
        cout<<"La frecuencia relativa de la cara "<<i+1<<" es "<<frecuencia_rel[i]<<endl;
    }

    //Ahora comprobamos que, realmente, la suma de todas las frecuencias relativas sumen 1
    double p=0;
    for(int i=0; i<6; i++)
    {
        p=p+frecuencia_rel[i];
    }
    cout<<p<<endl;

    return 0;
}
