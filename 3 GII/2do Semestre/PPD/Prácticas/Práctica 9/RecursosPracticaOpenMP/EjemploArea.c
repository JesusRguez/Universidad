/********************************************************************
 * Guadalupe Ortiz Bellot
 *
 * Calculo de un área con OpenMP
 *********************************************************************/

#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int i, h, base, area, tid;
    int bases[10]={1,2,3,4,5,6,7,8,9,10};
    int total_base=0;
    int n=10;
    int sumaparcial=0;
    omp_set_num_threads(4);
    // int numThreads =omp_get_num_threads();
    int base_parcial[4];

    h = 2;

    //Secuencial
    for (i = 0; i < n; i++) {
        total_base += bases[i];
    }
    area = total_base * h;
    printf("Solución secuencial: %d\n", area );

    //Paralelo 1
    total_base=0;
    #pragma omp parallel  private(i,tid)
    {
        int numThreads =omp_get_num_threads();
        tid = omp_get_thread_num();
        for (i = tid, base_parcial[i]=0; i < n; i+=numThreads) {
            base_parcial[tid]+= bases[i];
            //  printf("El thread %d calcula la iteracion i = %d\n bbb %d", tid, i, base_parcial[i]);
        }
    }
    total_base=0;
    int numThreads =omp_get_num_threads();
    for (i = 0; i < 4; i++) {
        total_base += base_parcial[i];
    }

    area = total_base * h;
    printf("Solución paralela 1: %d\n", area );

    //Paralelo 2
    #pragma omp parallel private(i,tid)
    {
        total_base=0;
        int numThreads =omp_get_num_threads();
        tid = omp_get_thread_num();
        for (i = tid; i < n; i+=numThreads) {
            sumaparcial+= bases[i];
        }

        #pragma omp critical
            total_base += sumaparcial*h;
    }

    printf("Solución paralela 2: %d\n", total_base);

    //Paralelo 3
    // La variable total_base es una variable de reducción mediante suma
    total_base=0;

    #pragma omp parallel for reduction(+:total_base) private(i,tid)
        for (i = 0; i < n; i++) {
            tid = omp_get_thread_num();
            total_base += bases[i];
            printf("El thread %d calcula la iteracion i = %d\n", tid, i);
        }
        area = total_base * h;
        printf("Solución con reducción: %d\n", area );
}
