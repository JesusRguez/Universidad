/***************************************************************************//**
 * \file    uda1380_i2c2_lpc40xx.c
 *
 * \brief   Funciones para configurar el codec de audio UDA1380 a trav�s del
 *          interfaz I2C 0 del LPC4078.
 *
 */

#include "uda1380_lpc4078fbd80.h"
#include "i2c_lpc40xx.h"
#include "gpio_lpc40xx.h"
#include "uda1380.h"
#include "timer_lpc40xx.h"
#include "i2s_lpc40xx.h"
#include "uda1380.h"

/* Direccion I2C del dispositivo UDA1380
 */

#define UDA1380_I2C	    I2C2
#define UDA1380_ADDRESS	0x18

/***************************************************************************//**
 * \brief   Incializar la comunicaci�n con el UDA1380 a trav�s del interfaz I2C 0.
 *          Se seleccionar� una frecuencia SCL de 100 kHz. En la tarjera
 *          Embedded Artist LPC4078 no se consigue que el UDA1380 funcione a la
 *          frecuencia m�xima de 400 kHz indicada en su datasheet.
 */
void uda1380_inicializar(void)
{
    i2c_inicializar(I2C2,
                    100000,
                    PUERTO0,
                    PIN10,
                    PUERTO0,
                    PIN11);
    
    /*--------------------------------------------------------------------------    
     * Se usa el timer 3 para generar la se�al del reloj SYSCLK para el UDA1380.
     *
     * Despu�s de configurar el UDA1380, su reloj interno se sintetizar� a partir
     * de la se�al I2S_TX_WS y la se�al SYSCLK no ser� necesaria, pero antes de que
     * pueda llavarse a cabo la configuraci�n es necesario que est� aplicada una
     * se�al de reloj correcta al pin SYSCLK.
     *
     * La forma normal de generar la se�al SYSCLK para el UDA1380 ser�a mediante
     * la se�al I2S_TX_MCLK del interfaz I2S del LPC40xx pero el modelo LPC4078FBD80
     * no presenta al exterior la se�al I2S_TX_MCLK. Entonces, se usar� el timer 3
     * para generar hacia el exterior una se�al de 12 MHz a trav�s del pin
     * P1[9]/ENET_RXD0/T3_MAT0.
     *
     * Una vez que se haya configurado el UDA1380 y el interfaz I2S del
     * microcontrolador podr�a dejar de generarse el reloj a trav�s de 
     * P1[9]/ENET_RXD0/T3_MAT0.
     */
    LPC_IOCON->P1_9 = 3;
    LPC_SC->PCONP |= 1 << 23;
    LPC_TIM3->TCR = 0;
    LPC_TIM3->PC = 0;
    LPC_TIM3->TC = 0;
    LPC_TIM3->MR0 = (PeripheralClock/12000000)/2 - 1;
    LPC_TIM3->MCR = 2;
    LPC_TIM3->EMR = (3 << 4) | 1;
    LPC_TIM3->TCR = 1;
    
    /*--------------------------------------------------------------------------
     */
        
    LPC_IOCON->P0_7 = 1 | (1u << 7);
    LPC_IOCON->P0_8 = 1 | (1u << 7);
    LPC_IOCON->P0_9 = 1 | (1u << 7);
    
    LPC_SC->PCONP |= 1 << 27;    
    
//    LPC_I2S->DAI = 0x00;    
//    LPC_I2S->DAO = 0x3DD;    
//    
//    LPC_I2S->TXMODE = 0;        
//    LPC_I2S->TXRATE = 0x93FA;
//    LPC_I2S->RXRATE = 0x0;
//    LPC_I2S->TXBITRATE = 0x18;    

    /* Activar el interfaz I2S en PCONP.
     */
    LPC_SC->PCONP |= 1 << 27;    
    
    /* En el registro DAI, activar el bit STOP para parar la parte de recepci�n
     * del I2S porque en esta aplicaci�n el microcontrolador s�lo env�a al
     * UDA1380, no recibe de �l.
     */
    LPC_I2S->DAI = 1 << 3;

    /* En el registro DAO, seleccionar:
     *
     * Ancho de palabras de datos: 16.
     * Modo est�reo.
     * De momento, activar el bit STOP para parar el interfaz hasta terminar la configuraci�n.
     * Activar el bit RESET para resetear el interfaz.
     * Modo m�ster.
     * Semiperiodo WS en unidades de TX_SCK de 16 ciclos.
     * De momento, activar el MUTE mientras dura la configuraci�n.
     */
    LPC_I2S->DAO = (1 << 15) | (15 << 6) | (1 << 4) | (1 << 3) | 1;    
    
    /* En el registro TXMODE, activar la salida TX_MCLK.
     */
    LPC_I2S->TXMODE = 1 << 3;        
    
    /* C�lculo de los divisores de reloj.
     *
     * La frecuencia de muestreo de audio que queremos es de
     *
     * f_S = 44100 Hz
     *
     * Como cada muestra de audio que vamos a enviar al UDA1380 est� compuesta
     * por 16 bits y en cada periodo de muestreo hay que enviar una muestra del
     * canal izquierdo y una muestra del canal derecho, la tasa de bits es de
     *
     * 44100*16*2 = 1411200 bits/s
     *
     * Por tanto la frecuencia de la se�al de reloj I2S_TX_SCK debe ser de
     * 1411200 Hz:
     *
     * f_I2S_TX_SCK = 1411200 Hz
     *
     * Por otra parte, la frecuencia de la se�al I2S_TX_MCLK debe ser 256 veces
     * la frecuencia de muestreo.
     *
     * f_I2S_TX_MCLK = 256*f_S = 256*44100 = 11289600 Hz
     *
     * Las frecuencias de las se�ales f_I2S_TX_SCK y f_I2S_TX_MCLK est�n determinadas
     * por los valores de los registros TXRATE y TXBITRATE y por la frecuencia de
     * reloj de la CPU f_CCLK (el interfaz I2S usa CCLK y no PCLK).
     *
     * f_I2S_TX_MCLK = f_CCLK*TXRATE_X_DIVIDER/(2*TXRATE_Y_DIVIDER)
     *
     * donde TXRATE_X_DIVIDER y TXRATE_Y_DIVIDER son los campos de 8 bits
     * en el registro TXRATE.
     *
     * Resulta TXRATE_X_DIVIDER/TXRATE_Y_DIVIDER = 2*f_I2S_TX_MCLK/f_CCLK = 0.18816
     *
     * Seleccionamos TXRATE_X = 19
     *               TXRATE_Y = 101
     *
     * Por su parte
     *
     * f_I2S_TX_SCK = f_I2S_TX_MCLK/(TXBITRATE + 1)
     *
     * luego TXBITRATE = f_I2S_TX_MCLK/f_I2S_TX_SCK - 1 = 7
     */
    LPC_I2S->TXRATE = (19 << 8) | 101;
    LPC_I2S->TXBITRATE = 7;
    
    /* Configurar el registro IRQ para habilitar las interrupciones de transmisi�n
     * I2S y fijar un nivel de 4 para la FIFO de transmisi�n. Esto har� que el
     * interfaz genere una interrupci�n siempre que en la FIFO de transmisi�n haya
     * 4 palabras de 32 bits o menos (cada palabra de 32 bits representa dos
     * muestras, canal izquierdo y derecho, de 16 bits cada una). La capacidad total
     * de la FIFO de transmisi�n es de 8 palabras de 32 bits, as� que se fija el
     * nivel de interrupci�n a la mitad de la capacidad de la FIFO.
     */
    LPC_I2S->IRQ = (4 << 16) | (1 << 1);
    
    /* Una vez que toda la parte de transmisi�n est� ajustada, volvemos a escribir
     * en el registro DAO la misma configuraci�n que antes, pero desactivando los
     * bits de RESET, STOP y MUTE.
     */
    LPC_I2S->DAO = (15 << 6) | 1;
    
    /* NOTA: En esta aplicaci�n, la configuraci�n que se realiza del UDA1380 a trav�s
     *       del interfaz I2C hace que �ste sintetize su reloj de sobremuestreo
     *       interno (SYSCLK = 256*f_S) a partir de la se�al I2S_TX_WS por lo que,
     *       en principio, no ser�a necesario que el microcontrolador generase la
     *       se�al I2S_TX_MCLK. Sin embargo, el interfaz I2C del UDA1380 no funciona
     *       hasta que no hay disponible una se�al SYSCLK, as� que antes de poder
     *       configurar el UDA1380 para sintetizar su propio SYSCLK es necesario
     *       aplicar un SYSCLK externo.
     */
          
    timer_inicializar(TIMER0);
    timer_retardo_ms(TIMER0, 100);        
    
    uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, UDA1380_REG_L3,  0);
    uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, UDA1380_REG_I2S, 0);   
    uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, UDA1380_REG_MSTRMUTE, 0);
    uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, UDA1380_REG_MIXSDO, 0);        
    uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, UDA1380_REG_EVALCLK, 
        EVALCLK_DEC_EN | EVALCLK_DAC_EN | EVALCLK_INT_EN | EVALCLK_DAC_SEL_WSPLL | EVALCLK_WSPLL_SEL25_50K);                        
    uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, UDA1380_REG_PWRCTRL,
              PWR_PON_PLL_EN | PWR_PON_HP_EN | PWR_PON_DAC_EN | PWR_PON_BIAS_EN);                     

    LPC_I2S->DAO = 0x3C1;
}

