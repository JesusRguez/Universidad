# p7.asm

# Problema 7: Función strrev que recibe un puntero a una cadena e invierte el orden de los carácteres de dicha cadena.

# Datos de entrada:
# 	- $a0 = puntero a la cadena origen
# Proceso:
# Recibe como parámetro un puntero a la cadena origen e intercambia las posiciones de los caracteres.
# Datos de salida:	No devuelve resultados.

.data
cad_origen: .asciiz "Esta cadena se va a intercambiar."
.text
ppal:
	la $s0, cad_origen


	move $a0,$s0	#Parametro *orig
	
	jal strrev	# Salto a la función strrev

	li $v0,4	# Imprime la cadena
	syscall

	li $v0,10		
	syscall			# Fin del programa
###################   Fin programa ppal   ###################

##### función strrev #####
	.globl strrev
strrev:
	li $t0,0		# Contador
bucle:
	add $t2,$a0,$t0		# Recorremos la cadena
	lb $t1,0($t2)		# Caracter = puntero auxiliar
	blez $t1,fin_bucle	# Bucle para controlar el recorrido del vector
	add $sp,$sp,-1		# Reservamos tamaño en pila
	sb $t1, 0($sp)		# Cargamos el caracter en la pila de tamaño byte
	add $t0,$t0,1		# Incrementamos el contador
	j bucle			# Reitera
fin_bucle:

bucleimp:
	lb $t1,0($sp)		# Caracter = puntero auxiliar
	add $sp,$sp,1		# Implementamos un hueco en pila de tamaño byte
	blez $t1,fin_bucleimp	# Bucle para controlar el recorrido del vector
	add $t2,$a0,$t7		# Recorremos la cadena
	sb $t1,0($t2)		# Caracter = puntero auxiliar
	add $t7,$t7,1		# incrementamos el contador
	j bucleimp		# Reitera
fin_bucleimp:
	jr $ra			# Salto a la función ppal
##### Fin función strrev #####
