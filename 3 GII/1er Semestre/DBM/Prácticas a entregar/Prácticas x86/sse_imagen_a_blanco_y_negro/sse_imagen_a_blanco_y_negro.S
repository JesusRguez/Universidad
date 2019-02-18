
; int sse_imagen_a_blanco_y_negro(unsigned char *ptr_imagen,
;                                 int ancho,
;                                 int alto,
;                                 unsigned char umbral);


        global      sse_imagen_a_blanco_y_negro

        section    .text

sse_imagen_a_blanco_y_negro:

	xor eax, eax

	test rdi, rdi
	jz error

	test esi, esi
	jz error

	test edx, edx
	jz error

	test ecx, ecx
	jz error

	movd xmm0, ecx

	pxor xmm1, xmm1

	pshufb xmm0, xmm1

	mov eax, edx
	shr edx, 4
	jz menos_de_16_pixeles

	bucle:
		movdqa xmm1, [rdi]
		;Si valor_pixel>=umbral
			;valor_pixel=255
		;si_no
			;valor_pixel=0
		pminub xmm1, xmm0
		pcmpeqb xmm1, xmm0

		add rdi, 16
		dec edx
		jnz bucle

	menos_de_16_pixeles:
		and eax, 15
		jz salida

		mov esi, 255
		bucle2:
			mov dl, [rdi]
			cmp dl, cl
			cmov edx, esi
			mov [rdi], dl
			inc rdi
			dec eax
			jnz bucle2

	salida:
		mov eax, 1

	error:
		ret

	ret
