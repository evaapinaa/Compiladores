############################
 # Seccion de datos
 .data

# Cadenas ##################
$str1:	.asciiz "Inicio del programa\n" 
$str2:	.asciiz "Introduzca un valor para la variable \" c \":\n" 
$str3:	.asciiz " \" c \" no era nulo . " 
$str4:	.asciiz " \ n " 
$str5:	.asciiz " \" c \" si era nulo . " 
$str6:	.asciiz " \ n " 
$str7:	.asciiz " \" d \" vale " 
$str8:	.asciiz " \ n " 
$str9:	.asciiz " \" a \"y \" x \" no son opuestos . " 
$str10:	.asciiz " \ n " 
$str11:	.asciiz " \" a \"y \" x \" son opuestos . " 
$str12:	.asciiz " \ n " 
$str13:	.asciiz "La variable e es más grande que a" 
$str14:	.asciiz " Final " 
$str15:	.asciiz " \ n " 

# Identificadores ##############
_a:	.word 0
_b:	.word 0
_c:	.word 0
_d:	.word 0
_e:	.word 0
_x:	.word 0
###################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,1
	neg $t1,$t0
	sw $t1,_a
	lw $t0,_a
	li $t1,6
	neg $t2,$t1
	mul $t1,$t0,$t2
	li $t0,3
	div $t2,$t1,$t0
	sw $t2,_b
	li $t0,5
	li $t1,2
	lw $t2,_b
	lw $t3,_a
	sub $t4,$t2,$t3
	mul $t2,$t1,$t4
	add $t1,$t0,$t2
	sw $t1,_d
	li $t0,9
	li $t1,3
	div $t2,$t0,$t1
	sw $t2,_e
	li $t0,1
	sw $t0,_x
	la $a0,$str1
	syscall
	la $a0,$str2
	syscall
	li $v0,5
	syscall
	sw $v0,_c
	lw $t0,_c
	beqz $t0,$l1
	la $a0,$str3
	syscall
	b $l2
$l1:

	la $a0,$str5
	syscall
$l2:

$l3:

	lw $t0,_d
	beqz $t0,$l4
	la $a0,$str7
	syscall
	lw $t1,_d
	li $t2,1
	sub $t3,$t1,$t2
	sw $t3,_d
	b $l3
$l4:

	lw $t0,_a
	lw $t1,_x
	add $t2,$t0,$t1
	beqz $t2,$l5
	la $a0,$str9
	syscall
	b $l6
$l5:

	la $a0,$str11
	syscall
$l6:

	lw $t0,_a
	lw $t1,_x
	sub $t2,$t0,$t1
	move $a0,$t2
	li $v0,1
	syscall
	lw $t0,_e
	lw $t1,_a
	sub $t2,$t0,$t1
	beqz $t2,$l7
	la $a0,$str13
	syscall
$l7:

	la $a0,$str14
	syscall
##################
# Fin
	li $v0, 10
	syscall
