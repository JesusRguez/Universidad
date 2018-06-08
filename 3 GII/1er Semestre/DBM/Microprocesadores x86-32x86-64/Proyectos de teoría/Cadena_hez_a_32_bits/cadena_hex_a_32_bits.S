global b32_cadena_hex_a_32_bits

section .text

b32_cadena_hex_a_32_bits:
	%define cadena dword[ebp+8]
	%define resultado dword[ebp+12]

	push ebp
	mov ebp, esp

	xor eax, eax

	push esi
	push edi

	mov esi, cadena
	mov edi, resultado

	test esi, esi
	jz error

	test edi, edi
	jz error ;Si pasa de aquí es porque los argumentos son correctos

	xor edx, edx

	siguiente_caracter:
		mov al, [esi]
		inc esi

		test al, al
		jz salida

		cmp al, '0'
		jb salida

		sub al, '0'

		cmp al, 9
		jbe nuevo_nibble

		sub al, 'A'-10-'0'

		cmp al, 10
		jb salida

		cmp al, 15
		jbe nuevo_nibble

		sub al, 'a'-'A'

		cmp al, 10
		jb salida

		cmp al, 15
		ja salida

	nuevo_nibble:
		shl edx, 4
		or dl, al

		test edx, 0xF0000000
		jnz salida

		jmp siguiente_caracter

	salida:
		mov [edi], edx
		mov eax, 1

	error:
		pop edi
		pop esi
		pop ebp
		ret
