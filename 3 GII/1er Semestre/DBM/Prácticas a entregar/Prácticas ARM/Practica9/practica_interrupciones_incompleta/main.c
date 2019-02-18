/***************************************************************************//**
 * \file    main.c
 *
 * \brief   Ejemplo de uso de interrupciones que usa la interrupción del timer 0
 *          para mostrar un cronómetro con horas, minutos y segundos.
 */

#include <LPC407x_8x_177x_8x.h>
#include "gpio_lpc40xx.h"
#include <stdio.h>
#include "tipos.h"
#include "glcd.h"
#include "timer_lpc40xx.h"
#include "joystick.h"
#include "leds.h"

/* Los nombres de los registros de las interrupciones de los pines de los
 * puertos P0 y P2 del fichero LPC407x_8x_177x_8x.h no están actualizados
 * a la última versión del manual del microcontrolador.
 *
 * Aquí se redefinen de forma que coincidan con el manual.
 */

typedef struct
{
    __I  uint32_t STATUS;
    __I  uint32_t STATR0;
    __I  uint32_t STATF0;
    __O  uint32_t CLR0;
    __IO uint32_t ENR0;
    __IO uint32_t ENF0;
       uint32_t RESERVED0[3];
    __I  uint32_t STATR2;
    __I  uint32_t STATF2;
    __O  uint32_t CLR2;
    __IO uint32_t ENR2;
    __IO uint32_t ENF2;
} LPC_GPIOINT_TypeDef_corregido;

#undef  LPC_GPIOINT
#define LPC_GPIOINT ((LPC_GPIOINT_TypeDef_corregido   *) LPC_GPIOINT_BASE  )

/* Variables globales para mantener el tiempo.
 */


int main(void)
{
	static uint32_t horas = 0;
	static uint32_t minutos = 0;
	static uint32_t segundos = 0;
    /* Inicializar el LCD.
     */
    glcd_inicializar();
	
	LPC_GPIOINT->CLR2=1<<25|1<<27;//Para el ejercicio 2
	LPC_GPIOINT->ENF2=1<<25|1<<27;//Para el ejercicio 2
	
	
	
	/* Borrar peticiones de interrupción del timer 0 pendientes.
     */		
	
    /* C O M P L E T A R
     */
	
		NVIC_ClearPendingIRQ(GPIO_IRQn);
    
    /* Asignar prioridad 1 a la interrupción del timer 0.
     */
     
    /* C O M P L E T A R
     */
		 NVIC_SetPriority(GPIO_IRQn, 1);

    /* Habilitar la interrupción del timer 0.
     */
     
    /* C O M P L E T A R
     */
		 NVIC_EnableIRQ(GPIO_IRQn);
	
	


    /* Inicializar las variables horas, minutos y segundos.
     */
    horas = 0;
    minutos = 0;
    segundos = 0;
	/* Inicializar el timer 0.
     */
     
    /* C O M P L E T A R
     */
		 timer_inicializar(TIMER0);
    
    /* Iniciar la generación de ciclos de 1 segundo con el timer 0.
     * (función timer_iniciar_ciclos_ms de la práctica anterior).
     */
     
    /* C O M P L E T A R
     */
		 timer_iniciar_ciclos_ms(TIMER0,1000);
		 
		 /* Habilitar globalmente las interrupciones.
     */
    	
	/* Borrar peticiones de interrupción del timer 0 pendientes.
     */		
	
    /* C O M P L E T A R
     */
	
		NVIC_ClearPendingIRQ(TIMER0_IRQn);
    
    /* Asignar prioridad 1 a la interrupción del timer 0.
     */
     
    /* C O M P L E T A R
     */
		 NVIC_SetPriority(TIMER0_IRQn, 1);

    /* Habilitar la interrupción del timer 0.
     */
     
    /* C O M P L E T A R
     */
		 NVIC_EnableIRQ(TIMER0_IRQn);
		 


    
                 
    
     
    /* C O M P L E T A R
     */
		 __enable_irq();
    
    /* Imprimir el reloj por primera vez.
     */
    glcd_xprintf(0, 0, VERDE, BLACK, FONT16X32, "%02u:%02u:%02u",
                 horas, minutos, segundos);
    

    /* Inicializar los LEDs.
     */
    leds_inicializar();
   
    while (TRUE)
    {
        /* Si el joystick se pulsa hacia el centro, encender el LED 1,
         * si no, apagarlo.
         */
         
        /* C O M P L E T A R
         */
			if(gpio_leer_pin(PORT2,PIN22) == FALSE){
				led_encender(LED1);}
			else{
				led_apagar(LED1);
    }
}}

/***************************************************************************//**
 * \brief   Rutina de servicio de interrupción del timer 0.
 */
void TIMER0_IRQHandler(void)
{
    /* C O M P L E T A R
     */
	static uint32_t horas=0, minutos=0, segundos=0;
	TIMER0->IR=1;
	segundos++;
			if(segundos>59){
				minutos++;
				segundos=0;
			}
			if(minutos>59){
				horas++;
				minutos=0;
			}
			if(horas>23){
				horas=0;
				minutos=0;
				segundos=0;
			}
	glcd_xprintf(0, 0, VERDE, BLACK, FONT16X32, "%02u:%02u:%02u",
                 horas, minutos, segundos);
			
}

/***************************************************************************//**
 * \brief   Manejador de interrupción de las interrupciones de los pines
 *          de los puertos P0 y P2.
 */
/*******************************************************************************
 * PARA EL EJERCICIO 2. NO ES NECESARIO COMPLETAR PARA EL EJERCICIO 1.
 */
void GPIO_IRQHandler(void)
{
    /* C O M P L E T A R
     */
	if(LPC_GPIOINT->STATF2 & (1<<25)){
		LPC_TIM0->TCR=1;
		LPC_GPIOINT->CLR2=(1<<25);
	}
	else if(LPC_GPIOINT->STATF2 & (1<<27)){
		LPC_TIM0->TCR=0;
		LPC_GPIOINT->CLR2=(1<<27);
	}
	
}
