#include <cstdio>
#include <time.h>
#define N 4
#define M 3

int main () {
    int i, j, k, temp;
    int nthreads, tid;
    int n, m;
    int A[M][N], B[N][M], R[M][M];

    unsigned t0, t1;

    m = M;
    n = N;

    //Inicialización de la primera matriz:
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            A[i][j] = i + j;
        }
    }

    printf("Impresion de A:\n");
    for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){
        	printf("%d\t",A[i][j]);
    	}
    	printf("\n");
    }

    //Inicialización de la segunda matriz:
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            B[i][j] = i + j;
        }
    }

    printf("Impresion de B:\n");
    for (i = 0; i < n; i++){
    	for (j = 0; j < m; j++){
        	printf("%d\t",B[i][j]);
    	}
    	printf("\n");
    }

    t0=clock();
    for (i = 0 ; i < m ; i++ ){
        for (k = 0 ; k < m ; k++ ){
            temp = 0;
            for (j = 0 ; j < n ; j++ ){
                temp += A[i][j] * B[j][k];
                R[i][k] = temp;
            }
        }
    }
    t1=clock();

    printf("El resultado secuencial es:\n");
	for (i = 0; i < M; i++){
    	for (j = 0; j < M; j++){
        	printf("%d\t",R[i][j]);
    	}
    	printf("\n");
    }

    double tiempo=double(t1-t0)/CLOCKS_PER_SEC;
    printf("El tiempo usado es: %d segundos.\n", tiempo);
}
