#include <iostream>
#include <algorithm>
#include <time.h>
#include "carta.h"
#include "pilapseudoestatica.h"
#include "Solitario.h"

using namespace std;

int main(){

    tCarta baraja[40];
    tfig base[4];
    // Generar las 40 cartas de la baraja española.
    for (int i = 0, j = OROS; j <= BASTOS; j++)
        for (int k = AS; k <= REY; k++, i++)
            baraja[i] = tCarta(tpalo(j), tfig(k));
    srand(time(0));
    bool victoria = false;
    int partidas = 0;
    do {
        random_shuffle(baraja, baraja+40); // Barajar las cartas
        victoria = solitario(baraja, base); // Jugar
        // Mostrar resultado
        cout << "Partidas jugadas = " << ++partidas << endl;
        cout << "Últimas cartas colocadas:\n"
        << "\t" << tCarta(OROS, base[OROS]) << endl
        << "\t" << tCarta(COPAS, base[COPAS]) << endl
        << "\t" << tCarta(ESPADAS, base[ESPADAS]) << endl
        << "\t" << tCarta(BASTOS, base[BASTOS]) << endl
        << endl;
    } while (!victoria); // Parar al ganar una partida.
    cout << "½Conseguido! Bien hecho.\n" << endl;

    return 0;


}
