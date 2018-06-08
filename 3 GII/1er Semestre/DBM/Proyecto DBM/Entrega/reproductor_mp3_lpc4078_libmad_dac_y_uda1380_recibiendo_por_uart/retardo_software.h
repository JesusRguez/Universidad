/***************************************************************************//**
 * \file   retardo_software.h
 *
 * \brief  Funciones para generar retardos mediante bucle software. Evita tener
 *         que gastar un timer para realizar el retardo y puede ser suficiente
 *         en muchas ocasiones.
 */

#ifndef RETARDO_SOFTWARE_H
#define RETARDO_SOFTWARE_H

#include "tipos.h"

void retardo_software_inicializar(void);

void retardo_software_fijar_escala(uint32_t escala);

void retardo_software_us(uint32_t retardo_us);

#endif  /* RETARDO_SOFTWARE_H */
