#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n, a, b;

    srand(time(0));

    cout<<"Introudzca el primer numero:"<<endl;
    cin>>a;
    cout<<"Introduzca el segundo numero:"<<endl;
    cin>>b;

    n=a+(rand()%(b-a)+1);

    cout<<n<<endl;

    return 0;
}
