global b32_es_binario_capicua

section .text

b32_es_binario_capicua:
	push ebp
	mov ebp, esp

	mov eax, [ebp+8]

	xor edx, edx

	mov ecx, 16

	bucle:
		shr eax, 1
		rcl edx, 1
		dec ecx
		jnz bucle

	cmp eax, edx

	mov eax, 1
	cmovne eax, ecx

	pop ebp
	ret
