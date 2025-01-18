miniC: Lexico_miniC_main.c miniC.tab.c lex.yy.c listaSimbolos.c listaCodigo.c
	gcc -g Lexico_miniC_main.c miniC.tab.c lex.yy.c listaSimbolos.c listaCodigo.c -lfl -o miniC
	
miniC.tab.c miniC.tab.h: miniC.y
	bison -d -v miniC.y
	
lex.yy.c: lexico_miniC.l
	flex lexico_miniC.l
	
limpia:
	rm -f miniC miniC.s errores.txt sintactico.output lex.yy.c sintactico.tab.*
	
