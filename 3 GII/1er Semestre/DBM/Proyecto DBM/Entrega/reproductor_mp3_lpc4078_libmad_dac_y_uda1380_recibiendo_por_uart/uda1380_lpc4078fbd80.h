/***************************************************************************//**
 * \file    uda1380_lpc4078fbd80.h
 */

#ifndef UDA1380_LPC4078FBD80_H
#define UDA1380_LPC4078FBD80_H

#include "tipos.h"

void uda1380_inicializar(void);
void uda1380_escribir_registro_configuracion(uint8_t direccion_i2c,
                                             uint8_t registro_a_escribir,
                                             uint16_t dato_a_escribir);
uint16_t uda1380_leer_registro_configuracion(uint8_t direccion_i2c,
                                             uint8_t registro_a_leer); 
bool_t uda1380_configurar_salida_audio(float32_t sample_rate,
                                       uint8_t data_size,
                                       uint8_t audio_format);

#endif  /* UDA1380_LPC4078FBD80_H */
