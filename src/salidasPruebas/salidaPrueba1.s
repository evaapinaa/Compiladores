############################
 # Seccion de datos
 .data

# Cadenas ##################
$str1:	.asciiz "Test 1\n" 
$str2:	.asciiz "no_cambia =" 
$str3:	.asciiz "\n" 
$str4:	.asciiz "cambia = " 
$str5:	.asciiz "\n" 
$str6:	.asciiz "podria_cambia = " 
$str7:	.asciiz "\n" 
$str8:	.asciiz "Fin test1\n" 

# Identificadores ##############
_no_cambia:	.word 0
_cambia:	.word 0
_podria_cambiar:	.word 0
###################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,2
	sw $t0,_no_cambia
	li $t0,4
	sw $t0,_podria_cambiar
	la $a0,$str1
	syscall
	lw $t0,_no_cambia
	sw $t0,_podria_cambiar
	lw $t0,_podria_cambiar
	lw $t1,_no_cambia
	mul $t2,$t0,$t1
	lw $t0,_no_cambia
	lw $t1,_no_cambia
	add $t3,$t0,$t1
	add $t0,$t2,$t3
	sw $t0,_cambia
	la $a0,$str2
	syscall
	lw $t0,_no_cambia
	move $a0,$t0
	li $v0,1
	syscall
	la $a0,$str3
	syscall
	la $a0,$str4
	syscall
	lw $t0,_cambia
	move $a0,$t0
	li $v0,1
	syscall
	la $a0,$str5
	syscall
	la $a0,$str6
	syscall
	lw $t0,_podria_cambiar
	move $a0,$t0
	li $v0,1
	syscall
	la $a0,$str7
	syscall
	la $a0,$str8
	syscall
##################
# Fin
	li $v0, 10
	syscall
