#include <mutex>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <atomic>

std::mutex l;
std::atomic<int> n(0);
int m = 0;
int inc;

void incrementoMutex(){
    l.lock();
    for (size_t i = 0; i < inc; i++) {
        m++;
    }
    l.unlock();
}

void incrementoAtomic(){
    for (size_t i = 0; i < inc; i++) {
        n++;
    }
}

int main() {
    std::cout << "Introduzca el número de incrementos" << '\n';
    std::cin >> inc;
    std::chrono::time_point<std::chrono::system_clock> startMutex, endMutex, startAtomic, endAtomic;
    std::thread hilos[4];
    startMutex = std::chrono::system_clock::now();
    for (size_t i = 0; i < 4; i++) {
        hilos[i] = std::thread(incrementoMutex);
    }
    for (size_t i = 0; i < 4; i++) {
        hilos[i].join();
    }
    endMutex = std::chrono::system_clock::now();

    startAtomic = std::chrono::system_clock::now();
    for (size_t i = 0; i < 4; i++) {
        hilos[i] = std::thread(incrementoAtomic);
    }
    for (size_t i = 0; i < 4; i++) {
        hilos[i].join();
    }
    endAtomic = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_mutex = endMutex - startMutex;
    std::cout << "Tiempo para mutex: "<< elapsed_seconds_mutex.count() << '\n';

    std::chrono::duration<double> elapsed_seconds_atomic = endAtomic - startAtomic;
    std::cout << "Tiempo para atomic: "<< elapsed_seconds_atomic.count() << '\n';
}