/***************************************************************************//**
 * \brief       Escribir en un registro interno del UDA1380.
 *
 * \param[in]   direccion_i2c           Direcci�n I2C del UDA1380.
 * \param[in]   registro_a_escribir     N�mero del registro a escribir.
 * \param[in]   dato_a_escribir         Dato a escribir en el registro.
 */
void uda1380_escribir_registro_configuracion(uint8_t direccion_i2c,
                                             uint8_t registro_a_escribir,
                                             uint16_t dato_a_escribir)
{
	  /* Proceso de escritura:
	   *
		 * 1.- Crear la condici�n de START.
     * 2.- Enviar la direcci�n I2C a�adiendole un bit R/W a cero a la derecha.
     * 3.- Transmitir el n�mero del registro que queremos escribir (valor de
     *     registro_a_escribir).
     * 4.- Transmitir el byte alto del dato que queremos escribir en el registro
     *     (byte alto de de dato_a_escribir).
     * 5.- Transmitir el byte bajo del dato que queremos escribir en el registro
     *     (byte bajo de de dato_a_escribir).    
     * 6.- Crear la condici�n de STOP.    
     */
 
    i2c_start(I2C2);

    i2c_transmitir_byte(I2C2, direccion_i2c << 1);
    i2c_transmitir_byte(I2C2, registro_a_escribir);

    i2c_transmitir_byte(I2C2, dato_a_escribir >> 8);
    i2c_transmitir_byte(I2C2, dato_a_escribir &  0xFF);

    i2c_stop(I2C2);
}

