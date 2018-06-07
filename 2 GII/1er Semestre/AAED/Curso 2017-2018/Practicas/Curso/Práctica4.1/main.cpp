#include <iostream>
#include "polinom.h"
#include "operaciones.h"
#include "ESpolinomio.h"


using namespace std;

int GradoMaximo(polinomio p1, polinomio p2){
    int maximo=0;
    if(p1.grado()>p2.grado())
        maximo=p1.grado();
    else
        maximo=p2.grado();
    return maximo;
}

int main()
{
    int n,gr_a,gr_b,gradototal;

    cout <<"\n         �������������������������������������������������������������ͻ";
    cout <<"\n         �                   ::   BIENVENIDO   ::                      �";
    cout <<"\n         �������������������������������������������������������������͹";
    cout <<"\n         �                                                             �";
    cout <<"\n         �     1.- Sumar polinomios        2.- Restar polinomios       �";
    cout <<"\n         �                                                             �";
    cout <<"\n         �     3.- Multiplicar polinomios  4.- Derivar polinomio       �";
    cout <<"\n         �                                                             �";
    cout <<"\n         �                       0.- Salir                             �";
    cout <<"\n         �                                                             �";
    cout <<"\n         �������������������������������������������������������������ͼ";
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


