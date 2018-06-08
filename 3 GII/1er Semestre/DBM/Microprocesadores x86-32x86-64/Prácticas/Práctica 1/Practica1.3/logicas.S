global logicas

section .text

logicas:
	push ebp
	mov ebp, esp

	mov eax, [ebp+8]
	and eax, 4278190080 ;11111111000000000000000000000000
	;Intentar ponerlo en hexadecimal para ver más claramente qué bits cambian y cuales no.

	mov ecx, eax

	mov eax, [ebp+12]
	and eax, 16777215 ;00000000111111111111111111111111

	or eax, ecx

	pop ebp
	ret
