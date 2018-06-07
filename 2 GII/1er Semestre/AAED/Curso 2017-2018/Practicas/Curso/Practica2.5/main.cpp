#include <iostream>
#include <algorithm>
#define PERMUTACIONES 10000000

using namespace std;

int main()
{
    int numeros[6]={1,2,3,4,5,6}, ordenadas=0;
    const size_t n=sizeof numeros/sizeof *numeros;


    for(int i=0; i<PERMUTACIONES; i++){
        random_shuffle(numeros, numeros+n);
        if(next_permutation(numeros,numeros+n)==false)
            ordenadas++;
    }
    cout<<"Hay "<<ordenadas<<" permutaciones ordenadas."<<endl;

    return 0;
}
