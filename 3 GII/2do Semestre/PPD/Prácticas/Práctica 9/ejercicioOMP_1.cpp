#include <cstdio>
#include <iostream>
#include <omp.h>

using namespace std;

int main ()  {
    int nthreads, tid;
    
    #pragma omp parallel private(tid)     
    {
        tid = omp_get_thread_num(); // Obtiene el identificador del thread 
    	#pragma omp master
    	{
    	cout<<"Hola amigos, soy vuestro maestro con id "<<tid<<endl;
    	}
    	#pragma omp barrier
    	
    	if(tid!=0)
	        printf("Hola maestro, soy el esclavo %d\n",tid);
    }  
}
