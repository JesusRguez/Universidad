# p2.asm

# Problema 2: Funci�n swap que tome como par�metros dos punteros a enteros de tama�o palabra
# e intercambie los contenidos de las dos posiciones de memoria apuntada por los punteros.
# Datos de entrada:
# 	- $a0 = puntero al primer n�mero entero.
#	- $a1 = puntero al segundo n�mero entero.
# Proceso:
# Recibe como par�metros dos punteros a enteros e intercambia las posiciones de memoria.

.data
n1: .word 5
n2: .word 10
.text
ppal:
	lw $s0, n1		# Cargamos el primer n�mero en el registro $s0
	lw $s1, n2		# Cargamos el segundo n�mero en el resgistro $s1
	
	move $a0,$s0		# Declaramos los par�metros
	move $a1,$s1		
	
	jal swap		# Llamada a la funci�n swap
	
	move $a0,$v0		# Movemos el valor de $v0 a $a0
	
	li $v0, 1		# Imprimimos el valor del segundo n�mero introducido
	syscall
	
	move $a0,$v1		# Movemos el valor de $v1 a $a0
	
	li $v0,1		# Imprimimos el valor del primer n�mero introducido
	syscall
	
	li $v0,10		
	syscall			# Fin del programa
###################   fin programa ppal   ###################

##### funci�n swap #####
.globl swap
swap:
	move $t1,$a0		# Movemos el valor ubicado en $a0 a $t1 (el cual utilizamos como registro auxiliar
	move $a0,$a1		# Movemos el valor de $a1 a $a0
	move $a1,$t1		# Movemos el valor de $t1 a $a1
	
	move $v0,$a0		# Movemos el valor de $a0 a $v0
	move $v1,$a1		# Movemos el valor de $a1 a $v1
	
	jr $ra			# Salto a la funci�n ppal	
##### Fin funci�n swap #####
