#include<iostream>
#include <thread>
#include <random>
#include <chrono>
#include <ctime>
#include <atomic>
#include <math.h>
using namespace std;

//gcc -pthread -std=c++11 piParalelo.cpp
//Luego habrá que hacer ./piParalelo

std::atomic<int> puntosdentro(0);

void pi(int intentos) //codigo a ejecutar por la hebras con parametros
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for(int i=0;i<intentos;i++){
        double cx=dis(gen);
        double cy=dis(gen);
        if(pow(cx,2)+pow(cy,2)<=1){
            puntosdentro++;
        }
    }
}

int main()
{
int nHilos = 4;
int puntos;
thread hilos[nHilos];

cout<<"PPIntroduce el numero de puntos:"<<endl;
cin>>puntos;
puntos=puntos/nHilos;

std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();

for(int i=0; i<nHilos; i++)hilos[i]=thread (pi, puntos); //las hebras se crean -y ejecutan de esta forma
for(int i=0; i<nHilos; i++)hilos[i].join();

end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
cout<<4.0*puntosdentro/(puntos*nHilos)<<"\nEn "<<elapsed_seconds.count()<<" segundos"<<endl;
return(0);
}
