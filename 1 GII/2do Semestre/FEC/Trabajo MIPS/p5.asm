# p5.asm
#
# Problema 5: Funci�n isdigit: N�meros=1 y car�cteres=0
#
# Datos de entrada:
# 	- $a0 = puntero a cadena origen.
# Proceso:
#	Recorre la cadena y en caso de encontrar un n�mero escribe un 1 y en caso de encontrar un car�cter escribe un 0.
# 
# Datos de salida:	Si hay un n�mero un 1 y si hay un car�cter un 0.

	.data
cad_origen: 	.asciiz	"Naci el 25/03/1997."
cad_dest:	.space 128

	.text
ppal: 			
	la $s0, cad_origen
	
	move $a0, $s0 	# par�metro *orgien
	
	jal isdigit
	
	move $a0, $s0	# par�metro *dest
	li $v0, 4	# print_string
	syscall
	
	li $v0, 10	# EXIT
	syscall	
###################   fin programa ppal   ###################	


##### funci�n isdigit #####
	.globl isdigit 	
isdigit:
	li $t0, 0	# $t0 = i = �ndice/contador
isdigit_while:
	add $t2,$a0,$t0		# Utilizamos el registro $t2 como �ndice para recorrer los vectores
	lb $t1,0($t2)		# Caracter = puntero auxiliar
	beqz $t1,isdigit_fin	# Bucle para controlar el recorrido por los vectores
	blt $t1,48,else		# Estructura condicional para establecer el l�mite entre n�meros y caracteres
	bgt $t1,57,else	
	add $t1,$zero,49	# Sumamos el car�cter ASCII 49 (n�mero 1) al registro $t1 para que en caso de que haya un n�mero escriba un 1
	j fin_if
else:
	add $t1,$zero,48	# Sumamos el car�cter ASCII 48 (n�mero 0, al registro $t1 para que en caso de que haya un car�cter escriba un 0
fin_if:
	add $t2,$a0,$t0		# Registro $t2 como �ndice para recorrer el vector
	sb $t1,0($t2)		# Puntero auxiliar = nuevo car�cter
	addi $t0,$t0,1		# Incrementamos el �ndice
	j isdigit_while		# Reiterar
isdigit_fin:
	jr $ra			# Salto a la funci�n ppal
##### Fin funci�n isdigit #####
