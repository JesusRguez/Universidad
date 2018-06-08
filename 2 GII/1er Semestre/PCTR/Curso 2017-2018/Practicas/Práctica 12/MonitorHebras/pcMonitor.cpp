#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

//gcc -pthread -std=c++11 pcMonitor.cpp
//Luego habrá que hacer ./pcMonitor

struct Monitor {
    int* buffer;
    int tam, cont, in_ptr, out_ptr;
    mutex em;
    condition_variable not_full;
    condition_variable not_empty;

    Monitor(int capacidad) {
        tam = capacidad;
        cont = 0;
        in_ptr = 0;
        out_ptr = 0;
        buffer = new int[capacidad];
    }

    ~Monitor() {
        delete[] buffer;
    }

    void insertar(int dato) {
        unique_lock<mutex> l(em);
        while(cont == tam)
        not_full.wait(l);
        buffer[in_ptr] = dato;
        in_ptr = (in_ptr + 1) % tam;
        cont ++;
        not_empty.notify_one();
    }

    int extraer() {
        unique_lock<mutex> l(em);
        while(cont == 0)
        not_empty.wait(l);
        int result = buffer[out_ptr];
        out_ptr = (out_ptr + 1) % tam;
        cont --;
        not_full.notify_one();
        return result;
    }
};

