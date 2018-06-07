# p5.asm
#
# Problema 5: Función isdigit: Números=1 y carácteres=0
#
# Datos de entrada:
# 	- $a0 = puntero a cadena origen.
# Proceso:
#	Recorre la cadena y en caso de encontrar un número escribe un 1 y en caso de encontrar un carácter escribe un 0.
# 
# Datos de salida:	Si hay un número un 1 y si hay un carácter un 0.

	.data
cad_origen: 	.asciiz	"Naci el 25/03/1997."
cad_dest:	.space 128

	.text
ppal: 			
	la $s0, cad_origen
	
	move $a0, $s0 	# parámetro *orgien
	
	jal isdigit
	
	move $a0, $s0	# parámetro *dest
	li $v0, 4	# print_string
	syscall
	
	li $v0, 10	# EXIT
	syscall	
###################   fin programa ppal   ###################	


##### función isdigit #####
	.globl isdigit 	
isdigit:
	li $t0, 0	# $t0 = i = índice/contador
isdigit_while:
	add $t2,$a0,$t0		# Utilizamos el registro $t2 como índice para recorrer los vectores
	lb $t1,0($t2)		# Caracter = puntero auxiliar
	beqz $t1,isdigit_fin	# Bucle para controlar el recorrido por los vectores
	blt $t1,48,else		# Estructura condicional para establecer el límite entre números y caracteres
	bgt $t1,57,else	
	add $t1,$zero,49	# Sumamos el carácter ASCII 49 (número 1) al registro $t1 para que en caso de que haya un número escriba un 1
	j fin_if
else:
	add $t1,$zero,48	# Sumamos el carácter ASCII 48 (número 0, al registro $t1 para que en caso de que haya un carácter escriba un 0
fin_if:
	add $t2,$a0,$t0		# Registro $t2 como índice para recorrer el vector
	sb $t1,0($t2)		# Puntero auxiliar = nuevo carácter
	addi $t0,$t0,1		# Incrementamos el índice
	j isdigit_while		# Reiterar
isdigit_fin:
	jr $ra			# Salto a la función ppal
##### Fin función isdigit #####
