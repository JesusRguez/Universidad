global b32_rellenar_bloque

section .text

b32_rellenar_bloque:
	push ebp
	mov ebp, esp

	%define ptr_bloque dword[ebp+8]
	%define byte_relleno byte[ebp+12]
	%define longitud_bloque dword[ebp+16]

	push edi

	mov edi, ptr_bloque

	xor eax, eax

	test edi, edi
	jz error

	mov ecx, longitud_bloque

	test ecx, ecx
	jz salida
;Desde esta línea...
	mov al, byte_relleno

	cld

	rep stosb
;...hasta esta línea se puede hacer tal como se escribe más abajo, optimizado para mover 32 bits.
	salida:
		mov eax, 1

	error:
		pop edi
		pop ebp
		ret

	pop ebp
	ret

;En las líneas de arriba podemos sustituir lo que hay por lo siguiente para ganar optimización
;a la hora de mover 32 bits
;	shr ecx, 2
;	jz menos_de_4

;	mov al, byte_relleno
;	mov ah, al
;	mov edx, eax
;	shl edx, 16
;	mov dx, ax;O estas dos...
;	mov eax, edx;...instrucciones o esta: or eax, edx
;	cld
;	rep stosd

;	menos_de_4:
;		mov eax, longitud_bloque
;		and ecx, 3
;		jz salida
;		rep stosb
