//Compilar con: g++ archivo.cpp -o archvo -pthread -std=c++11

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
extern "C" {
    #include "unistd.h" // Para generar números aleatorios
}
#include <thread>

using namespace std;

// Declaración de variables y/o funciones donde una de ellas será la llamada por los hilos

int main(int argc, char const *argv[]) {
    // Si queremos generar números aleatorios:
    srand(time(NULL)); // Semilla
    std::random_device gna; // Generador de números aleatorios
    std::uniform_int_distribution<size_t> dis(-20, 20); // Establecemos el rango de los números
    int a = dis(gna); // Hemos generado un número aleatorio y se lo hemos asignado a la variable "a"
    

    // Para medir el tiempo:
    std::chrono::time_point<std::chrono::system_clock> start, end; // start es donde empieza y end donde acaba
    // Para encender el cronómetro:
    start = std::chrono::system_clock::now();
    // Para pararlo:
    end = std::chrono::system_clock::now();
    // El tiempo que ha tardado es la resta de ambas variables:
    std::chrono::duration<double> elapsed_seconds = end-start;
    // Para imprimir lo que tarda:
    std::cout << "Ha tardado" << elapsed_seconds.count() << '\n';

    return 0;
}
