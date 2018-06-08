global contar_valor_en_array

section .text

contar_valor_en_array:
	test rdi, rdi
	jz error

	test rsi, rsi
	jz error

	test rdx, rdx
	jz error

	mov rax, 1

	mov dword[rcx], 0

	bucle:
		cmp edi, [rsi]
		jne no_incrementar
		add dword[rcx], 1
		no_incrementar:
		add rsi, 4
		dec rdx
		jnz bucle

	jmp salida

	error:
		mov rax, 0

	salida:
		ret
