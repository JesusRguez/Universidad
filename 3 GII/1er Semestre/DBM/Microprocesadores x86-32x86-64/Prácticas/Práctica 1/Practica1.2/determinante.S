global det

section .text

det	: 	push ebp
		mov ebp, esp

		mov eax, [ebp+16]
		imul eax, [ebp+12]

		mov ecx, eax

		mov eax, [ebp+20]
		imul eax, [ebp+8]

		sub eax, ecx

		pop ebp
		ret
