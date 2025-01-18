#include <stdio.h>
#include <stdlib.h>
#include "lexico_miniC.h"

extern char *yytext;
extern int  yyleng;
extern FILE *yyin;
extern int yylex();
extern int yyparse();
extern int yydebug;
extern int numErroresSintacticos;
extern int numErroresSemanticos;
extern int ProgramaCorrecto();
FILE *fich;
int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Uso correcto: %s fichero\n",argv[0]);
		exit(1);
	}
   int i;
    if ((fich=fopen(argv[1],"r"))==NULL) {
        printf("***ERROR, no puedo abrir el fichero\n");
        exit(2);
    }
    yyin=fich;
 	//Llamamos al sintactico
    yydebug = 0;
    yyparse();
    //Primero se analiza el Sintactico y luego el Semantico ya que de haber errores sintacticos no se debería ejecutar un analisis Semantico
    if (numErroresSintacticos) {
	printf("Analisis sintactico con errores\n");
    }
    if (numErroresSemanticos) {
	printf("Analisis semantico con errores\n");
    }

    fclose(fich);
    return 0;
}
