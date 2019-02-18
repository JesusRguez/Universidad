global int_a_cadena_decimal

section .text

;Para trabajar con los numeros negativos, primero tenemos que tener en cuenta si el numero que nos
;envía el usuario es negativo o no. Si lo es, tendremos que quitarle el signo negativo, lo que
;implica, obtener su valor absoluto multiplicando por -1. Despues de ello, tendremos que codificar el
;numero en la cadena, igual que se hace para los positivos y al final del programa, acordarnos de
;ponerle el signo - para que se quede bien codificado en la cadena decimal.

int_a_cadena_decimal:
	push ebp
	mov ebp, esp

	push ebx
	push esi

	mov eax, [ebp+8]
	mov ebx, [ebp+12]
	add ebx, 10
	mov ecx, 10
	mov esi, 10



	cmp eax, 0
	jl negativos

	mov byte[ebx], 0
	dec ebx

	bucle:
		xor edx, edx
		idiv ecx
		add dl, 48 ;Si pongo '0' también funciona
		mov [ebx], dl
		dec ebx
		dec esi
		jnz bucle
	jmp fin

	negativos:
		add ebx, 1
		mov byte[ebx], 0
		dec ebx
		neg eax
		bucle_negativos:
			xor edx, edx
			idiv ecx
			add dl, 48 ;Si pongo '0' también funciona
			mov [ebx], dl
			dec ebx
			dec esi
			jnz bucle_negativos
		mov byte[ebx], 45
		jmp fin

	fin:

	mov eax, [ebp+12]

	pop esi
	pop ebx

	pop ebp
	ret
