# p4.asm
#
# Problema 4: Función strcat: Concatenar dos cadenas de caracteres.
#
# Datos de entrada:
# 	- $a0 = puntero a cadena 1.
#	- $a1 = puntero a cadena 2.
# Proceso:
#	Concatena las dos cadenas que se le pasan por parámetros
# Datos de salida:	No devuelve resultados.

	.data
dest: 	.asciiz	"En un lugar de La Mancha "
orig:	.asciiz "de cuyo nombre no quiero acordarme..."

	.text
ppal: 			
	la $s0, dest	# Cargamos la cadena dest en $s0
	la $s1, orig # Cargamos la cadena dest en $s1
	
	move $a0, $s0 	# Parámetro *cadena1
	move $a1, $s1 	# Parámetro *cadena2
	jal strcat	# Llamada a la función strcat
	
	move $a0, $s0	# Parámetro *cadena2
	li $v0, 4	# Imprime la cadena
	syscall
	
	li $v0, 10	# Fin del programa
	syscall	
###################   fin programa ppal   ###################	


##### función strcat #####
	.globl strcat 		# La función strcat contará los caracteres de la segunda cadena y luego concatenará el contenido de la primera cadena con el contenido de la segunda cadena, uniéndolo todo en la segunda cadena.
strcat:	
	li $t0, 0		# $t0=contador de la longitud de la cadena
contador:			# El contador nos sirve para saber cual es la longitud de la cadena
	add $t2,$a0,$t0		# Recorremos la primera cadena para ver su longitud
	lb $t1,0($t2)		# Carácter = puntero auxiliar
	beqz $t1,fin_contador	# Bucle para recorrer la primera cadena
	add $t0,$t0,1		# Incrementamos el registro $t0 con cada iteración para incrementar el valor de la longitud de la cadena
	j contador		# Reiteración
fin_contador:
strcat_while:
	add $t1,$a1,$t4		# Recorremos la primera cadena
	lb $t3,0($t1)		# Caracter = puntero auxiliar
	beqz $t3,strcat_fin	# Bucle para controlar el recorrido por los vectores
	add $t1,$a0,$t0		# Recorremos la primera cadena
	sb $t3,0($t1)		# Puntero auxiliar = nuevo carácter
	addi $t0,$t0,1		# Incrementamos el índice $t0
	addi $t4,$t4,1		# Incrementamos el índice $t4
	j strcat_while		# Reiteración
strcat_fin:
	jr $ra			# Salto a la función ppal
##### Fin función strcat #####
