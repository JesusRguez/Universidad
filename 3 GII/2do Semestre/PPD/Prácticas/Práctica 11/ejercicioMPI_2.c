#include <stdio.h>
#include <mpi.h>
#define N    10

int main (int argc, char *argv[]) {
	int  n, myid, numprocs;

	int mi_res, res;

	int source, dest, tag = 100;
	MPI_Status status;
    int i, mi_suma, suma;
    int a[N], b[N], c[N];

	MPI_Init(&argc, &argv);                  // Inicializa el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);  // Número de identificación
                                             // del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);    // Número total de procesos

	if(myid==0){
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
	}

	MPI_Barrier ( MPI_COMM_WORLD );

	suma=0;
	res=0;

	for (i = 0; i < N; i++) {
		a[i] = b[i] = i * 1.0;
	}

    for (i = myid ; i < N; i += numprocs) {
        c[i] = a[i] * b[i];
        printf("El thread %d, de %d threads, calcula la iteracion i = %d: %d*%d=%d\n", myid, numprocs, i,a[i],b[i],c[i]);
    }

    for(i = myid ; i < N; i += numprocs) {
        suma=suma+c[i];
    }

	mi_suma=suma;
	printf("\nProceso: %d, mi_suma: %.d\n", myid, mi_suma);

	if(myid == 0) {
        res = mi_suma;
        for (i = 1; i < numprocs; i++) {
            source = i;        // Recibe resultados del resto de procesos
            MPI_Recv(&mi_suma, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
            res += mi_suma;
        }
        printf("\nLa suma paralela es: %d\n",res);
    } else {
        dest = 0;
        // Envía cálculo local al proceso 0
        MPI_Send(&mi_suma, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
    }



	MPI_Finalize();

}
