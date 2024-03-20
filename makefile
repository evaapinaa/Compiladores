sintactico: sintactico.tab.c sintactico.tab.h lex.yy.c 
			gcc lex.yy.c sintactico.tab.c -lfl -o sintactico

sintactico.tab.c sintactico.tab.h: sintactico.y
								   bison -d -v sintactico.y

lex.yy.c: 	lexico1.l
			flex lexico1.l

clean:
			rm lex.yy.c sintactico.tab.c sintactico.tab.h sintactico.output sintactico
 
run: 
			./sintactico p
