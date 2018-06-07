# Problema 1:
# Programar una función que cuente el número de caracteres de una cadena.


# Se da como referencia la siguiente descripción del algoritmo:

# Parámetro de entrada: puntero "p" a cadena de caracteres asciiz (con carácter terminador).
# Parámetro de salida:  entero "i" igual a la longitud de la cadena (sin contar el terminador).

# Se debe programar un bucle que en cada iteración lea un carácter de la cadena y compruebe si es
# o no es un terminador (comparar con valor numérico 0, o bien con el carácter '\0').
# Si el carácter leído no es terminador, incrementar el contador de caracteres. Si lo es,
# devolver en $v0 el número de caracteres que se han contado.




############################################################
# Programa principal (no alterar)

	.data
	
cadena:		.asciiz "Tengo 20 caracteres."
mensaje:	.asciiz "La longitud de la cadena es "
lineanueva:	.asciiz "\n"

	.text
ppal: 	la $a0, cadena
	jal strlen      # Llamada a la función strlen que se pide programar
	
	move $s0, $v0   # Transferir resultado a un registro salvado
	
	# Imprimir resultados por pantalla:
	la $a0, mensaje # "La longitud de la cadena es "
	li $v0, 4    	# servicio "print string"
	syscall

	move $a0, $s0	# resultado numérico
	li $v0, 1	# servicio "print integer"
	syscall
	
	la $a0, lineanueva  	# cadena "\n"
	li $v0, 4		# print string
	syscall
	
	# Fin del programa
	
	li $v0, 10		# servicio "exit (terminate execution)"
	syscall
# Fin ppal.	
######################################


######################################
# Función strlen:

	.globl strlen
strlen:

bucle:				#inicializamos el bucle
	lb $t2,cadena($t1)	#Ponemos la cadena en bytes
	beq $t2,0,fin_bucle	#Condición del bucle
	sll $t1,$t0,1		#Incremento del índice

	add $v0,$v0,1		#Incrementamos el contador del programa
	
	add $t0,$t0,1		#Incrementamos el índice
	
	j bucle
	
fin_bucle:	
	addi $v0,$v0,-1		#Al estar en bytes, el resultado de $v0 será 11 en este caso debido a que estammos implementando un resultado más, por lo tanto hay que restar uno
	sll $v0, $v0, 1		#Por la misma razón (que está en bytes), debemos duplicar el resultado para que te de el resultado exacto.
		

	jr $ra  # devolver control al programa principal
# Fin strlen
###############################################################
