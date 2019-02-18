global sse_sumar_filas

section .text

sse_sumar_filas:

	xor eax, eax

	test rdi, rdi
	jz error

	test esi, esi
	jz error

	mov r8, 3
	movaps xmm0, [rdi]
	sumar:
		movaps xmm1, [rdi+16]
		addps xmm0, xmm1
		add rdi, 16
		dec r8
		jnz sumar

	movdqa [rsi], xmm0

	salida:
		mov rax, 1

	error:
		ret
