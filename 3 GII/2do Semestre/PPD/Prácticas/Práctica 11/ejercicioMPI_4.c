#include <stdio.h>
#include <mpi.h>
#define N 8

int main (int argc, char *argv[]) {


	int myid, numprocs;

	int mi_res, res;

	int source, dest, tag = 100;
	MPI_Status status;

    int i, j, k, temp;
    int n, m;
    int A[N*N], v[N], r[N];

    n = N;
	MPI_Init(&argc, &argv);                  // Inicializa el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);  // Número de identificación
                                             // del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);    // Número total de procesos

	int Ap[N*N/numprocs], Rp[N/numprocs];

    for (i = 0; i < n*n; ++i)
        A[i] = i;

	for(i=0; i<n;++i){
		v[i] = i;
		r[i]=0;
	}


	if(myid==0){
		printf("Primero realizaemos la multiplicacion secuencial:\n");

		for(i=0;i<n;++i){
	    	r[i]=0;
	    	for(j=0;j<n;++j){
	    	    r[i]=r[i]+(A[i*n+j]*v[j]);
	    	}
		}

		printf("El resultado secuencial es:\n");

    	for (j = 0; j < n; j++){
        	printf("%d\t",r[j]);
    	}
    	printf("\n");

	    printf("\nA continuación, realizaremos la multiplicacion paralela:\n\n");
	}

    MPI_Barrier ( MPI_COMM_WORLD );

	for (i = 0; i < n*n; ++i)
		A[i] = i;

	for(i=0; i<n;++i){
		v[i] = i;
		r[i]=0;
	}

	MPI_Bcast(v, n, MPI_INT, 0, MPI_COMM_WORLD);
	//printf("El scatter envía %d numeritos\n", n*n/numprocs);
	MPI_Scatter (A, n*n/numprocs, MPI_INT, Ap, n*n/numprocs, MPI_INT, 0, MPI_COMM_WORLD);

	for(i=0;i<n/numprocs;++i){
		r[i]=0;
		for(j = 0 ; j < n; ++j){
			temp=Rp[i];
			Rp[i]=Rp[i]+(Ap[i*n+j]*v[j]);
			printf("El proceso %d, de %d procesos, calcula la iteracion i = %d: %d+%d*%d=%d\n", myid, numprocs, i, temp, Ap[i*n+j], v[j], Rp[i]);
		}
		printf("\n");
	}


	MPI_Gather (Rp, n/numprocs, MPI_INT, r, n/numprocs, MPI_INT, 0, MPI_COMM_WORLD);


	if(myid==0){
		printf("El resultado paralelo es:\n");

		for (j = 0; j < n; j++){
			printf("%d\t",r[j]);
		}
		printf("\n");

	}


	MPI_Finalize();
}
