#include <cstdlib>
#include <iostream>
#include <ctime>
#include <omp.h>
#include <random>
#include <string>
#include <omp.h>

const int N=50;

using namespace std;

int generapos();
int generasentido();
bool colocar(char sopa[N][N], int sentido, int posx, int posy, string c);
bool todoguiones(char sopa[N][N], int sentido, int posx, int posy, string c);
void imprimirSopa(char sopa[N][N]);
bool busca(char sopa[N][N], int i, int j, string c, int *sentido);

int main(){
	char sopa[N][N];

	unsigned t0, t1;

	srand(time(NULL));

	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			sopa[i][j]='-';
		}
	}

	string v[]={"bicicletas","murcielago","carpintero","terremotos","archipielago"};

	int longitud = sizeof(v)/sizeof(string);

	//Rellenamos la sopa con las palabras

	int sentido, posx, posy;
	for(int i=0;i<longitud;++i){
		do{
			sentido=generasentido();
			posx=generapos();
			posy=generapos();
			//printf("Imprimimos en sentido %d: Coor. [%d,%d]\n", sentido,posx,posy);
		}while(!colocar(sopa, sentido, posx, posy, v[i]));
	}

	//imprimirSopa(sopa);

	//Terminamos de rellenar la sopa
	static const char letras[]={"abcdefghijklmnopqrstuvwxyz"};
	const std::size_t longtd=sizeof(letras)-1;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			if(sopa[i][j]=='-') {
				std::random_device gna;
				std::uniform_int_distribution<size_t> dis(0, longtd-1);
				sopa[i][j]=letras[dis(gna)];
			}
		}
	}

	//Imprimir la matriz
	imprimirSopa(sopa);

	//Ahora a buscar las palabras en la sopa
	//Primero recorremos en horizontal
	t0=clock();
	int x, y;
	sentido=-1;
	string localizacion[longitud];
	struct pal{
		string p;
		int x, y, s;
	};
	pal palabraEncontrada[longitud];
	int k=0, l=0, i=0, j=0;
	#pragma omp parallel default(none) private(k, l, i, j, x, y, sentido) shared(longitud, v, sopa, palabraEncontrada)
	#pragma omp for
	for(k=0;k<longitud;++k){
		l=0;
		for(i=0;i<N;++i){
			for(j=0;j<N;++j){
				if(v[k][l]==sopa[i][j]){
					if(busca(sopa,i,j,v[k],&sentido)){
						x=i;
						y=j;
						palabraEncontrada[k].p=v[k];
						palabraEncontrada[k].x=x;
						palabraEncontrada[k].y=y;
						palabraEncontrada[k].s=sentido;
					}
				}
			}
		}//Aqui dejamos de recorrer para una palabra
		++l;
	}
	t1=clock();

	for(int i=0;i<longitud;++i){
		cout<<"La palabra "<<palabraEncontrada[i].p<<" en posicion ["<<palabraEncontrada[i].x<<"], ["<<palabraEncontrada[i].y<< "] con sentido "<<(palabraEncontrada[i].s? "vertical":"horizontal")<<endl;
	}

	double time=(double(t1-t0)/CLOCKS_PER_SEC);
	cout<<"Tiempo de búsqueda paralelo: "<<time<<" segundos."<<endl;

	return 0;
}

int generasentido(){
	int sentido=rand()%2;
	//sentido=0 -> horizontal  sentido=1 -> vertical
	return sentido;
}

int generapos(){
	return rand()%N;
}

bool colocar(char sopa[N][N], int sentido, int posx, int posy, string c){
	switch (sentido) {
	case 0:
		if(todoguiones(sopa, sentido, posx, posy, c) && posy+c.length()<N) {
			printf("Entra. Caso 0: horizontal [%d,%d]\n",posx,posy );
			for(int i=0;i<c.length();++i){
				sopa[posx][posy+i]=c[i];
			}
		}
		else
			return false;
		break;
	case 1:
		if(todoguiones(sopa, sentido, posx, posy, c) && posx+c.length()<N) {
			printf("Entra. Caso 1: vertical [%d,%d]\n",posx,posy );
			for(int i=0;i<c.length();++i){
				sopa[posx+i][posy] = c[i];
			}

		}
		else
			return false;
		break;
	}
	return true;
}

bool todoguiones(char sopa[N][N], int sentido, int posx, int posy, string c){
	bool entra=true;
	int i=0, j=0;
	switch (sentido) {
		case 0://horizontal
			while(j<c.length() && entra==true){
				if(sopa[posx][posy+j]!='-'){
					entra=false;
				}
				++j;
			}
		break;
		case 1://vertical
			while(i<c.length() && entra==true){
				if(sopa[posx+i][posy]!='-'){
					entra=false;
				}
				++i;
			}
		break;
	}
	return entra;
}

bool busca(char sopa[N][N], int i, int j, string c, int *sentido){
	bool horizontal=true, vertical=true;
	int x=0;
	while((horizontal || vertical) && (x<c.length())){
		if(sopa[i][j+x]!=c[x]){
			horizontal=false;
		}
		//horizontal = sopa[i][j+x]==c[x];
		if(sopa[i+x][j]!=c[x]){
			vertical=false;
		}
		++x;
	}

	if(horizontal){
		*sentido=0;
	}

	if(vertical){
		*sentido=1;
	}


	return horizontal||vertical;
}

void imprimirSopa(char sopa[N][N]){
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			printf("%c  ", sopa[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
