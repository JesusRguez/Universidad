#include <iostream>

using namespace std;

void mostrar(int i){std::cout<<i<<" [entero]"<<std::endl;}
void mostrar(double f){std::cout<<f<<" [real]"<<std::endl;}
//Si ponemos float en vez de double en la linea de arriba, no funciona.

int main(){
	mostrar(2);
	mostrar(2.5);
	mostrar('a');
}
