global sumar_diagonal

section .text

sumar_diagonal:
	test rdi, rdi
	jz error

	test rsi, rsi
	jz error

	test rdx, rdx
	jz error

	mov rax, 1

	mov r8, rsi
	inc r8
	imul r8, 8

	xor r9,r9

	bucle:
		add r9, [rdi]
		add rdi, r8
		dec rsi
		jnz bucle

	jmp salida

	error:
		mov rax, 0

	salida:
		mov [rdx], r9
		ret
