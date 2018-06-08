global b64_sumar_char_short_int_long

section .text

b64_sumar_char_short_int_long:

	movsx edi, dil
	movsx esi, si

	add esi, edi
	movsx rsi, esi
	movsx rdx, edx
	add rdx, rsi
	add rdx, rcx
	mov rax, rdx

	ret
