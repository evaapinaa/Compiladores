# MiniC Compiler - Traducción a Ensamblador MIPS

## 📌 Descripción
Este proyecto es un **compilador** para el lenguaje **MiniC**, diseñado en el marco de la asignatura de **Compiladores**. Su función es traducir código MiniC a **ensamblador MIPS**, permitiendo la ejecución en un entorno simulador de MIPS.

## 📜 Características
- Análisis **léxico** con **Flex**.
- Análisis **sintáctico y semántico** con **Bison**.
- **Generación de código** ensamblador MIPS.
- Implementación de un **bucle do-while**.
- **Tratamiento de errores léxicos, sintácticos y semánticos**.

## 📌 Requisitos
- **Sistema Linux** (requerido para Makefile).
- **Flex y Bison** instalados.
- **Simulador MIPS** (Opcional para ejecutar código ensamblador).

## 📡 Especificación del Lenguaje MiniC
MiniC es un subconjunto simplificado de **C** con restricciones:
- Maneja **constantes y variables enteras**.
- **Operadores aritméticos** básicos (`+`, `-`, `*`, `/`).
- Estructuras de control: **if-else, while, do-while**.
- **Sin funciones** excepto `main`.

Ejemplo de código MiniC:
```c
main() {
    const a = 0, b = 0;
    var c = 5 + 2 - 2;
    print("Inicio del programa\n");
    if (a) print("a\n");
    else if (b) print("No a y b\n");
    else while (c) {
        print("c = ", c, "\n");
        c = c - 2 + 1;
    }
    print("Final\n");
}
```

## 🛠 Mejoras Implementadas
- **Soporte para bucle `do-while`**.
- **Tratamiento de errores léxicos, sintácticos y semánticos**.
- **Generación optimizada de código MIPS**.

## 📷 Ejemplo de Código Generado en MIPS
```assembly
.data
    _c: .word 0
    $str1: .asciiz "c\n"

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
    li $v0, 10
    syscall
```
