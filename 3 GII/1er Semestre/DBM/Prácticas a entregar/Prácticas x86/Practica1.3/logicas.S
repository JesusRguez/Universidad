global logicas

section .text

logicas:
	push ebp
	mov ebp, esp

	mov eax, [ebp+8]
	and eax, 4278190080 ;1111 1111 0000 0000 0000 0000 0000 0000
	;Intentar ponerlo en hexadecimal para ver más claramente qué bits cambian y cuales no.

	mov ecx, eax

	mov eax, [ebp+12]
	and eax, 16777215 ;0000 0000 1111 1111 1111 1111 1111 1111

	or eax, ecx

	pop ebp
	ret
