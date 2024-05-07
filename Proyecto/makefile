miniC:	miniC.tab.c miniC.tab.h lex.yy.c  listaSimbolos.h listaSimbolos.c listaCodigo.h listaCodigo.c
		gcc lex.yy.c miniC.tab.c listaSimbolos.c listaCodigo.c -lfl -o miniC

miniC.tab.c miniC.tab.h: 	miniC.y
							bison -d -v miniC.y

lex.yy.c:	lexico.l
			flex lexico.l

clean:
			rm lex.yy.c miniC.tab.c miniC.tab.h miniC.output miniC
 
run: 
			./miniC p
