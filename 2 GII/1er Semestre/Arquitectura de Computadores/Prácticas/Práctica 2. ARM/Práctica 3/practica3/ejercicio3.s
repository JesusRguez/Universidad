	AREA	Calc,CODE,READWRITE
	
SWI_EscrCar	EQU	&0		; codigo de impresion de caracter (0) asignado a SWI_EscrCar
SWI_Salir	EQU	&11		; codigo de impresion de salida del programa(11)
SWI_write0	EQU 	&2
SWI_ReadC	EQU 	&4

NUM	DCB	1,2,3,0

	ENTRY					; Punto de entrada del código

	ADR	r1, NUM
	LDRB	r2, [r1]
	LDRB	r3, [r1, #1]!
	LDRB	r4, [r1, #1]!


	ADD	r5,r2,r3
	ADD	r5,r4,r5


	ADR	r1, NUM
	LDRB	r2, [r1]
	LDRB	r3, [r1, #1]
	LDRB	r4, [r1, #2]

	ADD	r5,r2,r3
	ADD	r5,r4,r5


	ADR	r1, NUM
	LDRB	r0, [r1]
	LDRB	r0, [r1], #1
	LDRB	r0, [r1], #2

	ADD	r5,r2,r3
	ADD	r5,r4,r5




SALIR		
	SWI SWI_Salir ; Sale del programa







	END

        