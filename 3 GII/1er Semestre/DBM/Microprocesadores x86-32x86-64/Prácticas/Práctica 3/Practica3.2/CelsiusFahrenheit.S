global convertir_celsius_fahrenheit

section .text

convertir_celsius_fahrenheit:
	push ebp
	mov ebp, esp

	push esi

	mov ecx, [ebp+16]

	mov edx, [ebp+12]
	jnz celsius_fahrenheit ;si se elige la opción de celsius->fahrenheit, salta a dicha etiqueta


	mov esi, 5
	mov eax, [ebp+8]
	imul esi
	add esi, 4
	sub eax, 32
	div esi

	mov [ecx], eax

	jmp salida


	celsius_fahrenheit:
		mov esi, 9
		mov eax, [ebp+8]
		imul esi
		sub esi, 4
		div esi
		add eax, 32
	mov [ecx], eax


	salida:
		pop esi
		pop ebp
		ret
