global fpu_producto_escalar

section .text

fpu_producto_escalar:
	push ebp
	mov ebp, esp

	fldz

	mov eax, [ebp+8]
	test eax, eax
	jz error

	mov edx, [ebp+12]
	test edx, edx
	jz error

	mov ecx, [ebp+16]
	test ecx, ecx
	jz error

	bucle:
		fld qword[eax]
		fmul qword[edx]
		faddp st1, st0
		add eax, 8
		dec ecx
		jnz bucle

	error:
		pop ebp
		ret
