#Traducción de C:

#void strcpy(char *dest, char *orig)
#{
#int i=0;
#while((dest[i]=orig[i])!=0)
#    {
#	i++;
#    }
#}

#Por convenio, *dest es $a0 y *orig es $a1; la variable i es $t0 que será el desplazamiento

.data
cad_origen: .asciiz "En un lugar de La Mancha..."
cad_destino: .space 128
.text
main:
la $s1, cad_origen
la $s0, cad_destino

move $a0,$s0	#Parametro *dest
move $a1,$s1	#Parametro *orig
jal strcpy

move $a0,$s1
li $v0,4	#print_string
syscall

li $v0,10	#EXIT
syscall

strcpy:
li $t0,0
bucle:
#1. Leer carácter origen
add $t1,$a1,$t0		#Puntero auxiliar=puntero origen+i
lb $t2,0($t1)		#Carácter auxiliar=puntero auxiliar
#2. Almacenar carácter leído en destino
add $t1,$a0,$t0		#Puntero auxiliar=puntero destino+i
sb $t2,0($t1)		#Puntero auxiliar=caracter auxiliar
#3. Comparar carácter copiado con terminador
beqz $t2,fin_bucle	#while((dest[i]=orig[i])!=0)
addi $t0,$t0,1
j bucle			#i++
fin_bucle:
jr $ra