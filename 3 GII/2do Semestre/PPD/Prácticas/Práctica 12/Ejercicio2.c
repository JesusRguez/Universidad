#include <stdio.h>
#include <mpi.h>
#include <time.h>
#define N 3
#define M 4

int main (int argc, char *argv[]) {

    int myid, numprocs;

	int mi_res, res;

	int source, dest, tag = 100;
	MPI_Status status;

    int i, j, k, temp;
    int nthreads, tid;
    int n, m;
    int A[M*N], B[N*M], R[M*M];

    int r[(M*M)/numprocs];

    unsigned t0, t1;

    m = M;
    n = N;

    MPI_Init(&argc, &argv);                  // Inicializa el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);  // Número de identificación
                                             // del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);    // Número total de procesos

    if(myid==0){
        //Inicialización de la primera matriz:
        for (i = 0; i < n*m; ++i){
            A[i] = i;
        }

        printf("Impresion de A:\n");
        for (i = 0; i < m; i++){
        	for (j = 0; j < n; j++){
            	printf("%d\t",A[i*n+j]);
        	}
        	printf("\n");
        }

        //Inicialización de la segunda matriz:
        for (i = 0; i < m*n; ++i){
            B[i] = i;
        }

        printf("Impresion de B:\n");
        for (i = 0; i < n; i++){
        	for (j = 0; j < m; j++){
            	printf("%d\t",B[i*m+j]);
        	}
        	printf("\n");
        }
    }

    MPI_Barrier ( MPI_COMM_WORLD );

    MPI_Bcast(A, n*m, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(B, m*n, MPI_INT, 0, MPI_COMM_WORLD);
    //MPI_Send(A)

    int indice=0;
    t0=clock();
    for(i=myid*m/numprocs;i<(myid+1)*m/numprocs;++i){
        for(j=0;j<m;++j){
    		r[indice]=0;
    		for(k = 0 ; k < n; ++k){
    			r[indice]+=(A[i*n+k]*B[k*m+j]);
                //printf("%d-%d\n",myid*m/numprocs,(myid+1)*m/numprocs);
                //printf("[%d,%d](%d) = [%d,%d](%d) * [%d,%d](%d)\n",i+1,j+1,r[indice],i+1,k+1,A[i*N+k],k+1,j+1,B[k*M+j]);
    		}
            indice++;
    	}
    }
    t1=clock();

    /*for (i = 0 ; i < m ; i++ ){
        for (k = 0 ; k < m ; k++ ){
            temp = 0;
            for (j = 0 ; j < n ; j++ ){
                temp += A[i][j] * B[j][k];
                R[i][k] = temp;
            }
        }
    }*/


    MPI_Gather (r, (m*m)/numprocs, MPI_INT, R, (m*m)/numprocs, MPI_INT, 0, MPI_COMM_WORLD);

    if(myid==0){
        printf("El resultado paralelo es:\n");
        for (i = 0; i < m; i++){
            for (j = 0; j < m; j++){
                printf("%d\t",R[i*m+j]);
            }
            printf("\n");
        }
        double tiempo=(double)(t1-t0)/CLOCKS_PER_SEC;
        printf("El tiempo usado es: %d segundos.\n", tiempo);
    }

    MPI_Finalize();
}
