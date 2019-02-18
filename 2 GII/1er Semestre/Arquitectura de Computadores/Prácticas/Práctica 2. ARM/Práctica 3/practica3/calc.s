	AREA	Calc,CODE,READWRITE
	
SWI_EscrCar	EQU	&0		; codigo de impresion de caracter (0) asignado a SWI_EscrCar
SWI_Salir	EQU	&11		; codigo de impresion de salida del programa(11)
SWI_write0	EQU 	&2
SWI_ReadC	EQU 	&4

RES	DCD	0

	ENTRY					; Punto de entrada del c�digo

BUCLE	

	ADRL 	r0, cad1				; Obtenemos la direccion de la cadena1
	SWI 	SWI_write0			; Interrupcion de Soft. para mostrar la cadena
		; PARA INTRODUCIR EL DATO PONER PUNTO DE RUPTURA EN LA SIGUIENTE LINEA Y INTRODUCIR EL DATO EN R0
	MOV	r1, r0				; Movemos el valor introducido en r0 a r1



	ADRL 	r0, cad2				; Obtenemos la direccion de la cadena2
	SWI 	SWI_write0			; Interrupcion de Soft. para mostrar la cadena
		; PARA INTRODUCIR EL DATO PONER PUNTO DE RUPTURA EN LA SIGUIENTE LINEA Y INTRODUCIR EL DATO EN R0
	MOV	r2, r0				; Movemos el valor introducido en r0 a r1



	ADRL 	r0, cad3				; Obtenemos la direccion de la cadena3
	SWI 	SWI_write0			; Interrupcion de Soft. para mostrar la cadena


	
	SWI 	SWI_ReadC			; Interrupcion de Soft. para leer un caracter de teclado
         CMP 	r0, #49				; Se ha pulsado la tecla 1 ??
	BLEQ 	SUMA				; 	ejecuta la rutina SUMA
	CMP 	r0, #50				; Se ha pulsado la tecla 2 ??
	BLEQ 	RESTA				; 	ejecuta la rutina RESTA
	CMP 	r0, #51				; Se ha pulsado la tecla 3 ??
	BLEQ 	PROD				; 	ejecuta la rutina PROD
	CMP 	r0, #52				; Se ha pulsado la tecla 4 ??
	BLEQ 	DIV				; 	ejecuta la rutina DIV
	CMP 	r0, #53				; Se ha pulsado la tecla 5 ??
	BLEQ 	POT				; 	ejecuta la rutina POT

	ADR	r1, RES
	STR	r3, [r1]

	

	ADRL 	r0, cad4				; Obtenemos la direccion de la cadena3
	SWI 	SWI_write0			; Interrupcion de Soft. para mostrar la cadena

	ADRL	r0, cad5
	SWI	SWI_write0
	SWI 	SWI_ReadC
	CMP 	r0, #115
	BLEQ 	BUCLE


SALIR		; PARA INTRODUCIR EL DATO PONER PUNTO DE RUPTURA EN LA SIGUIENTE LINEA Y CONSULTAR EL RESULTADO EN R3
	SWI SWI_Salir ; Sale del programa


SUMA	ADD	r3, r1, r2
	MOV pc, r14

RESTA
	SUB	r3, r1, r2
	MOV	pc, r14

PROD
	MUL	r3, r1, r2


DIV
	CMP 	r2, #0
	BEQ 	SALIR

	MOV	r4, #0

DIVIDE
	SUB	r3, r1, r2
	ADD	r4, r4, #1
	CMP	r1, r2
	BLT	DIVIDE

POT
	CMP 	r2, #0
	MOV	r3, #1
	CMP	r2, #0
	BEQ	SALIR

ELEVA

	MUL	r3, r1, r1
	CMP	r1, r2
	BLT	ELEVA
	MOV	r1, r4



cad1	=	"Intoduce operando 1 en registro r0 y pulsa F5", &0a, &0d, 0
cad2	=	"Intoduce operando 2 en registro r0 y pulsa F5", &0a, &0d, 0
cad3	=	"Elige operacion PULSANDO EN TECLADO el numero correspondiente:", &0a, &0d, "1. Sumar", &0a, &0d, "2. Restar", &0a, &0d, "3. Multiplicar", &0a, &0d, "4. Dividir", &0a, &0d, "5. Potencia", &0a, &0d, 0
cad4	=	&0a, &0d, "Programa terminado. Resultado en r3 y resto de la divisi�n en r4", &0a, &0d, 0
cad5	=	&0a, &0d, "Pulsa S para reiniciar o N para terminar", &0a, &0d, 0

	END

        