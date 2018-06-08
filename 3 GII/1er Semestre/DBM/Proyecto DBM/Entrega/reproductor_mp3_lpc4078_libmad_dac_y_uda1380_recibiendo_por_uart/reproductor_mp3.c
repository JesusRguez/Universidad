/***************************************************************************//**
 * \file    reproductor_mp3.c
 *
 * \brief   Este fichero contiene las funciones que usan conjuntamente la
 *          biblioteca de sistemas de archivos FatFs y la biblioteca de
 *          decodificaci�n del MP3 libmad para llevar a cabo la reproducci�n
 *          del un fichero MP3 almacenado en el disco o memoria que se
 *          haya montado en FatFs.
 *
 *          La �nica funci�n p�blica que ofrece este m�dulo es reproducir_mp3,
 *          a la que se llama con un manejador al fichero a reproducir. El
 *          manejador se habr� obtenido mediante una llamada previa la
 *          funci�n f_open de FatFs.
 *
 *          El resto de funciones son las funciones "callback" que libmad
 *          llamar� para obtener datos del stream MP3 (funci�n input), entregar
 *          bloques de muestras de audio decodificadas (funci�n output) e
 *          indicar errores durante el proceso de reproducci�n (funci�n error).
 */
 
#include <LPC407x_8x_177x_8x.h>
#include "mad.h"
#include "generacion_audio.h"
#include "reproductor_mp3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tipos.h"
#include "gpio_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "uart_lpc40xx_xon_xoff.h"
#include "lcd_hd44780_lpc40xx.h"
#include "timer_lpc40xx.h"

uint32_t bitsAtruncar=0;
int iter=20;
/* El siguiente b�ffer act�a como una FIFO que va siendo rellenada con datos
 * procedentes del fichero MP3 y del que el decodificador los va tomando para
 * procesarlos. Cada bloque de datos procesado va siendo retirado dejando un
 * hueco que ser� rellenado con nuevo datos del fichero.
 */
static uint8_t buffer_stream_mp3[512];

/* Tasa de muestreo actual de la salida de audio. Un valor 0 indica que a�n no
 * ha sido inicializada con una tasa de muestreo v�lida.
 */
static uint32_t tasa_muestreo_actual = 0;

/* La estructura buffer_info se usa para guardar informaci�n sobre un bloque de
 * bytes gen�rico. Tiene campos para indicar la direcci�n de comienzo del bloque
 * y su longitud.
 */
struct buffer_info {
    uint8_t const *comienzo;
    uint32_t longitud;
};

/* Funciones "callback" que libmad llamar� para obtener datos del stream MP3
 * (funci�n input), entregar bloques de muestras de audio decodificadas
 * (funci�n output) e indicar errores durante el proceso de reproducci�n
 * (funci�n error).
 */
static enum mad_flow input(void *data, struct mad_stream *stream);
static enum mad_flow output(void *data,
                            struct mad_header const *header,
                            struct mad_pcm *pcm);
static enum mad_flow error(void *data,
		                   struct mad_stream *stream,
		                   struct mad_frame *frame);

/***************************************************************************//**
 * \brief       Lanza la reproducci�n de un fichero MP3. La funci�n no retorna
 *              hasta que no termina la reproducci�n.
 *
 * \param[in]   manejador_fichero   manejador al fichero a reproducir obtenido
 *                                  mediante una llamada previa a f_open.
 *
 * \return      c�digo de salida de la funci�n mad_decoder_run.
 */
