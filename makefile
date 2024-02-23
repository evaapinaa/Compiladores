lexico1: 	lex.yy.c
			gcc lex.yy.c -lfl -o lexico1

lex.yy.c: 	lexico1.l lexico1.h
			flex lexico1.l

clean:
			rm -rf lex.yy.c lexico1
