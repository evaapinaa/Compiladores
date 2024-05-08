#####################
# Seccion de datos
   .data
_a:
   .word 0
_b:
   .word 0
_c:
   .word 0
$str1:
   .asciiz "Inicio del programa\n"
$str2:
   .asciiz "a"
$str3:
   .asciiz "\n"
$str4:
   .asciiz "No a y b\n"
$str5:
   .asciiz "c = "
$str6:
   .asciiz "\n"
$str7:
   .asciiz "Final"
$str8:
   .asciiz "\n"

#####################
# Seccion de codigo
   .text
   .globl main
main:
   li $t0, 0
   sw $t0, _a
   li $t0, 0
   sw $t0, _b
   li $t0, 5
   li $t1, 2
   add $t2, $t0, $t1
   li $t1, 2
   sub $t3, $t2, $t1
   sw $t3, _c
   la $a0, $str1
   li $v0, 4
   syscall 
   lw $t1, _a
   beqz $t1, $l5
   la $a0, $str2
   li $v0, 4
   syscall 
   la $a0, $str3
   li $v0, 4
   syscall 
   b $l6, 
$l5:
   lw $t3, _b
   beqz $t3, $l3
   la $a0, $str4
   li $v0, 4
   syscall 
   b $l4, 
$l3:
$l1:
   lw $t4, _c
   beqz $t4, $l2
   la $a0, $str5
   li $v0, 4
   syscall 
   lw $t5, _c
   move $a0, $t5
   li $v0, 1
   syscall 
   la $a0, $str6
   li $v0, 4
   syscall 
   lw $t5, _c
   li $t6, 2
   sub $t7, $t5, $t6
   li $t6, 1
   add $t8, $t7, $t6
   sw $t8, _c
   b $l1, 
$l2:
$l4:
$l6:
   la $a0, $str7
   li $v0, 4
   syscall 
   la $a0, $str8
   li $v0, 4
   syscall 

#####################
# Fin
   li $v0, 10
   syscall
