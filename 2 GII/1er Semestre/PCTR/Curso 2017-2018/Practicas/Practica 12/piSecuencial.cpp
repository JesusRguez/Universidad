#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <ctime>
#include <math.h>
using std::cout;
using std::endl;
using std::cin;

//gcc -pthread -std=c++11 piSecuencial.cpp
//Luego habrá que hacer ./piSecuencial

int main ()
{
    int intentos, puntos=0;
    cout<<"PSIntroduzca el numero de intentos"<<endl;
    cin>>intentos;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for(int i=0;i<intentos;i++){
        double cx=dis(gen);
        double cy=dis(gen);
        if(pow(cx,2)+pow(cy,2)<=1){
            puntos++;
        }
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout<<4.0*puntos/intentos<<"\nEn "<<elapsed_seconds.count()<<" segundos"<<endl;
    return 0 ;
}
