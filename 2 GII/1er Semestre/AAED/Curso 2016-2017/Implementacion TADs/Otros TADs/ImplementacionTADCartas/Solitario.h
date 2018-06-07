#ifndef SOLITARIO_H
#define SOLITARIO_H

bool solitario(tCarta* baraja, tfig* base)
{
    // Elementos del juego
    Pila<tCarta> Mazo(40),
    Monton(40);
    // Preparar el mazo...
    for (int i = 0; i < 40; i++) {
        Mazo.push(baraja[i]);
    }
    // ... y las bases vacías.
    base[OROS] = VACIA; base[COPAS] = VACIA;
    base[ESPADAS] = VACIA; base[BASTOS] = VACIA;
    // Jugar
    int colocadas;
    do {
        colocadas = 0;
        while (!Mazo.vacia()) {
            // Pasar dos cartas (si hay) del mazo al montón de descartes.
            // ...
            // Pasar cartas del montón de descartes a sus bases mientras
            // sea posible.
            while (!Monton.vacia() && Monton.tope().fig() == base[Monton.tope().palo()] + 1) {
                base[Monton.tope().palo()] = Monton.tope().fig();
                Monton.pop();
                colocadas++;
            }
        } // Mazo vacío
        // Reponer el mazo con las cartas del montón de descartes.
        // ...
        // Parar si no quedan cartas en el mazo o bien en el último
        // ciclo no se ha colocado ninguna en su base.
    } while (!Mazo.vacia() && colocadas > 0);
    return (Mazo.vacia()); // TRUE (éxito) si el mazo está vacío, o lo
    // que es lo mismo, todas las cartas están
    // en sus bases.
}

#endif // SOLITARIO_H
