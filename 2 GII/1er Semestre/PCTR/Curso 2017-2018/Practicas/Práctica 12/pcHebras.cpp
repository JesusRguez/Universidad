#include <ctime>
#include <chrono>
#include <cstdlib>
#include <thread>
#include "pcMonitor.cpp"

using namespace std;

//gcc -pthread -std=c++11 pcHebras.cpp
//Luego habrá que hacer ./pcHebras

int n_vueltas;

void productor(int id, Monitor& monitor) {
    int valor = 0;
    for(int i = 0 ; i < n_vueltas ; i ++) {
        valor = rand() % 100;
        monitor.insertar(valor);
    }
}

void consumidor(int id, Monitor& monitor) {
    int valor = 0;
    for(int i = 0 ; i < n_vueltas ; i ++)
        monitor.extraer();
}

int main(){
    cout<<"Indique el numero de vueltas"<<endl;
    cin>>n_vueltas;
    Monitor monitor(100);
    thread hilos_c[5];
    thread hilos_p[5];
    srand(time(NULL));
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    for(int i = 0 ; i < 5 ; i ++) {
        hilos_p[i] = thread(productor, i, ref(monitor));
        hilos_c[i] = thread(consumidor, i, ref(monitor));
    }
    for(int i = 0 ; i < 5 ; i ++) {
        hilos_p[i].join();
        hilos_c[i].join();
    }

    chrono::duration<double> tiempo = chrono::system_clock::now() - start;
    cout << "Ejecucion finalizada en " << tiempo.count() << " segundos." << endl;
}
