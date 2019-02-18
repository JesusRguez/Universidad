global ordenar

section .text

ordenar:

	xor eax, eax
	test rdi, rdi ;array
	jz salida

	mov r9, rsi

bucle_grande:
	bucle: ;burbuja
		mov rcx, [rdi]
		mov rdx, [rdi+4]
		cmp rdx, rcx
		jl cambia
		continua:
		add rdi, 4
		dec rsi
		jnz bucle
	dec r9
	jnz bucle_grande

	mov rax, 1

	jmp salida



	salida:
		ret

	cambia:
		mov r8, rcx
		mov rcx, rdx
		mov rdx, r8
		jmp continua
