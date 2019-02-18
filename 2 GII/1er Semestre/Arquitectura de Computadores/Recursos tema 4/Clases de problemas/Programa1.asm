.data 
 
num:  	.word32 3  
vec:    	.word 1
	   	.word 2 
		.word 3 
		.word 4
		.word 5 
		.word 6
		.word 7
		.word 8	;word tiene tamaño 8 bytes
  
.text   
start: 
	
	lui $s0, num	;Carga la direccion de num
	lw $s0, 0($s0)	;Carga num en s0
	addi $s1, $s1, vec	;s1 esta a 0, le suma la dir. de vec
	addi $s2, $s2, 8		;Carga en 2 el tamaño del vector
loop:  
	lw $s3,0($s1)  	;Carga el elemento del vector
	add $s3,$s3,$s0 	;Le suma el numero
	sw $s3, 0($s1)	;Lo guarda
	lw $s5, 8($s1)	;Carga el siguiente elemento 
	add $s5,$s5,$s0	;Le suma el numero
	sw $s5, 8($s1)  ;Lo guarda
	addi $s1,$s1,16	;Aumenta el puntero a la sig. posicion
	addi $s4,$s4, 2  ;s4 empieza en 0, le sumamos 2.
	bne $s2,$s4,loop   ;Mientras $s2 y $s4 no sean iguales
	syscall 0	;Salir
