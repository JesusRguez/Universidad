/***************************************************************************//**
 * \file    dac_lpc40xx.c
 *
 * \brief   Funciones de manejo del convertidor digital/analógico del LPC40xx.
 */

#ifndef DAC_LPC40XX_H
#define DAC_LPC40XX_H

#include "tipos.h"

void dac_inicializar(void);
void dac_convertir(uint16_t valor_a_convertir);

#endif