/***************************************************************************//**
 * \brief   Leer un registro interno del LM75B.
 *
 * \param[in]   direccion_i2c       Direcci�n I2C del UDA1380.
 * \param[in]   registro_a_leer     N�mero del registro a leer.
 *
 * \return      Valor le�do del registro .
 */
uint16_t uda1380_leer_registro_configuracion(uint8_t direccion_i2c,
                                             uint8_t registro_a_leer)
{
    uint8_t byte_alto = 0, byte_bajo;
    
    /* Comprobar que registro_a_leer es menor o igual a 4. En caso
     * de que sea mayor que 4, retornar.
     */
    
    if(registro_a_leer > 3) return FALSE;
    
	  /* Proceso de lectura:
		 *
     * 1.- Crear la condici�n de START.
     * 2.- Enviar la direcci�n I2C a�adiendole un bit R/W a cero a la derecha.
     * 3.- Transmitir el n�mero del registro que queremos leer (valor de
     *     registro_a_leer).
     * 4.- Crear nuevamente la condici�n de START (esto ser� un REPEATED START).
     * 5.- Enviar la direcci�n I2C a�adiendole ahora bit R/W a uno a la derecha.    
     * 6.- Recibir un byte y no reconocerlo (para que el esclavo entienda que no
     *     queremos recibir m�s).
     * 7.- Crear la condici�n de STOP.
     */
		 
    i2c_start(I2C2);
    i2c_transmitir_byte(I2C2, direccion_i2c << 1);
    i2c_transmitir_byte(I2C2, registro_a_leer);
    i2c_start(I2C2);
    i2c_transmitir_byte(I2C2, (direccion_i2c << 1) | 1);


    byte_alto = i2c_recibir_byte(I2C2, TRUE);
    byte_bajo = i2c_recibir_byte(I2C2, FALSE);

    i2c_stop(I2C2);
			        
    /* Retornar el dato leido del registro del LM75B combinando el byte_alto
     * y el byte_bajo (si es el registro de configuraci�n byte_alto habr�
     * permanecido a 0.
     */
     
    return ((byte_alto << 8) | byte_bajo);
}

