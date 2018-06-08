/***************************************************************************//**
 * \file    dac_lpc40xx.c
 *
 * \brief   Funciones de manejo del convertidor digital/anal�gico del LPC40xx.
 */
 
#include <LPC407x_8x_177x_8x.h>
#include "dac_lpc40xx.h"

/***************************************************************************//**
 * \brief       Inicializar el convertidor digital/anal�gico del LPC40xx. Para
 *              activar el convertidor hay que configurar el pin P0[26] para que
 *              realice la funci�n DAC_OUT (consultar la p�gina 138 del manual
 *              del LPC40xx). Despu�s, escribiremos 0 en el registro CTRL del DAC
 *              para deshabilirar el uso de DMA y escribiremos tambi�n 0 en el
 *              registro CR del DAC para generar inicialmente una tensi�n de 0
 *              voltios por su salida (ver el cap�tulo 33 del manual del
 *              LPC40xx).
 */
void dac_inicializar(void)
{
    /* C O M P L E T A R
     */
		LPC_IOCON->P0_26 = (1<<16) | 2;
		LPC_DAC ->CTRL = 0;
		LPC_DAC ->CR = 0;
		
	
}

/***************************************************************************//**
 * \brief       Env�a al convertidor digital/anal�gico del LPC40xx un dato
 *              digital para que �ste lo convierta en una tensi�n anal�gica de
 *              salida (ver el cap�tulo 33 del manual del LPC40xx).
 *
 * \param[in]   valor_a_convertir   Valor a enviar al DAC. Debe estar entre 0
 *                                  y 1023, ya que el DAC es unipolar de 10 bits.
 *                                  La funci�n no genera error si el dato de
 *                                  entrada est� por encima de 1023 sino que
 *                                  preserva y escribe en el DAC s�lo los 10
 *                                  bits menos significativos del valor.
 */
void dac_convertir(uint16_t valor_a_convertir)
{
    /* C O M P L E T A R
     */
//		//ASSERT(valor_a_convertir > 0 , "Valor a convertir menor que 0");
//		if(valor_a_convertir<0)
//			valor_a_convertir=0;
//		if(valor_a_convertir >1023)
//			valor_a_convertir &= 1023;
		
		LPC_DAC ->CR = (valor_a_convertir & 0x3FF)<<6; // Desplazamiento para posicionar correctamente el valor a convertir
		
}
