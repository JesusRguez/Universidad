#include <cstdio>
#include <cmath>
#include <iostream>
#include <random>

using namespace std;

class Ants{
public:
	Ants(){
		for(int i=0;i<n;++i){
			x[i]=(int)rand()%10;
			y[i]=(int)rand()%10;
			cout<<"La ciudad "<<i<<" en posición: "<<x[i]<<", "<<y[i]<<endl;
		}
		cout<<"\n\n"<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				d[i][j]=CalculaDistancia(i,j);
				if(i==j){
					f[i][j]=0.0;
				}else{
					f[i][j]=1.0;
				}
			}
		}

		/*for(int i=0;i<10;++i){
			for(int j=0;j<10;++j){
				cout<<d[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n\n"<<endl;*/
	}



	double CalculaDistancia(int p1, int p2){
		return (sqrt(pow((x[p1]-x[p2]),2)+pow((y[p1]-y[p2]),2)));
	}

	double D(int i,int j)const{ return d[i][j]; }

	void F(int i, int j, double s){
		f[i][j]=s;
	}

	double verF(int i, int j) const{ return f[i][j]; }

private:
	static const int n=10;
	int x[n];
	int y[n];
	double d[n][n];
	double f[n][n];
};

class Solution{
public:
	Solution(){
		int aux, paux;
		for(int i=0;i<n;++i){
			path[i]=i;
		}
		for(int i=0;i<n;++i){
			paux=rand()%10;
			aux=path[paux];
			path[paux]=path[i];
			path[i]=aux;
		}

		aux=path[0];
		path[0]=0;
		path[aux]=aux;

		coste=0;
		performance_=0.0;

		/*for(int i=0;i<10;++i){
			cout<<path[i]<<", ";
		}
		cout<<endl;*/
	}

	void calculaCoste(Ants a){
		int c=0;
		for(int i=0;i<n;++i){
			coste+=a.D(c, path[i]);
			c=path[i];
		}
		//cout<<"El coste es: "<<coste<<endl;
	}

	double vercoste() const{
		return coste;
	}

	void performance(double p){
		cout<<"Le sumo "<<p<<" a "<<performance_<<endl;
		performance_+=p;
		cout<<"performance vale: "<<performance_<<endl;
	}

	double mostrarperformance()const{
		return performance_;
	}

	int verpath(int j) const{
		return path[j];
	}
private:
	static const int n=10;
	int path[n];
	double coste;
	double performance_;
};

int main(int argc, char const *argv[]) {
	Ants a;
	/*for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			cout<<a.D(i,j)<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\n"<<endl;*/
	//cout<<"\n\n"<<endl;

	Solution s[10];

	for(int i=0;i<10;++i){



		int costemedio=0;
		for(int i=0;i<10;++i){
			s[i].calculaCoste(a);
			costemedio+=s[i].vercoste();
		}
		costemedio=costemedio/10;
		cout<<"La media es: "<<costemedio<<endl;
		cout<<"\n\n"<<endl;


		for(int i=0;i<10;++i){
			s[i].performance(costemedio-s[i].vercoste());
		}

		for(int i=0;i<10;++i){
			cout<<"El performance de "<<i<<" es: "<<s[i].mostrarperformance()<<endl;
		}
		cout<<"\n\n"<<endl;

		int c=0;
		for(int i=0;i<10;++i){
			if(s[i].mostrarperformance()>0){
				for(int j=1;j<10;++j){
					cout<<"Vamos a coger este performance: "<<s[i].mostrarperformance()<<endl;
					a.F(c,s[i].verpath(j),s[i].mostrarperformance());
					cout<<"Ahora el performance es: "<<s[i].mostrarperformance()<<endl;
					c=s[i].verpath(j);
				}
			}
		}

		for(int i=0;i<10;++i){
			for(int j=0;j<10;++j){
				cout<<a.verF(i,j)<<"\t";
			}
			cout<<"\n";
		}
	}

	return 0;
}
