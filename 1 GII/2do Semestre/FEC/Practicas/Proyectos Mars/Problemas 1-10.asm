.data 
valor: .half 0xa,0xb,0x01,0x02  
texto: .asciiz "La suma es: "
SUMA:  .half 0x0
.text 
.globl main  

main:  
	move $t0,$zero   # $t0<-- "indice" con valor inicial 0  
	move $t1,$zero   # $t1<-- "suma" con valor inicial 0  
	li   $t2, 4      # $t2<-- constante 
	la   $s0, valor  # $s0 ? puntero a ‘valor’  

#############################################################################################

bucle:  
	# add $t3,$t0,$t0 # t3 = indide +indice = 2 * indice  
	# add $t3,$t3,$t3 # t3 = 2*indide + 2*indice = 4 * indice  
	# add $t4,$s0,$t3 # Suma del desplazamiento a la dirección base, t1= base + 4*i
	
	# Bloque do-while
	sll $t3,$t0, 1 # Hace todo lo anterior reducido en una sentencia más pequeña

	# lw $s1,0($t4) # Carga del elemento referenciado por la dirección guardada en t1, se carga en s1  
	lh $s1,valor($t3) # Carga del elemento directamente de la etiqueta

	add $t1,$t1,$s1 # Suma el elemento a la suma anterior  
  
	add $t0,$t0, 1 # Incremento del indice 
	
	# Salta a bucle
	blt $t0,$t2, bucle # Repite el bucle si no se ha llegado al ultimo elemento (indice<4)

################################################################################################

	add $s3,$s3,$t1
	sh $s3, SUMA

	#Imprime en pantalla: La suma es...
print:
	li   $v0, 4
	la   $a0, texto
	syscall

	li   $v0, 1
	lh   $a0,SUMA
	syscall

################################################################################################
	
	# Termina el programa con una llamada al sistema

	li   $v0, 10
	syscall

######  END  ###################################################  END  ########################

