global calcular_histograma

section .text

calcular_histograma:

	push ebp
	mov ebp, esp

	push ebx

	xor eax, eax

	mov ecx, [ebp+8] ;puntero a datos
	mov edx, [ebp+12] ;tamaño del vector de datos
	mov ebx, [ebp+16] ;puntero a histograma

	test ecx, ecx
	jz error

	test ebx, ebx
	jz error

	mov eax, 1

	push edi
	push esi

	bucle:
		mov edi, [ecx]
		mov esi, [ebx + edi*4]
		;hemos cogido el valor actua del histograma en el índice correspondiente
		inc esi
		mov [ebx + edi*4], esi
		;ahora estaría guardado en el histograma, el dato incrementado en uno
		add ecx, 1 ;como contiene char, el incremento del array se hace de uno en uno, porque un char mide un byte
		dec edx
		jnz bucle

	push esi
	push edi

	error:
		pop ebx
		pop ebp
		ret