int32_t reproducir_mp3(void)
{ 
    struct buffer_info buffer;
    struct mad_decoder decoder;
    int32_t resultado;
    
    generacion_audio_inicializar();
    
    timer_inicializar(TIMER0);
    timer_inicializar(TIMER1);
    timer_inicializar(TIMER2);
    timer_inicializar(TIMER3);
	
    uart_inicializar(UART0,
                     230400,
                     UART_BITS_DATOS_8,
                     UART_PARIDAD_NINGUNA,
                     UART_BITS_STOP_1,
                     PUERTO0,
                     PIN0,
                     PUERTO0,
                     PIN1,
                     5,
                     NULL);
    LPC_UART0->FCR |= 2 << 7;
    /*Interrupcion del cambio de bits en el flujo de datos*/
//		LPC_SC->EXTMODE = 1;
//		LPC_SC->EXTPOLAR = 1;
//		NVIC_SetPriority(EINT0_IRQn,10);
//		LPC_IOCON->P2_10=1;
//		LPC_SC->EXTINT = 1;
//		NVIC_ClearPendingIRQ(EINT0_IRQn);
//		NVIC_EnableIRQ(EINT0_IRQn);
		LPC_GPIOINT->IO2IntEnR = 1 << 10;
		LPC_GPIOINT->IO2IntClr = 1 << 10;
		//LPC_SC->EXTPOLAR = 1;
		NVIC_SetPriority(GPIO_IRQn,31);
		//LPC_IOCON->P2_10=1;
		//LPC_SC->EXTINT = 1;
		NVIC_ClearPendingIRQ(GPIO_IRQn);
		NVIC_EnableIRQ(GPIO_IRQn);
		__enable_irq();
		lcd_inicializar();
		lcd_borrar();
		lcd_imprimir_cadena_xy_16x2("Bits: 16",0,0);
		lcd_cursor_xy_16x2(16,0);
		/*
		uint32_t aux = 26;
		char cadena[6];
		snprintf(cadena,6,"%u",aux);
		lcd_imprimir_cadena_xy_16x2(cadena,0,0);
		*/
		
		//LPC_IOCON->P2_10
		//LPC_SC->EXTINT
		//LPC_SC->EXTPOLAR
		//LPC_SC->EXTMODE
		//Como compruebo rising edge 
		//Como accedo a extMODE0
		//Como accedo a extpolar0
		
    while (uart_bytes_disponibles(UART0) < (80*UART_TAMANO_BUFFER_RECEPCION)/100) {}
    
			//uart_leer...
		
		char cadena[3];
			
		uint32_t maxI,maxAux;
		uart_leer(UART0,3,cadena,&maxI);
		
		if(maxI == 3 && !strcmp(cadena,"ID3"))
		{
			char auxChar[128];
			uart_leer(UART0,128,&auxChar,&maxAux);
			int i=0;
			bool comienzoEncontrado = FALSE;
					while(i<128 && !comienzoEncontrado)
					{
							if(auxChar[i] == 'T' && auxChar[i+1] == 'I' &&auxChar[i+2] == 'T' &&auxChar[i+3] == '2')
							{
								auxChar[i]='\0';
								auxChar[i+1]='\0';
								auxChar[i+2]='\0';
								auxChar[i+3]='\0';
								comienzoEncontrado = TRUE;
							}
						
							i++;
					}
			i = i+4; // ME SALTO LA CABECERA TIT2
			char Titulo[31];
			if(!comienzoEncontrado) //No tiene Titulo
					//Titulo = "Desconocido";
					strcpy(Titulo,"Desconocido");
			else
					while (!((auxChar[i] >= 'A' && auxChar[i]<='Z') || (auxChar[i]>= 'a' && auxChar[i]<= 'z')) && i<=30)
						i++;
					bool_t arreglado = FALSE; //ACABO CON EL PTR EN EL COMIENZO DEL TITULO
					int j=i;
					while(j<128 && !arreglado)
					{
							if(auxChar[j] == 'T' && auxChar[j+1] == 'P' && auxChar[j+2] == 'E' && auxChar[j+3] == '1')
							{
								auxChar[j]='\0';
								auxChar[j+1]='\0';
								auxChar[j+2]='\0';
								auxChar[j+3]='\0';
								arreglado = TRUE;
							}
						
							j++;
							
					}
					strcpy(Titulo,(&auxChar[i]));
					
			lcd_imprimir_cadena_xy_16x2(Titulo,0,1);
			lcd_cursor_xy_16x2(16,1);
		}
    /* Inicializar tasa_muestro_actual con valor inicial inv�lido que ser�
     * cambiado cuando el decodificador sepa la tasa de muestro del fichero
     * que se va a reproducir.
     */
    tasa_muestreo_actual = 0; 
    
    /* Inicializar el sistema de generaci�n de audio que llevar� las muestras
     * de audio decodificadas al altavoz/altavoces o salida de audio concreta
     * usando DAC, I2S, etc.
     * Este m�dulo es independiente respecto del sistema de generaci�n de audio
     * concreto que se use. Los detalles estar� en la implementaci�n de
     * generaci�n de audio usada.
     */
    generacion_audio_inicializar();

    /* Se inicializan los campos de buffer (de tipo buffer_info) para que
     * inicialmente indique la disponibilidad de todo el buffer_stream_mp3
     * para que la funci�n input coloque datos del fichero en �l
     * (ver los comentarios de buffer_stream_mp3).
     *
     * Las funciones callback input, output y error reciben un puntero
     * a esta estructura a trav�s del argumento data.
     */
    buffer.comienzo  = buffer_stream_mp3;
    buffer.longitud = sizeof(buffer_stream_mp3);

    /* Inicializar el decodificador MP3 de libmad indic�ndole las funciones
     * input, output y error que queremos que use.
     */
    mad_decoder_init(&decoder, 
                     &buffer,
                     input, 
                     NULL, /* header callback */
                     NULL, /* filter callback */
                     output,
                     error, 
                     NULL); /* message callback */

    /* Comenzar la decodificaci�n.
     */
    resultado = mad_decoder_run(&decoder, MAD_DECODER_MODE_SYNC);

    /* "Cerrar" o finalizar el decodificador.
     */
    mad_decoder_finish(&decoder);

    /* Retornar el valor que devolvi� mad_decoder_run.
     */
    return resultado;    
}

