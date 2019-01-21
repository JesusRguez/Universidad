#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <random>
extern "C" {
 	#include <unistd.h>
}

using namespace std;

int puntosTotales;
int aciertos=0;

void pi(int puntos, int i){
    std::random_device gna;
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    for (int i = 0; i < puntosTotales/4; i++) {
        double x = dis(gna);
        double y = dis(gna);
        if (sqrt(pow(x, 2)+pow(y, 2)) <= 1) {
            aciertos++;
        }
    }
}

int main(int argc, char const *argv[]) {
    /*for (int i = 0; i < 4; i++) {
        aciertos[i] = 0;
    }*/
    std::cout << "Introduzca el número de puntos:" << '\n';
    std::cin >> puntosTotales;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    thread hilos[4];
    start = std::chrono::system_clock::now();
    for (int i = 0; i < 4; i++) {
        hilos[i] = thread(pi, puntosTotales/4, i);
    }
    for (int i = 0; i < 4; i++) {
        hilos[i].join();
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> tiempo = end-start;

    std::cout << "Resultado: "<< aciertos*4/(double)puntosTotales << '\n';
    std::cout << "Tarda: "<< tiempo.count()<< " segundos" << '\n';
    return 0;
}
