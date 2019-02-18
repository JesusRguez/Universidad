global uint_a_cadena_binario

section .text

uint_a_cadena_binario:
	push ebp
	mov ebp, esp

	mov edx, [ebp+8]
	mov eax, [ebp+12]

	mov ch, 32

	bucle:
		mov cl, 48
		sal edx, 1
		adc cl, 0
		mov [eax], cl
		inc eax
		dec ch
		jnz bucle

	mov byte[eax], 0

	sub eax, 32

	pop ebp
	ret