/***************************************************************************//**
 * \brief       Esta es la funci�n a la que libmad llamar� cada vez que quiera
 *              rellenar parte (o todo) el buffer de entrada con nuevos datos
 *              del stream MP3. En nuestro el stream MP3 procede de un fichero
 *              as� que leeremos del fichero un bloque de datos del tama�o
 *              necesario.
 *
 * \param[in]   data    puntero a datos de usuario que libmad pasa a la funci�n.
 *                      En la llamada a mad_decoder_init indicamos que queremos
 *                      que nos llegue un puntero a la structura buffer (de
 *                      tipo buffer_info) declarada en reproducir_mp3. Usamos
 *                      esta estrucura para ganar acceso al espacio disponible
 *                      en el buffer de entrada buffer_stream_mp3.
 *
 *              stream  puntero a estructura de tipo mad_stream que indica
 *                      informaci�n sobre el stream MP3 en reproducci�n.
 *
 * \return      MAD_FLOW_CONTINUE => todo correcto, la reproducci�n MP3 puede
 *                                   proseguir.
 *              MAD_FLOW_STOP     => error, la reproducci�n MP3 deber�a parar.
 */
static enum mad_flow input(void *data, struct mad_stream *stream)
{
    /* Convertir el puntero void data a un puntero a estructura de tipo
     * buffer_info.
     */
    struct buffer_info *buffer = data;
    
    uint32_t rb = 0;
    uint32_t bytes_solicitados;
    uint32_t bytes_disponibles;
    uint32_t numero_bytes_leidos;
    volatile uint8_t dummy;
   	
    /* Si el hueco en buffer_stream_mp3, error.
     */
    if (buffer->longitud == 0)
    {
        return MAD_FLOW_STOP;
    }
		/*IMPRESION POR PANTALLA*/


		
		/*BITS A TRUNCAR*/

			
		if(gpio_leer_pin(PORT0,PIN22)==FALSE)
		{
			if(iter == 0){
				if(bitsAtruncar<16){
					bitsAtruncar++;
					iter = 20;
					char cadena[3];
					uint32_t bitsImprimir = 16 - bitsAtruncar;
					snprintf(cadena,3,"%u",bitsImprimir);
					lcd_imprimir_cadena_xy_16x2(cadena,6,0);
					lcd_cursor_xy_16x2(16,0);
				}
			}
		}
		
		if(gpio_leer_pin(PORT0,PIN25)==FALSE)
		{
			if(iter == 0){
				if(bitsAtruncar>0){
					bitsAtruncar--;
					iter = 20;
					char cadena[3];
					uint32_t bitsImprimir = 16 - bitsAtruncar;
					snprintf(cadena,3,"%u",bitsImprimir);
					lcd_imprimir_cadena_xy_16x2(cadena,6,0);
					lcd_cursor_xy_16x2(16,0);
				}
			}
		}
		
		if(iter >0)
			iter--;
    /* Rellenar el buffer de entrada con el n�mero de bytes solicitado.
     * (Explicar mejor).
     */
    if (stream->this_frame != NULL && stream->next_frame != NULL)
    {
        rb = buffer->longitud -
            ((uint32_t)stream->next_frame - (uint32_t)stream->buffer);

        memmove((void *)stream->buffer, (void *)stream->next_frame, rb);
        
        bytes_solicitados = buffer->longitud - rb;
        
        do
        {
            bytes_disponibles = uart_bytes_disponibles(UART0);
            if (bytes_disponibles < bytes_solicitados)
            {
                dummy++;
            }
        }
        while (bytes_disponibles < bytes_solicitados);
        uart_leer(UART0, bytes_solicitados, (void *)(stream->buffer + rb), &numero_bytes_leidos);
    }
    else
    {
        while (uart_bytes_disponibles(UART0) < buffer->longitud) {}
        uart_leer(UART0, buffer->longitud, (void *)buffer->comienzo, &numero_bytes_leidos);
    }

