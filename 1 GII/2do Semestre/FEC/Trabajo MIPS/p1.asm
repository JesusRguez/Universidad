# p1.asm

# Problema 1: Funci�n absv que tome como par�metro un n�mero entero con sigo y devuelva el valor absoluto de ese mismo entero.

# Datos de entrada:
# 	- $a0 = puntero al numero entero.
# Proceso:
# Recibe como par�metro un numero entero con signo y devuelve su valor absuluto.
# Datos de salida:	Valor absoluto del n�mero introducido.

	.data
pregunta: .asciiz "Introduce un n�mero para obtener su valor absoluto: "
	.text
ppal:
	la   $a0, pregunta      # Cargamos la direcci�n de la etiqueta pregunta
	li   $v0, 4           	# Imprimimos la cadena
	syscall               	# Se imprime la cadena
	
	li   $v0, 5	    	# Leemos el n�mero introducido por el usuario
	syscall
	
	move $a0,$v0		# Puntero al par�metro
	
	jal absv		# Funci�n absv (absolute value)
	
	move $a0,$v0		# Movemos el resultado de $v0 a $a0 para introducirlo en el syscall
	
	li $v0, 1		# Imprimimos el valor absoluto del n�mero inicialmente introducido.
	syscall
	
	li $v0,10		
	syscall			# Fin del programa
###################   Fin programa ppal   ###################

##### funci�n absv #####
	.globl absv
absv:
	add $t0,$t0,$a0		# Utilizamos el registro $t0 para almacenar el n�mero
	bgez $t0,fin_if		# Estructura selectiva simple para que, en caso de que el n�mero sea negativo, nos devuelva su valor absoluto (multiplicando por -1)
	mul $t0,$t0,-1		# Multiplicamos el n�mero negativo por -1. Esa sentencia nos guardar� el resultado en $t0
	move $v0,$t0		# Movemos el resultado de $t0 a $v0 para pasarlo a la funci�n ppal
fin_if:
	jr $ra			# Salto a la funci�n ppal
##### Fin funci�n absv #####
