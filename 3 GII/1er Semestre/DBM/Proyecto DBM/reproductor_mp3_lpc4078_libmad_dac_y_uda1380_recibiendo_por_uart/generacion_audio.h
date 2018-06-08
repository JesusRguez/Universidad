

#ifndef GENERACION_AUDIO_H
#define GENERACION_AUDIO_H

#include "tipos.h"

void generacion_audio_habilitar(void);
void generacion_audio_deshabilitar(void);
void generacion_audio_esperar_fin_fragmento(void);
void generacion_audio_encolar_bloque_muestras(int32_t *ptr_muestras_izquierda,
                                              int32_t *ptr_muestras_derecha,
                                              uint16_t longitud,
                                              uint16_t numero_canales);
void generacion_audio_ajustar_tasa_muestreo(uint32_t sample_rate);
void generacion_audio_inicializar(void);

#endif
