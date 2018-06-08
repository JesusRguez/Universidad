global fpu_raices_reales

section .text

fpu_raices_reales:
	push ebp
	mov ebp, esp

	%define coef_a qword[ebp+8]
	%define coef_b qword[ebp+16]
	%define coef_c qword[ebp+24]
	%define raiz1 dword[ebp+32]
	%define raiz2 dword[ebp+36]

	xor eax, eax
	mov edx, raiz1
	test edx, edx
	jz salir

	mov ecx, raiz2
	test ecx, ecx
	jz salir

	mov eax, -1

	fld coef_a
	fadd st0,st0

	fld st0

	fadd st0, st0
	fmul coef_c
	fld coef_b
	fmul st0, st0
	fsubrp st1, st0

	fldz
	fcomp st1

	fsqrt

	fld coef_b

	fchs
	fld st0
	fsub st0, st2
	fdiv st0, st3
	fstp qword[ecx]
	faddp st1, st0

	fdivrp st1, st0
	fstp qword[edx]

	mov eax, 1

	pop ebp
	ret

	salir:
		fstp st0
		pop ebp
		ret
