# p2.asm

# Problema 2: Función swap que tome como parámetros dos punteros a enteros de tamaño palabra
# e intercambie los contenidos de las dos posiciones de memoria apuntada por los punteros.
# Datos de entrada:
# 	- $a0 = puntero al primer número entero.
#	- $a1 = puntero al segundo número entero.
# Proceso:
# Recibe como parámetros dos punteros a enteros e intercambia las posiciones de memoria.

.data
n1: .word 5
n2: .word 10
.text
ppal:
	lw $s0, n1		# Cargamos el primer número en el registro $s0
	lw $s1, n2		# Cargamos el segundo número en el resgistro $s1
	
	move $a0,$s0		# Declaramos los parámetros
	move $a1,$s1		
	
	jal swap		# Llamada a la función swap
	
	move $a0,$v0		# Movemos el valor de $v0 a $a0
	
	li $v0, 1		# Imprimimos el valor del segundo número introducido
	syscall
	
	move $a0,$v1		# Movemos el valor de $v1 a $a0
	
	li $v0,1		# Imprimimos el valor del primer número introducido
	syscall
	
	li $v0,10		
	syscall			# Fin del programa
###################   fin programa ppal   ###################

##### función swap #####
.globl swap
swap:
	move $t1,$a0		# Movemos el valor ubicado en $a0 a $t1 (el cual utilizamos como registro auxiliar
	move $a0,$a1		# Movemos el valor de $a1 a $a0
	move $a1,$t1		# Movemos el valor de $t1 a $a1
	
	move $v0,$a0		# Movemos el valor de $a0 a $v0
	move $v1,$a1		# Movemos el valor de $a1 a $v1
	
	jr $ra			# Salto a la función ppal	
##### Fin función swap #####
