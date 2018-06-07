#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    float permutaciones=10000000;
    int ordenadas=0, v[6]={1,2,3,4,5,6};
    const size_t n = sizeof v / sizeof *v;

    for(int i=0; i<permutaciones; i++)
    {
        random_shuffle(v, v+n);
        if(next_permutation(v, v+n)==false)
            ordenadas++;
    }

    cout<<ordenadas<<endl;

    return 0;
}
