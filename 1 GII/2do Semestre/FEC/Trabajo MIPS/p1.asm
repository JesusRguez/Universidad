# p1.asm

# Problema 1: Función absv que tome como parámetro un número entero con sigo y devuelva el valor absoluto de ese mismo entero.

# Datos de entrada:
# 	- $a0 = puntero al numero entero.
# Proceso:
# Recibe como parámetro un numero entero con signo y devuelve su valor absuluto.
# Datos de salida:	Valor absoluto del número introducido.

	.data
pregunta: .asciiz "Introduce un número para obtener su valor absoluto: "
	.text
ppal:
	la   $a0, pregunta      # Cargamos la dirección de la etiqueta pregunta
	li   $v0, 4           	# Imprimimos la cadena
	syscall               	# Se imprime la cadena
	
	li   $v0, 5	    	# Leemos el número introducido por el usuario
	syscall
	
	move $a0,$v0		# Puntero al parámetro
	
	jal absv		# Función absv (absolute value)
	
	move $a0,$v0		# Movemos el resultado de $v0 a $a0 para introducirlo en el syscall
	
	li $v0, 1		# Imprimimos el valor absoluto del número inicialmente introducido.
	syscall
	
	li $v0,10		
	syscall			# Fin del programa
###################   Fin programa ppal   ###################

##### función absv #####
	.globl absv
absv:
	add $t0,$t0,$a0		# Utilizamos el registro $t0 para almacenar el número
	bgez $t0,fin_if		# Estructura selectiva simple para que, en caso de que el número sea negativo, nos devuelva su valor absoluto (multiplicando por -1)
	mul $t0,$t0,-1		# Multiplicamos el número negativo por -1. Esa sentencia nos guardará el resultado en $t0
	move $v0,$t0		# Movemos el resultado de $t0 a $v0 para pasarlo a la función ppal
fin_if:
	jr $ra			# Salto a la función ppal
##### Fin función absv #####
