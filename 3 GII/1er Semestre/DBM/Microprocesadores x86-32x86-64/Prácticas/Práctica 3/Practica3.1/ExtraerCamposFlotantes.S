global extraer_campos_float

section .text

extraer_campos_float:
	push ebp
	mov ebp, esp
;Primera forma con desplazamiento de los bits hacia la derecha, lo que nos dará el dato (exponente,
;fracción o mantisa) en sentido contrario al que debe estar. Es arreglable pero farragoso.
;	push edi
;	push ebx
;	push esi
;
;	mov edx, [ebp+8]
;	mov eax, 0
;	mov ecx, 22
;	mov esi, [ebp+12]
;
;	bucle_fraccion:
;		mov edi, 0
;		shr edx, 1
;		adc edi, edi
;		mov esi, edi
;		dec ecx
;		jnz bucle_fraccion
;
;	mov ecx, 8
;	mov esi, [ebp+16]
;	bucle_exponente:
;		mov edi, 0
;		shr edx, 1
;		adc edi, edi
;		mov esi, edi
;		dec ecx
;		jnz bucle_exponente
;
;	mov esi, [ebp+20]
;	shr edx, 1
;	adc edi, edi
;	mov esi, edi
;
;	cmp edx, 0
;	jnz salida
;
;	salida:
;		mov eax, 1
;
;	pop ebx
;	pop edi

;Segunda forma: Usando máscaras de bits para obtener el dato que necesitamos del dato original
	mov edx, [ebp+8]

	mov ecx, [ebp+12]
	mov eax, edx
	and eax, 0x7FFFFF;
	mov [ecx], eax

	mov ecx, [ebp+16]
	mov eax, edx
	and eax, 0x7F800000
	shr eax, 23
	mov [ecx], al ;Lo movemos desde al porque es de 8 bits y no de 32 (yo tenía puesto eax)

	mov ecx, [ebp+20]
	mov eax, edx
	shr eax, 31
	mov [ecx], al ;Lo movemos desde al porque es de 8 bits y no de 32 (yo tenía puesto eax)

	pop ebp
	ret
;De la segunda forma es más fácil dee hacerlo y de verlo debido a que no es ncesario tanto
;desplazamiento como en la primera forma que era lo que yo tenía pensado.
