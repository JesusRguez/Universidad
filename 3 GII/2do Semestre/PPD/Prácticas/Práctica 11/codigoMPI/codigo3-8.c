/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Capítulo 3, Código 3.8
* Cálculo de PI haciendo uso de funciones colectivas
*********************************************************************/

#include <mpi.h>
#include <stdio.h>
#include <math.h>


double fabs(double);

double f(double a) {
    return (4.0 / (1.0 + a * a));
}

/*int main(int argc, char *argv[]) {
    int  n, myid, numprocs, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    int source, dest, tag = 100;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    printf("\nProcess %d of %d", myid, numprocs);
    if (myid == 0) {
       // Inicializa el número de intervalos n =
        printf("¿Cuantos intervalos quiere utilizar? ");
        scanf("%d",&n);
    }
    // El proceso 0 envía el número de intervalos
    // al resto de los procesos
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    h   = 1.0 / (double) n;
    sum = 0.0; // Suma de intervalos
    for (i = myid + 1; i <= n; i += numprocs) {
        x = h * ((double)i - 0.5);
        sum += f(x);
    }
    mypi = h * sum;
    printf("\nProceso: %d, mypi: %.16f\n", myid, mypi);
    // Reducción mediante suma del valor computado localmente
    // en el proceso 0
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid == 0)
        printf("\npi es aproximadamente %.16f, el error cometido es %.16f\n", pi, fabs(pi - PI25DT));

    MPI_Finalize();
}*/


/********************************************************************
* Guadalupe Ortiz Bellot
*
* Calculo de un área con OpenMPI con funciones colectivas
*********************************************************************/

int main(int argc, char *argv[]) {
    int  n, myid, numprocs, i,m;

    int mi_area, area, h, total_base;
    int bases[10]={1,2,3,4,5,6,7,8,9,10};

    h = 2;
    int source, dest, tag = 100;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    total_base=0;
    n=10;

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);


    for (i = myid ; i < n; i += numprocs) {
        total_base += bases[i];
	  printf("El thread %d calcula la iteracion i = %d\n", myid, i);
    }
    mi_area = total_base * h ;
    printf("\nProcessor: %d, mi_area: %.d\n", myid, mi_area);

    MPI_Reduce(&mi_area, &area, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);


    if(myid == 0) {
        printf ("\n**********TOTAL: %d *********************\n",area);
    }

    MPI_Finalize();
}
