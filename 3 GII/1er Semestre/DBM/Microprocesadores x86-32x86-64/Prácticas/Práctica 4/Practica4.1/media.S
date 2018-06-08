global media

section .text

media:
	push ebp
	mov ebp, esp

	mov edx, [ebp+8]
	mov ecx, [ebp+12]


	fldz
	;comprobar que no es puntero nulo y que ecx es > 0
	cmp edx, 0
	jz salida
	cmp ecx, 0
	jz salida

	bucle:
		fld qword[edx]
		add edx, 8
		faddp st1, st0
		dec ecx
		jnz bucle


	fild dword[ebp+12]
	fdivp st1, st0

	salida:
		pop ebp
		ret
