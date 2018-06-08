#include<iostream>
#include <random>
#include <thread>
#include <atomic>

using namespace std;
std::atomic<int> nDentro(0);

void pi(int nTimes)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    double x,y;
    for(int i=0;i<nTimes;i++)
    {
        x=dis(gen);
        y=dis(gen);
        if((x*x)+(y*y) <= 1){
            nDentro++;
        }
    }
}

int main(){
    cout<<"Introduce el numero de hilos"<<endl;
    int nHilos;
    cin>>nHilos;
    cout<<"Introduce el numero de puntos totales"<<endl;
    int nPuntos;
    cin>>nPuntos;
    thread hilos[nHilos];
    int puntosHilo = nPuntos/nHilos;
    for(int i=0; i<nHilos; i++)
        hilos[i]=thread(pi, puntosHilo);

    for(int i=0; i<nHilos; i++)
        hilos[i].join();

    cout<<4.0*nDentro/nPuntos<<endl;
}
