/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

 #include<iostream>
 #include <cstdlib>
 #include <ctime>
 #include <chrono>
 #include <random>
 extern "C" {
 	#include <unistd.h>
 }
#include <thread>

using namespace std;

int m[10000][10000];
int r[10000][10000];
int f[3][3];
const int n = 10000;

void convolucion(int inicio, int fin){
    int a[3][3];
    int v = 0;
    for (int i=1; i<9999; ++i) {
        for (int j=1; j<9999; ++j) {
            a[0][0] = m[i-1][j-1];
            a[0][1] = m[i-1][j];
            a[0][2] = m[i-1][j+1];
            a[1][0] = m[i][j-1];
            a[1][1] = m[i][j];
            a[1][2] = m[i][j+1];
            a[2][0] = m[i+1][j-1];
            a[2][1] = m[i+1][j];
            a[2][2] = m[i+1][j+1];
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    v += a[k][l] * f[k][l];
                }
            }
            if (v < -20) {
                v = -20;
            }
            if (v > 20) {
                v = 20;
            }
            r[i][j] = v;
        }
    }
}

void convolucionar(int i, int h){
    int rango = 10000/h;
    int inicio = 1 + (i*rango);
    int fin = inicio + rango - 2;
    convolucion(inicio, fin);
}

int main(int argc, char const *argv[]) {

    srand(time(NULL));
    std::random_device gna;
    std::uniform_int_distribution<size_t> dis(-20, 20);

    for (int i=0; i<10000; ++i) {
        for (int j=0; j<10000; ++j) {
            m[i][j] = dis(gna);
        }
    }

    int opcion;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int h;
    std::cout << "Número de hilos: ";
    std::cin >> h;
    thread hilos[h];
    do {
        std::cout << "Introduzca el filtro a aplicar o salir:\n1. Enfocar\n2. Realzar bordes\n3. Detectar bordes\n4. Filtro de Sobel\n5. Filtro de Sharpen\n6. Salir" << '\n';
        cin >> opcion;
        switch (opcion) {
            case 1:
                f[0][0] = 0;
                f[0][1] = -1;
                f[0][2] = 0;
                f[1][0] = -1;
                f[1][1] = 5;
                f[1][2] = -1;
                f[2][0] = 0;
                f[2][1] = -1;
                f[2][2] = 0;

                start = std::chrono::system_clock::now();
                for (int i = 0; i < h; ++i) {
                    hilos[i] = thread(convolucionar, i, h);
                }
                for (int i = 0; i < h; ++i) {
                    hilos[i].join();
                }
                end = std::chrono::system_clock::now();
            break;
            case 2:
                f[0][0] = 0;
                f[0][1] = 0;
                f[0][2] = 0;
                f[1][0] = -1;
                f[1][1] = 1;
                f[1][2] = 0;
                f[2][0] = 0;
                f[2][1] = 0;
                f[2][2] = 0;

                start = std::chrono::system_clock::now();
                for (int i = 0; i < h; ++i) {
                    hilos[i] = thread(convolucionar, i, h);
                }
                for (int i = 0; i < h; ++i) {
                    hilos[i].join();
                }
                end = std::chrono::system_clock::now();
            break;
            case 3:
                f[0][0] = 0;
                f[0][1] = 1;
                f[0][2] = 0;
                f[1][0] = 1;
                f[1][1] = -4;
                f[1][2] = 1;
                f[2][0] = 0;
                f[2][1] = 1;
                f[2][2] = 0;

                start = std::chrono::system_clock::now();
                for (int i = 0; i < h; ++i) {
                    hilos[i] = thread(convolucionar, i, h);
                }
                for (int i = 0; i < h; ++i) {
                    hilos[i].join();
                }
                end = std::chrono::system_clock::now();
            break;
            case 4:
                f[0][0] = -1;
                f[0][1] = 0;
                f[0][2] = 1;
                f[1][0] = -2;
                f[1][1] = 0;
                f[1][2] = 2;
                f[2][0] = -1;
                f[2][1] = 0;
                f[2][2] = 1;

                start = std::chrono::system_clock::now();
                for (int i = 0; i < h; ++i) {
                    hilos[i] = thread(convolucionar, i, h);
                }
                for (int i = 0; i < h; ++i) {
                    hilos[i].join();
                }
                end = std::chrono::system_clock::now();
            break;
            case 5:
                f[0][0] = 1;
                f[0][1] = -2;
                f[0][2] = 1;
                f[1][0] = -2;
                f[1][1] = 5;
                f[1][2] = -2;
                f[2][0] = 1;
                f[2][1] = -2;
                f[2][2] = 1;

                start = std::chrono::system_clock::now();
                for (int i = 0; i < h; ++i) {
                    hilos[i] = thread(convolucionar, i, h);
                }
                for (int i = 0; i < h; ++i) {
                    hilos[i].join();
                }
                end = std::chrono::system_clock::now();
            break;
            case 6:
                exit(0);
            break;
            default:
                std::cout << "Por favor, introduzca una opción válida" << '\n';
        }
    } while(opcion < 1 || opcion > 6);
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "La convolución ha tardado "<< elapsed_seconds.count() << " segundos\n";

    return 0;
}
