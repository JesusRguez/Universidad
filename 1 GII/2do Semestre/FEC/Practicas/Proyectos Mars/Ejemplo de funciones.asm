.data
v1: .word 10, 15, 30, 40, 9
v2: .word 5, 20, 27, 33, 50
v3: .space 4
caracter: .asciiz " "
.text

.globl main

main:
li $t0, 0
li $s0, 4

bucle:
bgt $t0,$s0, fin_bucle		#desplazamiento=indice*4
sll $t1,$t0, 2
sll $t2,$t0,2		
		
lw $a0, v1($t1)
lw $a1, v2($t2)

addi $sp,$sp,-8
sw $t0, 4($sp)
sw $t1, 0($sp)
jal max
lw $t1, 0($sp)
lw $t0, 4($sp)

#sw $v0, v3			#almacena resultado


lw   $a0, v3
li   $v0, 1
syscall

li $v0, 11
la $a0, caracter
syscall

addi $t0,$t0,1
j bucle
fin_bucle:

li $v0,10	#Fin programa
syscall


max:
ble $a0, $a1, else

#bloque if
sw $a0,v3

#termina bloque if
j fin_if

#bloque else
else:
sw $a1, v3
fin_if:

jr $ra
