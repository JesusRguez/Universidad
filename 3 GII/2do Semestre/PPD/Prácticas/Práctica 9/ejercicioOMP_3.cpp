#include <cstdio>
#include <omp.h>
#define N 3 
#define M 3

int main () {
    int i, j, k, temp;
    int nthreads, tid;
    int n, m;
    int A[M][N], B[M][N], R[M][N];
    
    m = M;
    n = N;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        B[i][j] = A[i][j] = i + j;
        
    printf("Primero realizaemos la multiplicacion secuencial:\n");
        
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
        	R[i][j]=0;
        	for(k=0;k<n;k++){
        	    R[i][j]=(R[i][j]+(A[i][k]*B[k][j]));
        	}
        }
	}
	
	printf("El resultado secuencial es:\n");
	for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){
        	printf("%d\t",R[i][j]);
    	}
    	printf("\n");
    }
    
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        B[i][j] = A[i][j] = i + j;    
    
    printf("\nA continuación, realizaremos la multiplicacion paralela:\n\n");
	
    #pragma omp parallel for default(none) \
    private(tid, i, j, k, temp) shared(m, n, A, B, R, nthreads)
    for(i=0;i<m;i++){
    	tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
    	for(j=0;j<n;j++){
        	R[i][j]=0;
        	for(k=0;k<n;k++){
        		temp=R[i][j];
        	    R[i][j]=(R[i][j]+(A[i][k]*B[k][j]));
        	    printf("El thread %d, de %d threads, calcula la iteracion i = %d: %d+%d*%d=%d\n", tid, nthreads, i, temp, A[i][k], B[k][j], R[i][j]);
        	}
        	printf("\n");
        }
	}
    
    printf("El resultado paralelo es:\n");
	for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){
        	printf("%d\t",R[i][j]);
    	}
    	printf("\n");
    }
}
