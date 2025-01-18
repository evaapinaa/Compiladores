#include <stdio.h>
#include <stdlib.h>

extern int numErroresSintacticos;
extern int numErroresSemanticos;
extern int numErroresLexicos;
extern char *yytext;
extern int  yyleng;
extern FILE *yyin;
extern int yyparse();
extern int yydebug;
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
	yydebug=0;
	if (!(numErroresSintacticos == 0 && numErroresSemanticos == 0 && numErroresLexicos == 0)){
		printf("\n------ERRORES--TOTALES------\n");
	 	printf(" Errores léxicos: %d\n", numErroresLexicos);
		printf(" Errores sintácticos: %d\n", numErroresSintacticos);
		printf(" Errores semánticos: %d\n", numErroresSemanticos);
	}
    fclose(fich);
    return 0;
}


