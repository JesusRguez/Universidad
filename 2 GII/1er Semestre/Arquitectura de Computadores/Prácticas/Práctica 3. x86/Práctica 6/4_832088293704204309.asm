;EasyCodeName=Module1,1
.Const

.Data
numero_a DD 0
numero_b DD 0
operador DD 0

.Code

start:
;Inicio del programa principal.
Invoke printf, "Introduce un numero entero (a): "
Invoke scanf, "%d", Addr numero_a
Invoke printf, "Introduce un numero entero (b): "
Invoke scanf, "%d", Addr numero_b
Mov Edi, [numero_a]
Mov Ebx, [numero_b]
Invoke puts, " ", "/n"
Invoke printf, "Que operacion desea realizar? "
Invoke puts, " ", "/n"
Invoke printf, "1 Suma"
Invoke puts, " ", "/n"
Invoke printf, "2 resta"
Invoke puts, " ", "/n"
Invoke printf, "3 Multiplicacion"
Invoke puts, " ", "/n"
Invoke printf, "4 Division"
Invoke puts, " ", "/n"
Invoke scanf, "%d", Addr operador
Mov Ecx, [operador]
Cmp Ecx, 1
Je > call_suma
Cmp Ecx, 2
Je > call_resta
Cmp Ecx, 3
Je > call_mult
Cmp Ecx, 4
Je > call_divi
Cmp Ecx, 5
Jge > error

call_suma:
PushA
Push [numero_b]
Push [numero_a]
Call suma
Add Esp, 8
Invoke printf, "El resultado de la suma es: %d", Eax
PopA
Jmp > fin_programa

call_resta:
PushA
Push [numero_b]
Push [numero_a]
Call resta
Add Esp, 8
Invoke printf, "El resultado de la resta es: %d", Eax
PopA
Jmp > fin_programa

call_mult:
PushA
Push [numero_b]
Push [numero_a]
Call mult
Add Esp, 8
Invoke printf, "El resultado es: %d", Eax
PopA
Jmp > fin_programa

call_divi:
PushA
Push [numero_b]
Push [numero_a]
Call divi
Add Esp, 8
Invoke printf, "El cociente es: %d y el resto es: %d", Eax, Edx
PopA
Jmp > fin_programa

error:
	Invoke printf, "Valor erróneo, vuelva a intentar"
	Jmp < start

fin_programa:
Invoke puts, " ", "/n"
Invoke printf, "PROGRAMA TERMINADO."
Invoke puts, " ", "/n"
	Invoke system, "pause"
	Xor Eax, Eax
	Invoke ExitProcess, Eax

;Fin del programa principal

;Subprogramas:
suma:
	 Push Ebp
	 Mov Ebp, Esp
	 Add Edi, Ebx
	 Mov Eax, Edi
	 Pop Ebp
	 ret
resta:
	 Push Ebp
	 Mov Ebp, Esp
	 Sub Edi, Ebx
	 Mov Eax, Edi
	 Pop Ebp
	 ret
mult:
	 Push Ebp
	 Mov Ebp, Esp
	 Mov Eax, Edi
     Mul Ebx  ;EAX=eax*ebx

	 Pop Ebp
	 ret
divi:
	 Push Ebp
	 Mov Ebp, Esp
	 Cmp Edi, Ebx
	 Jl > intercambio
retorno_intercambio:
	 Cmp Ebx, 0
	 Je > division_por_cero
	 Mov Eax, 0
bucle_divi:
	 Sub Edi, Ebx
	 Inc Eax
	 Cmp Edi, Ebx
	 Jge bucle_divi
     Mov Edx, Edi ;Cociente en eax,resto en edx
	 Pop Ebp
	 Jmp > divi_ok
division_por_cero:
	Invoke printf, "Division por cero"
	Jmp < fin_programa
intercambio:
	Mov Ecx, Edi
	Mov Edi, Ebx
	Mov Ebx, Ecx
	Jmp < retorno_intercambio
divi_ok:
	 ret

