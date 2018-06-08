/***************************************************************************//**
 */
 
/* USAR SOLO LA UART0. PARA QUE QUEPA EN RAM, LOS BUFFERS DEL RESTO DE UARTS NO
 * ESTÁN.
 */

#include <LPC407x_8x_177x_8x.h>
#include <stdio.h>
#include "reproductor_mp3.h"
#include "mad.h"
#include "midmad.h"
#include "tipos.h"
#include "timer_lpc40xx.h"
#include <string.h>
  
int main(void)
{		
	
		/*
		LPC_SC->EXTMODE = 1;
		LPC_SC->EXTPOLAR = 1;
		NVIC_SetPriority(EINT0_IRQn,10);
		LPC_IOCON->P2_10=1;
		LPC_SC->EXTINT = 1;
		NVIC_ClearPendingIRQ(EINT0_IRQn);
		NVIC_EnableIRQ(EINT0_IRQn);
		__enable_irq();
	*/
	reproducir_mp3();
    
    while (1) {}
}

