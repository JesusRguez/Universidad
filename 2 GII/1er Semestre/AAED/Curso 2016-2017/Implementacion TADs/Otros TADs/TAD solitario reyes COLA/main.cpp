#include <iostream>
#include <algorithm>
#include <time.h>
#include "carta.h"
#include "ColaCircular.h"
#include "Solitario.h"

using namespace std;

int main(){

    tCarta baraja[40];
    tMonton reyes(5);//cola de hasta 5 cartas
    // Generar las 40 cartas de la baraja española.
    for (int i = 0, p = OROS; p <= BASTOS; p++)
        for (int f = AS; f <= REY; k++, i++)
            baraja[i] = tCarta(tpalo(p), tfig(f));
    srand(time(0));
    bool victoria = false;
    int partidas = 0;
    do {
        tfig monton = tfig(rand()%10);
        random_shuffle(baraja, baraja+40); // Barajar las cartas
        victoria = solitario(baraja, monton, reyes); // Jugar
        // Mostrar resultado
        cout << "Partidas jugadas = " << ++partidas << endl;
        cout << "Monton de reyes:\n"
        while (!reyes.vacia()) // Parar al ganar una partida.
        {
            cout<<"\t"<<reyes.frente()<<endl;
            reyes.pop();
        }
    }
    cout << "½Conseguido! Bien hecho.\n" << endl;

    return 0;


}
