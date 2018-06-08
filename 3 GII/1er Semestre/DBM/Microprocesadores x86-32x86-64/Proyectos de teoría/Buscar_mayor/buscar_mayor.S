global b64_buscar_mayor

section .text

b64_buscar_mayor:
	xor eax, eax
	test rdi, rdi
	jz salir

	test esi, esi
	jz salir

	test rdx, rdx
	jz salir

	mov eax, [rdi]
	dec esi
	jz fin_busqueda

	bucle:
		add rdi, 4
		cmp eax, [rdi]
		jge no_cambiar
		mov eax, [rdi]
		no_cambiar:
			dec esi
			jnz bucle

	fin_busqueda:
		mov [rdx], eax
		mov eax, 1

	salir:
		ret
