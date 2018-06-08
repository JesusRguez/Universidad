global ordenar

section .text

ordenar:
	test rdi, rdi
	jz error

	test rsi, rsi
	jz error

	mov rax, 1

	bucle:
		mov rdx, rsi
		mov rcx, [rdi]
		cmp rcx, [rdi+8]
		jnz es_mayor
		mov rcx, [rdi+8]
		xchg rcx, [rdi]
		es_mayor:
		add rdi, 8
		dec rsi
		jnz bucle

	jmp salida

	error:
		mov rax, 0

	salida:
		ret
