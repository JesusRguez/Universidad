global eval_poli

section .text

eval_poli:
	push ebp
	mov ebp, esp

	push ebx

	mov eax, [ebp+8]
	mov ecx, [ebp+20]

	fldz
	cmp eax, 0
	jz salida

	inc ecx

	fld qword[ebp+12]

	mov ebx, [ebp+20];este es para el bucle interno

	bucle:
		fld qword[eax]
		fld qword[eax]
		bucle_coeficiente:
			fmul st0, st1
			dec ebx
			jnz bucle_coeficiente
		dec ebx
		fmul st0, st2
		add eax, 8
		faddp st1, st0
		dec ecx
		jnz bucle

	salida:
		pop ebx
		pop ebp
		ret