///***************************************************************************//**
// * \brief       Configura la salida de audio del UDA1380
// *
//* \param[in]   sample_rate		velocidad de sampleado utilizada en el audio a transmitir divida entre 1000.
// *\param[in]		data_size			tama�o de palabra del audio a transmitir.
// *\param[in]		audio_format	formato de audio stereo (2) o mono (1).
// *
// *\return      TRUE => �xito, FALSE => algun parametro no es correcto.
// */
// 
//bool_t uda1380_configurar_salida_audio(float32_t sample_rate, uint8_t data_size, uint8_t audio_format){
//	
//	/*float32_t wsi_signal_frequency;
//	uint8_t divider;*/
//	
//	/* Elige el valor de los divisores de frecuencia para generar WSPLL en funcion de la frecuencia de WS
//	 */
//	/*wsi_signal_frequency = sample_rate * 1000.f;
//	
//	if(wsi_signal_frequency < 12500 && wsi_signal_frequency > 6250){
//		divider = 0;
//	}
//	else if (wsi_signal_frequency < 25000 && wsi_signal_frequency > 12500){
//		divider = 1;
//	}
//	else if (wsi_signal_frequency < 50000 && wsi_signal_frequency > 25000){
//		divider = 2;
//	}
//	else if (wsi_signal_frequency < 100000 && wsi_signal_frequency > 50000){
//		divider = 3;
//	}
//	else return FALSE;*/
//	
//	i2s_configurar_transmision(sample_rate, data_size, audio_format);
//	
////	uda1380_escribir_registro_configuracion(UDA1380_ADDRESS, 0x7f, 0xFFFF );
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS ,REG0, REG0_EN_ADC|REG0_EN_DAC|REG0_EN_INT|REG0_EN_DEC|REG0_PLL_25TO50|REG0_ADC_USE_WSPLL|REG0_DAC_USE_WSPLL);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS ,I2S_REG, (FMT_I2S << I2S_REG_SFORO_SHIFT)|(FMT_I2S << I2S_REG_SFORI_SHIFT | (1<< 6)));
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,PWR_REG,PWR_REG_PON_DAC|PWR_REG_PON_BIAS);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,MASTER_VOL_REG, 0x4040);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,MIXER_VOL_REG, 0xaa);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,MBT_REG, 0xaa);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS, MMCDM_REG, 0x0);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,MIXER_CTL_REG, 0x70);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,DEC_VOL_REG, 0xaa);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,DPM_REG, 0xaa);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,DEC_ADC_REG, 0xaa);
////	timer0_retardo_ms(50);
////	uda1380_escribir_registro_configuracion (UDA1380_ADDRESS,DEC_AGC_REG, 0xaa);
////	timer0_retardo_ms(50);
//	return TRUE;
//}