    if (numero_bytes_leidos == 0)
    {
        /* Si no se pudieron obtener nuevos datos del fichero, terminar la reproducci�n de
         * los muestras de audio decodificadas hasta el momento e indicar parar la
         * reproducci�n.
         */
        generacion_audio_esperar_fin_fragmento();
        buffer->longitud = 0;
        return MAD_FLOW_STOP;
    }
    else
    {
        /* Actualizar el n�mero de datos disponibles en el buffer de entrada.
         */        
        buffer->longitud = numero_bytes_leidos + rb;
    }

    /* Indicar a libmad el bloque de datos de entrada de que dispone para decodificar.
     */
    mad_stream_buffer(stream, buffer->comienzo, buffer->longitud);

    /* Seguir con la decodificaci�n.
     */
    return MAD_FLOW_CONTINUE;
}

/***************************************************************************//**
 * \brief       Esta es la funci�n a la que libmad llamar� cada vez que haya
 *              decodificado un nuevo frame MP3 para que las muestras de
 *              audio resultantes se env�en a la salida de audio.
 *
 * \param[in]   data    puntero a datos de usuario que libmad pasa a la funci�n.
 *                      En la llamada a mad_decoder_init indicamos que queremos
 *                      que nos llegue un puntero a la structura buffer (de
 *                      tipo buffer_info) declarada en reproducir_mp3. Usamos
 *                      esta estrucura para ganar acceso al espacio disponible
 *                      en el buffer de entrada buffer_stream_mp3.
 *
 *              header  puntero a estructura de tipo mad_header que ...
 *
 *              pcm     puntero a estructura de tipo mad_pcm que ...
 *
 * \return      MAD_FLOW_CONTINUE => todo correcto, la reproducci�n MP3 puede
 *                                   proseguir.
 *              MAD_FLOW_STOP     => error, la reproducci�n MP3 deber�a parar.
 *
 *  #### LA SALIDA DE AUDIO NO SE ENV�A AQU� SINO EN LAS FUCNCIONES synth_full y synth_half
 *  #### DEL FICHERO synth.c.
 */
static enum mad_flow output(void *data,
                            struct mad_header const *header,
                            struct mad_pcm *pcm)
{
    if (pcm->samplerate != tasa_muestreo_actual)
    {
        generacion_audio_ajustar_tasa_muestreo(pcm->samplerate);
        tasa_muestreo_actual = pcm->samplerate;
    }

    generacion_audio_encolar_bloque_muestras(pcm->samples[0],
                                             pcm->samples[1],
                                             pcm->length,
                                             pcm->channels);
    
    return MAD_FLOW_CONTINUE;
}

/*
 * This is the error callback function. It is called whenever a decoding
 * error occurs. The error is indicated by stream->error; the list of
 * possible MAD_ERROR_* errors can be found in the mad.h (or stream.h)
 * header file.
 */
/***************************************************************************//**
 * \brief       Esta es la funci�n a la que libmad llamar� cada vez que
 *
 * \param[in]   data    puntero a datos de usuario que libmad pasa a la funci�n.
 *                      En la llamada a mad_decoder_init indicamos que queremos
 *                      que nos llegue un puntero a la structura buffer (de
 *                      tipo buffer_info) declarada en reproducir_mp3. Usamos
 *                      esta estrucura para ganar acceso al espacio disponible
 *                      en el buffer de entrada buffer_stream_mp3.
 *
 *              stream  puntero a estructura de tipo mad_stream que ...
 *
 *              frame   puntero a estructura de tipo mad_frame que ...
 *
 * \return      MAD_FLOW_CONTINUE => todo correcto, la reproducci�n MP3 puede
 *                                   proseguir.
 *              MAD_FLOW_STOP     => error, la reproducci�n MP3 deber�a parar.
 */
static enum mad_flow error(void *data,
		                   struct mad_stream *stream,
		                   struct mad_frame *frame)
{
    /* Ignoramos el error e intentamos seguir decodificando.
     */
    return MAD_FLOW_CONTINUE;
}
