#include <cstdio>
#include <omp.h>
#define CHUNKSIZE 2
#define N    10

int main () {
        int i, chunk, nthreads, tid, suma;
        int a[N], b[N], c[N];
        for (i = 0; i < N; i++) {
                a[i] = b[i] = i * 1.0;
        }

        for(int j=0; j< N; ++j) {
                c[j]=a[j]*b[j];
        }

        suma=0;

        printf("Primero realizaremos la suma secuencial:\n");

        for(int k=0; k<N; ++k) {
                suma=suma+c[k];
        }

        printf("\nLa suma secuencial es: %d\n",suma);

        for (i = 0; i < N; i++)
                a[i] = b[i] = i;

        printf("\nA continuacion, la suma paralela:\n\n");

        chunk = CHUNKSIZE;

        // Las variables a, b, c, chunk son de tipo compartido
        // Las variables i, tid  son privadas a cada thread
    #pragma omp parallel shared(a, b, c, chunk) private(i, tid)
        {
                // Se realiza una asignación estática de iteraciones
                // en la que el tamaño del bloque se fija a chunk
        #pragma omp for schedule(static, chunk)
                for (i = 0; i < N; i++) {
                        tid = omp_get_thread_num();
                        nthreads = omp_get_num_threads();
                        c[i] = a[i] * b[i];
                        printf("El thread %d, de %d threads, calcula la iteracion i = %d: %d*%d=%d\n", tid, nthreads, i,a[i],b[i],c[i]);
                }
        } // Fin de la región paralela

        suma=0;

        for(int k=0; k<N; ++k) {
                suma=suma+c[k];
        }

        printf("\nLa suma paralela es: %d\n",suma);

}
