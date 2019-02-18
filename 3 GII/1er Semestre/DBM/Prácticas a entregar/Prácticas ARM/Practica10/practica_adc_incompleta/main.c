/***************************************************************************//**
 * \file    main.c
 *
 * \brief   Función main para la práctica 10.
 */

#include <LPC407x_8x_177x_8x.h>
#include "glcd.h"
#include "adc_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "termistor_ntc.h"

int main(void)
{
    /* C O M P L E T A R
     */
	
	uint32_t frecuencia=1000000;
	uint32_t convertido, temp_comvertido;
	float tension, temp_tension, temperatura;
	
	timer_inicializar(TIMER0);
	timer_inicializar(TIMER1);
	glcd_inicializar();
	adc_inicializar(frecuencia, (1u << 2) | (1u << 0));
	while(TRUE){
	temperatura=0;
	convertido=adc_convertir(2);
	tension=adc_traducir_a_tension(convertido);
	
		for(int i=0;i<100;i++){
		temp_comvertido=adc_convertir(0);
		temp_tension=adc_traducir_a_tension(temp_comvertido);
		temperatura=temperatura+ntc_traducir_tension_a_temperatura(temp_tension);
		timer_iniciar_ciclos_ms(TIMER1,10);
		timer_esperar_fin_ciclo(TIMER1);
		}
	temperatura=temperatura/100;
		
	glcd_xprintf(0,0,VERDE, NEGRO, FONT16X32, "Resultado ADC: %u", convertido);
	glcd_xprintf(0,40,VERDE, NEGRO, FONT16X32, "Tensión: %f", tension);
  glcd_xprintf(0,80,VERDE, NEGRO, FONT16X32, "Temperatura: %f", temperatura);
	
	timer_iniciar_ciclos_ms(TIMER0, 1000);
	timer_esperar_fin_ciclo(TIMER0);
	}
}


