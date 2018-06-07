#include <iostream>
#include <cstdlib>
#include <ctime>
#define TIRADAS 10000000

using namespace std;

int main()
{
    int a=1, b=6, resultado;
    int fr[6]={0,0,0,0,0,0};
    srand(time(0));

    for(int i=0;i<TIRADAS;i++){
        resultado=a+rand()%((b-a)+1);
        switch(resultado){
        case 1:
            fr[0]=fr[0]+1;
            break;
        case 2:
            fr[1]=fr[1]+1;
            break;
        case 3:
            fr[2]=fr[2]+1;
            break;
        case 4:
            fr[3]=fr[3]+1;
            break;
        case 5:
            fr[4]=fr[4]+1;
            break;
        case 6:
            fr[5]=fr[5]+1;
            break;
        }
    }
    for(int i=0;i<6;i++){
        cout<<"El numero "<<i+1<<" sale "<<fr[i]<<" veces."<<endl;
        cout<<"Su frecuencia relativa es: "<<fr[i]/(double)TIRADAS<<endl;
    }

    return 0;
}
