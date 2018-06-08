;*******************************************************************************
; \file     retardo_software_asm.s
;
; \brief    Parte en ensamblador de las funciones de retardo por software.
;
;           La ventaja de que retardo_software_us esté en ensamblador es que el
;           código previo al bucle de retardo así como el que forma el bucle de
;           retardo puede controlarse totalmente y puede hacerse muy corto, lo
;           que da mayor exactitud en los retardos conseguidos. Además el código
;           de la función no dependerá del nivel de optimización seleccionado en
;           el compilador.
;
        EXPORT  retardo_software_fijar_escala
        EXPORT  retardo_software_us

;*******************************************************************************
; Sección de datos inicializados.
;
        AREA    |.data|, DATA
        ALIGN   4
;*******************************************************************************
;           La variable iteraciones_por_us indica el número de iteraciones que
;           el bucle de retardo debe realizar por cada microsegundo de retardo
;           requerido. Su valor inicial es 1 pero debe ser calibrada antes de
;           usar la función retardo_software_us para generar retardos. La
;           calibración se realiza mediante la función
;           retardo_software_inicializar en el fichero retardo_software.c
;
iteraciones_por_us
        SPACE   4

;*******************************************************************************
; Sección de código.
;
        AREA    |.text|, CODE, READONLY
        THUMB
        ALIGN   2     

;*******************************************************************************
; \brief        Asignar un valor a la variable iteraciones_por_us.
;
; \pararm[in]   R0  valor a dar a iteraciones_por_us.
;
retardo_software_fijar_escala PROC
        ldr     r1, =iteraciones_por_us
        str     r0, [r1]
        bx      lr
        ENDP
   
;*******************************************************************************
; \brief        Realizar un retardo del número de microsegundos indicado.
;
;               Antes de llamar esta función debe haberse realizado la
;               calibración del retardo llamando a la función
;               retardo_software_inicializar en el fichero retardo_software.c
;
; \pararm[in]   R0  número de microsegundos a retardar.
;        
retardo_software_us PROC
        ldr     r1, =iteraciones_por_us
        ldr     r1, [r1]
        mul     r0, r0, r1
bucle   subs    r0, r0, #1
        bne     bucle
        bx      lr
        ENDP
        
        END