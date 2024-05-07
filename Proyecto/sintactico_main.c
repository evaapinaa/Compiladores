#include <stdio.h>
#include <stdlib.h>

extern int err_lex;
extern int err_sin;
extern int err_sem;
extern char *yytext;
extern int  yyleng;
extern FILE *yyin;
extern int yyparse();
FILE *fich;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Uso correcto: %s fichero\n",argv[0]);
		exit(1);
	}
	FILE *fich = fopen(argv[1],"r");
	if (fich == 0) {
		printf("No se puede abrir %s\n",argv[1]);
		exit(1);
	}
    yyin=fich;
    yyparse();
	if (!(err_lex == 0 && err_sem == 0 && err_sin == 0)){
		printf("--------------------\n");
	 	printf(" Errores léxicos: %d\n", err_lex);
		printf(" Errores sintácticos: %d\n", err_sin);
		printf(" Errores semánticos: %d\n", err_sem);
	}
    fclose(fich);
    return 0;
}


