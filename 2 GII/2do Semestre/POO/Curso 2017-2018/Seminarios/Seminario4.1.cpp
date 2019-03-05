#include <iostream>

using namespace std;

void mostrar(int i){cout<<i<<" [entero]"<<endl;}
void mostrar(double f){cout<<f<<" [real]"<<endl;}
//Si ponemos float en vez de double en la linea de arriba, no funciona.

int main(){
	mostrar(2);
	mostrar(2.5);
	mostrar('a');
}
