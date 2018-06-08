global b64_sumar_8_ints

section .text

b64_sumar_8_ints:

	push rbp
	mov rbp, rsp
	mov eax, esi
	add eax, esi
	add eax, edx
	add eax, ecx
	add eax, r8d
	add eax, r9d
	add eax, [rbp+16]
	add eax, [rbp+24]

	pop rbp
	ret
