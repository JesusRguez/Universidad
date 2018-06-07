# p3.asm
#
# Problema 3: Función strupr: Pasar una cadena a mayúsculas.
#
# Datos de entrada:
# 	- $a0 = puntero a cadena destino.
#	- $a1 = puntero a cadena origen.
# Proceso:
#	Copia los caracteres de la cadena apuntada por origen a partir
# de la posición apuntada por destino, cambiando las letras minúsculas
# por mayúsculas.
# Datos de salida:	No devuelve resultados.

	.data
cad_origen: 	.asciiz	"En un lugar de La Mancha..."
cad_destino:	.space 128

	.text
ppal: 			
	la $s1, cad_origen
	la $s0, cad_destino
	
	move $a0, $s0 	# parámetro *dest
	move $a1, $s1 	# parámetro *orig
	jal strupr
	
	move $a0, $s0	# parámetro *dest
	li $v0, 4	# print_string
	syscall
	
	li $v0, 10	# EXIT
	syscall	
###################   fin programa ppal   ###################	


##### función strupr #####
	.globl strupr 	
strupr:
	li $t0, 0	# $t0 = i = índice/contador
strupr_while:
	add $t2,$a1,$t0		# Utilizamos el registro $t2 como índice para recorrer los vectores
	lb $t1,0($t2)		# Caracter = puntero auxiliar
	beqz $t1,strupr_fin	# Bucle para controlar el recorrido por los vectores
	blt $t1,97,fin_if	# Estructura condicional para establecer el límite entre mayúsculas y minúsculas
	bgt $t1,122,fin_if	
	sub $t1,$t1,32		# Restamos 32 al caracter ASCII para obtener la letra mayúscula
fin_if:
	add $t2,$a0,$t0		# Registro $t2 como índice para recorrer el vector
	sb $t1,0($t2)		# Puntero auxiliar = nuevo carácter
	addi $t0,$t0,1		# Incrementamos el índice
	j strupr_while		# Reiterar
strupr_fin:
	jr $ra			# Salto a la función ppal
##### Fin función strupr #####
