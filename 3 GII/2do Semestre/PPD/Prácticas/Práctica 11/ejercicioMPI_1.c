#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[])  {

    int myrank, size;

	MPI_Init(&argc, &argv);                  // Inicializa el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);  // Número de identificación
                                             // del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);    // Número total de procesos
    if(myrank==0){
		printf("Hola amigos, soy vuestro maestro con id %d\n", myrank);
	}else{
		printf("Hola maestro, soy el esclavo %d\n",myrank);
	}
    MPI_Finalize();
}
