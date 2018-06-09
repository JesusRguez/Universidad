#ifndef _CELDA_HPP_
#define _CELDA_HPP_

//True = there is wall
//False = there is no wall

struct celda
{
	celda(bool del, bool det, bool izq, bool dech);

  celda(const celda&) = default;  //Copy constructor
  celda& operator=(const celda&) = default;
  celda(celda&&) = default;       //Movement constructor1
  celda& operator=(celda&&) = default;

	bool delante;
	bool detras;
	bool izquierda;
	bool derecha;
};
//Default cell has no walls around it
inline celda::celda(bool del = false, bool det = false, bool izq = false, bool dech = false): delante{del}, detras{det}, izquierda{izq}, derecha{dech} {}

#endif
