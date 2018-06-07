#include <iostream>
#include "polinom.h"
#include "ESpolinomio.h"
#include "AritmeticaPolinomio.h"

using namespace std;

int main()
{
    int n,gr_a,gr_b,gradototal;

    cout <<"\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    cout <<"\n         บ                   ::   BIENVENIDO   ::                      บ";
    cout <<"\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน";
    cout <<"\n         บ                                                             บ";
    cout <<"\n         บ     1.- Sumar polinomios        2.- Restar polinomios       บ";
    cout <<"\n         บ                                                             บ";
    cout <<"\n         บ     3.- Multiplicar polinomios  4.- Derivar polinomio       บ";
    cout <<"\n         บ                                                             บ";
    cout <<"\n         บ                       0.- Salir                             บ";
    cout <<"\n         บ                                                             บ";
    cout <<"\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    cout <<"\																		  ";
    cout <<"\n                              Elija una opcion: "<< endl;

    cin>>n;

    switch (n)
		{
        case 1:
            {
                cout <<"Introduzca el grado del primer polinomio:"<<endl;
                cin>>gr_a;
                polinomio Pol1(gr_a);
                cout <<"Introduzca el primer polinomio:"<<endl;
                Entrada_Polinomio(Pol1,gr_a);

                cout <<"Introduzca el grado del segundo polinomio:"<<endl;
                cin>>gr_b;
                polinomio Pol2(gr_b);
                cout <<"Introduzca el segundo polinomio:"<<endl;
                Entrada_Polinomio(Pol2,gr_b);

                gradototal=GradoMaximo(Pol1,Pol2);
                polinomio PolSol(gradototal);

                PolSol=Pol1+Pol2;

                Mostrar_Polinomio(PolSol);
            }
            break;
        case 2:
            {
                cout <<"Introduzca el grado del primer polinomio:"<<endl;
                cin>>gr_a;
                polinomio Pol1(gr_a);
                cout <<"Introduzca el primer polinomio:"<<endl;
                Entrada_Polinomio(Pol1,gr_a);

                cout <<"Introduzca el grado del segundo polinomio:"<<endl;
                cin>>gr_b;
                polinomio Pol2(gr_b);
                cout <<"Introduzca el segundo polinomio:"<<endl;
                Entrada_Polinomio(Pol2,gr_b);

                gradototal=GradoMaximo(Pol1,Pol2);
                polinomio PolSol(gradototal);

                PolSol=Pol1-Pol2;

                Mostrar_Polinomio(PolSol);
            }
            break;
        case 3:
            {
                cout <<"Introduzca el grado del primer polinomio:"<<endl;
                cin>>gr_a;
                polinomio Pol1(gr_a);
                cout <<"Introduzca el primer polinomio:"<<endl;
                Entrada_Polinomio(Pol1,gr_a);

                cout <<"Introduzca el grado del segundo polinomio:"<<endl;
                cin>>gr_b;
                polinomio Pol2(gr_b);
                cout <<"Introduzca el segundo polinomio:"<<endl;
                Entrada_Polinomio(Pol2,gr_b);

                gradototal=GradoMaximo(Pol1,Pol2);
                polinomio PolSol(gradototal);

                PolSol=Pol1*Pol2;

                Mostrar_Polinomio(PolSol);
            }
            break;
        case 4:
            {
                cout <<"Introduzca el grado del polinomio:"<<endl;
                cin>>gr_a;
                polinomio Pol1(gr_a);
                cout <<"Introduzca el polinomio:"<<endl;
                Entrada_Polinomio(Pol1,gr_a);

                gradototal=Pol1.grado();
                polinomio PolSol(gradototal);

                PolSol=derivada(Pol1);

                Mostrar_Polinomio(PolSol);
            }
            break;
        default:
            cout <<"Gracias por utilizar el programa."<<endl;
            break;
		}

    return 0;
}
