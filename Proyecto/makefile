sintactico: sintactico.tab.c sintactico.tab.h lex.yy.c  listaSimbolos.h listaSimbolos.c listaCodigo.h listaCodigo.c
			gcc lex.yy.c sintactico.tab.c listaSimbolos.c listaCodigo.c -lfl -o miniC

sintactico.tab.c sintactico.tab.h: sintactico.y
								   bison -d -v sintactico.y

lex.yy.c: 	lexico.l
			flex lexico.l

clean:
			rm lex.yy.c sintactico.tab.c sintactico.tab.h sintactico.output miniC
 
run: 
			./miniC p
