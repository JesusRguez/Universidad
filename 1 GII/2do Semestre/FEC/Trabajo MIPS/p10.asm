# p10.asm
#
# Problema 10: Progamar una calculadora
#
# Proceso:
#	Crear una calculadora que procese las operaciones b�sicas.
# 
# Datos de salida:	Resultado de la operaci�n.

	.data
pregunta: .asciiz "�Qu� operaci�n desea realizar?\n> "
resultado: .ascii "= "
	.text
ppal:	
	la $a0, pregunta      # Cargamos la direcci�n de la etiqueta pregunta
	li $v0, 4           	# Imprimimos la cadena
	syscall               	# Se imprime la cadena
	
	li $v0, 8	    	# Leemos la operaci�n introducida por el usuario
	li $a1, 8
	syscall
	
	jal calculadora		# Funci�n calculadora
	
	la $a0, resultado       # Cargamos la direcci�n de la etiqueta pregunta
	li $v0, 4           	# Imprimimos la cadena
	syscall               	# Se imprime la cadena
	
	move $a0,$v1		# Movemos el resultado de $v0 a $a0 para introducirlo en el syscall
	
	li $v0, 1		# Imprimimos el resultado de la operaci�n
	syscall
	
	li $v0,10		
	syscall			# Fin del programa
###################   Fin programa ppal   ###################

##### funci�n calculadora #####
	.globl calculadora
calculadora:
	li $t0, 0		# $t0 = i = Indice
calculadora_while:
	add $t2,$a0,$t0		# Utilizamos el registro $t2 como �ndice para recorrer el vector
	lb $t1,0($t2)		# Caracter = puntero auxiliar
	beqz $t1,calculadora_fin	# Bucle para controlar el recorrido por el vector
	beq $t1,43,suma		# Sentencia condicional para la suma
	beq $t1,45,resta	# Sentencia condicional para la resta
	beq $t1,42,producto	# Sentencia condicional para el producto
	beq $t1,47,division	# Sentencia condicional para la divisi�n
	add $t0,$t0,1		# Incremento del contador
	j calculadora_while	# Reitera
##############################################################
suma: 
	add $t2,$a0,$t7			# Utilizamos el registro $t2 como �ndice para recorrer el vector
	lb $t1,0($t2)			# Caracter = puntero auxiliar
	beqz $t1,calculadora_fin	# Bucle para recorrer la operaci�n inicial en busca de los d�gitos de la suma
	blt $t1,48,fin_if_suma		# Estructura condicional para para establecer el l�mite ASCII entre n�meros y el resto de caracteres
	bgt $t1,57,fin_if_suma
	bnez $t3,else_suma		# Si el registro $t3 est� ocupado, lo almacenar� en $t4
	sub $t3,$t1,48			# Restamos 48 a $t3 para obtener el n�mero en decimal a partir del c�digo ASCII
	add $t7,$t7,1			# Incrementamos el contador
	j suma				# Salta a suma
else_suma:				# Almacena el n�mero en $t4 si el registro $t3 est� ocupado
	sub $t4,$t1,48			# Restamos 48 a $t4 para obtener el n�mero en decimal a partir del c�digo ASCII
	add $t5,$t3,$t4			# Ejecutamos la suma
	move $v1,$t5			# Movemos el contenido del registro $t5 a $v1 para pasarlo a la funci�n ppal
fin_if_suma:
	add $t7,$t7,1			# Incrementamos el contador
	j suma
###############################################################	
resta: 
	add $t2,$a0,$t7			# Utilizamos el registro $t2 como �ndice para recorrer el vector
	lb $t1,0($t2)			# Caracter = puntero auxiliar
	beqz $t1,calculadora_fin	# Bucle para recorrer la operaci�n inicial en busca de los d�gitos de la resta
	blt $t1,48,fin_if_resta		# Estructura condicional para para establecer el l�mite ASCII entre n�meros y el resto de caracteres
	bgt $t1,57,fin_if_resta
	bnez $t3,else_resta		# Si el registro $t3 est� ocupado, lo almacenar� en $t4
	sub $t3,$t1,48			# Restamos 48 a $t3 para obtener el n�mero en decimal a partir del c�digo ASCII
	add $t7,$t7,1			# Incrementamos el contador
	j resta				# Sala a resta
else_resta:				# Almacena el n�mero en $t4 si el registro $t3 est� ocupado
	sub $t4,$t1,48			# Restamos 48 a $t4 para obtener el n�mero en decimal a partir del c�digo ASCII
	sub $t5,$t3,$t4			# Ejecutamos la resta
	move $v1,$t5			# Movemos el contenido del registro $t5 a $v1 para pasarlo a la funci�n ppal
fin_if_resta:
	add $t7,$t7,1			# Incrementamos el contador
	j resta
###############################################################
producto: 
	add $t2,$a0,$t7			# Utilizamos el registro $t2 como �ndice para recorrer el vector
	lb $t1,0($t2)			# Caracter = puntero auxiliar
	beqz $t1,calculadora_fin	# Bucle para recorrer la operaci�n inicial en busca de los d�gitos del producto
	blt $t1,48,fin_if_producto	# Estructura condicional para para establecer el l�mite ASCII entre n�meros y el resto de caracteres	
	bgt $t1,57,fin_if_producto
	bnez $t3,else_producto		# Si el registro $t3 est� ocupado, lo almacenar� en $t4
	sub $t3,$t1,48			# Restamos 48 a $t3 para obtener el n�mero en decimal a partir del c�digo ASCII
	add $t7,$t7,1			# Incrementamos el contador
	j producto			# Salta a producto
else_producto:				# Almacena el n�mero en $t4 si el registro $t3 est� ocupado
	sub $t4,$t1,48			# Restamos 48 a $t4 para obtener el n�mero en decimal a partir del c�digo ASCII
	mul $t5,$t3,$t4			# Ejecutamos el producto
	move $v1,$t5			# Movemos el contenido del registro $t5 a $v1 para pasarlo a la funci�n ppal
fin_if_producto:
	add $t7,$t7,1			# Incrementamos el contador
	j producto
###############################################################
division: 
	add $t2,$a0,$t7			# Utilizamos el registro $t2 como �ndice para recorrer el vector
	lb $t1,0($t2)			# Caracter = puntero auxiliar
	beqz $t1,calculadora_fin	# Bucle para recorrer la operaci�n inicial en busca de los d�gitos de la divisi�n
	blt $t1,48,fin_if_division	# Estructura condicional para para establecer el l�mite ASCII entre n�meros y el resto de caracteres	
	bgt $t1,57,fin_if_division
	bnez $t3,else_division		# Si el registro $t3 est� ocupado, lo almacenar� en $t4
	sub $t3,$t1,48			# Restamos 48 a $t3 para obtener el n�mero en decimal a partir del c�digo ASCII
	add $t7,$t7,1			# Incrementamos el contador
	j division			# Salta a divisi�n
else_division:				# Almacena el n�mero en $t4 si el registro $t3 est� ocupado
	sub $t4,$t1,48			# Restamos 48 a $t4 para obtener el n�mero en decimal a partir del c�digo ASCII
	div $t5,$t3,$t4			# Ejecutamos la divisi�n
	move $v1,$t5			# Movemos el contenido del registro $t5 a $v1 para pasarlo a la funci�n ppal
fin_if_division:
	add $t7,$t7,1			# Incrementamos el contador
	j division
	
calculadora_fin:	
	jr $ra				# Salto a la funci�n ppal
##### Fin funci�n calculadora #####
