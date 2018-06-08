#include <LPC407x_8x_177x_8x.h>
#include <string.h>
#include "generacion_audio.h"
#include "dac_lpc40xx.h"
#include "tipos.h"
#include "error.h"

#define  STREAM_DECODED_SIZE   1024
#define  ENABLED                  1
#define  DISABLED                 0

bool_t generando_audio = FALSE;

typedef struct {
  short int raw[STREAM_DECODED_SIZE];	/* 16 bit PCM output samples [ch][sample] */
  volatile  unsigned short wr_idx;
  volatile  unsigned short rd_idx;
}decoded_stream_t;

static decoded_stream_t     DecodedBuff;

#define IS_DFIFO_FULL()    ((DecodedBuff.wr_idx+1)%STREAM_DECODED_SIZE == DecodedBuff.rd_idx)
#define IS_DFIFO_EMPTY()   (DecodedBuff.wr_idx == DecodedBuff.rd_idx)

#define DFIFO_WRITE(S)     do {                                                                   \
                             DecodedBuff.raw[DecodedBuff.wr_idx] = S;                             \
                             DecodedBuff.wr_idx = ( (DecodedBuff.wr_idx+1)%STREAM_DECODED_SIZE ); \
                           }while(0)

#define DFIFO_READ(S)      do {                                                                   \
                             S = DecodedBuff.raw[DecodedBuff.rd_idx];                             \
                             DecodedBuff.rd_idx = ( (DecodedBuff.rd_idx+1)%STREAM_DECODED_SIZE ); \
                           }while(0)

#define FIFO_LEN()        ( DecodedBuff.wr_idx >= DecodedBuff.rd_idx ? \
                            DecodedBuff.wr_idx - DecodedBuff.rd_idx  : \
                            DecodedBuff.wr_idx + (STREAM_DECODED_SIZE - DecodedBuff.rd_idx) )

/***************************************************************************//**
 *
 */
void generacion_audio_habilitar(void)
{
    LPC_TIM0->TCR = 1;
    generando_audio = TRUE;
}

/***************************************************************************//**
 *
 */
void generacion_audio_deshabilitar(void)
{
    LPC_TIM0->TCR = 0;
    generando_audio = FALSE;
}

/***************************************************************************//**
 *
 */
void generacion_audio_esperar_fin_fragmento(void)
{
    while (!IS_DFIFO_EMPTY());
    generacion_audio_deshabilitar();
}

/***************************************************************************//**
 *
 */
void generacion_audio_encolar_bloque_muestras(int32_t *ptr_muestras_izquierda,
                                              int32_t *ptr_muestras_derecha,
                                              uint16_t longitud,
                                              uint16_t numero_canales)
{
    uint16_t i;
    
    if (numero_canales == 1)
    {
        for (i = 0; i < longitud; i++)
        {
            while (IS_DFIFO_FULL());
            DFIFO_WRITE((int16_t)((*ptr_muestras_izquierda) >> 16));
            ptr_muestras_izquierda++;
        }
    }
    else if (numero_canales == 2)
    {
        for (i = 0; i < longitud; i++)
        {
            while (IS_DFIFO_FULL());            
            DFIFO_WRITE((int16_t)(((*ptr_muestras_izquierda >> 16) + (*ptr_muestras_derecha >> 16)) >> 1));
            ptr_muestras_izquierda++;
            ptr_muestras_derecha++;
        }
    }
    else
    {
        ERROR("Numero de canales incorrecto.");
    }

    if (!generando_audio) generacion_audio_habilitar();
}

/***************************************************************************//**
 *
 */
void generacion_audio_ajustar_tasa_muestreo(uint32_t sample_rate)
{
    LPC_TIM0->TCR = 0;
    LPC_TIM0->PC = 0;
    LPC_TIM0->TC = 0;
    LPC_TIM0->PR = 0;
    LPC_TIM0->MCR = 3;
    LPC_TIM0->MR0 = ((uint32_t)PeripheralClock/sample_rate) - 1;
    LPC_TIM0->TCR = 1;
}

/***************************************************************************//**
 *
 */
void generacion_audio_inicializar(void)
{    
    DecodedBuff.wr_idx = DecodedBuff.rd_idx = 0;
    generando_audio = FALSE;

    LPC_TIM0->TCR = 0;    
    LPC_TIM0->IR = 1;
    LPC_TIM0->PC = 0;
    LPC_TIM0->TC = 0;
    LPC_TIM0->PR = 0;
    LPC_TIM0->MCR = 3;
    
    NVIC_ClearPendingIRQ(TIMER0_IRQn);
    NVIC_EnableIRQ(TIMER0_IRQn);
    
    dac_inicializar();
    
    __enable_irq();
}

/***************************************************************************//**
 *
 */
void TIMER0_IRQHandler(void)
{
    int16_t muestra;

    LPC_TIM0->IR = 1;
        
    if (!IS_DFIFO_EMPTY())
    {
        DFIFO_READ(muestra);
    }
    else
    {
        muestra = 0;  
    }
   
    dac_convertir(muestra/64 + 512);
}
