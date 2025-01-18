#####################
# Seccion de datos
   .data
_c:
   .word 0
$str1:
   .asciiz "c\n"

#####################
# Seccion de codigo
   .text
   .globl main
main:
   li $t0, 4
   sw $t0, _c
$l1:
   la $a0, $str1
   li $v0, 4
   syscall 
   lw $t0, _c
   li $t1, 1
   sub $t2, $t0, $t1
   sw $t2, _c
   lw $t1, _c
   bnez $t1, $l1

#####################
# Fin
   li $v0, 10
   syscall
